#!/bin/bash

echo "Preparing the installation..."
echo "Installing the compiler..."
sudo add-apt-repository --yes ppa:ubuntu-toolchain-r/test
sudo apt-get update -qq
sudo apt-get install -qq gcc-4.8
sudo apt-get install -qq g++-4.8
sudo update-alternatives --install /usr/bin/gcc gcc /usr/bin/gcc-4.8 20
sudo update-alternatives --install /usr/bin/g++ g++ /usr/bin/g++-4.8 20
sudo update-alternatives --config gcc
sudo update-alternatives --config g++
echo "Installing SFML dependencies..."
sudo apt-get install -qq cmake
sudo apt-get install -qq freeglut3-dev
sudo apt-get install -qq libjpeg-dev
sudo apt-get install -qq libfreetype6-dev
sudo apt-get install -qq libxrandr-dev
sudo apt-get install -qq libglew-dev
sudo apt-get install -qq libsndfile1-dev
sudo apt-get install -qq libopenal-dev
echo "Installing SFML..."
wget http://www.sfml-dev.org/download/sfml/2.1/SFML-2.1-sources.zip
unzip SFML-2.1-sources.zip -d SFML
cd SFML/SFML-2.1
cmake -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D BUILD_SHARED_LIBS=TRUE .
make
sudo make install
cmake -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Release -D BUILD_SHARED_LIBS=TRUE .
make
sudo make install
cmake -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Debug -D BUILD_SHARED_LIBS=FALSE .
make
sudo make install
cmake -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Release -D BUILD_SHARED_LIBS=FALSE .
make
sudo make install
cd ../../
echo "Installation done !"
