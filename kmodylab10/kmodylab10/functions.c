/**************************
 *Kevin Mody                                
 *CPSC2310 Fall2020 Sec: 001     
 *UserName: kmody                              
 *Instructor:  Dr. Yvon Feaster  
*************************/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
int printReturn( int a, int b, int action){
   
    return( action == 1 ? a==b      
    :action == 2 ? a < b     
    :action == 3 ? a > b      
    :-50000);

    

}
