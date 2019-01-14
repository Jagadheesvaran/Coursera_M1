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
 * @file stats.h 
 * @brief Header file for the first peer graded assignment
 *
 * The file includes the declaration and documentation for the function 
 * from the stats.c file. 
 *
 * @author Jagadheesvaran T S
 * @date 1/1/2019
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
 
/**
 * @brief Prints the statistics values after computation
 *
 * This function takes the unsigned character pointer to an array and its 
 * length as inputs. It computes the statistics values using other statistics
 * computation functions such as find_mean() etc. and prints the same in the 
 * console using printf() function of standard output library.  
 *
 * @param array The unsigned char pointer to an array whose statistical values 
 * are to be computed
 * @param length The length of that array as unsigned integer 
 *
 * @returns nothing - return type - void 
 */
void print_statistics(unsigned char array[], unsigned int size);

/**
 * @brief Prints the contents of the array passed
 *
 * This function takes the unsigned character pointer to an array and its 
 * length as inputs. It prints the elements of the array in the console using 
 * printf() function of the standard output library.  
 *
 * @param array The unsigned char pointer to an array whose contents are to be  * printed
 * @param length The length of that array as unsigned integer 
 *
 * @returns nothing - return type - void 
 */
void print_array(unsigned char array[], unsigned int size);

/**
 * @brief Finds the median of the given data array contents
 * 
 * This function takes the unsigned character pointer to a sorted array and its
 * length as inputs. It finds the median of the contents and returns the same 
 * as unsigned character.
 *
 * @param array The unsigned char pointer to a sorted array 
 * @param length The length of that array as unsigned integer
 * 
 * @return The unsigned char value of the median   
 */
unsigned char find_median(unsigned char array[], unsigned int size);

/**
 * @brief Calcuates the mean of the given data array contents
 * 
 * This function takes the unsigned character pointer to an array and its
 * length as inputs. It computes the mean of the contents and returns the same 
 * as unsigned character.
 *
 * @param array The unsigned char pointer to an array 
 * @param length The length of that array as unsigned integer
 * 
 * @return The unsigned char value of the mean     
 */
unsigned char find_mean(unsigned char array[], unsigned int size);

/**
 * @brief Finds the maximum of the given data array contents
 * 
 * This function takes the unsigned character pointer to a sorted array and its
 * length as inputs. It finds the maximum of the contents and returns the same 
 * as unsigned character.
 *
 * @param array The unsigned char pointer to a sorted array 
 * @param length The length of that array as unsigned integer
 * 
 * @return The unsigned char value of the maximum valued content    
 */
unsigned char find_maximum(unsigned char array[], unsigned int size);

/**
 * @brief Calcuates the minimum of the given data array contents
 * 
 * This function takes the unsigned character pointer to a sorted array and its
 * length as inputs. It finds the minimum of the contents and returns the same 
 * as unsigned character.
 *
 * @param array The unsigned char pointer to a sorted array 
 * @param length The length of that array as unsigned integer
 * 
 * @return The unsigned char value of the minimum valued content  
 */
unsigned char find_minimum(unsigned char array[], unsigned int size);

/**
 * @brief Sort the given array in descending order
 *
 * This function takes the unsigned character pointer to an array and its
 * length as inputs. It utilizes insertion sorting algorithm as it is efficient
 * for small to medium data set. It is a stable sorting technique and adaptive  * in execution ie. less steps for partially sorted array. It is better than 
 * bubble and selection sorts and also less complex to implement. It sorts the  * array contents in descending order.
 *
 * @param array The unsigned char pointer to an array 
 * @param length The length of that array as unsigned integer
 *
 * @returns nothing - return type - void
*/
void sort_array(unsigned char array[], unsigned int size);
 


#endif /* __STATS_H__ */
