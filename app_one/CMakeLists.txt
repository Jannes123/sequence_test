cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)

set(base ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_BUILD_DIRECTORY ${base}/build)

project(Collies C)
include_directories(include
		src
		)
add_executable(Collies src/calculate.c)
target_link_libraries(Collies m)