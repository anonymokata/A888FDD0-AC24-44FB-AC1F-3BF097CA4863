#include <stdlib.h>
#include <check.h>

#include "../include/regexMatcher_test.h"

START_TEST(regex_match_simple) {
  int matches;
  char *regex = "M";
  char *word = "MM";
  matches = doesStringMatchRegex(regex, word);
  ck_assert_int_eq(1, matches);
}
END_TEST

Suite* regexMatchingSuite(void) {
  Suite *su;
  TCase *tcase;

  su = suite_create("Convert Int To Roman Numeral");
  
  tcase = tcase_create("Convert Single Character");
  tcase_add_test(tcase, regex_match_simple);

  suite_add_tcase(su, tcase);
  
  return su;
}
