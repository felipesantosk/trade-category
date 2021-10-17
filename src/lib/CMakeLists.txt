include_guard(GLOBAL)

cmake_minimum_required(VERSION 3.10)

project(Trade)

add_library(${PROJECT_NAME} trade.cpp)

target_link_libraries(${PROJECT_NAME} PUBLIC CONAN_PKG::boost)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
