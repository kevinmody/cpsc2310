/**************************
 *Kevin Mody                                
 *CPSC2310 Sec: 001     
 *UserName: kmody                              
 *Instructor:  Dr. Yvon Feaster  
*************************/

#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


void checkArg(int argc){
    //This function ensures the number of command line arguments is appropriate.
    //There are 3 argument in int argc, example: ./a.out input.txt output.txt
    if (argc != 3){
        printf("usage: ./a.out <filename> <filename>\n");
        exit(0);
    }
    
}

void checkFile(FILE *fp){
    //This function determines whether the file opened successfully. If the file does not open successfully you must print to stderr a statement that prints the following: 
    //fopen() failed in file (a file name is printed here) at line #(the line number is printed here), of function (the name of the function is printed here). 
    //__FILE__ : This macro expands to the name of the current input file, in the form of a C string constant. 
    //This is the path by which the preprocessor opened the file, not the short name specified in ‘#include’ or as the input file name argument. 
    //__LINE__ : This macro expands to the current input line number, in the form of a decimal integer constant. 
    //While we call it a predefined macro, it’s a pretty strange macro, since its “definition” changes with each new line of source code.
    //C99 (the most recent version of the C language, at the time of writing) introduced another macro called __func__ which also names the function in use: checkFile(fp)
    //resources: https://gcc.gnu.org/onlinedocs/cpp/Standard-Predefined-Macros.html
    if(fp==NULL)
    {
        fprintf(stderr, "This is line %d of file \"%s\" (function <%s>)\n",__LINE__, __FILE__, __func__);
        exit(0);
    }
}
int getFileCount(FILE* fp){
    //tally will count the number of characters including spaces in the file
    char c;
    int charcount = 0;
    for(c = getc(fp); c != EOF; c = getc(fp)){
        charcount += 1;
    }
    fseek(fp, 0, SEEK_SET);
    char BUFFERSIZE[charcount];
    int count= fread(&BUFFERSIZE, sizeof(char), charcount, fp);
    return count;
}

void retFP(FILE* fp){
    //resettinng the file pointer "fp" back to the begining.
    //fseek move the file pointer to beginning in the file
        long pos = 0;
        pos = ftell(fp);

        int val = fseek(fp, 0, SEEK_SET);
        
        if(val != 0){
            fprintf(stderr, "fseek failed\n");
            exit(-1);
        }
        else{
            pos = ftell(fp);
            fprintf(stderr,"The position of the pointer is %ld\n ", pos);
        }
   
}

void readFile(char* filechars, FILE* fp, int hold){
   //This function is used to read all of the characters in the file and store them in an array of characters
   //Dynamically allocate memory here (malloc)
   //The "filechars" is the array that you must store the information when you read the file, 
   //the "fp" is the file pointer that is pointing to the beginning of the file to be read, lastly, 
   //int "hold" the variable that holds the number of characters in the file that will be read. 
   printf("Count is: %d\n", hold);
   
    int bytes = fread(filechars, sizeof(char), hold, fp);
    if(bytes!=hold){
        fprintf(stderr, "fread failed\n");
        exit(-1);
    }
    else{
        retFP(fp);
    }
}

void ASCII(char* filechars, FILE* outfp, int hold){
    //This function will be called to print, to a file, the ascii value of each character in the file. 
    //The "filechars" is the array that holds each character in the file. The "outfp" is the pointer to the output file, and the "hold" is the count of characters in the file.
    int row = 1;
    fprintf(outfp, "ASCI: ");
    for(int i = 0;i<hold;i++){
        fprintf(outfp, "\n%d: ", row);
        for(int j = 0; j < 9; j++){
            if(filechars[i]!=0)
                fprintf(outfp, "%d ", filechars[i]);
                i++;
        }
        row++;
    }

}

void Binary(char* filechars, FILE* outfp, int hold){
    //This function will be called to print, to the output file, the binary representation of each character in the file. 
    //It also prints binary in the output file.
    fprintf(outfp, "\nBinary: ");
    for(int i = 0; i < hold; i++){
        fprintf(outfp, "\n%d: ", i);
        for(int j = 7; j >=0; j--){
            int x = filechars[i]>>j;
            if(x & 1){
                fprintf(outfp, "1 ");
            }
            else {
                fprintf(outfp, "0 ");
            }
        }
    }
    
}

void print(void (*fp)(char* filechars, FILE* fp , int hold), char* filechars, FILE* outfp , int hold){
    //calls the ascii and binary functions, and prints in output.txt. This is a callback function.
    if(fp == &ASCII){
        ASCII(filechars, outfp, hold);
    }
    else{
        Binary(filechars, outfp, hold);
    }

}
