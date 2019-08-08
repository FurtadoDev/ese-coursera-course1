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
 * @file <stats.c> 
 * @brief <Add Brief Description Here >
 *
 * <Add Extended Description Here>
 *
 * @author <Veinstin Furtado>
 * @date <16-July-2019>
 *
 */



#include <stdio.h>
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

void print_statistics(unsigned char *original_array){
	sort_array(original_array, SIZE);
	find_maximum(original_array,SIZE);
	find_minimum(original_array,SIZE);
	find_mean(original_array,SIZE);
        find_median(original_array,SIZE);
}

void print_array(unsigned char* original_array, int length){
	for(int i=0;i<length;i++)
	{
		printf("%d\n",original_array[i]);
	}
}

void find_median(unsigned char* original_array, int length){
	int medianIndex = (length)/2;
	printf("The Median value is %d\n",original_array[medianIndex]);
}

void find_mean(unsigned char* original_array, int length){
	int sum = 0;
	int mean = 0;
	for(int i=0;i<length;i++)
	{
		sum+=original_array[i];
	}
	mean = sum/length;
	printf("The Mean value is %d\n",mean);
}

void find_maximum(unsigned char* original_array, int length){
	printf("The Maximum is  %d\n",original_array[0]);
}

void find_minimum(unsigned char* original_array, int length){
	printf("The Minimum is  %d\n",original_array[length-1]);
}

void sort_array(unsigned char* original_array, int length){
	mergesort(0,length-1, original_array);
}

//Merge sort using recursion
void merge(int low, int mid, int high, unsigned char* original_array){
	int temp[high+1];
	int tempIndex = 0;
	int i = low;
	int j = mid+1;
	int k = high;
	while((i <= mid) && (j <= high)){
		if(original_array[i] > original_array[j]){
			temp[tempIndex] = original_array[i];
			i++;
			tempIndex++;
		}else if(original_array[j] > original_array[i]){
			temp[tempIndex] = original_array[j];
			j++;
			tempIndex++;
		}else{
			temp[tempIndex] = original_array[i];
			tempIndex++;
			temp[tempIndex] = original_array[i];
			tempIndex++;
			i++;
			j++;
		}

	}

	if((i >= mid) && (j <= high)){ //j is stll remaining and i has finished
		while(j <= high)
		{
			temp[tempIndex] = original_array[j];
			j++;
			tempIndex++;
		}
	}else if((i <= mid) && (j >= high)){ //i is still remaining and j has finished
		while(i <= mid)
		{
			temp[tempIndex] = original_array[i];
			i++;
			tempIndex++;
		}
	}
	
	tempIndex = 0;
	for(int p=low; p<=high; p++){
		original_array[p] = temp[tempIndex];
		tempIndex++;
	}

}


void mergesort(int low, int high, unsigned char* original_array){
	if(low<high)
	{
		int mid = (low+high)/2;
		mergesort(low, mid, original_array);
		mergesort(mid+1, high, original_array);
		merge(low, mid, high, original_array);
	}
}


void main() {

  unsigned char original_array[SIZE] = { 34, 201, 190, 154,   8, 194, 2, 6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

  print_statistics(original_array);
  printf("Sorted Array:\n");
  print_array(original_array, SIZE);
  
}

/* Add other Implementation File Code Here */

