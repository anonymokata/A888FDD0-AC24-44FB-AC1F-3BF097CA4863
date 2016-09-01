#include <stdlib.h>
#include <string.h>

typedef struct numeralValues numeralValues;

struct numeralValues {
  char *numeral;
  int value;
};

void convertIntToRomanNumerals(char *romanNumerals, int value){
  numeralValues numerals[] = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};

  int index = 0;
  while(value > 0){
    if(value >= numerals[index].value){
      strcat(romanNumerals, numerals[index].numeral);
      value = value - numerals[index].value;
    } else {
      index++;
    }
  }
}
