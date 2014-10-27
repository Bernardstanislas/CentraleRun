#!/bin/bash

echo "Preparing the build..."
g++ -std=c++11 Run/*.cpp -framework SFML-graphics -framework SFML -framework SFML-window -framework SFML-system -o out
