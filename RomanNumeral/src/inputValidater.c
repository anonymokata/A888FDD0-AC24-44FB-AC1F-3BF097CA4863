#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "../include/inputValidater.h"

int hasValidCharacters(char *numeral){
  char validChars[3] = {'M', 'D', 'C'};
  
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

int validateInputs(char *invalidMsg, char *firstNumeral, char *secondNumeral){
  if(!hasValidCharacters(firstNumeral)){
    return 0;
  }

  return 1;
}
