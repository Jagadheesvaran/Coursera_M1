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
ifeq ($(PLATFORM),MSP432)
	SRCS = src/interrupts_msp432p401r_gcc.c \
       	       src/memory.c \
               src/system_msp432p401r.c \
               src/startup_msp432p401r_gcc.c \
               src/main.c \
	       src/data.c \
	       src/stats.c \
	       src/course1.c
else ifeq ($(PLATFORM),HOST)
	SRCS = src/main.c \
	       src/memory.c \
	       src/data.c \
	       src/stats.c \
	       src/course1.c
else
	$(error Enter a valid target)
endif

# Add your include paths to this variable
ifeq ($(PLATFORM),MSP432)
	INCLUDES = -Iinclude/CMSIS \
	  	   -Iinclude/common \
	   	   -Iinclude/msp432
else ifeq ($(PLATFORM),HOST)
	INCLUDES = -Iinclude/common
else
	$(error Enter a valid target)
endif
