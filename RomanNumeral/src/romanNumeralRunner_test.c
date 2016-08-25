#include <stdlib.h>
#include <check.h>
#include <stdio.h>

#include "../include/hellomake.h"
#include "../include/romanNumeralRunner_test.h"

START_TEST(testHelloMake){
  myPrintHelloMake();
  ck_assert_int_eq(5,5);
}
END_TEST

Suite * helloSuite(void){
  Suite *s;
  TCase *tcase;

  s = suite_create("helloMake");
  tcase = tcase_create("case");
  tcase_add_test(tcase, testHelloMake);
  suite_add_tcase(s, tcase);

  return s;
}

int runAllTests(void){
  int numberFailed;

  Suite *s;
  SRunner *sr;

  s = helloSuite();
  sr = srunner_create(s);
 
  Suite *convertToInt;
  convertToInt = convertToIntSuite();
  srunner_add_suite(sr, convertToInt);

  srunner_run_all(sr, CK_NORMAL);
  numberFailed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (numberFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
