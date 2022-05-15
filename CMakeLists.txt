# Change version of the cmake accorting of your   <REQUIRED>
cmake_minimum_required(VERSION 3.22.2 FATAL_ERROR)

# set the project name with version
# ${PROJECT_NAME}
project(rppp VERSION 1.0.0)

# #------------------------------------------------------------------------------------------------------------
# # RPATH Settings

# set(CMAKE_MACOSX_RPATH 1)

# # # use, i.e. don't skip the full RPATH for the build tree
# set(CMAKE_SKIP_BUILD_RPATH FALSE)

# # # when building, don't use the install RPATH already
# # # (but later on when installing)
# set(CMAKE_BUILD_WITH_INSTALL_RPATH FALSE)

# set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")

# # # add the automatically determined parts of the RPATH
# # # which point to directories outside the build tree to the install RPATH
# set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)
# set(INSTALL_RPATH_USE_LINK_PATH TRUE)

# # # the RPATH to be used when installing, but only if it's not a system directory
# list(FIND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES "${CMAKE_INSTALL_PREFIX}/lib" isSystemDir)
# if("${isSystemDir}" STREQUAL "-1")
#     set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
# endif("${isSystemDir}" STREQUAL "-1")
# #------------------------------------------------------------------------------------------------------------

# Specify C++ standards
# C++ standards declerations must be above the call to add_executable
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Specify C Standards
# C standards declerations must be above the call to add_executable
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED True)
set(CMAKE_C_EXTENSIONS ON)

# ObjectiveC Standards
if(APPLE)
    enable_language(OBJC)
endif()

# Configure the header file to pass the version number to the source code
configure_file(rpppConfig.h.in rpppConfig.h)

# add the executable
add_executable(${CMAKE_PROJECT_NAME} main.cpp)
# add_executable(temp temp.cpp) #example to add new executable : Step1

# add the binary tree to the search path for include files# so that we will find rppfConfig.h
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIR})

# setings for modules dir
set(MODULES_DIR ${CMAKE_SOURCE_DIR}/modules)
add_subdirectory(${MODULES_DIR})
# settings for external dir
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)
set(SOURCES_DIR ${EXTERNAL_DIR}/sources)

#------------------------------------------------------------------------------------------------------------
# download all git submodules of they do not downloaded
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()
#
#------------------------------------------------------------------------------------------------------------
# Check OpenCV Module
if(NOT EXISTS "${SOURCES_DIR}/SDL/CMakeLists.txt")
    message(FATAL_ERROR "The sdl2 submodules was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

find_package(SDL2 REQUIRED PATHS "${EXTERNAL_DIR}/sdl" NO_DEFAULT_PATH)
if(SDL2_FOUND)
    # message(STATUS "opencv found! as ${OpenCV}")
    # list(APPEND EXTRA_LIB_DIRS ${OpenCV_LIBS})
    list(APPEND EXTRA_INCLUDE_DIRS ${SDL2_INCLUDE_DIRS})
    list(APPEND EXTRA_LINKS ${SDL2_LIBRARIES})
    message(STATUS "OpenCV Libs : ${SDL2_LIBRARIES}")
    message(STATUS "Include Dirs : ${SDL2_INCLUDE_DIRS}")
    include_directories(${SDL2_INCLUDE_DIRS})

else()
    message(FATAL_ERROR "no sdl, sad day")
endif()


target_include_directories( 
    ${PROJECT_NAME} 
    # PUBLIC ${EXTRA_INCLUDE_DIRS}
    PUBLIC ${SDL2_INCLUDE_DIRS}
) 
# #
target_link_directories( 
    ${PROJECT_NAME} 
    PUBLIC ${EXTRA_LIB_DIR}
    # ${SOURCES_DIR}/opencv
)
#
# link the library to our project
target_link_libraries(
    ${PROJECT_NAME} 
    # PUBLIC ${EXTRA_LINKS}
    ${SDL2_LIBRARIES}
    # SD2
    # SDLMain
)
# ------------------------------------------------------------------------------------




# ------------------------------------------------------------------------------------

# ---------------------- Installing Begin ----------------------
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/rpppConfig.h" DESTINATION include)
# install(FILES "${EXTERNAL_DIR}/sdl/bin/sdl2-config" DESTINATION bin)
# install(DIRECTORY ${EXTERNAL_DIR}/sdl/lib/ DESTINATION lib)
# install(DIRECTORY ${EXTERNAL_DIR}/sdl/include/ DESTINATION include)
# ---------------------- Installing End ------------------------


# ---------------------- Packing Begin ----------------------
# Options for packing
set(PACK_PACKAGE_VENDOR "eheperson")
set(CPACK_SYSTEM_NAME "enivicivokki")
set(PACKAGE_DIR "${CMAKE_SOURCE_DIR}/out/package")
set(CPACK_PACKAGE_DIRECTORY "${PACKAGE_DIR}")
#
# to distribute our project to other people 
# This module will include any runtime libraries that are needed by the project 
# for the current platform
include(InstallRequiredSystemLibraries)
#
# set some CPack variables to where we have stored the license and 
# version information for this project.
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "My funky project")
set(CPACK_PACKAGE_VENDOR ${CPACK_PACKAGE_VENDOR})
#
set(CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_SOURCE_DIR}/README.md")
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
#
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_NAME_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_NAME_VERSION_MINOR}")
# #
set(CPACK_SOURCE_GENERATOR "TGZ")
# #
include(CPack)
# ---------------------- Packing End ------------------------

