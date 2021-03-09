/**************************
 *KEVIN MODY                                
 *CPSC2310 Lab7                         
 *UserName: kmody                              
 *Lab Section: 002                            
/*************************/


#include<stdio.h>

int main()
{
    /*Fill in a C expression that evaluates to 1 when the follow conditions are
     *true and to 0 when they are false.  Assume the value is of type int. 
     *Your code MUST follow the Rules described in the lab document. With the
     *additional restriction that you may not use equality (==) or inequality
     *(!=) test. */
    
    //Part A:  
    printf("1.\n");
    int a = 0;//!!a
    printf("prints 1 when any bit of a number equals 1 %d\n", !!a/*YOUR EXPRESSION GOES HERE*/ );
    a = 1;//!!a
    printf("prints 1 when any bit of a number equals 1 %d\n",!!a /*YOUR EXPRESSION GOES HERE*/ );

    //Part B:
    printf("\n2.\n");
    int b = -1;//!!~b
    printf("prints 1 when any bit of a number equals 0 %d\n", !!~b /*YOUR EXPRESSION GOES HERE*/);
    b = 1;//!!~b
    printf("prints 1 when any bit of a number equals 0 %d\n", !!~b/*YOUR EXPRESSION GOES HERE*/);

    //Part C:
    printf("\n3.\n");
    int c = 1;//!!(c & 0xFF)
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n", !!(c & 0xFF)/*YOUR EXPRESSION GOES HERE*/ );
    c = 0;//!!(c & 0xFF)
    printf("prints 1 when any bit in the least significant byte of c equals 1 %d\n", !!(c & 0xFF)/*YOUR EXPRESSION GOES HERE */);

    //Part D;
    printf("\n4.\n");
    int d = -1;//(~d & 0xFF)
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", !!(~d & 0xFF)/*YOUR EXPRESSION GOES HERE*/ );
    d = 0;
    printf("prints 1 when any bit in the most significant byte of d equals 0 %d\n", !!(~d & 0xFF)/*YOUR EXPRESSION GOES HERE*/ );

    return 0;
}
