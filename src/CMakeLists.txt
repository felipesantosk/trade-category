cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -D_GLIBCXX_DEBUG)

project(TradeProject)

include(Conan.cmake)

add_subdirectory(lib)
add_subdirectory(bin)

if(${TESTS})
   add_subdirectory(test)
endif()

