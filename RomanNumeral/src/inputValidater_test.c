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

START_TEST(valid_occur_D){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "DD", "III");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only contain one occurrence of the characters: D,L,V", invalidMsg);
}
END_TEST

START_TEST(valid_occur_L){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "XILL", "III");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only contain one occurrence of the characters: D,L,V", invalidMsg);
}
END_TEST

START_TEST(valid_occur_V){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "XXVXXV", "III");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only contain one occurrence of the characters: D,L,V", invalidMsg);
}
END_TEST

START_TEST(valid_occur_both_numerals){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "III", "DIIID");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only contain one occurrence of the characters: D,L,V", invalidMsg);
}
END_TEST

START_TEST(valid_occur_C){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "MMMCCCC", "III");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only contain three occurrences of the characters: C,X,I", invalidMsg);
}
END_TEST

START_TEST(valid_occur_X){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "MMMXXXX", "III");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only contain three occurrences of the characters: C,X,I", invalidMsg);
}
END_TEST

START_TEST(valid_occur_I){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "MMMIIII", "III");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only contain three occurrences of the characters: C,X,I", invalidMsg);
}
END_TEST

START_TEST(valid_occur_three_both){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "MMMIII", "IIII");
  
  ck_assert_int_eq(0, isValid);
  ck_assert_str_eq("Roman Numerals can only contain three occurrences of the characters: C,X,I", invalidMsg);
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

  TCase *oneOccur;
  oneOccur = tcase_create("Characters occur one time");
  tcase_add_test(oneOccur, valid_occur_D);
  tcase_add_test(oneOccur, valid_occur_L);
  tcase_add_test(oneOccur, valid_occur_V);
  tcase_add_test(oneOccur, valid_occur_both_numerals);

  suite_add_tcase(su, oneOccur);

  TCase *threeOccur;
  threeOccur = tcase_create("Characters occur three times");
  tcase_add_test(threeOccur, valid_occur_C);
  tcase_add_test(threeOccur, valid_occur_X);
  tcase_add_test(threeOccur, valid_occur_I);
  tcase_add_test(threeOccur, valid_occur_three_both);
  
  suite_add_tcase(su, threeOccur);

  return su;
}
