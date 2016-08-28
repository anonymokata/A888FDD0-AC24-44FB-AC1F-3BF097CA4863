#include <stdlib.h>
#include <check.h>

#include "../include/inputValidater_test.h"
#include "../include/inputValidater.h"

START_TEST(valid_chars_input_one_M){
  char invalidMsg[100];
  int isValid;
  
  isValid = validateInputs(invalidMsg, "M", "III");
  
  ck_assert_int_eq(1, isValid);
  //ck_assert_str_eq("Roman Numerals can only be comprised of the following characters: M,D,C,L,X,V,I", invalidMsg);
}
END_TEST

Suite* validateInputSuite(void){
  Suite *su;
  TCase *tcase;

  su = suite_create("Validate Inputs");
  tcase = tcase_create("Valid Characters");
  tcase_add_test(tcase, valid_chars_input_one_M);

  suite_add_tcase(su, tcase);

  return su;
}
