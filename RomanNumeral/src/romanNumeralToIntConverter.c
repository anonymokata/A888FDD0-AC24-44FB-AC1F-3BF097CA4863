#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/romanNumeralToIntConverter.h"

int determineValueOfRomanNumeral(char numeral){
  
  if(numeral == 'V'){
    return 5;
  } else if(numeral == 'X'){
    return 10;
  } else if(numeral == 'L'){
    return 50;
  } else if(numeral == 'C'){
    return 100;
  } else if(numeral == 'D'){
    return 500;
  } else if(numeral == 'M'){
    return 1000;
  }
  
  return 1;
}

int convertRomanNumeralsToInt(char romanNumerals[]){
  int value = 0;
  int numeralLen = strlen(romanNumerals);

  int prevVal = 0;
  int i = numeralLen - 1;
  for(i ; i >= 0; i--){
    int currVal = determineValueOfRomanNumeral(romanNumerals[i]);
    
    if(currVal < prevVal){
      value -= currVal;
    } else {
      value += currVal;
    }
   
    prevVal = currVal;
  }

  return value;
}
