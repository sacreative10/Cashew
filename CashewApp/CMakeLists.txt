
cmake_minimum_required(VERSION 3.26)
project(ExampleCashewApp)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(../ cmake-build-debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ../CashewLib/src/)
target_link_libraries(${PROJECT_NAME} Cashew)
