#!/bin/bash

# installing SDL
cd $HOME
git clone https://github.com/libsdl-org/SDL
cd SDL
mkdir build
cd build
../configure
make
echo "Install SDL2 into libraries path"
sudo make install

# installing ttf
cd $HOME
git clone https://github.com/libsdl-org/SDL_ttf.git
cd SDL_ttf
mkdir build
cd build
../configure
make
echo "Install SDL_ttf (for fonts) into libraries path"
sudo make install

# installing SDL_Image
cd $HOME
wget https://www.libsdl.org/projects/SDL_image/release/SDL2_image-2.0.5.zip
unzip SDL2_image-2.0.5.zip
rm SDL2_image-2.0.5.zip
cd SDL2_image-2.0.5
mkdir build
cd build
../configure
make
echo "Install SDL_image into libraries path"
sudo make install