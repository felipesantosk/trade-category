include_guard(GLOBAL)

cmake_minimum_required(VERSION 3.10)

project(TradeCategoryTest)

add_executable(${PROJECT_NAME} main.cpp)

target_link_libraries(${PROJECT_NAME} CONAN_PKG::catch2 Trade)
