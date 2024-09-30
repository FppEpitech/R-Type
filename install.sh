##
## EPITECH PROJECT, 2024
## R-TYPE
## File description:
## Install compilers, cmake, and set up the env vars.
##

sudo dnf update

sudo dnf install gcc gcc-c++
sudo dnf install cmake
sudo dnf install make

curl -L https://github.com/microsoft/vcpkg/archive/refs/heads/master.zip -o vcpkg.zip
unzip vcpkg.zip
rm vcpkg.zip
cd vcpkg-master

./bootstrap-vcpkg.sh

# if ! grep -q 'export PATH=.*vcpkg' ~/.bashrc; then
#     echo 'export PATH="$PATH:'$(pwd)'"' >> ~/.bashrc
# fi

# source ~/.bashrc

cd ..

./vcpkg-master/vcpkg install
