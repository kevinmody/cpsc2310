/**************************
 *Kevin Mody                                
 *CPSC2310 Fall2020 Sec: 001     
 *UserName: kmody                              
 *Instructor:  Dr. Yvon Feaster  
*************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>

#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))
#define ABS(N) ((N<0)?(-N):(N))
#define LARGEST(a, b, c) (a > b) ? (a > b ? a : c) : (b > c ? b : c)
#define SMALLEST(a, b, c) (a < b) ? (a < b ? a : c) : (b < c ? b : c)
#define DEBUG_FPRINT() fprintf(stderr, "In File %s line %d", __FILE__, __LINE__)
#define ISEVEN_ODD(n) n % 2 == 0 ? 1 : 0
#define MALLOC(a, b) (b*)malloc(a)


int printReturn( int a, int b, int action);
#endif