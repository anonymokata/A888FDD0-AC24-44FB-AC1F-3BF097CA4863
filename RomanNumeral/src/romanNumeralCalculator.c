#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/romanNumeralCalculator.h"
#include "../include/romanNumeralToIntConverter.h"

void calculate(char *result, char *op, char *first, char *sec){
  int firstNum, secNum;

  firstNum = convertRomanNumeralsToInt(first);
  secNum = convertRomanNumeralsToInt(sec);

  convertIntToRomanNumerals(result, firstNum + secNum);
}
