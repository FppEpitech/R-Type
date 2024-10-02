@REM ##
@REM ## EPITECH PROJECT, 2024
@REM ## R-TYPE
@REM ## File description:
@REM ## Installs compilers, cmake, and set up the env vars.
@REM ##

@REM MUST BE EXECUTED IN WINDOWS CMD.

winget install cmake

winget source update

curl -O -L https://aka.ms/vs/16/release/vs_buildtools.exe
SET "CURRENT_DIR=%CD%"


@REM winget install -e --id Microsoft.VisualStudio.2022.BuildTools --override "--passive --wait --add Microsoft.VisualStudio.Workload.VCTools;includeRecommended"
.\vs_buildtools.exe --quiet --wait --norestart --includeRecommended --add Microsoft.VisualStudio.Workload.VCTools
@REM cd "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64"
@REM # setx /M PATH "%PATH%;$(pwd)"
@REM # set PATH="%PATH%;${pwd}"
cd "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build"
call vcvars32.bat

echo "après pwd"
cd "%CURRENT_DIR%"


git clone https://github.com/microsoft/vcpkg.git

cd vcpkg

call bootstrap-vcpkg.bat

cd ..
.\vcpkg\vcpkg install
