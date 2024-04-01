# RPP-P (Rec-Play-Pause Pico)
 Template repository for cross-platform cpp development based on CMake build system Resources

> **NOTE :** This repository is tested only on MacOS and debian based Linux Distributions. Will be updated for Windows in the future.

### Who is this repository for?
* If project based on CMakeLists build system.
* If project contains only few source files like `main.cpp`, `mylib.cpp` etc.
* If your project requires 3Rd dependencies like `SDL3`.
* If project requires develop extra libraries  like `TestLib.h`. add if them requires 3Rd dependencies.
* If you need a C++ development laboratuary to test simple libraries requires 3Rd dependencies.

### Requirements:
* Cmake
* Make (optional)
* Git
* Compiler xd


Generate the build files using CMake for Release configuration:
```bash
# Windows
cmake -G "MinGW Makefiles" -DUSE_TESTLIB=ON -DCMAKE_INSTALL_PREFIX=out/app -S . -B out//build

# Unix/Linux
cmake -DUSE_TESTLIB=ON -DCMAKE_INSTALL_PREFIX=out/app -S . -B out//build

```

Build the project (Release configuration will be used by default)
```bash
cmake  --build .//out//build -j 12 -v
```

Install the project (Release configuration will be used by default)
```bash
cmake --install .//out//build  --verbose
```


Package the project
```bash
cpack .\out\build  -c Debug --verbose
```

--- 

### TODOs
- inlcude compiler options to the cmake