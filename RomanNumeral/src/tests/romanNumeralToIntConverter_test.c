#include <stdlib.h>
#include <check.h>

#include "../include/tests/romanNumeralToIntConverter_test.h"

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

START_TEST(convertToInt_X_to_10){
  char one[1] = "X";

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(10, result);
}
END_TEST

START_TEST(convertToInt_L_to_50){
  char one[1] = "L";

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(50, result);
}
END_TEST

START_TEST(convertToInt_C_to_100){
  char one[1] = "C";

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(100, result);
}
END_TEST

START_TEST(convertToInt_D_to_500){
  char one[1] = "D";

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(500, result);
}
END_TEST

START_TEST(convertToInt_M_to_1000){
  char one[1] = "M";

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(1000, result);
}
END_TEST

START_TEST(convertToInt_II_to_2){
  char one[3] = "II";
  one[2] = '\0';

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(2, result);
}
END_TEST

START_TEST(convertToInt_DC_to_600){
  char one[3] = "DC";
  one[2] = '\0';

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(600, result);
}
END_TEST

START_TEST(convertToInt_IV_to_4){
  char one[3] = "IV";
  one[2] = '\0';

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(4, result);
}
END_TEST

START_TEST(convertToInt_Largest_to_3999){
  char one[10] = "MMMCMXCIX";
  one[9] = '\0';

  int result = convertRomanNumeralsToInt(one);
  ck_assert_int_eq(3999, result);
}
END_TEST

Suite* convertToIntSuite(void){
  Suite *su;
  TCase *tcase;

  su = suite_create("Convert Roman Numeral To Int");
  tcase = tcase_create("Convert Single Character");

  tcase_add_test(tcase, convertToInt_I_to_1);
  tcase_add_test(tcase, convertToInt_V_to_5);
  tcase_add_test(tcase, convertToInt_X_to_10);
  tcase_add_test(tcase, convertToInt_L_to_50);
  tcase_add_test(tcase, convertToInt_C_to_100);
  tcase_add_test(tcase, convertToInt_D_to_500);
  tcase_add_test(tcase, convertToInt_M_to_1000);

  suite_add_tcase(su, tcase);

  TCase *multiCase = tcase_create("Convert Multiple Characters");
  tcase_add_test(multiCase, convertToInt_II_to_2);
  tcase_add_test(multiCase, convertToInt_DC_to_600);
  tcase_add_test(multiCase, convertToInt_IV_to_4);
  tcase_add_test(multiCase, convertToInt_Largest_to_3999);

  suite_add_tcase(su, multiCase);

  return su;
}


