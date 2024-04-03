cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(myapp C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(blinkled
		blinkled.c
		)
pico_add_extra_outputs(blinkled)
target_link_libraries(blinkled pico_stdlib)
pico_enable_stdio_usb(blinkled 1)
pico_enable_stdio_uart(blinkled 0)