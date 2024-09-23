@echo off
 
:: Install CMake
echo Installing CMake...
winget install Kitware.CMake
 
:: Clone vcpkg repository
echo Cloning vcpkg repository...
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
 
:: Bootstrap vcpkg
echo Bootstrapping vcpkg...
bootstrap-vcpkg.bat
 
:: Add vcpkg to the PATH persistently
echo Adding vcpkg to PATH...
setx PATH "%PATH%;%cd%"
 
cd ..
 
:: Install required packages using vcpkg
echo Installing vcpkg packages...
vcpkg install
 
:: Download Visual Studio Build Tools
echo Downloading Visual Studio Build Tools...
Invoke-WebRequest -Uri https://aka.ms/vs/16/release/vs_buildtools.exe -OutFile .\vs_buildtools.exe

:: Install Visual Studio Build Tools with MSVC
echo Installing Visual Studio Build Tools with MSVC...
.\vs_buildtools.exe --quiet --wait --norestart --includeRecommended --add Microsoft.VisualStudio.Workload.VCTools
 
:: Ensure the Build Tools are configured correctly
echo Configuring MSVC environment...
IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" (
    cd "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\"
    vcvarsall.bat amd64
) ELSE IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Auxiliary\Build\vcvarsall.bat" (
    cd "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Auxiliary\Build\"
    vcvarsall.bat amd64
) ELSE (
    echo "Visual Studio Build Tools not found!"
    exit /b 1
)
 
:: Verify MSVC installation and adjust the environment PATH
echo Updating PATH for MSVC...
IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\*" (
    setx PATH "%PATH%;C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\bin\Hostx64\x64"
) ELSE IF EXIST "C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Tools\MSVC\*" (
    setx PATH "%PATH%;C:\Program Files (x86)\Microsoft Visual Studio\2017\BuildTools\VC\Tools\MSVC\bin\Hostx64\x64"
) ELSE (
    echo "MSVC tools not found!"
    exit /b 1
)
 
echo Installation completed successfully. vcpkg has been added to your PATH.
pause