# JustCoderdev Makefile for Arduino projects v1

PNAME = blink

SRC_FILES = main.c
OBJ_FILES  = $(patsubst %.c,%.o,${SRC_FILES})
SILICON_FILES = lib/silicon/si_io.c lib/silicon/si_clock.c

CCFLAGS = -xc -std=c89 -ansi -pedantic-errors -pedantic \
          -Wall -Wextra -Werror -Wshadow -Wpointer-arith \
          -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes \
          -Wno-conversion -g

MEGAFLAGS = -nostdlib -mmcu=atmega328p --param=min-pagesize=0

IFLAGS = -I./ -I./lib/include
LDFLAGS = -L./

DFLAGS = -DF_CPU=16000000UL
FLAGS = $(CCFLAGS) $(MEGAFLAGS) $(IFLAGS) $(LDFLAGS) $(DFLAGS)

local: clean build
build:
	@mkdir -p build

	@echo "Compiling... "
	avr-gcc $(FLAGS) $(SRC_FILES) $(SILICON_FILES) -o "build/$(PNAME).o"

	@echo "Hexxing..."
	avr-objcopy -O ihex -j.text -j.data "build/$(PNAME).o" "build/$(PNAME).hex"

flash: clean build
	@echo "Flashing... "
	avrdude -v -p ATmega328P -c arduino \
		-P /dev/ttyACM0 -b 115200 \
		# -U "flash:w:build/$(PNAME).hex:i"

# /nix/store/lip8zy6vvk1mcfldc6q4ghvrrciy9gvs-arduino-1.8.19/share/arduino/hardware/tools/avr/bin/avrdude \
# 	-C/nix/store/lip8zy6vvk1mcfldc6q4ghvrrciy9gvs-arduino-1.8.19/share/arduino/hardware/tools/avr/etc/avrdude.conf \
# 	-v -patmega328p -carduino -P/dev/ttyACM0 -b115200 -D -U "flash:w:build/$(PNAME).hex:i"

.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf ./bin ./build
