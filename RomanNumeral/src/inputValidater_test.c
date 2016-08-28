#include <stdlib.h>
#include <check.h>

#include "../include/inputValidater_test.h"
#include "../include/inputValidater.h"

START_TEST(valid_chars_input_M){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "M", "III");
  
  ck_assert_int_eq(1, isValid);
}
END_TEST

START_TEST(valid_chars_input_D){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "D", "III");
  
  ck_assert_int_eq(1, isValid);
}
END_TEST

START_TEST(valid_chars_input_C){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "C", "III");
  
  ck_assert_int_eq(1, isValid);
}
END_TEST

START_TEST(valid_chars_input_L){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "L", "III");
  
  ck_assert_int_eq(1, isValid);
}
END_TEST

START_TEST(valid_chars_input_X){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "X", "III");
  
  ck_assert_int_eq(1, isValid);
}
END_TEST

START_TEST(valid_chars_input_V){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "V", "III");
  
  ck_assert_int_eq(1, isValid);
}
END_TEST

START_TEST(valid_chars_input_I){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "I", "III");
  
  ck_assert_int_eq(1, isValid);
}
END_TEST

START_TEST(valid_chars_input_firstnumeral){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "ABC", "III");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only be comprised of the following characters: M,D,C,L,X,V,I", invalidMsg);
}
END_TEST

START_TEST(valid_chars_input_secondnumeral){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "III", "ABC");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only be comprised of the following characters: M,D,C,L,X,V,I", invalidMsg);
}
END_TEST

Suite* validateInputSuite(void){
  Suite *su;
  TCase *tcase;

  su = suite_create("Validate Inputs");
  tcase = tcase_create("Valid Characters");
  tcase_add_test(tcase, valid_chars_input_M);
  tcase_add_test(tcase, valid_chars_input_D);
  tcase_add_test(tcase, valid_chars_input_C);
  tcase_add_test(tcase, valid_chars_input_L);
  tcase_add_test(tcase, valid_chars_input_X);
  tcase_add_test(tcase, valid_chars_input_V);
  tcase_add_test(tcase, valid_chars_input_I);
  tcase_add_test(tcase, valid_chars_input_firstnumeral);
  tcase_add_test(tcase, valid_chars_input_secondnumeral);

  suite_add_tcase(su, tcase);

  return su;
}
