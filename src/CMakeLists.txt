cmake_minimum_required(VERSION 3.10)

project(TradeProject)

add_subdirectory(lib)
add_subdirectory(bin)

if(${TESTS})
   add_subdirectory(test)
endif()

