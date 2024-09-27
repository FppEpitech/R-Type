@REM ##
@REM ## EPITECH PROJECT, 2024
@REM ## R-TYPE
@REM ## File description:
@REM ## Builds windows r-type project.
@REM ##

VCPKG_ROOT="${PWD}/vcpkg"

del /q *.exe
rmdir /s /q build

mkdir build

cmake . -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake" -B build
