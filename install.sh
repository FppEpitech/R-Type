sudo dnf update

sudo dnf install gcc gcc-c++
sudo dnf install cmake
sudo dnf install make




git clone https://github.com/microsoft/vcpkg.git

cd vcpkg

./bootstrap-vcpkg.sh

export PATH=$PATH:$(pwd)

cd ..

vcpkg install