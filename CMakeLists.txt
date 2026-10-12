cmake_minimum_required(VERSION 3.10)

# Project name
project(BSTNodeSearch)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(code src/main.cpp)

# Optional: Set compiler options for better warnings
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O2")