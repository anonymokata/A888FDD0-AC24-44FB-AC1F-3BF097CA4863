#ifndef ROMAN_NUMERAL_CALC_H
#define ROMAN_NUMERAL_CALC_H

#define BENEATH_MIN_RESULT 101
#define EXCEEDED_MAX_RESULT 102

#define INVALID_CHARS 200
#define SINGLE_CHARS_EXCEEDED 201
#define EXCEEDED_MAX_SEQ_CHARS 202

int calculate(char *result, const char *op, const char *first, const char *sec);

#endif
