cmake_minimum_required(VERSION 3.12)

include(pico_sdk_import.cmake)

project(PicoTracer C CXX ASM)
set(CMAKE_C_STNDARD 11)
set(CMAKE_CXX_STANDARD 17)
add_subdirectory(application)
add_subdirectory(driver)
pico_sdk_init()

add_executable(PicoTracer
  PicoTracer.c
)

pico_enable_stdio_usb(PicoTracer 1)
pico_enable_stdio_uart(PicoTracer 1)

pico_add_extra_outputs(PicoTracer)

target_link_libraries(PicoTracer pico_stdlib)
target_link_libraries(PicoTracer application)
target_link_libraries(PicoTracer driver)