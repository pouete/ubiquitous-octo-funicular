/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material.
 *
 *****************************************************************************/
/**
 * @file stats.s
 * @brief Implements m1 assessment
 *
 * Provides the needed functions to
 *
 * @author Julien Godin
 * @date 27/10/2017
 *
 */
#ifndef __STATS_H__
#define __STATS_H__


/**
 * @brief prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * prints the statistics of an array including minimum, maximum, mean, and median.
 *
 * @param array A pointer to the array that needs to be analyzed
 * @param array_size The size of the array
 *
 * @return Zero  if the function was successfull, -1 else.
 */
unsigned char print_statistics(unsigned char *array, unsigned int array_size);

/**
 * @brief Prints the array
 *
 * Pretty print the array.
 *
 * @param array A pointer to the array that needs to be printed
 * @param array_size The size of the array
 *
 * @return Always return 0
 */
unsigned char print_array(unsigned char *array, unsigned int array_size);

/**
 * @brief Finds the median value
 *
 * Given an array, finds and return the median value.
 *
 * @param array A pointer to the array that needs to be printed
 * @param array_size The size of the array
 *
 * @return Returns the median value , -1 else.
 */
unsigned char find_median(unsigned char *array, unsigned int array_size);

/**
 * @brief Finds the mean
 *
 * Given an array, finds and return the mean value.
 *
 * @param array A pointer to the array that needs to be printed
 * @param array_size The size of the array
 *
 * @return Returns the mean value , -1 else.
 */
unsigned char find_mean(unsigned char *array, unsigned int array_size);

/**
 * @brief Finds the maximum
 *
 * Given an array, finds and return the maximum value.
 *
 * @param array A pointer to the array that needs to be printed
 * @param array_size The size of the array
 *
 * @return Returns the maximum value , -1 else.
 */
unsigned char find_maximum(unsigned char *array, unsigned int array_size);

/**
 * @brief finds the minimum of an array
 *
 * Given an array, finds and return the minimum value.
 *
 * @param array A pointer to the array that needs to be printed
 * @param array_size The size of the array
 *
 * @return Returns the minimum value , -1 else.
 */
unsigned char find_minimum(unsigned char *array, unsigned int array_size);

/**
 * @brief Sorts an array
 *
 *  Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )
 *
 * @param array A pointer to the array that needs to be printed
 * @param array_size The size of the array
 *
 * @return Returns a pointer to the sorted array, -1 else.
 */
unsigned char sort_array(unsigned char *array, unsigned int array_size);


#endif /* __STATS_H__ */
