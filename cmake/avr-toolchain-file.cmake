set(CMAKE_SYSTEM_NAME AVR)
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_CXX_COMPILER avr-g++)

# Set the flags for the compiler
set(CMAKE_C_FLAGS "-mmcu=atmega328p -Os -Wall -Wextra")
set(CMAKE_CXX_FLAGS "-mmcu=atmega328p -Os -Wall -Wextra")

# Specify the linker and its flags
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=atmega328p")