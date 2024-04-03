cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(myapp C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(helloworld
		helloworld.c
		)
pico_add_extra_outputs(helloworld)
target_link_libraries(helloworld pico_stdlib)
pico_enable_stdio_usb(helloworld 1)
pico_enable_stdio_uart(helloworld 0)