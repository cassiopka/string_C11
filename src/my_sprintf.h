#ifndef MY_SPRINTF_H
#define MY_SPRINTF_H

#include "my_string.h"

#define MAX_DIGITS 1024

struct specifier {
  int minus;
  int plus;
  int space;
  int hashtag;
  int zero;
  int width;
  int is_precision;
  int oldPrecision;
  int precision;
  int length;
  int is_short;
  int is_long;
  int is_verylong;
  int neg_number;
  int stepE;
  int upper;
  int case_e;
  int case_g;
  int case_p;
  int case_o;
  int case_x;
};

char *char_case(struct specifier *structure, char c, char *str);
char *float_case(struct specifier *structure, long double num, char *str);
char *int_case(struct specifier *structure, long long int num, char *str);
char *uint_case(struct specifier *structure, long long unsigned num, char *str);
char *string_case(struct specifier *structure, char *inserted_str, char *str);
char *g_case(struct specifier *structure, long double fnum, char *str);
char *case_x(struct specifier *structure, long long int num, char *str);
char *case_o(struct specifier *structure, long long int num, char *str);

char *string_insert(char *str, char *add_str);
long double normalize(long double *number, struct specifier *structure);
int parse_config(struct specifier *structure, char c, va_list arg);
char *arg_inserter(struct specifier *structure, char c, va_list arg, char *str);

#endif