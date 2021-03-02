/**************************
 *Kevin Mody                                
 *CPSC2310 Fall 2020 Sec 001            
 *UserName: kmody                               
 *Instructor:  Dr. Yvon Feaster  
*************************/

#include <stdio.h> 
#include <stdlib.h>
#include "functions.h"
#include <stdbool.h>
int main(int argc, char** argv)
{
    printf("cheking command line arguments\n");
    if (argc < 2) 
    { 
        printf("not enought argument: ./exe filename\n"); 
        exit(-1);
    }

    FILE* fp = fopen(argv[1], "r");
    if(fp==NULL)
    {
        printf("fp did into open\n"); 
        exit(-1);
    }
    int size = 0;
    int **mat = readFile(fp, &size);
    printMatrix(mat, size);
    int total = calculateVal(mat, size);
    printf("Total = %d\n", total);
    return 0;
}
