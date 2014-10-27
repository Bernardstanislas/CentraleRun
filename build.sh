#!/bin/bash

echo "Building the solution..."
cd Run/
g++ --version
g++ -std=c++0x *.cpp -lsfml-graphics -lsfml-window -lsfml-system -o out
echo "Building done !"
