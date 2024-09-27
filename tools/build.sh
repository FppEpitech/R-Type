#!/bin/bash

##
## EPITECH PROJECT, 2024
## R-TYPE
## File description:
## Builds linux & windows r-type project.
##

VCPKG_ROOT="${PWD}/vcpkg"


if [[ "$OSTYPE" == "msys" || "$OSTYPE" == "mingw"* ]]; then
    del /q *.exe
    rmdir /s /q build
else
    rm -f *.exe
    rm -rf build/
fi

mkdir build

cmake . -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" -B build
