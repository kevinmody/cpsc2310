/**************************
 *KEVIN MODY
 *CPSC2310 FALL 2020
 *Lab Section: 001
 *UserName: kmody              
 *Instructor:  Dr. Yvon Feaster  
 *************************/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

//multiplicand* holds integer data from the multiplicand and multiplier* holds the integer data from the multiplier
//User input for the multiplicand
//Checking to see if the multiplicand is withing the parameters
//User input for the multiplier
//Checking to see if the multiplier is withing the parameters
void Userinput(int* MULTIPLICAND, int* multiplier);

//multiplicand that has been passed in from the user input
//Error message on termianl to the user and ask for a valid multiplicand value which are in bounds
//ask user for multiplicand
void CheckMultiplicand(int* MULTIPLICAND);

//multiplier that has been passed in from the user input 
//If the user entered a number that is not between 0 and 255 inclusive
//Error message to the user and ask for a valid multiplier value
//Asks the user for a different multiplier value
 
void CheckMultiplier(int* multiplier);

//it takes in the unsigned int multiplier 
//Prints the decimal value inside parentheses of the multiplicand
void printDecimalValuesParen(uint8_t multiplier);

//it takes in the unsigned int multiplier 
//Prints the decimal value inside parentheses of the multiplier
void printDecimals(uint8_t multiplier);

//Takes in the unsigned int multiplier
//prints the binary representation of the mulitplier 
void printBinarys(uint8_t multiplier);

/* it takes in the unsigned int multiplier
 * Returns the int which is the least significant bit of multiplier
 * This function uses bit manipulation to get the least
 * significant bit of multiplier.
 */
int leastBit(uint8_t multiplier);

//unisigned int to hold the carry if overflow
//incrementing the counter while multiplier is not equal to 0
//Incrementing the counter and checks to see if there is an overflow because it can only holds 9 bits
bool bitOverflow(unsigned int multiplier);

//it takes in the carry, accumulator, multiplicand, and multiplier
//prints the carry, accumulator(ACC), multiplicand, multiplier all that information like the format from the word doc.
//also prints the table with steps
void printSteps(uint8_t* carry, uint8_t* accumulator, uint8_t* multiplicand, uint8_t* multiplier);

//it takes in the unsigned int multiplicand and multiplier
//printing the summary at the terminal
void checkMultiplication(uint8_t* multiplier, uint8_t* multiplicand);

#endif
