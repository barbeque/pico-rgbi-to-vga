cmake_minimum_required(VERSION 3.13)

# use PICO_SDK_PATH to import Pico SDK
include($ENV{PICO_SDK_PATH}/pico_sdk_init.cmake)

# locate PicoVGA
if(NOT DEFINED PICOVGA_PATH)
	set(PICOVGA_PATH "../../PicoVGA")
endif()
set(PICOVGA_SRC "${PICOVGA_PATH}/_picovga")

project(rgbi C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(rgbi
    ./src/main.cpp
    # ...PicoVGA files
    ${PICOVGA_SRC}/vga_blitkey.S
    ${PICOVGA_SRC}/vga_render.S
    ${PICOVGA_SRC}/render/vga_attrib8.S
    ${PICOVGA_SRC}/render/vga_color.S
    ${PICOVGA_SRC}/render/vga_atext.S
    ${PICOVGA_SRC}/render/vga_ctext.S
    ${PICOVGA_SRC}/render/vga_dtext.S
    ${PICOVGA_SRC}/render/vga_ftext.S
    ${PICOVGA_SRC}/render/vga_gtext.S
    ${PICOVGA_SRC}/render/vga_mtext.S
    ${PICOVGA_SRC}/render/vga_fastsprite.S
    ${PICOVGA_SRC}/render/vga_graph1.S
    ${PICOVGA_SRC}/render/vga_graph2.S
    ${PICOVGA_SRC}/render/vga_graph4.S
    ${PICOVGA_SRC}/render/vga_graph8.S
    ${PICOVGA_SRC}/render/vga_graph8mat.S
    ${PICOVGA_SRC}/render/vga_graph8persp.S
    ${PICOVGA_SRC}/render/vga_levelgrad.S
    ${PICOVGA_SRC}/render/vga_persp.S
    ${PICOVGA_SRC}/render/vga_persp2.S
    ${PICOVGA_SRC}/render/vga_plane2.S
    ${PICOVGA_SRC}/render/vga_level.S
    ${PICOVGA_SRC}/render/vga_progress.S
    ${PICOVGA_SRC}/render/vga_oscline.S
    ${PICOVGA_SRC}/render/vga_oscil.S
    ${PICOVGA_SRC}/render/vga_sprite.S
    ${PICOVGA_SRC}/render/vga_tile.S
    ${PICOVGA_SRC}/render/vga_tile2.S
    ${PICOVGA_SRC}/render/vga_tilepersp.S
    ${PICOVGA_SRC}/render/vga_tilepersp15.S
    ${PICOVGA_SRC}/render/vga_tilepersp2.S
    ${PICOVGA_SRC}/render/vga_tilepersp3.S
    ${PICOVGA_SRC}/render/vga_tilepersp4.S
    ${PICOVGA_SRC}/util/overclock.cpp
    ${PICOVGA_SRC}/util/print.cpp
    ${PICOVGA_SRC}/util/rand.cpp
    ${PICOVGA_SRC}/font/font_boldB_8x16.cpp
    ${PICOVGA_SRC}/vga.cpp
    ${PICOVGA_SRC}/vga_layer.cpp
    ${PICOVGA_SRC}/vga_pal.cpp
    ${PICOVGA_SRC}/vga_screen.cpp
    ${PICOVGA_SRC}/vga_vmode.cpp
)

target_include_directories(rgbi
    PUBLIC ${PICOVGA_PATH}
    PUBLIC src # so picovga can find vga_config.h, a gross hack
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
