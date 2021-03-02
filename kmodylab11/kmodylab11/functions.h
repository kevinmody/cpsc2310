/**************************
 *Kevin Mody                                
 *CPSC2310 Fall 2020 Sec 001            
 *UserName: kmody                               
 *Instructor:  Dr. Yvon Feaster  
*************************/

#include <stdbool.h>

int** readFile(FILE* fp, int *size);
void printMatrix (int** mat, int num);
int calculateVal(int** mat, int size); 
bool isRightDiagonal(int size, int row, int col); 
bool isLeftDiagonal(int row, int col); 
