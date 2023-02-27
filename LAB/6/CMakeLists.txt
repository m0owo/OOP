cmake_minimum_required(VERSION 3.0.0)
project(1.1.cpp VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(1 1.cpp)
add_executable(2 2.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
