/**************************
 *KEVIN MODY
 *CPSC2310 FALL 2020
 *Lab Section: 001
 *UserName: kmody              
 *Instructor:  Dr. Yvon Feaster  
 *************************/

#include <stdio.h>
#include "functions.h"

//User input for the multiplicand
//Checking to see if the multiplicand is withing the parameters
//User input for the multiplier
//Checking to see if the multiplier is withing the parameters
void Userinput(int* multiplicand, int* multiplier)
{
  printf("Enter multiplicand: ");
  scanf(" %d", multiplicand);
  CheckMultiplicand(multiplicand);
  printf("Enter multiplier: ");
  scanf(" %d", multiplier);
  CheckMultiplier(multiplier);
}

//If the user entered a number that is not between 0 and 255 inclusive and
//Error message on termianl to the user and ask for a valid multiplicand value which are in bounds
//ask user for multiplicand
void CheckMultiplicand(int* multiplicand)
{
  while(*multiplicand < 0 || *multiplicand > 255)
  {
    printf("The integer %d needs to be between 0 and 255 (both inclusive)" , *multiplicand);
    printf("\nEnter Multiplicand: ");
    scanf(" %d", multiplicand);
  }
}
//If the user entered a number that is not between 0 and 255 inclusive
//Error message to the user and ask for a valid multiplier value
//Asks the user for a different multiplier value
void CheckMultiplier(int* multiplier)
{ 
  while(*multiplier < 0 || *multiplier > 255)
  {
    printf("The integer %d needs to be between 0 and 255 in the bounds", *multiplier);
    printf("\nEnter Multiplier: ");
    scanf(" %d", multiplier);
  }
}

//Prints the decimal value inside parentheses of the multiplicand
void printDecimalValuesParen(uint8_t multiplier)
{
  printf(" (%u)", multiplier);
}

//Prints the decimal value inside parentheses of the multiplier
void printDecimals(uint8_t multiplier)
{
  printf("%u", multiplier);
}

//prints the binary representation of the mulitplier 
void printBinarys(uint8_t multiplier)
{
  int Bits[8] = {0};
  int counter = 0;
  while(multiplier != 0)
  {
    Bits[counter] = multiplier & 1;
    multiplier = multiplier >> 1;
    counter++;
  }
  for(int i = 7; i >= 0; i--)
  {
    printf("%d", Bits[i]);
  }
}
//unisigned int to hold the carry if overflow
//incrementing the counter while multiplier is not equal to 0
//Incrementing the counter and checks to see if there is an overflow because it can only holds 9 bits
bool bitOverflow(unsigned int multiplier)
{
  int Bits[9] = {0};
  int counter = 0;
  while(multiplier != 0){
    Bits[counter] = multiplier & 1;
    multiplier = multiplier >> 1;
    
    counter++;
  }
  return Bits[8] == 1;
}
//Least significant bit is the 1st bit in the integer array for the bits
int leastBit(uint8_t multiplier){
  int Bits[8] = {0};
  int counter = 0;
  while(multiplier != 0){
    Bits[counter] = multiplier & 1;
    multiplier = multiplier >> 1;
    counter++;
  }
  return Bits[0];
}
//prints the carry, accumulator(ACC), multiplicand, multiplier all that information like the format from the word doc.
//also prints the table with steps
void printSteps(uint8_t* carry, uint8_t* accumulator, uint8_t* multiplicand, uint8_t* multiplier)
{
  printf("\nM = multiplicand = ");
  printDecimals(*multiplicand);
  printf("\nQ = multiplier = ");
  printDecimals(*multiplier);
  printf("\nC = carry = %u\nACC = accumulator = %u\n", *carry, *accumulator);
  printf("\nStep 0: \tInitialize the data M = ");
  printBinarys(*multiplicand);
  printDecimalValuesParen(*multiplicand);
  printf(" C = %u ACC = %u Q = ", *carry, *accumulator);
  printBinarys(*multiplier);
  printDecimalValuesParen(*multiplier);
  printf("\n");

  int counter = 0;
  while(counter < 8){
    printf("\n\tC\tACC\t\tQ\n");
    printf("Step %d: %u\t", (counter+1), *carry);
    printBinarys(*accumulator);
    printf("\t");
    printBinarys(*multiplier);
    printf("\n");
    int leastSigBit = leastBit(*multiplier);
    if(leastSigBit == 1)
    {
      printf("\t\t\t\t       -");
      printf("\n\t      + ");
      printBinarys(*multiplicand);
      printf("\t\t  lsb = %d add M to the ACC", leastSigBit);
      printf("\n\t        --------\n");
      unsigned int var = *accumulator + *multiplicand;
      
      printf("%d",var);
      *accumulator = *accumulator + *multiplicand;
      
      //Checking accumulator by calling overflow funciton and casting to var to check if there is a carry
      if(bitOverflow(var))
      {
        *carry = 1;
      }
      printf("\t%u\t", *carry);
      printBinarys(*accumulator);
      printf("\t");
      printBinarys(*multiplier);
      printf("\n\t\t\t\t\t  Shift >> 1\n");
      if((*accumulator & 1) == 1)
      {
        *multiplier = *multiplier >> 1;
        *multiplier = *multiplier|(0x80);
      }
      else
      {
        *multiplier = *multiplier >> 1;
      }
      *accumulator = *accumulator >> 1;
      printf("\t%u\t", *carry);
      printBinarys(*accumulator);
      printf("\t");
      printBinarys(*multiplier);
    }
    else
    {
      //else statement if the leastSigBit = 0
      printf("\t\t\t\t       -");
      printf("\n\t      + ");
      printBinarys(0);
      printf("\t\t  lsb = %d add M to the ACC", leastSigBit);
      printf("\n\t        --------\n");
      printf("\t%u\t", *carry);
      printBinarys(*accumulator);
      printf("\t");
      printBinarys(*multiplier);
      printf("\n\t\t\t\t\t  Shift >> 1\n");
      if((*accumulator&1)==1)
      {
        *multiplier = *multiplier >> 1;
        *multiplier = *multiplier|(0x80);
      }
      else
      {
        *multiplier = *multiplier >> 1;
      }
      *accumulator = *accumulator >> 1;
      printf("\t%u\t", *carry);
      printBinarys(*accumulator);
      printf("\t");
      printBinarys(*multiplier);
    }
    printf("\n");
    counter++;
  }
}

//printing the summary at the terminal 
void checkMultiplication(uint8_t* multiplicand, uint8_t* multiplier){
  uint8_t product = *multiplicand*(*multiplier);
  printf("\nMultiplication summary:\n%u (Multiplicand) * %u (Multiplier) = %u",*multiplicand, *multiplier, product);

  printf("\n");
  printBinarys(*multiplicand);
  printf(" (Multiplicand) * ");
  printBinarys(*multiplier);
  printf(" (Multiplier) = ");
  printBinarys(product);
  printf("\n");
}
//end