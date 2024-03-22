cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)

set(base ${CMAKE_CURRENT_SOURCE_DIR})
set(CMAKE_BUILD_DIRECTORY ${base}/build)

project(Collies C)
include_directories(include
		src
		)
include(CTest)
add_compile_options(-Wall)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)
add_link_options(-Wall)
add_executable(Collies src/calculate.c)
target_link_libraries(Collies m)

add_test(example_test Collies)
