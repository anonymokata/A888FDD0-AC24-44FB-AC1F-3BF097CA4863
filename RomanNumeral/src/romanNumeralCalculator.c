#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../include/romanNumeralCalculator.h"
#include "../include/romanNumeralToIntConverter.h"
#include "../include/inputValidator.h"

int calculate(char *result, char *op, char *firstRomanNumeral, char *secondRomanNumeral){

  int validationStatus = validateInputs(firstRomanNumeral, secondRomanNumeral);
  if(validationStatus){
    return validationStatus;
  }

  int convertedFirstNumber, convertedSecondNumber, resultingNumber;

  convertedFirstNumber = convertRomanNumeralsToInt(firstRomanNumeral);
  convertedSecondNumber = convertRomanNumeralsToInt(secondRomanNumeral);

  if(strcmp("sub", op) == 0){
    resultingNumber = convertedFirstNumber - convertedSecondNumber;
  } else {
    resultingNumber = convertedFirstNumber + convertedSecondNumber;
  }

  if(resultingNumber < 1){
    return BENEATH_MIN_RESULT;
  } 

  if(resultingNumber > 3999){
    return EXCEEDED_MAX_RESULT;
  }

  convertIntToRomanNumerals(result, resultingNumber);
  return EXIT_SUCCESS;
}
