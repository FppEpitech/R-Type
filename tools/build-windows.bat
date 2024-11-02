@REM ##
@REM ## EPITECH PROJECT, 2024
@REM ## R-TYPE
@REM ## File description:
@REM ## Builds windows r-type project.
@REM ##

@REM MUST BE EXECUTED IN WINDOWS CMD.

del /q *.exe
rmdir /s /q build

mkdir build

cmake . -DCMAKE_TOOLCHAIN_FILE="%CD%\vcpkg\scripts\buildsystems\vcpkg.cmake" -DCMAKE_BUILD_TYPE=Release -B build

cd build

cmake --build . --parallel 10

cd ..
