/**************************
 *Kevin Mody                                
 *CPSC2310 Sec: 001     
 *UserName: kmody                              
 *Instructor:  Dr. Yvon Feaster  
*************************/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int main(int argc, char *argv[]){
    //calling the checkArg function
    checkArg(argc);
    //opening input.txt file
    FILE* fp = fopen(argv[1], "r");
    //opening output.txt file
    FILE* outfp = fopen(argv[2], "w");
    //calling the function to see print the line number, file and function error
    checkFile(fp);
    
    //holding the character from input.txt
    int hold = getFileCount(fp);
    //resetting file pointer to the begining
    retFP(fp);
    //using allocated memory to store characters into an array
    char* filechars = (char*) malloc(sizeof(char) * hold);
    
    //function is storing characters into an arrau
    readFile(filechars, fp, hold);
    void(*file)(char* , FILE*, int);

    //converting and calling the function of ascii
    file = &ASCII;
    //printing the ascii in the output.txt
    print(file, filechars, outfp , hold);

    //converting and calling the function of binary
    file = &Binary;
    //printing the binary in the output.txt
    print(file, filechars, outfp , hold);
    //close input.txt
    fclose(fp);
    //close output.txt
    fclose(outfp);
    //free filechars memory
    free(filechars);
    return 0;
}