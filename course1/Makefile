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
# Build the C1M2 file
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      HOST: the host  machine
#      MSP432 : the MSP432 dev board
#
# Platform Overrides:
#      HOST : any linux machine equiped with GCC ( default )
#      MSP432 : a cortex ARM v7 dev platform
#------------------------------------------------------------------------------
include sources.mk

BUILDFILE=c1m2
# Architectures Specific Flags
LINKER_FILE=-T../msp432p401r.lds

ARMSWITCH=-DMSP432
ARMCPU=-mcpu=cortex-m4\
	-mthumb

ARMARCH =-march=armv7e-m\
	-mfloat-abi=hard\
	-mfpu=fpv4-sp-d16

DEPS = -MT $@ -MMD -MP -MF $*.dep
SPECS = --specs=nosys.specs

# Compiler Flags and Defines
CFLAGS =-Wall -Wl,-Map=${BUILDFILE}.map -Werror -g -O0 -std=c99

HOSTCFLAGS=-DHOST

PREPROCESSED= main.i memory.i
OBJ=main.o memory.o

ARMFLAGS=$(LINKER_FILE)\
	$(ARMSWITCH)\
	$(ARMCPU)\
	$(ARMARCH)\
	$(SPECS)

ifndef PLATFORM
$(info PLATFORM variable not setted, forcing PLATFORM to HOST)
PLATFORM=HOST
endif


ifeq ($(PLATFORM),HOST)
	CC = $(shell which gcc)
	SIZETOOL += $(shell which size)
	CFLAGS += $(HOSTCFLAGS)
else
	CC = $(shell which arm-none-eabi-gcc)
	SIZETOOL += $(shell which arm-none-eabi-size)
	CFLAGS += $(ARMFLAGS)
	PREPROCESSED += interrupts_msp432p401r_gcc.i system_msp432p401r.i startup_msp432p401r_gcc.i
	OBJ += interrupts_msp432p401r_gcc.o system_msp432p401r.o startup_msp432p401r_gcc.o
endif


%.i: %.c
	$(CC) $^ -o $@ -E $(CFLAGS) $(INCLUDES) ${DEPS}

%.asm: %.c
	$(CC) $^ -o $@ -S $(CFLAGS) $(INCLUDES) ${DEPS}

%.o: %.c
	$(CC) $^ -o $@ -c $(CFLAGS) $(INCLUDES) ${DEPS}

${BUILDFILE}: build

.PHONY: build
build: compile-all
	$(CC) $(OBJ) -o ${BUILDFILE}.out $(CFLAGS) $(INCLUDES)
	${SIZETOOL} ${BUILDFILE}.out


.PHONY: compile-all
compile-all: $(OBJ)


.PHONY: clean
clean:
	rm -rf *.i *.o *.asm *.map *.out *.dep