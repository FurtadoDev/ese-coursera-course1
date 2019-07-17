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

all : main.s memory.s interrupts_msp432p401r_gcc.i startup_msp432p401r_gcc.i system_msp432p401r.i main.i memory.i

# Platform Overrides
override PLATFORM = MSP432 

LINKER_FILE = msp432p401r.lds

# Architecture Specific Flags
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs

# Compiler Flags and Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
LDFLAGS = -Wl,-Map=c1m2.map -T $(LINKER_FILE)
CFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -Wall
CPPFLAGS = $(INCLUDES) 

#Pre-processing Stage
main.i : main.c ../include/common/memory.h ../include/common/platform.h
	$(CC) -E -D$(PLATFORM)  $(CFLAGS) $(CPPFLAGS) $< -o $@

memory.i : memory.c ../include/common/memory.h
	$(CC) -E  $(CFLAGS) $(CPPFLAGS) $< -o $@

interrupts_msp432p401r_gcc.i : interrupts_msp432p401r_gcc.c 
	$(CC) -E $(CFLAGS) $< -o $@

startup_msp432p401r_gcc.i : startup_msp432p401r_gcc.c
	$(CC) -E $(CFLAGS) $< -o $@

system_msp432p401r.i : system_msp432p401r.c ../include/msp432/msp432p401r.h
	$(CC) -E $(CFLAGS) $(CPPFLAGS) $< -o $@ 

#Compiler-Proper Stage
main.s : main.i
	$(CC) -S -D$(PLATFORM)  $(CFLAGS) $(CPPFLAGS) $< -o $@

memory.s: memory.i
	$(CC) -S  $(CFLAGS) $(CPPFLAGS) $< -o $@

