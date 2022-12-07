cmake_minimum_required(VERSION 3.21)
project (KURSOVAYA)

set(CMAKE_CXX_STANDARD 17)

add_executable(KURSOVAYA main.cpp authorization.h authorization.cpp MD5.h MD5.cpp cmake-build-debug/konteyner.cpp cmake-build-debug/konteyner.h)
