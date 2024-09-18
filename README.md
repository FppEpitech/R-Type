# R-Type
Multi-threaded server and a graphical client for a well-known legacy video game called R-Type, using a game engine of our own design.

## How to build ? (Linux)
First, download the repository from Github, then compile it with:
```
git clone git@github.com:FppEpitech/R-Type.git
cmake -B build
cmake --build build/
```
Then to run the server:
```
./r-type_server
```
And the client:
```
./r-type_client
```
