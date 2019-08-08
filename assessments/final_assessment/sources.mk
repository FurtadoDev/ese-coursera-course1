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

# Add your Source files to this variable
SOURCES := src/interrupts_msp432p401r_gcc.c \
	  src/main.c \
	  src/course1.c \
	  src/stats.c \
	  src/memory.c \
	  src/startup_msp432p401r_gcc.c \
	  src/system_msp432p401r.c \
	  src/data.c
# Source files that need to be compiled when compiling for the target(MSP432) platform
SOURCES_MSP432 := src/interrupts_msp432p401r_gcc.c src/main.c src/memory.c src/startup_msp432p401r_gcc.c src/system_msp432p401r.c src/course1.c src/stats.c src/data.c

# Source files that need to be compiled when compiling for the host platform
SOURCES_HOST := src/main.c src/memory.c src/course1.c src/stats.c src/data.c

# Add your include paths to this variable
INCLUDES := -Iinclude/CMSIS \
	    -Iinclude/common \
	    -Iinclude/msp432
