#include <stdlib.h>

#include "../include/romanNumeralToIntConverter.h"

int determineValueOfRomanNumeral(char numeral){
  int numeralValue = 1;
  if(numeral == 'V'){
    numeralValue = 5;
  } else if(numeral == 'X'){
    numeralValue = 10;
  } else if(numeral == 'L'){
    numeralValue = 50;
  } else if(numeral == 'C'){
    numeralValue = 100;
  }
  
  return numeralValue;
}

int convertRomanNumeralsToInt(char *romanNumerals){
  int value = determineValueOfRomanNumeral(romanNumerals[0]);

  return value;
}
