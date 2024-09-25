winget install cmake

curl https://aka.ms/vs/16/release/vs_buildtools.exe -o .\vs_buildtools.exe && .\vs_buildtools.exe --quiet --wait --norestart --includeRecommended --add Microsoft.VisualStudio.Workload.VCTools
cd "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Tools\MSVC\14.29.30133\bin\Hostx64\x64"
setx /M PATH "%PATH%;$(pwd)"
set PATH="%PATH%;${pwd}"
cd "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build"
.\vcvars32.bat amd64
 
curl https://github.com/microsoft/vcpkg/archive/refs/heads/master.zip -o vcpkg.zip
tar -xf vcpkg.zip
cd vcpkg-master
./bootstrap-vcpkg.bat
setx /M PATH "%PATH%;$(pwd)"
set PATH="%PATH%;${pwd}"

cd ..
vcpkg install
