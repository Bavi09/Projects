cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)
project(myapp C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(electricmotor
    electricmotor.c
)

# Include directories for Pico SDK
target_include_directories(electricmotor PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/pico-sdk/src/rp2_common/hardware_adc/include
    ${CMAKE_CURRENT_LIST_DIR}/pico-sdk/src/rp2_common/hardware_pwm/include
    ${CMAKE_CURRENT_LIST_DIR}/pico-sdk/src/rp2_common/hardware_gpio/include
)

# Link the Raspberry Pi Pico SDK libraries
target_link_libraries(electricmotor PRIVATE pico_stdlib  hardware_adc hardware_pwm )

# Enable extra outputs, such as hex files
pico_enable_stdio_uart(electricmotor 0)
pico_enable_stdio_usb(electricmotor 1)

# Create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(electricmotor)
