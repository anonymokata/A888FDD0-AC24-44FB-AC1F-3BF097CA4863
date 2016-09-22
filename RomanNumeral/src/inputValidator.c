#include <stdlib.h>
#include <string.h>

#include "../include/inputValidator.h"
#include "../include/regexMatcher.h"
#include "../include/romanNumeralCalculator.h"

int hasInvalidCharacters(const char *numeral){
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
