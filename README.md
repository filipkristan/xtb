# The X ToolBox Library
A small library for x11-based Linux systems.

## TODO:
- Make functions take *Display* as a parameter
- Standardize header guard naming

## Install the library to your system

```
cmake -S . -B build
cmake --build build
sudo cmake --install build
```

## Test out the library
Test it out by building the project and running the *demo* provided.    
You can find the binary file inside cmake-build-debug.  
You can also modify src/main.c to test out the library.     

## NOTES:
- CLion users should press the hammer button instead of the play button to compile.
