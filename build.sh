#!/bin/bash

echo "Preparing the build..."
echo "Installing SFML..."
sudo apt-get install libsfml-dev
echo "Building the solution..."
cd Run/
g++ -std=c++0x *.cpp -lsfml-graphics -lsfml-window -lsfml-system -o out
