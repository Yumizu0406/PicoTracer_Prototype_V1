cmake_minimum_required(VERSION 3.12)
include(../pico_sdk_import.cmake)

project(PicoTracer C CXX ASM)
set(CMAKE_C_STNDARD 11)
set(CMAKE_CXX_STANDARD 17)
add_library(driver STATIC timer.c)

pico_sdk_init()

target_link_libraries(driver pico_stdlib)
