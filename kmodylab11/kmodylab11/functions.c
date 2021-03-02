/**************************
 *Kevin Mody                                
 *CPSC2310 Fall 2020 Sec 001            
 *UserName: kmody                               
 *Instructor:  Dr. Yvon Feaster  
*************************/

#include<stdio.h>
#include<stdlib.h>
#include "functions.h"
#include <stdbool.h>

int** readFile(FILE* fp, int *size)
{
    fscanf(fp, "%d", size);
    int num = *size;
    int index = 0;
    
    int** mat = (int**)malloc(num * sizeof(int*));
    for(index = 0; index < num; index++)
        mat[index] = (int*)malloc(num * sizeof(int)); 

    int row = 0; 
    int col = 0;
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            fscanf(fp, "%d", &mat[row][col]);
        }
    }
    return mat;
}


void printMatrix (int** mat, int num)
{
    int row = 0; 
    int col = 0;
    for(row = 0; row < num; row++)
    {
        for(col = 0; col < num; col++)
        {
            printf("%.2d\t", mat[row][col]);
        }
        printf("\n");
    }
    
}
int calculateVal(int** mat, int size){
    int sum = 0;
    int row, col;
    for(row = 0; row<size; row++){
        for(col = 0; col<size;col++){
            if(!isLeftDiagonal(row,col)&&!isRightDiagonal(size,row,col)){
                sum = sum + mat[row][col];
		}
	}	
	}
	return sum;
} 
bool isRightDiagonal(int size, int row, int col){
    return ((size - 1)-row == col ? true: false);
}
bool isLeftDiagonal(int row, int col){
    return (row == col ? true : false);
}
