#include <stdlib.h>
#include <check.h>

#include "../include/tests/romanNumeralRunner_test.h"
#include "../include/tests/inputValidator_test.h"
#include "../include/tests/intToRomanNumeralConverter_test.h"
#include "../include/tests/romanNumeralToIntConverter_test.h"
#include "../include/tests/romanNumeralCalculator_test.h"
#include "../include/tests/regexMatcher_test.h"

int main(void){
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

  Suite *inputValid;
  inputValid = validateInputSuite();
  srunner_add_suite(sr, inputValid);

  Suite *regex;
  regex = regexMatchingSuite();
  srunner_add_suite(sr, regex);

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
