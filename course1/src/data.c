/******************************************************************************
 * Copyright (C) 2019 by Jagadheesvaran
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software.Jagadheesvaran T S is not liable for any misuse of this material.
 *
 *****************************************************************************/
/**
 * @file data.c
 * @brief Contains implementation of basic data manipulation
 *
 * This implementation file provides the implementation of very basic data manipulation
 * 
 * ###Modified### 
 *
 * @author Jagadheesvaran T S
 * @date January 14 2019
 *
 */

#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	bool signFlag = false;
	size_t ascii_count = 0;
	int32_t reminder = 0;
	
	/*Checking pointer and base values*/
	if(!ptr || !base)
	{
		return 0; 
	}	

	/*Defining response if data is 0 - special case */	
	if(data == 0)
	{
		*ptr = '0';
		*(++ptr) = '\0';
		return 2;
	}
	
	/*Setting the signFlag when data is negative */	
	if(data < 0)
	{
		signFlag = true;
		data = -data;
	}
	
	/*Digit by Digit Data Manipulation*/
	for(ascii_count = 0; data != 0; ascii_count++)
	{
		reminder = data % base;
		*(ptr + ascii_count) = (reminder <= 9)? reminder + '0' : (reminder - 10) + 'A';
		data /= base;
	}

	/*Adding '-' symbol if negative flag is set*/
	if(signFlag)
	{
		*(ptr + ascii_count++) = '-';
	}
	
	/*Reversing the contents to get correct order using a function in 
        memory.c implementation*/
	my_reverse(ptr, ascii_count);
	
	/*Adding Null Terminator*/
	*(ptr + ascii_count) = '\0';

	/*Returning the size of contents*/
	return ++ascii_count;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	bool signedFlag = false;
	size_t iterator = 0;
	int32_t converted_integer = 0;
	uint8_t current_digit = 0;
	
	/*Checking the passed on parameters for boundary conditions*/
	if(!ptr || !digits || !base)
	{
		return 0;
	}

	if(*(ptr) == '-')
	{
		signedFlag = true;
		ptr++;
		digits--;
	}

	for(iterator = 0; iterator < digits - 1; iterator++) // -1 to avoid null terminator
	{
		current_digit = *(ptr + iterator);
		converted_integer = converted_integer*base + (current_digit <= '9' ? current_digit - '0' : (current_digit - 'A') + 10);	
	}
	
	if(signedFlag)
	{
		converted_integer = -converted_integer;
	}

	return converted_integer; 
}
