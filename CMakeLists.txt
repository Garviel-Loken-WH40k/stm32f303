message(STATUS "Toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "Try compile target type: ${CMAKE_TRY_COMPILE_TARGET_TYPE}")

cmake_minimum_required(VERSION 3.13)
project(stm32f303_gpio_blink C)

set(CMAKE_C_STANDARD 11)

set(SOURCE_FILES
    src/main.c
    src/gpio.c
    src/syscalls.c
)

include_directories(include)

add_executable(stm32f303_gpio_blink ${SOURCE_FILES})

if(CMAKE_C_COMPILER MATCHES "arm-none-eabi-gcc")
    target_link_options(stm32f303_gpio_blink PRIVATE
        -T${CMAKE_SOURCE_DIR}/linker.ld
        -nostartfiles
        -Wl,--gc-sections
    )
endif()

message(STATUS "Toolchain file: ${CMAKE_TOOLCHAIN_FILE}")
message(STATUS "Try compile target type: ${CMAKE_TRY_COMPILE_TARGET_TYPE}")
