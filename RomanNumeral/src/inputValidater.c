#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/inputValidater.h"

int hasValidCharacters(char *numeral){
  char validChars[7] = {'M', 'D', 'C', 'L', 'X', 'V', 'I'};
  
  int outer = 0;
  for(outer; outer < strlen(numeral); outer++){
    int isValid = 0;
    int inner = 0;

    for(inner; inner < strlen(validChars); inner++){
      if(validChars[inner] == numeral[outer]){
	isValid = 1;
	break;
      }
    }

    if(!isValid){
      return 0;
    }
  }

  return 1;
}

int hasDesiredOccurrence(char *numeral, char *charsToCnt, int *cntOfChars, int size, int desiredOccurrence){

  int outer = 0;
  for(outer; outer < strlen(numeral); outer++){
    int inner = 0;
    for(inner; inner < size; inner++){
      if(charsToCnt[inner] == numeral[outer]){
	cntOfChars[inner] = cntOfChars[inner] + 1;
      }
    }
  }

  int index = 0;
  for(index; index < size; index++){
    if(cntOfChars[index] > desiredOccurrence){
      return 0;
    }
  }

  return 1;
}

int hasSingleOccurrence(char *numeral){
  char charsToCnt[] = {'D', 'L', 'V'};
  int cntOfChars[] = {0, 0, 0};

  return hasDesiredOccurrence(numeral, charsToCnt, cntOfChars, 3, 1);
}

int validateInputs(char *invalidMsg, char *firstNumeral, char *secondNumeral){
  if(!hasValidCharacters(firstNumeral) || !hasValidCharacters(secondNumeral)){
    strcpy(invalidMsg, "Roman Numerals can only be comprised of the following characters: M,D,C,L,X,V,I");
    return 0;
  }

  if(!hasSingleOccurrence(firstNumeral) || !hasSingleOccurrence(secondNumeral)){
    strcpy(invalidMsg, "Roman Numerals can only contain one occurrence of the characters: D,L,V");
    return 0;
  }

  return 1;
}
