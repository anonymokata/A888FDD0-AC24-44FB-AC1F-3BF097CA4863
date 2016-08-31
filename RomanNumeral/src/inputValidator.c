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
    strcpy(invalidMsg, "Roman Numerals can only be comprised of the following characters: M,D,C,L,X,V,I");
    return 0;
  }

  if(hasMoreThanSingleOccurrence(firstNumeral) || hasMoreThanSingleOccurrence(secondNumeral)){
    strcpy(invalidMsg, "Roman Numerals can only contain one occurrence of the characters: D,L,V");
    return 0;
  }

  if(hasMoreThanThreeOccurrences(firstNumeral) || hasMoreThanThreeOccurrences(secondNumeral)){
    strcpy(invalidMsg, "Roman Numerals can only contain three occurrences of the characters: C,X,I");
    return 0;
  }

  return 1;
}
