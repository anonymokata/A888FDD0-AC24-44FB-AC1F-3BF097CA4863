#include <stdlib.h>
#include <check.h>

#include "../include/hellomake.h"
#include "../include/romanNumeralToIntConverter_test.h"

START_TEST(convertToInt_I_to_1){
  char one[1] = "I";

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(1, result);
}
END_TEST

Suite* convertToIntSuite(void){
  Suite *su;
  TCase *tcase;

  su = suite_create("ConvertToInt");
  tcase = tcase_create("convert");
  tcase_add_test(tcase, convertToInt_I_to_1);
  suite_add_tcase(su, tcase);

  return su;
}


