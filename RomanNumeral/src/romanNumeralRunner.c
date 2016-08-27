#include <stdio.h>


int main(int argc, char *argv[]){

  if(argc == 2 && strcmp("tests", argv[1]) == 0){
    printf("Running Tests\n");
    return runAllTests();
  }

  if(argc == 4) {
    char result[25];
    calculate(result, argv[1], argv[2], argv[3]);
    printf("Result: %s\n", result);
  }

  return 0;
}
