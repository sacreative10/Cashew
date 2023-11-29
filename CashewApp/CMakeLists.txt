
cmake_minimum_required(VERSION 3.26)
project(CashewApp)

set(CMAKE_CXX_STANDARD 17)


add_subdirectory(../CashewLib cmake-build-debug)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(CashewApp main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC ../CashewLib/src/)
target_link_libraries(${PROJECT_NAME} Cashew)
