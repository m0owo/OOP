cmake_minimum_required(VERSION 3.0.0)
project(2.1.1 VERSION 0.1.0)

include(CTest)
enable_testing()

add_executable(2.1.1 2.1/2.1.1.cpp)
add_executable(2.1.2 2.1/2.1.2.cpp)
add_executable(2.1.3 2.1/2.1.3.cpp)
add_executable(2.2.1 2.2/2.2.1.cpp 2.2/header.cpp)
add_executable(2.2.2.1 2.2/2.2.2.1.cpp 2.2/header.cpp)
add_executable(2.2.2.2 2.2/2.2.2.2.cpp 2.2/header.cpp)
add_executable(2.3.1 2.3/2.3.1.cpp 2.3/header.cpp 2.3/random.hpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
