@REM ##
@REM ## EPITECH PROJECT, 2024
@REM ## R-TYPE
@REM ## File description:
@REM ## Installs compilers, cmake, and set up the env vars.
@REM ##


winget install cmake

curl https://aka.ms/vs/16/release/vs_buildtools.exe -o .\vs_buildtools.exe && .\vs_buildtools.exe --quiet --wait --norestart --includeRecommended --add Microsoft.VisualStudio.Workload.VCTools
cd "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64"
@REM setx /M PATH "%PATH%;$(pwd)"
@REM set PATH="%PATH%;${pwd}"
cd "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build"
.\vcvars32.bat amd64

git clone https://github.com/microsoft/vcpkg.git

cd vcpkg

./bootstrap-vcpkg.bat

cd ..
.\vcpkg\vcpkg.exe install
