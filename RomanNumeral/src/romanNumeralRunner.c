#include <stdio.h>

int main(int argc, char *argv[]){

  if(argc == 2 && strcmp("tests", argv[1]) == 0){
    printf("Running Tests\n");
    return runAllTests();
  }

  printf("Should Run Real Program\n");
  return 0;
}
