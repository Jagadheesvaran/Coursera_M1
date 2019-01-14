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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 * 
 * ###Modified### 
 *
 * @author Jagadheesvaran T S
 * @date January 14 2019
 *
 */
#ifndef __MEMORY_H__
#define __MEMORY_H__
#include <stdlib.h>
#include <stdint.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the location
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the location
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Moves a memory content from source to destination
 *
 * Given two pointers to source and destination along with a length to move,
 * the source contents are moved to destination
 * 
 * Handles source and destination overlap with an intermediate buffer
 *
 * @param src Pointer to the source 
 * @param dst Pointer to the destination
 * @param length Length of bytes to move from source to destination 
 *
 * @return dst Pointer to the destination
 */
uint8_t my_memmove(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Copies a memory content from source to destination
 *
 * Given two pointers to source and destination along with a length to copy,
 * the source contents are moved to destination
 * 
 * Doesn't handle source and destination overlap with an intermediate buffer
 *
 * @param src Pointer to the source 
 * @param dst Pointer to the destination
 * @param length Length of bytes to copy from source to destination 
 *
 * @return dst Pointer to the destination
 */
uint8_t my_memcopy(uint8_t *src, uint8_t *dst, size_t length);

/**
 * @brief Sets a memory stretch, provided by a src pointer, to value passed
 *
 * Given a pointer to source, length in bytes along with a value to set,
 * all location of that memory span is set to given value
 *
 * @param src Pointer to the source
 * @param length Length of bytes to be set starting from source
 * @param value Value to set the source across its length given
 *
 * @return src Pointer to the source
 */
uint8_t my_memset(uint8_t *src, size_t length, uint8_t value);

/**
 * @brief Clears(Zeros) a memory stretch, provided by a src pointer
 *
 * Given a pointer to source and length in bytes, clears or zeros the contents
 * of memory stretch of given length pointed by source pointer
 *
 * @param src Pointer to the source
 * @param length Length of bytes to be cleared or zeroed starting from source
 *
 * @return src Pointer to the source
 */
uint8_t my_memzero(uint8_t *src, size_t length);

/**
 * @brief Reverses a memory stretch, provided by a src pointer
 *
 * Given a pointer to source and length in bytes, reverses the contents
 * of memory stretch of given length pointed by source pointer
 *
 * @param src Pointer to the source
 * @param length Length of bytes to be reversed starting from source
 *
 * @return src Pointer to the source
 */
uint8_t my_reverse(uint8_t *src, size_t length);

/**
 * @brief Reserve memory stretch for given number of words
 *
 * Given a length of words, allocate memory to them in dynamic memory (heap) 
 * and returns a pointer to that memory
 *
 * @param length Number of four byte words to be allocated memory
 *
 * @return src Pointer to the start of memory allocated
 */
int32_t* reserve_words(size_t length);

/**
 * @brief Free memory stretch pointed by a given pointer
 *
 * Given an pointer, free the heap memory pointed by it 
 *
 * @param src Pointer to the start of the memory intended to be freed
 * 
 * @return void
 */
void free_words(int32_t* src);

#endif /* __MEMORY_H__ */
