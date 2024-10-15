cmake_minimum_required(VERSION 3.27)
project(my_string C)

set(CMAKE_C_STANDARD 99)

add_executable(my_string main.c
        my_string.h
        my_string.c)
