TOOLCHAIN_BIN_DIR := /usr/local/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-eabi/bin
CC := $(TOOLCHAIN_BIN_DIR)/arm-none-eabi-gcc

INCLUDE_FLAGS := -I../lib/external/nrfx/ \
				 -I../lib/external/nrfx/drivers/include \
				 -I../lib/external/nrfx/hal/ \
				 -I../lib/external/nrfx/templates \
				 -I../lib/external/nrfx/mdk \
				 -I../lib/external/CMSIS_5/CMSIS/Core/Include 
ARCHITECTURE_FLAGS := -falign-functions=16 -fno-strict-aliasing -mcpu=cortex-m4 \
					  -mfloat-abi=soft -msoft-float -mthumb
override CC_FLAGS += -O0 -g -Wall $(ARCHITECTURE_FLAGS) $(INCLUDE_FLAGS) \
					 -D NRF52805_XXAA -D NRFX_SYSTICK_ENABLED=1 -nostdlib
CC_COMPILE_NO_LINK_FLAG = -c
LD_FLAGS = -T nrf52805_xxaa.ld -nostdlib -Wl,-Map=memory.map

.PHONY : all clean

blinky_app.bin: blinky_app.elf32-little
	$(TOOLCHAIN_BIN_DIR)/arm-none-eabi-objcopy -I elf32-little -O binary $< $@

blinky_app.elf32-little: main.o gcc_startup_nrf52805.o system_nrf52805.o nrfx_systick.o
	$(CC) -o $@ $^ $(LD_FLAGS)

main.o: main.c nrfx_systick.o
	$(CC) $(CC_FLAGS) $(CC_COMPILE_NO_LINK_FLAG) $<

nrfx_systick.o: ../lib/external/nrfx/drivers/src/nrfx_systick.c
	$(CC) $(CC_FLAGS) $(CC_COMPILE_NO_LINK_FLAG) $<

system_nrf52805.o: ../lib/external/nrfx/mdk/system_nrf52805.c
	$(CC) $(CC_FLAGS) $(CC_COMPILE_NO_LINK_FLAG) $<

gcc_startup_nrf52805.o: ../lib/external/nrfx/mdk/gcc_startup_nrf52805.S
	$(CC) $(CC_FLAGS) $(CC_COMPILE_NO_LINK_FLAG) -D __START=main \
		-D __STARTUP_CLEAR_BSS $<

clean:
	@echo "cleaning"
	rm -rf *.o *.elf32-little *.bin *.map
