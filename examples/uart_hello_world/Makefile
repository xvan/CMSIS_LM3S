#******************************************************************************
#
# Makefile - Rules for building the CMSIS uart_hello_world example.
#
# Copyright (c) 2009 Luminary Micro, Inc.  All rights reserved.
# Software License Agreement
# 
# Luminary Micro, Inc. (LMI) is supplying this software for use solely and
# exclusively on LMI's microcontroller products.
# 
# The software is owned by LMI and/or its suppliers, and is protected under
# applicable copyright laws.  All rights are reserved.  You may not combine
# this software with "viral" open-source software in order to form a larger
# program.  Any use in violation of the foregoing restrictions may subject
# the user to criminal sanctions under applicable laws, as well as to civil
# liability for the breach of the terms and conditions of this license.
# 
# THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
# OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
# MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
# LMI SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
# CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
# 
# This is part of revision 32 of the Stellaris CMSIS Package.
#
#******************************************************************************

#
# Defines the part type that this project uses.
#
PART=LM3S6965

#
# The base directory for DriverLib.
#
ROOT=../..

#
# Include the common make definitions.
#
include ${ROOT}/makedefs

#
# Where to find source files that do not live in this directory.
#
VPATH=../../CMSIS/Include
VPATH+=../../lm3s

#
# Where to find header files that do not live in the source directory.
#
IPATH=.
IPATH+=../..
IPATH+=../../CMSIS/Include

#
# The default rule, which causes the CMSIS uart_hello_world example to be built.
#
all: ${COMPILER}
all: ${COMPILER}/uart_hello_world.axf

#
# The rule to clean out all the build products.
#
clean:
	@rm -rf ${COMPILER} ${wildcard *~}

#
# The rule to create the target directory.
#
${COMPILER}:
	@mkdir ${COMPILER}

#
# Rules for building the CMSIS uart_hello_world example.
#
${COMPILER}/uart_hello_world.axf: ${COMPILER}/uart_hello_world.o
${COMPILER}/uart_hello_world.axf: ${COMPILER}/startup_${COMPILER}.o
${COMPILER}/uart_hello_world.axf: ${COMPILER}/system_lm3s.o
ifeq (${COMPILER}, gcc)
${COMPILER}/uart_hello_world.axf: uart_hello_world.ld
endif
SCATTERgcc_uart_hello_world=uart_hello_world.ld
ifeq (${COMPILER}, sourcerygxx)
${COMPILER}/uart_hello_world.axf: uart_hello_world_sourcerygxx.ld
endif
SCATTERsourcerygxx_uart_hello_world=lm3s6965-rom.ld -T uart_hello_world_sourcerygxx.ld
ENTRY_uart_hello_world=Reset_Handler

#
# Include the automatically generated dependency files.
#
ifneq (${MAKECMDGOALS},clean)
-include ${wildcard ${COMPILER}/*.d} __dummy__
endif
