# Simple make file for blink tutorial on ardunio board
# Author: Random guy

# Name of the project
PROJ_NAME=blink

# Compiler flags for avr-gcc
#----------------------------
#  g      We like Debug info.
#
#  Os     Crunch that executable into something compact and efficient. We're on
#           an embedded device so size really really counts
#
#  mmcu   Define the board type
#
#  DF_CPU 
#         Important to define the clockspeed of the board
#
#  -W1,-Map,'file_name'
#         We need these to extract the hex code. Honestly, the normal executable
#           that is made is almost unimportant.
CFLAGS=-g -Os -mmcu=atmega2560 -DF_CPU=16000000L -Wl,-Map,${PROJ_NAME}.map


# All...hit these components when someone just types [sh> make ]
all: ${PROJ_NAME}.elf ${PROJ_NAME}.hex 

# Compile the Source (.cpp) -> Exectuable (.elf)
${PROJ_NAME}.elf: ${PROJ_NAME}.cpp
	@echo "Compiling Source..."
	avr-gcc ${CFLAGS} -o ${PROJ_NAME}.elf ${PROJ_NAME}.cpp wiring_digital.o wiring.o
	@echo "Complete"

# Executable (.elf) -> Extract the Hex
${PROJ_NAME}.hex: ${PROJ_NAME}.elf
	@echo "Extracting hex file..."
	avr-objcopy -j .text -j .data -O ihex ${PROJ_NAME}.elf ${PROJ_NAME}.hex
	@echo "Complete"

# Hex -> Upload the Hex
upload: ${PROJ_NAME}.hex
	avrdude -c stk500v2 -p m2560 -U flash:w:${PROJ_NAME}.hex
