#!/bin/bash

rm -rf build
mkdir -p build
cd build
cmake .. -GNinja
cmake --build .

qemu-system-avr -M uno -bios avr-qemu-test -nographic -monitor null -serial stdio -d in_asm -D qemu.log