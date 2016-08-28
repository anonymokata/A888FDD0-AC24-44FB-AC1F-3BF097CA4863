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

START_TEST(calculateRomanNumerals_less_than_1){
  char romanNumerals[25];

  calculate(romanNumerals, "sub", "II", "II");
  ck_assert_str_eq("Invalid number less than 1", romanNumerals);
}
END_TEST

START_TEST(calculateRomanNumerals_greater_than_3999){
  char romanNumerals[25];

  calculate(romanNumerals, "add", "MMMCMXCIX", "MMMCMXCIX");
  ck_assert_str_eq("Invalid number greater than 3999", romanNumerals);
}
END_TEST

START_TEST(calculateRomanNumerals_uses_validation){
  char romanNumerals[100];

  calculate(romanNumerals, "add", "ABC", "I");
  ck_assert_str_eq("Roman Numerals can only be comprised of the following characters: M,D,C,L,X,V,I", romanNumerals);
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
  tcase_add_test(tcase, calculateRomanNumerals_less_than_1);
  tcase_add_test(tcase, calculateRomanNumerals_greater_than_3999);
  tcase_add_test(tcase, calculateRomanNumerals_uses_validation);

  suite_add_tcase(su, tcase);

  return su;
}
