#include <stdlib.h>
#include <string.h>

int convertIntGreaterThanEqToNinety(char *romanNumerals, int value, int *lenPtr){
  int len = *lenPtr;
  int subFromVal = 0;

  if(value >= 1000){
    romanNumerals[len] = 'M';
    subFromVal = 1000;
  } else if(value >= 900){
    romanNumerals[len] = 'C';
    romanNumerals[len + 1] = 'M';
    subFromVal = 900;
    len++;
  } else if(value >= 500){
    romanNumerals[len] = 'D';
    subFromVal = 500;
  } else if(value >= 400){
    romanNumerals[len] = 'C';
    romanNumerals[len + 1] = 'D';
    subFromVal = 400;
    len++;
  } else if(value >= 100){
    romanNumerals[len] = 'C';
    subFromVal = 100;
  } else{
    romanNumerals[len] = 'X';
    romanNumerals[len + 1] = 'C';
    subFromVal = 90;
    len++;
  }

  //len++;
  *lenPtr = len + 1;
 
  return subFromVal;
}

int convertIntGreaterThanEqToFive(char *romanNumerals, int value, int *lenPtr){
  int len = *lenPtr;
  int subFromVal = 0;

  if(value >= 50){
    romanNumerals[len] = 'L';
    subFromVal = 50;
  } else if(value >= 10){
    romanNumerals[len] = 'X';
    subFromVal = 10;
  } else if(value >= 5){
    romanNumerals[len] = 'V';
    subFromVal = 5;
  }

  //len++;
  *lenPtr = len + 1;

  return subFromVal;
}

void convertIntToRomanNumerals(char *romanNumerals, int value){
  int len = 0;

  while(value > 0){
    if(value >= 90){
      value -= convertIntGreaterThanEqToNinety(romanNumerals, value, &len);
    } else if(value >= 5){
      value -= convertIntGreaterThanEqToFive(romanNumerals, value, &len);
    } else {
      romanNumerals[len] = 'I';
      value -= 1;
      len++;
    }
    
  }

  romanNumerals[len] = '\0';
}
