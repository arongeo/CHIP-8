# CHIP-8

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/4ff47a7db2b546369c96b4ccb433d58a)](https://app.codacy.com/gh/mrmalac/CHIP-8?utm_source=github.com&utm_medium=referral&utm_content=mrmalac/CHIP-8&utm_campaign=Badge_Grade_Settings)

CHIP-8 is an interpreted programming language created in the 1970s.
It was widely used to create video games.

## Build

To build the program you can use CMake or GNU Make.

### CMake
To build with CMake you will need to use these two commands, when you are in the project folder.

```
cmake .
```

```
cmake --build .
```

After this you will find the binary executable in the /bin directory.

### GNU Make
IMPORTANT If you already used CMake you can't use GNU Make to build this project unless you reinstall it.
To build the project simply run:

```
make
```

To clean up the build and bin folders run:

```
make clean
```
