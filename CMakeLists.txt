cmake_minimum_required(VERSION 3.5)


INCLUDE(CMakeForceCompiler)
CMAKE_FORCE_C_COMPILER(/usr/bin/gcc-7 GNU)
CMAKE_FORCE_CXX_COMPILER(/usr/bin/g++-7 GNU)



project(LinuxAPI)

set(CMAKE_CXX_STANDARD 14)

add_executable(LinuxAPI main.cpp file.h process.h)



find_package(Threads)
target_link_libraries(LinuxAPI ${CMAKE_THREAD_LIBS_INIT})