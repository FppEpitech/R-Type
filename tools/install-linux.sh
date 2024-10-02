#!/bin/bash

##
## EPITECH PROJECT, 2024
## R-TYPE
## File description:
## Installs compilers, cmake, and set up the env vars.
##

. /etc/os-release

case $ID in
  ubuntu)
    sudo apt install gcc g++
    sudo apt install cmake
    sudo apt install make
    ;;

  *)
    sudo dnf install gcc gcc-c++
    sudo dnf install cmake
    sudo dnf install make
      ;;
esac

git clone https://github.com/microsoft/vcpkg.git

cd vcpkg

./bootstrap-vcpkg.sh

cd ..

./vcpkg/vcpkg install
