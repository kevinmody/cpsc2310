 /**************************
 *KEVIN MODY                                
 *CPSC2310 Lab8                         
 *UserName: kmody                              
 *Lab Section: 002                            
/*************************/
#include "functions.h"

#include <stdio.h>
int main(){
    //*Question 2 code
    printf("This is the output for Question 2\n");
    int array[]={1,2,3,4};//array of 4 elements
    reverse_array(array, 4);//calling the function

    int newArray[]={1,2,3,4,5};//array of 5 elements
    reverse_array(newArray, 5);//calling the function

    for(int i =0; i < 4; i++){
        printf("%d ", array[i]);//outputs 1 2 3 4 
    }
    printf("\n");

    for(int j = 0; j < 5; j++){
        printf("%d ", newArray[j]);//outputs 5 4 3 2 1
    }
    printf("\n");


    //*Question 3 code

    printf("This is the output for Question 5\n");

    unsigned int a=0x00000076;
    int b=fun1(a);
    int c=fun2(a);
    printf("%x %x %x\n",a,b,c);//word,fun1,fun2 for 0x00000076

    a=0x87654321;
    b=fun1(a);
    c=fun2(a);
    printf("%x %x %x\n",a,b,c);//word,fun1,fun2 for 0x87654321

    a=0x000000C9;
    b=fun1(a);
    c=fun2(a);
    printf("%x %x %x\n",a,b,c);//word,fun1,fun2 for 0x000000C9

    a=0xEDCBA987;
    b=fun1(a);
    c=fun2(a);
    printf("%x %x %x\n",a,b,c);//word,fun1,fun2 for 0xEDCBA987
}