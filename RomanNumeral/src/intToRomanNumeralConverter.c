#include <stdlib.h>
#include <string.h>

void convertIntToRomanNumerals(char *romanNumerals, int value){
  char *numerals[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
  int numVals[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  int len = 0;

  while(value > 0){
    int index = 0;
    for(index; index < sizeof(numVals); index++){
      if(value >= numVals[index]){
	if(strlen(numerals[index]) > 1) {
	  romanNumerals[len] = numerals[index][0];
	  romanNumerals[len + 1] = numerals[index][1];
	  len += 2;
	} else {
	  romanNumerals[len] = numerals[index][0];
	  len++;
	}

	value = value - numVals[index];
	break;
      }
    }
  }

  romanNumerals[len] = '\0';
}
