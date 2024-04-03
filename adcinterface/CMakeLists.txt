cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(myapp C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()
add_executable(adcinterface
		adcinterface.c
		)
target_include_directories(adcinterface PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/pico-sdk
    ${CMAKE_CURRENT_LIST_DIR}/pico-sdk/src/rp2_common/hardware_adcinterface/include)
 
pico_add_extra_outputs(adcinterface)
target_link_libraries(adcinterface  pico_stdlib hardware_adc hardware_pwm )
pico_enable_stdio_usb(adcinterface 1)
pico_enable_stdio_uart(adcinterface 0)