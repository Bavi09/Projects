cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(myapp C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(keypad
		keypad.c
		)
pico_add_extra_outputs(keypad)
target_link_libraries(keypad pico_stdlib)
pico_enable_stdio_usb(keypad 1)
pico_enable_stdio_uart(keypad 0)
