/**************************
 *KEVIN MODY
 *CPSC2310 FALL 2020
 *Lab Section: 001
 *UserName: kmody              
 *Instructor:  Dr. Yvon Feaster  
 *************************/
#include <stdio.h>
#include <limits.h>
#include "functions.h"
#include <stdint.h>
#include <stdbool.h>

int main(void){
  //multiplier variable which is int
  int multiplier;
  //multiplicand variable which is int
  int multiplicand;
  //unsigned int variables
  uint8_t carry = 0;
  uint8_t accumulator = 0;
  //addresses of multiplicand and multiplier form the input
  Userinput(&multiplicand, &multiplier);
  //casting multiplicand and multiplier to be of type uint8_t
  uint8_t M = (uint8_t)multiplicand;
  uint8_t Q = (uint8_t)multiplier;
  //Q is getting copied for each print steps
  uint8_t Qcopy = Q;
  //Printing the values by passing it
  printSteps(&carry, &accumulator, &M, &Q);
  //terminal summary mulitplication
  checkMultiplication(&M, &Qcopy);
}
