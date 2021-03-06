#include <stdlib.h>
#include <check.h>
#include <stdbool.h>

#include "../include/tests/regexMatcher_test.h"

START_TEST(regex_match_simple) {
  int matches;
  char *regex = "M";
  char *word = "MM";
  matches = doesStringMatchRegex(regex, word);
  ck_assert_int_eq(true, matches);
}
END_TEST

START_TEST(regex_match_simple_or) {
  int matches;
  char *regex = "M|C";
  char *word = "C";
  matches = doesStringMatchRegex(regex, word);
  ck_assert_int_eq(true, matches);
}
END_TEST

START_TEST(regex_match_multiple_or) {
  int matches;
  char *regex = "M|C|V";
  char *word = "XXXVXXX";
  matches = doesStringMatchRegex(regex, word);
  ck_assert_int_eq(true, matches);
}
END_TEST

START_TEST(regex_no_match) {
  int matches;
  char *regex = "M|C|V";
  char *word = "XXXXXX";
  matches = doesStringMatchRegex(regex, word);
  ck_assert_int_eq(false, matches);
}
END_TEST

Suite* regexMatchingSuite(void) {
  Suite *su;
  TCase *tcase;

  su = suite_create("Convert Int To Roman Numeral");
  
  tcase = tcase_create("Convert Single Character");
  tcase_add_test(tcase, regex_match_simple);
  tcase_add_test(tcase, regex_match_simple_or);
  tcase_add_test(tcase, regex_match_multiple_or);
  tcase_add_test(tcase, regex_no_match);

  suite_add_tcase(su, tcase);
  
  return su;
}
