#include <stdlib.h>
#include <regex.h>

#include "../include/regexMatcher.h"

int doesStringMatchRegex(char *regExp, char *word){
  regex_t regex;
  
  regcomp (&regex, regExp, REG_NOSUB|REG_EXTENDED);

  int result;
  result = regexec(&regex, word, 0, NULL, 0);
  regfree(&regex);
  
  if(result == 0){
    return EXIT_SUCCESS;
  }

  return EXIT_FAILURE;
}
