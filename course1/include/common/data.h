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
 * @file data.h
 * @brief Contains declarations of basic data manipulation
 *
 * This header file provides an abstraction of very basic data manipulation
 * 
 * ###Modified### 
 *
 * @author Jagadheesvaran T S
 * @date January 14 2019
 *
 */

#ifndef __DATA_H__
#define __DATA_H__

#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

#define BASE_2 (2)
#define BASE_3 (3)
#define BASE_4 (4)
#define BASE_5 (5)
#define BASE_6 (6)
#define BASE_7 (7)
#define BASE_8 (8)
#define BASE_9 (9)
#define BASE_10 (10)
#define BASE_11 (11)
#define BASE_12 (12)
#define BASE_13 (13)
#define BASE_14 (14)
#define BASE_15 (15)
#define BASE_16 (16)

/**
 * @brief Converts data from a standard integer into an ASCII string
 * 
 * @param data Data to be converted 
 * @param ptr Pointer to the allotted memory location to which the conversion
 * product has to be written
 * @param base Base to which the data has to be converted and stored 
 *
 * @return ascii_count Length of the converted data including null terminator
 * and sign
 */
uint8_t my_itoa(int32_t data, uint8_t *ptr, uint32_t base);

/**
 * @brief Converts data from an ASCII represented string to an integer type
 * 
 * @param ptr Pointer to the allotted memory location from which the ASCII
 * represented string has to be taken and converted to integer
 * @param digits Number of digits in character set
 * @param base Base to which the data has to be converted
 * 
 * @return converted_integer Integer of size 32 bits converted from the ASCII
 * string 
 */
int32_t my_atoi( uint8_t *ptr, uint8_t digits, uint32_t base);

#endif /* __DATA_H__ */
