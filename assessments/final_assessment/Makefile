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

ifndef PLATFORM
 PLATFORM = HOST
endif

#Liker file for target
LINKER_FILE = msp432p401r.lds
TARGET = c1final

ifeq ($(PLATFORM),MSP432)
SRC = $(SOURCES_MSP432)
OBJS = $(SRC:.c=.o)
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=$(TARGET).map -T $(LINKER_FILE)
CFLAGS = -mcpu=cortex-m4 -mthumb -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16 --specs=nosys.specs -Wall -Werror -g -O0 -std=c99
CPPFLAGS = $(INCLUDES) 
else
SRC = $(SOURCES_HOST)
OBJS = $(SRC:.c=.o)
CC = gcc
LD = ld
LDFLAGS = -Wl,-Map=$(TARGET).map
CFLAGS = -Wall -Werror -g -O0 -std=c99
CPPFLAGS = $(INCLUDES)
endif

#Pre-processing Stage
%.i : %.c
	$(CC) -E -D$(PLATFORM) -DCOURSE1 -DVERBOSE $(CFLAGS) $(CPPFLAGS) $*.c -o $*.i
	$(CC) -MM -D$(PLATFORM) -DCOURSE1 -DVERBOSE $(CFLAGS) $(CPPFLAGS) $*.c -o $*.d
#Compiler-proper Stage
%.asm : %.c
	$(CC) -S -D$(PLATFORM) -DCOURSE1 -DVERBOSE $(CFLAGS) $(CPPFLAGS) $*.c -o $*.asm
	$(CC) -MM -D$(PLATFORM) -DCOURSE1 -DVERBOSE $(CFLAGS) $(CPPFLAGS) $*.c -o $*.d
#Assembler Stage
%.o : %.c
	$(CC) -c -D$(PLATFORM) -DCOURSE1 -DVERBOSE $(CFLAGS) $(CPPFLAGS) $*.c -o $*.o
	$(CC) -MM -D$(PLATFORM) -DCOURSE1 -DVERBOSE $(CFLAGS) $(CPPFLAGS) $*.c -o $*.d
#Linker and Locator Stage
$(TARGET).out: $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) $(LDFLAGS) -o $@

.PHONY: build
build: all

.PHONY: all
all: $(TARGET).out

.PHONY: compile-all
compile-all: $(SRC:.c=.o)

.PHONY: clean
clean:
	rm -f $(SOURCES:.c=.o) $(SOURCES:.c=.d) $(SOURCES:.c=.i) $(SOURCES:.c=.asm) $(TARGET).out $(TARGET).map
