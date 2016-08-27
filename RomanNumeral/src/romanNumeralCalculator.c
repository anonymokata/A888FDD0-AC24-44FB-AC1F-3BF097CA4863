#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/romanNumeralCalculator.h"
#include "../include/romanNumeralToIntConverter.h"

void calculate(char *result, char *op, char *first, char *sec){
  int firstNum, secNum;

  firstNum = convertRomanNumeralsToInt(first);
  secNum = convertRomanNumeralsToInt(sec);

  int resultNum;
  if(strcmp("add", op) == 0){
    resultNum = firstNum + secNum;
  } else if(strcmp("sub", op) == 0){
    resultNum = firstNum - secNum;
  } else if(strcmp("mul", op) == 0){
    resultNum = firstNum * secNum;
  }

  convertIntToRomanNumerals(result, resultNum);
}
