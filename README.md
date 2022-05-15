# rpp-p (rec-play-pause-nano)
 template repository for cross-platform cpp development based on CMake build system Resources

**NOTE :** 3Rd dependencies linking statically.

**NOTE :** This repository is tested only on MacOS and debian based Linux Distributions. Will be updated for Windows in the future.

### Who is this repository for?
* If project based on CMakeLists build system.
* If project requires developing some extra libs with 3rd dependencies.

### Requirements:
* cmake
* git

---

## Project Structure
### Zero Files/Dirs :
* **`main.cpp` file :** Your C++ file.
* **`rpppConfig.h.in` file :** Configuration file of the project.
* **`module` directory :**  Contains your extra modules

### Created Files/Dirs :
* **`app` directory :** Installation directory of the CMake
* **`build` directory :** Build output of the CMake 

## Preparing Development Environment
    ```
    # clone the repo
    git clone git@github.com:eheperson/rpp-p.git

    # change access rights of compile.sh file
    chmod +x compile.sh

    # run the compile.sh to start CMake build process
    ./compile.sh
    ```

---

## Adding more .cpp files, modules, 3Rd dependencies :
> This section will be updated later