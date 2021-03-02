/**************************
 *KEVIN MODY                                
 *CPSC2310 Lab8                         
 *UserName: kmody                              
 *Lab Section: 002                            
/*************************/
#include "functions.h"
#include <stdio.h>
void inplace_swap(int *x, int *y)
{
		*y = *x ^ *y;
		*x = *x ^ *y;
		*y = *x ^ *y;
}
void reverse_array(int *array, int cnt)
{
	int first, last;
	for (first = 0, last = cnt-1; first < last; first++, last--)//first<=last replaced to first<last becasue there is no need to swap the middle element even if it is odd or even  
		inplace_swap(&array[first], &array[last]);
}

int fun1(unsigned word)
{
	return (int) ((word << 24)  >> 24); 
}
int fun2(unsigned word)
{
	return ((int) (word << 24) >> 24);
}

