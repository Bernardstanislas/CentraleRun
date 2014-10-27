#!/bin/bash

echo "Preparing the build..."
# echo "Downloading SFML..."
# wget http://sfml-dev.org/download/sfml/2.1/SFML-2.1-linux-gcc-32bits.tar.bz2
# echo "Uncompressing SFML..."
# tar -xvzf SFML-2.1-linux-gcc-32bits.tar.bz2

echo "Installing SFML..."
sudo apt-get install libsfml-dev
echo "Building the solution..."
g++ -std=c++11 Run/*.cpp -framework SFML-graphics -framework SFML -framework SFML-window -framework SFML-system -o out
