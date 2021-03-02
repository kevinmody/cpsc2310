/**************************
 *Kevin Mody                                
 *CPSC2310 Fall2020 Sec: 001     
 *UserName: kmody                              
 *Instructor:  Dr. Yvon Feaster  
*************************/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int main()
{
    printf("Testing: \n");
    printf("%d\n", printReturn(1, 2, 1));
    printf("%d\n", printReturn(1, 2, 2));
    printf("%d\n", printReturn(1, 2, 3));
    printf("%d\n", printReturn(1, 2, 4));

    printf("\nMacro 1: \n");
    printf("Max: %d\n", MAX(5,4));
    printf("Max: %.1f\n", MAX(10.5,11.9));
    printf("Max: %c\n", MAX('a','b'));

    printf("\nMacro:2 \n");
    printf("Min: %d\n", MIN(5,4));
    printf("Min: %.1f\n", MIN(10.5,11.9));
    printf("Min: %c\n", MIN('a','b'));

    printf("\nMacro:3 \n");
    printf("Abs: %d\n", ABS(-3));
    printf("Abs: %d\n", ABS(3));
    printf("Abs: %d\n", ABS(0));

    printf("\nMacro:4 \n");
    printf("Largest: %d\n", LARGEST(1,2,3));
    printf("Largest: %c\n", LARGEST('a','b','c'));
    printf("Largest: %c\n", LARGEST('c','b','a'));

    printf("\nMacro:5 \n");
    printf("Smallest: %d\n", SMALLEST(1,2,3));
    printf("Smallest: %c\n", SMALLEST('a','b','c'));
    printf("Smallest: %c\n", SMALLEST('c','b','a'));

    printf("\nMacro:6 \n");
    DEBUG_FPRINT();
    printf("\n");

    printf("\nMacro:7 \n");
    if(ISEVEN_ODD(4)== 1)
        printf("4 is even\n");
    else
        printf("4 is odd(something wrong)\n");
    if(ISEVEN_ODD(1)==1)
        printf("1 is even(something wrong)\n");
    else
        printf("1 is odd\n");
    
    printf("\nMacro:8 \n");
    int* var= NULL;
    var = MALLOC(5, int);

    printf("The address of var is %p\n", var);
    
    return 0;

}
