# JustCoderdev Makefile for Arduino projects v1

PNAME = blink

SRC_FILES = main.c
OBJ_FILES  = $(patsubst %.c,%.o,${SRC_FILES})
SILICON_FILES = lib/silicon/si_io.c \
                lib/silicon/si_clock.c

CCFLAGS = -xc -std=c89 -ansi -pedantic-errors -pedantic \
          -Wall -Wextra -Werror -Wshadow -Wpointer-arith \
          -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes \
          -Wno-conversion -g -nostdlib --param=min-pagesize=0

IFLAGS = -I./ -I./lib/include
LDFLAGS = -L./

DFLAGS = -DF_CPU=16000000UL
FLAGS = $(CCFLAGS) $(IFLAGS) $(LDFLAGS) $(DFLAGS)

local: clean build
build:
	@mkdir -p build

	@echo "Compiling... "
	avr-gcc $(FLAGS) -mmcu=atmega328p \
		$(SRC_FILES) $(SILICON_FILES) -o "build/$(PNAME).o"

	@echo "Hexxing..."
	avr-objcopy -O ihex -j.text -j.data "build/$(PNAME).o" "build/$(PNAME).hex"

flash: clean build
	@echo "Flashing... "
	# sudo avrdude -v -p ATmega328P -c arduino \
	# 	-P /dev/ttyACM0 -b 115200 \
	# 	-U "flash:w:build/$(PNAME).hex:i"

	avrdude -v -patmega328p -carduino -P/dev/ttyACM0 -b115200 \
		-D -Uflash:w:/tmp/arduino_build_242417/sketch_nov03a.ino.hex:i

.PHONY: clean
clean:
	@echo "Cleaning..."
	@rm -rf ./bin ./build
