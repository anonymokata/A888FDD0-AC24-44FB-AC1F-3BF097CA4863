#include <stdlib.h>
#include <string.h>

void convertIntToRomanNumerals(char *romanNumerals, int value){
  int len = 0;

  if(value == 1000){
    romanNumerals[len] = 'M';
  } else if(value == 500){
    romanNumerals[len] = 'D';
  }

  len++;
  romanNumerals[len] = '\0';
}
