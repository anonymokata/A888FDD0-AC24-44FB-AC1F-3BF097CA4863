#include <stdlib.h>

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
  }
  
  return 1;
}

int convertRomanNumeralsToInt(char *romanNumerals){
  int value = determineValueOfRomanNumeral(romanNumerals[0]);

  return value;
}
