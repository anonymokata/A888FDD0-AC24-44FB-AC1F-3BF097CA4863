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

START_TEST(convertToInt_V_to_5){
  char one[1] = "V";

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(5, result);
}
END_TEST

Suite* convertToIntSuite(void){
  Suite *su;
  TCase *tcase;

  su = suite_create("ConvertToInt");
  tcase = tcase_create("convert");

  tcase_add_test(tcase, convertToInt_I_to_1);
  tcase_add_test(tcase, convertToInt_V_to_5);

  suite_add_tcase(su, tcase);

  return su;
}

