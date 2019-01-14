/******************************************************************************
 * Copyright (C) 2018 by Jagadheesvaran T S
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Jagadheesvaran T S is not liable for any misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.c 
 * @brief Implementation file for the first assignment
 *
 * This file contains the definitions of the functions, declared in the stats.h
 * file, for the implementation of the assignment project
 *
 * @author Jagadheesvaran T S
 * @date 1/1/2019
 *
 */



#include <stdio.h>
#include "stats.h"
#include "platform.h"

/* Size of the Data Set */
//#define SIZE (40)

/*
void main()
{
 
	unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90}; 
	#ifdef VERBOSE
		PRINTF("\nThe given array is\n");
		print_array(test, SIZE);
	#endif
	sort_array(test, SIZE);
	#ifdef VERBOSE
		PRINTF("\nThe array after sorting in descending order is\n");
		print_array(test, SIZE);
	#endif
	print_statistics(test, SIZE);

}
*/

void print_statistics(unsigned char array[], unsigned int length)
{
  	
	PRINTF("\n The Median is %u\n", find_median(array, length));
	PRINTF("\n The Mean is %u\n", find_mean(array, length));
	PRINTF("\n The Maximum is %u\n", find_maximum(array, length));
	PRINTF("\n The Minimum is %u\n", find_minimum(array, length));

}

void print_array(unsigned char array[], unsigned int length)
{

	#ifdef VERBOSE
		unsigned int iterator;
		for(iterator = 0; iterator < length; iterator++)
		{
			PRINTF(" %u ", array[iterator]);
		}
		PRINTF("\n");
	#endif

}

unsigned char find_median(unsigned char array[], unsigned int length)
{

	if(length % 2 == 0)
	{
		return (unsigned char)((array[length/2-1]+array[length/2])/2);
	}
	else
	{
		return (unsigned char)(array[length/2]);
	}

}

unsigned char find_mean(unsigned char array[], unsigned int length)
{

	unsigned int iterator;
	unsigned int accumulator = 0;
	for(iterator = 0; iterator < length; iterator++)
	{
		accumulator += array[iterator];
	}
	return (unsigned char)(accumulator/length);	

}

unsigned char find_maximum(unsigned char array[], unsigned int length)
{

	return array[0]; //since the array is sorted in descending order

}

unsigned char find_minimum(unsigned char array[], unsigned int length)
{

	return array[length - 1]; //since the array is descending order sorted

}

void sort_array(unsigned char array[], unsigned int length)
{
	int forward_iterator;
	int reverse_iterator;
	int key;
	for(forward_iterator = 1; forward_iterator < length; forward_iterator++)
	{
		for(reverse_iterator = forward_iterator; reverse_iterator > 0 && array[reverse_iterator - 1] < array[reverse_iterator]; reverse_iterator--)
		{
			key = array[reverse_iterator];
			array[reverse_iterator] = array[reverse_iterator - 1];
			array[reverse_iterator - 1] = key;
		}
	}
}
