#include "TerrainSequence.h"
#include "Sprite.h"

void TerrainSequence::ParseFile(string path)
{
	ifstream file(path);
	string line;

	while (file.is_open())
	{
		int y = 0;
		while (getline(file, line))
		{
			string buf;
			stringstream ss(line);
			map<int, pair<char, char>> yData;
			int x = 0;
			while (ss >> buf)
			{
				if (buf != "--")
				{
					pair<char, char> values = { buf[0], buf[1] };
					yData.insert(make_pair(x, values));
				}
				x++;
			}
			terrainData.insert(make_pair(SEQUENCE_HEIGHT-1-y, yData));
			y++;
		}
		file.close();
	}
}

void TerrainSequence::FillData()
{
	auto regularBlocks = terrainData;

	auto y = regularBlocks.begin();
	while (y != regularBlocks.end())
	{
		auto x = y->second.begin();
		while (x != y->second.end())
		{
			if (x->second.second != 'X' || x->second.first == '+')
				x = y->second.erase(x);
			else
				x++;
		}
		if (y->second.size() == 0)
			y = regularBlocks.erase(y);
		else
			y++;
	}

	MakeBlocks(regularBlocks);
}

void TerrainSequence::MakeBlocks(TerrainGrid &blocksData)
{
	TerrainGrid block;

	while (blocksData.size() > 0)
	{
		block = blocksData;

		unsigned int minlength = SEQUENCE_SIZE;

		auto y = block.begin();

		while (y != block.end())
		{
			auto prevY = y; if (y != block.begin()) prevY = prev(y);
			if (y->first > prevY->first + 1)
				block.erase(y++);
			else
			{
				auto x = y->second.begin();
				while (x != y->second.end())
				{
					auto prevX = x; if (x != y->second.begin()) prevX = prev(x);
					auto prevXunder = prevY->second.begin();
					advance(prevXunder, distance(y->second.begin(),x));
					if (prevXunder == prevY->second.end())
						y->second.erase(x++);
					else if (x->first > prevX->first + 1 || *prevXunder != *x)
						y->second.erase(x++);
					else
						x++;
				}
				if (y->second.size() == 0)
					block.erase(y++);
				else
				{
					if (y->second.size() < minlength)
						minlength = y->second.size();
					y++;	
				}
			}
		}

		for (auto &y : block)
		{
			auto x = y.second.begin();
			advance(x, minlength);
			while (x != y.second.end())
				y.second.erase(x++);
		}

		SubstractBlock(blocksData, block);
		blockList.push_back(block);
	}
}

void TerrainSequence::SubstractBlock(TerrainGrid &grid, TerrainGrid &block)
{
	auto blockY = block.begin();
	auto gridY = grid.begin();
	while (blockY != block.end())
	{
		if (*gridY == *blockY)
			grid.erase(gridY++);
		else
		{
			auto blockX = blockY->second.begin();
			auto gridX = gridY->second.begin();
			while (gridX->first != blockX->first)
				gridX++;
			while (blockX != blockY->second.end())
			{
				if (*gridX == *blockX)
					gridY->second.erase(gridX++);
				else
					gridX++;
				blockX++;
			}
			gridY++;
		}
		blockY++;
	}
}

void TerrainSequence::PrintData(TerrainGrid &data)
{
	for (auto &y : data)
	{
		cout << y.first << ": { ";
		for (auto &x : y.second)
		{
			cout << "{ " << x.first << ": " << x.second.first << "," << x.second.second << " } ";
		}
		cout << "}" << endl;
	}
}

vector<TerrainGrid> TerrainSequence::getData()
{
	return blockList;
}