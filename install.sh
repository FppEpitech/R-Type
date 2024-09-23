sudo dnf update

sudo dnf install gcc gcc-c++
sudo dnf install cmake
sudo dnf install make




git clone https://github.com/microsoft/vcpkg.git

cd vcpkg

./bootstrap-vcpkg.sh

if ! grep -q 'export PATH=.*vcpkg' ~/.bashrc; then
    echo 'export PATH="$PATH:'$(pwd)'"' >> ~/.bashrc
fi

source ~/.bashrc

cd ..

vcpkg install