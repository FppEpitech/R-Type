#!/bin/bash

##
## EPITECH PROJECT, 2024
## R-TYPE
## File description:
## Builds linux & windows r-type project.
##

VCPKG_ROOT="${PWD}/vcpkg"

if [ -d "build" ]; then
    rm -rf build/
fi
if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "mingw"* ]]; then
    del /q *.exe
else
    rm -f *.exe
fi

mkdir build

cmake . -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" -B build
