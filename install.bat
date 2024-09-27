@REM ##
@REM ## EPITECH PROJECT, 2024
@REM ## R-TYPE
@REM ## File description:
@REM ## Install compilers, cmake, and set up the env vars.
@REM ##


@REM winget install cmake

@REM curl https://aka.ms/vs/16/release/vs_buildtools.exe -o .\vs_buildtools.exe && .\vs_buildtools.exe --quiet --wait --norestart --includeRecommended --add Microsoft.VisualStudio.Workload.VCTools
@REM cd "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64"
@REM setx /M PATH "%PATH%;$(pwd)"
@REM set PATH="%PATH%;${pwd}"
@REM cd "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build"
@REM .\vcvars32.bat amd64

curl https://github.com/microsoft/vcpkg/archive/refs/heads/master.zip -o vcpkg.zip

tar -xf vcpkg.zip

cd vcpkg-master

./bootstrap-vcpkg.bat

@REM setx /M PATH "%PATH%;$(pwd)"
@REM set PATH="%PATH%;${pwd}"

cd ..
.\vcpkg\vcpkg.exe install
