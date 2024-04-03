cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(servomotor C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)
pico_sdk_init()

# Add your source file to the project (replace "servomotor.c" with your source file name)
add_executable(servomotor
		servomotor.c
)

# Include directories for the Pico SDK
target_include_directories(servomotor PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/pico-sdk
    ${CMAKE_CURRENT_LIST_DIR}/pico-sdk/src/rp2_common/hardware_pwm/include
)

# Add extra outputs, such as hex files
pico_add_extra_outputs(servomotor)

# Link the required libraries
target_link_libraries(servomotor 
    pico_stdlib 
    hardware_adc 
    hardware_pwm 
)

# Enable USB serial output
pico_enable_stdio_usb(servomotor 1)

# Disable UART output
pico_enable_stdio_uart(servomotor 0)
