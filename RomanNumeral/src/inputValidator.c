#include <stdlib.h>
#include <string.h>

#include "../include/inputValidator.h"
#include "../include/regexMatcher.h"

int hasInvalidCharacters(char *numeral){
  char *regex = "[^MDCLXVI]";

  return doesStringMatchRegex(regex, numeral); 
}

int hasMoreThanSingleOccurrence(char *numeral){
  char *regex = "D.*D|L.*L|V.*V";

  return doesStringMatchRegex(regex, numeral);
}

int hasMoreThanThreeOccurrences(char *numeral){
  char *regex = "MMMM|CCCC|XXXX|IIII";

  return doesStringMatchRegex(regex, numeral);
}

int validateInputs(char *invalidMsg, char *firstNumeral, char *secondNumeral){

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
