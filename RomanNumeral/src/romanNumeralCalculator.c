#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/romanNumeralCalculator.h"
#include "../include/romanNumeralToIntConverter.h"

#define MAX_NUMERAL_VALUE 3999
#define MIN_NUMERAL_VALUE 1

int calculateResultInDecimalFormat(const char *op, const char *firstRomanNumeral, const char *secondRomanNumeral){
  int convertedFirstNumber, convertedSecondNumber, resultingNumber;

  convertedFirstNumber = convertRomanNumeralsToInt(firstRomanNumeral);
  convertedSecondNumber = convertRomanNumeralsToInt(secondRomanNumeral);

  if(strcmp("sub", op) == 0){
    resultingNumber = convertedFirstNumber - convertedSecondNumber;
  } else {
    resultingNumber = convertedFirstNumber + convertedSecondNumber;
  }

  return resultingNumber;
}

int calculate(char *result, const char *op, const char *firstRomanNumeral, const char *secondRomanNumeral){

  int validationStatus = validateInputs(firstRomanNumeral, secondRomanNumeral);
  if(validationStatus){
    return validationStatus;
  }

  int resultingNumber = calculateResultInDecimalFormat(op, firstRomanNumeral, secondRomanNumeral);

  if(resultingNumber < MIN_NUMERAL_VALUE){
    return BENEATH_MIN_RESULT;
  } 

  if(resultingNumber > MAX_NUMERAL_VALUE){
    return EXCEEDED_MAX_RESULT;
  }

  convertIntToRomanNumerals(result, resultingNumber);
  return EXIT_SUCCESS;
}
