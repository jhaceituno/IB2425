cmake_minimum_required(VERSION 3.1)
project(books VERSION 1.0 DESCRIPTION "Books exercise" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/build)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0 -Wall -Wextra -Wpedantic -Weffc++")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
include_directories(${PROJECT_SOURCE_DIR}/src)
add_executable(books src/book.h src/book.cc src/books.cc)
target_compile_features(books PRIVATE cxx_std_17)
target_compile_options(books PRIVATE -Wall -Wextra -Wpedantic -Weffc++)
