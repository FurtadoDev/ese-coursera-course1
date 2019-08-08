/******************************************************************************
 * Copyright (C) 2019 by Veinstin Furtado - Memorial University of Newfoundland
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Veinstin Furtado and Memorial University of Newfoundland are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file data.c 
 * @brief This file is to be used to course 1 final assessment.
 *
 * @author Veinstin Furtado
 * @date July 26, 2018
 *
 */

#include "course1.h"
#include "data.h"

int32_t binaryAddition(int32_t addend1,int32_t addend2)
{
	int32_t carry;
	while(addend2 != 0)
	{
		carry = (addend1 & addend2) << 1;
		addend1 = addend1 ^ addend2;
		addend2 = carry;
	}	
	return addend1;
}

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	uint8_t count = 0;
	int32_t temp1 = 0;
	uint8_t temp2;
	bool negativeFlag = 0;
	int32_t remainder;
	int32_t quotient;

	if(base == 2)
	{	
		for(int i = 31; i >=0; i--)
		{
		temp1 = data >> i;
		//if it is a one
		if(temp1 & 1)
		{
			*(ptr + count) = 1 + '0';
		}else{ //else it must be a zero
			*(ptr + count) = 0 + '0';
		}
			count++;
		}
		*(ptr + count) = '\0';
	}else if(base == 16 || base == 10){

		if(data < 0){
			data = binaryAddition(~(data), 1); //number without the -ve sign(converting to two's compliment and adding 1)
			negativeFlag = 1;
		}
		do
		{
			remainder = data%base;
			quotient = data/base;
			if(remainder <= 9)
			{
				*(ptr + count) = remainder + 48;
			}else
			{
				*(ptr + count) = remainder + 55;
			}
			data = quotient;
			count++;
		}while(quotient != 0);
		
		if(negativeFlag){
			*(ptr + count) = 45;
			count++;
		}
		//code to reverse the the characters
		for(int i = 0; i < count/2; i++)
		{
			temp2 = *(ptr + i);
			*(ptr + i) = *(ptr + count - 1 - i);
			*(ptr + count - 1 - i) = temp2;

		}
		*(ptr + count) = '\0';

	}
	if(negativeFlag == 1){
		return count - 1;
	}else{
		return count;
	}
}


int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	int32_t result = 0;
	int temp;
	int count = 0;
	if( (base<2) || (base>16) )
	{
		printf("Invalid Range : Range of base is from 2 to 16");
	}

	//if it is a negative number in 2's compliment representation
	if(base == 2 && *ptr == '1')
	{
		temp = *ptr - '0';
		result = (result*base + temp)*(-1);
		count++;
		for(int i=0; i < digits-1; i++){
			if(*(ptr+count) >= '0' && *(ptr+count) <= '9'){
				temp = *(ptr+count) - '0';
			}else{
				temp = *(ptr+count) - '7';
			}
		result = result*base + temp;
		count++;
		}
	//if it is a negative number in hex or base 10 format
	}else if((base == 10 && *ptr == '-') || (base == 16 && *ptr == '-')){
		count++;
		for(int i=0; i<digits; i++)
		{
			if(*(ptr+count) >= '0' && *(ptr+count) <= '9'){
				temp = *(ptr+count) - '0';
			}else{
				temp = *(ptr+count) - '7';
			}
		result = result*base + temp;
		count++;
		}
		result = result*(-1);
	//else it is a positive number(the procedure is the same for any base
	}else{
		for(int i=0; i<digits; i++)
		{
			if(*(ptr+count) >= '0' && *(ptr+count) <= '9'){
				temp = *(ptr+count) - '0';
			}else{
				temp = *(ptr+count) - '7';
			}
		result = result*base + temp;
		count++;
		}
	}

return result;
}
