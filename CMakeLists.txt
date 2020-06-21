cmake_minimum_required(VERSION 3.16)
project(Ascii85 C)

set(CMAKE_C_STANDARD 99)

add_executable(encode encasc85.c)
add_executable(decode decasc85.c)