#include "my_sscanf.h"

void d_(const char **s, long int *res, int ignor, int width) {
  long int temp = 0;
  int sign = 1;
  if (**s == '-') {
    sign = -1;
    (*s)++;
  } else if (**s == '+') {
    (*s)++;
  }
  while (**s >= '0' && **s <= '9' && width > 0) {
    temp = temp * 10 + (**s - '0');
    (*s)++;
    width--;
  }
  if (!ignor) {
    *res = sign * temp;
  }
}

void cC_(const char **s, char *res, int ignor, int width) {
  if (!ignor) {
    *res = **s;
  }
  if (width == MAXWIDTH) {
    (*s)++;
  } else {
    while (width > 0) {
      (*s)++;
      width--;
    }
  }
}

void i_(const char **s, int *res, int ignor, int width) {
  int temp = 0;
  int sign = 1;
  if (**s == '-') {
    sign = -1;
    (*s)++;
  } else if (**s == '+') {
    (*s)++;
  }
  while (width > 0 && **s >= '0' && **s <= '9') {
    temp = temp * 10 + (**s - '0');
    (*s)++;
    width--;
  }
  if (!ignor) {
    *res = sign * temp;
  }
}
void o_(const char **s, unsigned int *res, int ignor, int width) {
  unsigned int temp = 0;
  while (**s >= '0' && **s <= '7' && width > 0) {
    temp = temp * 8 + (**s - '0');
    (*s)++;
    width--;
  }
  if (!ignor) {
    *res = temp;
  }
}
void sSpecifier(const char **s, char *res, int ignor, int width) {
  while (**s && !isspace(**s) && width > 0) {
    if (!ignor) {
      *res = **s;
    }
    (*s)++;
    res++;
    width--;
  }
  if (!ignor) {
    *res = '\0';
  }
}

void u_(const char **s, unsigned int *res, int ignor, int width) {
  unsigned int temp = 0;
  int isNeg = 0;
  if (**s == '-') {
    isNeg = 1;
    (*s)++;
  } else if (**s == '+')
    (*s)++;
  while (**s >= '0' && **s <= '9' && width > 0) {
    temp = temp * 10 + (**s - '0');
    (*s)++;
    width--;
  }
  if (isNeg) temp = 4294967296 - temp;
  if (!ignor) {
    *res = temp;
  }
}
void p_(const char **s, void **res, int ignor) {
  if (**s == '0' && (*(*s + 1) == 'x' || *(*s + 1) == 'X')) {
    *s += 2;
    if (!ignor) {
      *res = (void *)strtoull(*s, NULL, 16);
    }
    while (isxdigit(**s)) {
      (*s)++;
    }
  } else {
    if (!ignor) {
      *res = NULL;
    }
  }
}
void procent_(const char **s, int width) {
  while (width > 0 && **s == '%') {
    (*s)++;
    width--;
  }
}
void n_(const char **s, int *count, const char *str) { *count = *s - str; }
void x_(const char **s, unsigned int *res, int ignor, int width) {
  unsigned int temp = 0;
  int is_neg = 1;
  if (**s == '-') {
    is_neg = -1;
    (*s)++;
  } else if (**s == '+')
    (*s)++;
  if (my_strstr(*s, "0x")) {
    (*s)++;
    (*s)++;
    width = width - 2;
  }
  while (isxdigit(**s) && width > 0) {
    char digit = **s;
    if (isalpha(digit)) {
      digit = toupper(digit);
    }
    temp = temp * 16 + (isdigit(digit) ? (digit - '0') : (digit - 'A' + 10));
    (*s)++;
    width--;
  }
  if (!ignor) {
    *res = temp * is_neg;
  }
}

void f_(const char **s, float *res, int ignor, int width) {
  int sign = 1;
  int flag = (width == MAXWIDTH) ? 1 : 0;
  if (**s == '-') {
    sign = -1;
    (*s)++;
  } else if (**s == '+') {
    (*s)++;
  }
  int integerPart = 0;
  while (isdigit(**s) && width > 0) {
    integerPart = integerPart * 10 + (**s - '0');
    (*s)++;
    width--;
  }
  float result = (float)integerPart;
  if (**s == '.') {
    (*s)++;
    float decimalPart = 0.0;
    float decimalMultiplier = 0.1;
    while (isdigit(**s) && flag == 1) {
      decimalPart += decimalMultiplier * (**s - '0');
      decimalMultiplier *= 0.1;
      (*s)++;
      width--;
    }
    result += decimalPart;
  }
  if (!ignor) {
    *res = sign * result;
  }
}
void e_(const char **s, float *res, int ignor, int width) {
  int sign = 1;
  int flag = (width == MAXWIDTH) ? 1 : 0;
  int count = 0;
  if (my_strchr(*s, 'e') || my_strchr(*s, 'E')) count = normis(s);
  if (**s == '-') {
    sign = -1;
    (*s)++;
  } else if (**s == '+') {
    (*s)++;
  }
  if (my_strstr(*s, "e+") || my_strstr(*s, "E+")) {
    sign = sign * pow(10.0, count);
  } else {
    sign = sign / pow(10.0, count);
  }
  int integerPart = 0;
  while (isdigit(**s) && width > 0) {
    integerPart = integerPart * 10 + (**s - '0');
    (*s)++;
    width--;
  }
  double result = (double)integerPart;
  if (**s == '.') {
    (*s)++;
    double decimalPart = 0.0;
    double decimalMultiplier = 0.1;
    while (isdigit(**s) && flag == 1) {
      decimalPart += decimalMultiplier * (**s - '0');
      decimalMultiplier *= 0.1;
      (*s)++;
      width--;
    }
    result += decimalPart;
  }
  if (!ignor) {
    *res = sign * result;
  }
}