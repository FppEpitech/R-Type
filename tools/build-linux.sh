#!/usr/bin/bash
##
## EPITECH PROJECT, 2024
## R-TYPE
## File description:
## Builds linux r-type project.
##

VCPKG_ROOT="${PWD}/vcpkg"

rm -f *.exe

rm -rf build/

mkdir build

# export LINTER=on

cmake . -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" -B build

cd build

make -j 10

cd ..
