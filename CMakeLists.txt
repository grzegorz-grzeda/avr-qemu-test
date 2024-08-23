cmake_minimum_required(VERSION 3.25)

include(cmake/avr-toolchain-file.cmake)

project(avr-qemu-test)
add_executable(${PROJECT_NAME})

add_subdirectory(src)