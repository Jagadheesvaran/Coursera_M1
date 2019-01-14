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
 * @file memory.c
 * @brief Implementation of memory read and write operations
 *
 * This file provides an implementation of reading and
 * writing to memory via function calls. 
 * 
 * ###Modified### 
 *
 * @author Jagadheesvaran T S
 * @date January 14 2019
 *
 */

#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value)
{
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index)
{
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index)
{
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size)
{
  unsigned int i;
  for(i = 0; i < size; i++) 
  {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size)
{
  set_all(ptr, 0, size);
}

uint8_t* my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
	size_t iterator = 0;
	uint8_t* buffer = (uint8_t*)malloc(length*sizeof(uint8_t));
	if(!buffer)
	{
		return buffer;
	}
	for(iterator = 0; iterator < length; iterator++)
	{
		*(buffer + iterator) = *(src + iterator);
	}
	for(iterator = 0; iterator < length; iterator++)
	{
		*(dst + iterator) = *(buffer + iterator);
	}
	free(buffer);
	return dst;
}

uint8_t* my_memcopy(uint8_t * src, uint8_t * dst, size_t length)
{
        size_t iterator = 0;
        for(iterator = 0; iterator < length; iterator++)
        {
                *(dst + iterator) = *(src + iterator);
        }
        return dst;
}

uint8_t* my_memset(uint8_t * src, size_t length, uint8_t value)
{	
	size_t iterator = 0;
	for(iterator = 0; iterator < length; iterator++)
	{
		*(src + iterator) = value;
	}
	return src;	
}

uint8_t * my_memzero(uint8_t * src, size_t length)
{
	size_t iterator = 0;
        for(iterator = 0; iterator < length; iterator++)
        {
                *(src + iterator) = 0;
        }
        return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length)
{
	size_t iterator = 0, decremented_iterator = 0;
        uint8_t* buffer = (uint8_t*)malloc(length*sizeof(uint8_t));
        if(!buffer)
        {
                return buffer;
        }
        for(iterator = 0; iterator < length; iterator++)
        {
                *(buffer + iterator) = *(src + iterator);
        }
        for(iterator = 0, decremented_iterator = length - 1; iterator < length; iterator++, decremented_iterator--)
        {
                *(src + iterator) = *(buffer + decremented_iterator);
        }
        free(buffer);
        return src;
}

int32_t * reserve_words(size_t length)
{
	return ((int32_t*)malloc(length*sizeof(int32_t)));	
}

void free_words(int32_t * src)
{
	free(src);
}


