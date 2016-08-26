#include <stdlib.h>
#include <check.h>

#include "../include/intToRomanNumeralConverter_test.h"

START_TEST(convertToChar_1000_to_M){
  char romanNumerals[25];

  convertIntToRomanNumerals(romanNumerals, 1000);
  ck_assert_str_eq("M", romanNumerals);
}
END_TEST

START_TEST(convertToChar_500_to_D){
  char romanNumerals[25];

  convertIntToRomanNumerals(romanNumerals, 500);
  ck_assert_str_eq("D", romanNumerals);
}
END_TEST

START_TEST(convertToChar_100_to_C){
  char romanNumerals[25];

  convertIntToRomanNumerals(romanNumerals, 100);
  ck_assert_str_eq("C", romanNumerals);
}
END_TEST

START_TEST(convertToChar_50_to_L){
  char romanNumerals[25];

  convertIntToRomanNumerals(romanNumerals, 50);
  ck_assert_str_eq("L", romanNumerals);
}
END_TEST

Suite* convertToRomanNumeralSuite(void){
  Suite *su;
  TCase *tcase;

  su = suite_create("Convert Int To Roman Numeral");
  
  tcase = tcase_create("Convert Single Character");
  tcase_add_test(tcase, convertToChar_1000_to_M);
  tcase_add_test(tcase, convertToChar_500_to_D);
  tcase_add_test(tcase, convertToChar_100_to_C);
  tcase_add_test(tcase, convertToChar_50_to_L);
  
  suite_add_tcase(su, tcase);

  return su;
}
