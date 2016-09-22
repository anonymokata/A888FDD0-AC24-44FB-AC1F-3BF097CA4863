#include <stdlib.h>
#include <check.h>

#include "../include/tests/inputValidator_test.h"
#include "../include/inputValidator.h"
#include "../include/romanNumeralCalculator.h"

START_TEST(valid_chars_input_M){
  int isValid = validateInputs("M", "III");
  
  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(valid_chars_input_D){
  int isValid = validateInputs("D", "III");
  
  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(valid_chars_input_C){
  int isValid = validateInputs("C", "III");
  
  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(valid_chars_input_L){
  int isValid = validateInputs("L", "III");
  
  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(valid_chars_input_X){
  int isValid = validateInputs("X", "III");
  
  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(valid_chars_input_V){
  int isValid = validateInputs("V", "III");
  
  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(valid_chars_input_I){
  int isValid = validateInputs("I", "III");
  
  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(valid_chars_input_firstnumeral){
  int isValid = validateInputs("ABC", "III");
  
  ck_assert_int_eq(INVALID_CHARS, isValid);
}
END_TEST

START_TEST(valid_chars_input_secondnumeral){
  int isValid = validateInputs("III", "ABC");
  
  ck_assert_int_eq(INVALID_CHARS, isValid);
}
END_TEST

START_TEST(invalid_occur_D){
  int isValid = validateInputs("DD", "III");
  
  ck_assert_int_eq(SINGLE_CHARS_EXCEEDED, isValid);
}
END_TEST

START_TEST(invalid_occur_L){
  int isValid = validateInputs("XILL", "III");
  
  ck_assert_int_eq(SINGLE_CHARS_EXCEEDED, isValid);
}
END_TEST

START_TEST(invalid_occur_V){
  int isValid = validateInputs("XXVXXV", "III");
  
  ck_assert_int_eq(SINGLE_CHARS_EXCEEDED, isValid);
}
END_TEST

START_TEST(valid_occur_both_numerals){
  int isValid = validateInputs("III", "DIIID");
  
  ck_assert_int_eq(SINGLE_CHARS_EXCEEDED, isValid);
}
END_TEST

START_TEST(invalid_occur_C){
  int isValid = validateInputs("MMMCCCC", "III");
  
  ck_assert_int_eq(EXCEEDED_MAX_SEQ_CHARS, isValid);
}
END_TEST

START_TEST(invalid_occur_X){
  int isValid = validateInputs("MMMXXXX", "III");
  
  ck_assert_int_eq(EXCEEDED_MAX_SEQ_CHARS, isValid);
}
END_TEST

START_TEST(valid_occur_X){
  int isValid = validateInputs("MMXXXIX", "III");
  
  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(invalid_occur_I){
  int isValid = validateInputs("MMMIIII", "III");
  
  ck_assert_int_eq(EXCEEDED_MAX_SEQ_CHARS, isValid);
}
END_TEST

START_TEST(invalid_occur_three_both){
  int isValid = validateInputs("MMMIII", "IIII");
  
  ck_assert_int_eq(EXCEEDED_MAX_SEQ_CHARS, isValid);
}
END_TEST

START_TEST(valid_result_parameter){
  char result[30] = "";
  int isValid = validateResultParam(result);
  
  ck_assert_int_eq(0, isValid);
}
END_TEST

START_TEST(invalid_result_parameter_null){
  int isValid = validateResultParam(NULL);
  
  ck_assert_int_eq(NULL_VALUE_RESULT_PARAM, isValid);
}
END_TEST

START_TEST(valid_operation_add){
  int isValid = validateOperationInput("add");

  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(valid_operation_sub){
  int isValid = validateOperationInput("sub");

  ck_assert_int_eq(EXIT_SUCCESS, isValid);
}
END_TEST

START_TEST(invalid_operation){
  int isValid = validateOperationInput("sam");

  ck_assert_int_eq(INVALID_OPERATION, isValid);
}
END_TEST

START_TEST(invalid_operation_null){
  int isValid = validateOperationInput(NULL);

  ck_assert_int_eq(INVALID_OPERATION, isValid);
}
END_TEST

START_TEST(invalid_first_input_null){
  int isValid = validateInputs(NULL, "I");

  ck_assert_int_eq(NULL_VALUE_INPUTS, isValid);
}
END_TEST

START_TEST(invalid_second_input_null){
  int isValid = validateInputs("I", NULL);

  ck_assert_int_eq(NULL_VALUE_INPUTS, isValid);
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
  tcase_add_test(oneOccur, invalid_occur_D);
  tcase_add_test(oneOccur, invalid_occur_L);
  tcase_add_test(oneOccur, invalid_occur_V);
  tcase_add_test(oneOccur, valid_occur_both_numerals);

  suite_add_tcase(su, oneOccur);

  TCase *threeOccur;
  threeOccur = tcase_create("Characters occur three times");
  tcase_add_test(threeOccur, invalid_occur_C);
  tcase_add_test(threeOccur, invalid_occur_X);
  tcase_add_test(threeOccur, valid_occur_X);
  tcase_add_test(threeOccur, invalid_occur_I);
  tcase_add_test(threeOccur, invalid_occur_three_both);
  
  suite_add_tcase(su, threeOccur);

  TCase *nullValue;
  nullValue = tcase_create("Check For Null Values");
  tcase_add_test(nullValue, valid_result_parameter);
  tcase_add_test(nullValue, invalid_result_parameter_null);
  tcase_add_test(nullValue, valid_operation_add);
  tcase_add_test(nullValue, valid_operation_sub);
  tcase_add_test(nullValue, invalid_operation);
  tcase_add_test(nullValue, invalid_operation_null);
  tcase_add_test(nullValue, invalid_first_input_null);
  tcase_add_test(nullValue, invalid_second_input_null);

  suite_add_tcase(su, nullValue);

  return su;
}
