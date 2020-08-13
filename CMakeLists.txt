cmake_minimum_required(VERSION 2.8)
project(template)

set (CMAKE_BUILD_TYPE         Debug)
set (CMAKE_CXX_FLAGS          "-std=c++17 -Wall")
set (CMAKE_CXX_FLAGS_DEBUG    "-std=c++17 -g -O0")
set (EXECUTABLE_OUTPUT_PATH   ${PROJECT_SOURCE_DIR}/bin)
set (LIBRARY_OUTPUT_PATH      ${PROJECT_SOURCE_DIR}/lib)

include_directories(./inc/)

add_subdirectory(src)
add_subdirectory(app)
add_subdirectory(test)