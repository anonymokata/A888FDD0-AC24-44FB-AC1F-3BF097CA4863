#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "../include/inputValidator.h"
#include "../include/regexMatcher.h"
#include "../include/romanNumeralCalculator.h"

int hasInvalidCharacters(const char *numeral){
  if(strlen(numeral) == 0){
    return true;
  }

  char *regex = "[^MDCLXVI]";

  return doesStringMatchRegex(regex, numeral); 
}

int hasMoreThanSingleOccurrence(const char *numeral){
  char *regex = "D.*D|L.*L|V.*V";

  return doesStringMatchRegex(regex, numeral);
}

int hasMoreThanThreeOccurrences(const char *numeral){
  char *regex = "MMMM|CCCC|XXXX|IIII";

  return doesStringMatchRegex(regex, numeral);
}

int validateInputs(const char *firstNumeral, const char *secondNumeral){
  if(firstNumeral == NULL || secondNumeral == NULL){
    return NULL_VALUE_INPUTS;
  }

  if(hasInvalidCharacters(firstNumeral) || hasInvalidCharacters(secondNumeral)){
    return INVALID_CHARS;
  }

  if(hasMoreThanSingleOccurrence(firstNumeral) || hasMoreThanSingleOccurrence(secondNumeral)){
    return SINGLE_CHARS_EXCEEDED;
  }

  if(hasMoreThanThreeOccurrences(firstNumeral) || hasMoreThanThreeOccurrences(secondNumeral)){
    return EXCEEDED_MAX_SEQ_CHARS;
  }

  return EXIT_SUCCESS;
}

int validateResultParam(const char *result){
  if(result == NULL){
    return NULL_VALUE_RESULT_PARAM;
  }

  return EXIT_SUCCESS;
}

int validateOperationInput(const char *operation){
  if(operation == NULL){
    return INVALID_OPERATION;
  }
  
  if(strcmp(operation, "add") != 0 && strcmp(operation, "sub") != 0){
    return INVALID_OPERATION;
  }

  return EXIT_SUCCESS;
}
