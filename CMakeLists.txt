cmake_minimum_required(VERSION 3.14)
project(cplusplus_memory_manager)

set(CMAKE_CXX_STANDARD 11)

add_executable(cplusplus_memory_manager main.cpp perClassAllocator.cpp perClassAllocator.h common.h perClassAllocatorBetter.cpp perClassAllocatorBetter.h)