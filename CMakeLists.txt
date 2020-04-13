cmake_minimum_required(VERSION 3.15)
project(selection)

set(CMAKE_CXX_STANDARD 17)

add_library(helper Helper.h Helper.cpp)
add_library(trie Trie.h Trie.cpp)
target_link_libraries(helper trie)
add_executable(main main.cpp)
target_link_libraries(main helper)