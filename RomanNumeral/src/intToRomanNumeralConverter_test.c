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

START_TEST(convertToChar_10_to_X){
  char romanNumerals[25];

  convertIntToRomanNumerals(romanNumerals, 10);
  ck_assert_str_eq("X", romanNumerals);
}
END_TEST

START_TEST(convertToChar_5_to_V){
  char romanNumerals[25];

  convertIntToRomanNumerals(romanNumerals, 5);
  ck_assert_str_eq("V", romanNumerals);
}
END_TEST

START_TEST(convertToChar_1_to_I){
  char romanNumerals[25];

  convertIntToRomanNumerals(romanNumerals, 1);
  ck_assert_str_eq("I", romanNumerals);
}
END_TEST

START_TEST(convertToChar_1500_to_MD){
  char romanNumerals[25];

  convertIntToRomanNumerals(romanNumerals, 1500);
  ck_assert_str_eq("MD", romanNumerals);
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
  tcase_add_test(tcase, convertToChar_10_to_X);
  tcase_add_test(tcase, convertToChar_5_to_V);
  tcase_add_test(tcase, convertToChar_1_to_I);
  
  suite_add_tcase(su, tcase);

  TCase *multi;
  multi = tcase_create("Convert Int To Multiple Roman Numerals");
  tcase_add_test(multi, convertToChar_1500_to_MD);

  suite_add_tcase(su, multi);

  return su;
}
