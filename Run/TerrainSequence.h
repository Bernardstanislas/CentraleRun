#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>
#include "config.h"
#include <vector>
#include "SpObstacle.h"
#include <memory>

using namespace std;

typedef map <int, map<int, pair<char, char>>> TerrainGrid;

class TerrainSequence
{
private:
	TerrainGrid terrainData;
	vector<TerrainGrid> blockList;
public:
	void ParseFile(string path);
	void PrintData(TerrainGrid &data);
	void FillData();
	void MakeBlocks(TerrainGrid &blocksData);
	
	void SubstractBlock(TerrainGrid &grid, TerrainGrid &block);
	vector<TerrainGrid> getData();
};