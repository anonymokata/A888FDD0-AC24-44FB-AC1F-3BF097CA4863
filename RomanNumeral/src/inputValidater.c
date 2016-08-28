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

int hasSingleOccurence(char *numeral){
  char charsToCnt[3] = {'D', 'L', 'V'};
  int cntOfChars[3] = {0, 0, 0};

  int outer = 0;
  for(outer; outer < strlen(numeral); outer++){
    
    int inner = 0;
    for(inner; inner < sizeof(charsToCnt); inner++){
      if(charsToCnt[inner] == numeral[outer]){
	cntOfChars[inner] = cntOfChars[inner] + 1;
      }
    }
  }

  int index = 0;
  for(index; index < sizeof(cntOfChars)/sizeof(int); index++){
    if(cntOfChars[index] > 1){
      return 0;
    }
  }

  return 1;
}

int validateInputs(char *invalidMsg, char *firstNumeral, char *secondNumeral){
  if(!hasValidCharacters(firstNumeral) || !hasValidCharacters(secondNumeral)){
    strcpy(invalidMsg, "Roman Numerals can only be comprised of the following characters: M,D,C,L,X,V,I");
    return 0;
  }

  if(!hasSingleOccurence(firstNumeral) || !hasSingleOccurence(secondNumeral)){
    strcpy(invalidMsg, "Roman Numerals can only contain one occurrence of the characters: D,L,V");
    return 0;
  }

  return 1;
}
