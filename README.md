# About
A basic blinky project for the [MDBT42T-DB-05 devlopment board](
https://www.raytac.com/product/ins.php?index_id=114) which is based on the raytac 
mdbt42t-192k module (nrf52805). 

I understand that there are some bad practices used in this project:
- makefile is insuffecient
- using a blocking delay instead of interupt based timer

I'm accepting these flaws becuase this project is so simple and is only used as a 
demo/sanity check.

# Installation/Usage
To get started with this project:
1. install `make` 
2. install an [arm-none-eabi gcc toolchain](
   https://developer.arm.com/downloads/-/arm-gnu-toolchain-downloads).
    - Ensure that the makefile's `TOOLCHAIN_BIN_DIR` variable correctly points at your 
      installed toolchain's `bin/` directory.
3. ensure that this project git submodules are initialized:  
`git submodule sync --recursive`  
`git submodule update --init --recursive`  
4. run `make` from within `./src/`
5. flash the device with `./src/blinky_app.bin`
6. (OPTIONAL) debug the device with gdb which can read symbols from 
   `./src/blinky_app.elf32-little`
