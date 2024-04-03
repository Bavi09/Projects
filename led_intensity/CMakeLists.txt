cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(myapp C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(led_intensity
		led_intensity.c
		)
target_include_directories(led_intensity PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/pico-sdk
    ${CMAKE_CURRENT_LIST_DIR}/pico-sdk/src/rp2_common/hardware_led_intensity/include)
 
pico_add_extra_outputs(led_intensity)
target_link_libraries(led_intensity  pico_stdlib hardware_adc hardware_pwm )
pico_enable_stdio_usb(led_intensity 1)
pico_enable_stdio_uart(led_intensity 0)