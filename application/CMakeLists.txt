cmake_minimum_required(VERSION 3.12)

project(PicoTracer C CXX ASM)
set(CMAKE_C_STNDARD 11)
set(CMAKE_CXX_STANDARD 17)
add_library(application STATIC control.c)
