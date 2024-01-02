# Welcome to graphs

[![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)



# Prerequisites

Building graphs requires the following software installed:

* A C++17-compliant compiler
* CMake `>= 3.9`
* The testing framework [Catch2](https://github.com/catchorg/Catch2) for building the test suite

# Building graphs

The following sequence of commands builds graphs.
It assumes that your current working directory is the top-level directory
of the freshly cloned repository:

```
mkdir build
cd build
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build .
```

The build process can be customized with the following CMake variables,
which can be set by adding `-D<var>={ON, OFF}` to the `cmake` call:

* `BUILD_TESTING`: Enable building of the test suite (default: `ON`)



# Testing graphs

When built according to the above explanation (with `-DBUILD_TESTING=ON`),
the C++ test suite of `graphs` can be run using
`ctest` from the build directory:

```
cd build
ctest
```


# Documentation

graphs *should* provide a documentation.
