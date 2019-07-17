#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# <Put a Description Here>
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <Put a description of the supported targets here>
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
#_*_Makefile_*_
include sources.mk
-include $(SRC:.c=.d)


#Liker file for target
LINKER_FILE = msp432p401r.lds

PLATFORM = MSP432
TARGET = c1m3

OBJS = $(SRC:.c=.o)
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs -Wall -Werror -g -O0 -std=c99
 


#Pre-processing Stage
%.i : %.c
	$(CC) -E -D$(PLATFORM) $(CFLAGS) $*.c -o $*.i
	$(CC) -MM -D$(PLATFORM) $(CFLAGS) $*.c -o $*.d
#Compiler-proper Stage
%.s : %.c
	$(CC) -S -D$(PLATFORM) $(CFLAGS) $*.c -o $*.s
	$(CC) -MM -D$(PLATFORM) $(CFLAGS) $*.c -o $*.d
#Assembler Stage
%.o : %.c
	$(CC) -c -D$(PLATFORM) $(CFLAGS) $*.c -o $*.o
	$(CC) -MM -D$(PLATFORM) $(CFLAGS) $*.c -o $*.d
#Linker and Locator Stage
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY: clean
clean:
	rm -f $(SOURCES:.c=.o) $(SOURCES:.c=.d) $(SOURCES:.c=.i) $(SOURCES:.c=.s) $(TARGET).out $(TARGET).map
