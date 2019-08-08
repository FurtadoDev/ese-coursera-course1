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
 * @file <stats.h> 
 * @brief <Contains function declarations that report analytics on an array>
 *
 * <The functions contained in this file analyze an array of unsigned char data items and report analytics on the maximum, minimum, 
 * mean, and median of the data set. In addition, it also contains a function that reorders this data set from large to small. All statistics 
 * are rounded down to the nearest integer. The statics are printed using the print_statistics function.
 *
 * @author <Veinstin Furtado>
 * @date <10-06-2019>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

#include "platform.h"

/* Add Your Declarations and Function Comments here */ 

/**
 * @brief <A function that prints the statistics of an array.>
 *
 * <Given an array, print the minimum, maximum, mean and median values>
 *
 * @param <myArray> <an array with SIZE number of elements>
 *
 * @return <void>
 */
void print_statistics(unsigned char* myArray);





/**
 * @brief <Given an array of data and a length, prints the array to the screen>
 *
 * @param <myArray> <an array with length number or elements>
 * @param <length> <length of the array>
 *
 * @return <void>
 */
void print_array(unsigned char* myArray, int length);





/**
 * @brief <Returns the median value>
 *
 * <Given an array of data and a length, returns the median value>
 *
 * @param <array> <an array with length number or elements>
 * @param <length> <length of the array>
 *
 * @return <void>
 */
void find_median(unsigned char* myArray, int length);





/**
 * @brief <Computes the mean of the array>
 *
 * <Given an array of data and a length, returns the mean>
 *
 * @param <array> <an array with length number or elements>
 * @param <length> <length of the array>
 *
 * @return <void>
 */
void find_mean(unsigned char* myArray, int length);





/**
 * @brief <Finds the maximum value in an array>
 *
 * <Given an array of data and a length, returns the maximum>
 *
 * @param <array> <an array with length number or elements>
 * @param <length> <length of the array>
 *
 * @return <void>
 */
void find_maximum(unsigned char* myArray, int length);





/**
 * @brief <Finds the minimum value in an array>
 *
 * <Given an array of data and a length, returns the minimum>
 *
 * @param <array> <an array with length number or elements>
 * @param <length> <length of the array>
 *
 * @return <void>
 */
void find_minimum(unsigned char* myArray, int length);





/**
 * @brief <Sorts an array by calling the appropriate sort algorithm>
 *
 * <Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )>
 *
 * @param <array> <an array with length number or elements>
 * @param <length> <length of the array>
 *
 * @return <Add Return Informaiton here>
 */
void sort_array(unsigned char* myArray, int length);





/**
 * @brief <Sorts an array using the merge sort technique with the help of recursion>
 *
 * <Given an array this function will recursively call itself until the whole array is sorted>
 *
 * @param <low> <the first index of the array(which is zero)>
 * @param <high> <the last index of the array>
 * @param <original_array> <the array which needs to be sorted>
 *
 * @return <void>
 */
void mergesort(int low, int high, unsigned char* original_array);





/**
 * @brief <merges two sorted arrays>
 *
 * <given a low index, a mid index and a high index, this method will merge them together in ascending order>
 *
 * @param <low> <the low index of the sub portion of the array>
 * @param <mid> <the mid index of the sub portion of the array>
 * @param <high> <the last index of the sub portion of the array>
 * @param <original_array> <the array which needs to be sorted>
 *
 * @return <void>
 */
void merge(int low, int mid, int high, unsigned char* original_array);
#endif /* __STATS_H__ */
