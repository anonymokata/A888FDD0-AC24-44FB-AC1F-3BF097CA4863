#include <stdlib.h>
#include <check.h>

#include "../include/inputValidator.h"
#include "../include/romanNumeralCalculator.h"

START_TEST(calculateRomanNumerals_II_plus_II){
  char romanNumerals[25];

  calculate(romanNumerals, "add", "II", "II");
  ck_assert_str_eq("IV", romanNumerals);
}
END_TEST

START_TEST(calculateRomanNumerals_V_sub_I){
  char romanNumerals[25];

  calculate(romanNumerals, "sub", "V", "I");
  ck_assert_str_eq("IV", romanNumerals);
}
END_TEST

START_TEST(calculateRomanNumerals_less_than_1){
  char romanNumerals[25];

  int status = calculate(romanNumerals, "sub", "II", "II");
  ck_assert_int_eq(BENEATH_MIN_RESULT, status);
}
END_TEST

START_TEST(calculateRomanNumerals_greater_than_3999){
  char romanNumerals[25];

  int status = calculate(romanNumerals, "add", "MMMCMXCIX", "MMMCMXCIX");
  ck_assert_int_eq(EXCEEDED_MAX_RESULT, status);
}
END_TEST

START_TEST(calculateRomanNumerals_uses_validation){
  char romanNumerals[101];

  int status = calculate(romanNumerals, "add", "ABC", "I");
  ck_assert_int_eq(INVALID_CHARS, status);
}
END_TEST

Suite* romanNumeralCalculatorSuite(void){
  Suite *su;
  TCase *tcase;

  su = suite_create("Roman Numeral Calculator");
  
  tcase = tcase_create("Add Roman Numerals");
  tcase_add_test(tcase, calculateRomanNumerals_II_plus_II);
  tcase_add_test(tcase, calculateRomanNumerals_V_sub_I);
  tcase_add_test(tcase, calculateRomanNumerals_less_than_1);
  tcase_add_test(tcase, calculateRomanNumerals_greater_than_3999);
  tcase_add_test(tcase, calculateRomanNumerals_uses_validation);

  suite_add_tcase(su, tcase);

  return su;
}
