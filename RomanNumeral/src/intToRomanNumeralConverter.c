#include <stdlib.h>
#include <string.h>

void convertIntToRomanNumerals(char *romanNumerals, int value){
  int len = 0;

  while(value > 0){
    if(value >= 1000){
      romanNumerals[len] = 'M';
      value -= 1000;
    } else if(value >= 500){
      romanNumerals[len] = 'D';
      value -= 500;
    } else if(value >= 100){
      romanNumerals[len] = 'C';
      value -= 100;
    } else if(value >= 50){
      romanNumerals[len] = 'L';
      value -= 50;
    } else if(value >= 10){
      romanNumerals[len] = 'X';
      value -= 10;
    } else if(value >= 5){
      romanNumerals[len] = 'V';
      value -= 5;
    } else {
      romanNumerals[len] = 'I';
      value -= 1;
    }
    
    len++;
  }

  romanNumerals[len] = '\0';
}
