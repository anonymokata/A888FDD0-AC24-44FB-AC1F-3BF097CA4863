#include <stdlib.h>
#include <check.h>
#include <stdio.h>

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

START_TEST(calculateRomanNumerals_V_mul_V){
  char romanNumerals[25];

  calculate(romanNumerals, "mul", "V", "V");
  ck_assert_str_eq("XXV", romanNumerals);
}
END_TEST

START_TEST(calculateRomanNumerals_V_div_II){
  char romanNumerals[25];

  calculate(romanNumerals, "div", "V", "II");
  ck_assert_str_eq("II", romanNumerals);
}
END_TEST

Suite* romanNumeralCalculatorSuite(void){
  Suite *su;
  TCase *tcase;

  su = suite_create("Roman Numeral Calculator");
  
  tcase = tcase_create("Add Roman Numerals");
  tcase_add_test(tcase, calculateRomanNumerals_II_plus_II);
  tcase_add_test(tcase, calculateRomanNumerals_V_sub_I);
  tcase_add_test(tcase, calculateRomanNumerals_V_mul_V);
  tcase_add_test(tcase, calculateRomanNumerals_V_div_II);

  suite_add_tcase(su, tcase);

  return su;
}
