cmake_minimum_required(VERSION 3.13)

# use PICO_SDK_PATH to import Pico SDK
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

project(rgbi C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(rgbi
    ./src/main.cpp
    ./src/render.cpp
)

# as in PicoVGA... not sure why we need this
add_compile_definitions(
)

# TODO: Maybe regenerate PIO header?

pico_set_program_name(rgbi "RGBI-to-VGA")

target_link_libraries(rgbi
    pico_stdlib
    # START picovga
    hardware_adc
    hardware_dma
    hardware_flash
    hardware_i2c
    hardware_interp
    hardware_pio
    hardware_pwm
    hardware_rtc
    hardware_spi
    pico_multicore
    boot_picoboot_headers # WTF?
    boot_uf2_headers
    pico_stdio_usb # for tinyusb?
    pico_malloc
    pico_mem_ops # pico/mem_ops.h
    pico_stdio_semihosting
    # END picovga's requirements (phew!)
)

# Produce bin, map, etc files
pico_add_extra_outputs(rgbi)
