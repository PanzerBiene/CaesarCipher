cmake_minimum_required(VERSION 3.21)
project(CeasarCipher)

set(CMAKE_CXX_STANDARD 23)

add_executable(CeasarCipher main.cpp Cipher.cpp Cipher.h main.h)
