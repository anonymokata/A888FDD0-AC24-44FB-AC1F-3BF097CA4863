#include <stdlib.h>
#include <check.h>

#include "../include/romanNumeralRunner_test.h"

int runAllTests(void){
  int numberFailed;

  Suite *convertToNumeral;
  SRunner *sr;

  convertToNumeral = convertToRomanNumeralSuite();
  sr = srunner_create(convertToNumeral);
 
  Suite *convertToInt;
  convertToInt = convertToIntSuite();
  srunner_add_suite(sr, convertToInt);

  Suite *calc;
  calc = romanNumeralCalculatorSuite();
  srunner_add_suite(sr, calc);

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
