cmake_minimum_required(VERSION 2.8)
project(template)

set (CMAKE_BUILD_TYPE         Debug)

# -------- To build 64 bit --------
set (CMAKE_CXX_FLAGS          "-std=c++17 -Wall")
set (CMAKE_CXX_FLAGS_DEBUG    "-std=c++17 -g -O0")
# ---------------------------------

# -------- Or to build 32 bit, only tested on linux --------
# set (CMAKE_C_FLAGS            "-m32")
# set (CMAKE_CXX_FLAGS          "-std=c++11 -Wall -m32")
# set (CMAKE_CXX_FLAGS_DEBUG    "-std=c++11 -g -O0 -m32")
# ----------------------------------------------------------

set (EXECUTABLE_OUTPUT_PATH   ${PROJECT_SOURCE_DIR}/bin)
set (LIBRARY_OUTPUT_PATH      ${PROJECT_SOURCE_DIR}/lib)

include_directories(./inc/)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(test)