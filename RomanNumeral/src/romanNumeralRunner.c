#include <stdio.h>
#include <stdlib.h>

#include "../include/inputValidator.h"
#include "../include/romanNumeralCalculator.h"


void printExceptionMessageBasedOnStatus(int status){
  if(status == BENEATH_MIN_RESULT){
    printf("Invalid number less than 1\n");
  } else if(status == EXCEEDED_MAX_RESULT){
    printf("Invalid number greater than 3999\n");
  } else if(status == INVALID_CHARS){
    printf("Roman Numerals can only be comprised of the following characters: M,D,C,L,X,V,I\n");
  } else if(status == SINGLE_CHARS_EXCEEDED){
    printf("Roman Numerals can only contain one occurrence of the characters: D,L,V\n");
  } else if(status == EXCEEDED_MAX_SEQ_CHARS){
    printf("Roman Numerals can only contain three occurrences of the characters: C,X,I\n");
  }
}

int main(int argc, char *argv[]){
  int status = -1;

  char result[100];
  if(argc == 4) {
    status = calculate(result, argv[1], argv[2], argv[3]);
  }
  
  if(status == 0){
    printf("Result: %s\n", result);
  } else {
    printExceptionMessageBasedOnStatus(status);
  }

  printf("\nUsage: romanNumeral [operation] [romanNumeral] [romanNumeral]\n");
  printf("Operations: add, sub \n\n");
  return (status == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
