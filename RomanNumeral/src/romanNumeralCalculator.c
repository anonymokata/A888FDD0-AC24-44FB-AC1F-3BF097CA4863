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
  if(strcmp("sub", op) == 0){
    resultNum = firstNum - secNum;
  } else if(strcmp("mul", op) == 0){
    resultNum = firstNum * secNum;
  } else if(strcmp("div", op) == 0){
    resultNum = firstNum / secNum;
  } else {
    resultNum = firstNum + secNum;
  }

  if(resultNum < 1){
    strcpy(result, "Invalid number less than one");
    printf("Should Be Zero: %s\n", result);
    return;
  }

  convertIntToRomanNumerals(result, resultNum);
}
