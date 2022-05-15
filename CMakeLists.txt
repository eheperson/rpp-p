# Change version of the cmake accorting of your   <REQUIRED>
cmake_minimum_required(VERSION 3.22.2 FATAL_ERROR)

# set the project name with version
# ${PROJECT_NAME}
project(rppp VERSION 1.0.0)

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

# settings for external dir
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)
add_subdirectory(${EXTERNAL_DIR})
set(EXTERNAL_SOURCES_DIR ${EXTERNAL_DIR}/sources)

# setings for modules dir
set(MODULES_DIR ${CMAKE_SOURCE_DIR}/modules)
add_subdirectory(${MODULES_DIR})

# add the binary tree to the search path for include files# so that we will find rpppConfig.h
target_include_directories(
  ${CMAKE_PROJECT_NAME} 
  PUBLIC "${MODULES_DIR}"
  PUBLIC "${PROJECT_BINARY_DIR}"
  PUBLIC ${EXTRA_INCLUDE_DIRS}
)

target_link_directories( 
    ${PROJECT_NAME} 
    PUBLIC ${EXTRA_LIB_DIR}
)

target_link_libraries(
  ${CMAKE_PROJECT_NAME} 
  PUBLIC ${EXTRA_LINKS}
  SDL_GENERAL
)

set(CMAKE_INSTALL_RPATH SDL_GENERAL)

target_include_directories(${PROJECT_NAME} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

# ---------------------- Installing Begin ----------------------
# add the install targets
install(TARGETS ${CMAKE_PROJECT_NAME} DESTINATION bin)
# install(TARGETS temp DESTINATION bin) #example to add new executable : Step4 (installation)
install(
  FILES "${PROJECT_BINARY_DIR}/rpppConfig.h"
  DESTINATION include
)
# ---------------------- Installing End ------------------------