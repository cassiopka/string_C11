#include "my_sprintf.h"

char *char_case(struct specifier *structure, char c, char *str) {
  if (structure->width) {
    int padding = structure->width - 1;
    if (!structure->minus) {
      while (padding > 0) {
        *str++ = ' ';
        padding--;
      }
    }
    *str++ = c;
    if (structure->minus) {
      while (padding > 0) {
        *str++ = ' ';
        padding--;
      }
    }
  } else {
    *str++ = c;
  }
  return str;
}

char *int_case(struct specifier *structure, long long int num, char *str) {
  if (num < 0) {
    structure->neg_number = 1;
    num *= -1;
  }
  str = uint_case(structure, num, str);
  return str;
}

char *float_case(struct specifier *structure, long double fnum, char *str) {
  int count;
  char fdigit[MAX_DIGITS] = "";
  if (fnum < 0) {
    structure->neg_number = 1;
    fnum *= -1;
  }
  if (fnum == -0.0) structure->neg_number = 1;
  if (structure->case_e) {
    count = normalize(&fnum, structure);
  }
  my_ftoa(fdigit, fnum, structure->precision);
  if (!structure->hashtag) {
    if (my_strchr(fdigit, '.')) {
      if (structure->case_g) {
        for (int i = my_strlen(fdigit) - 1; i >= 0; i--) {
          if (fdigit[i] == '0') {
            fdigit[i] = '\0';
          } else if (fdigit[i] == '.') {
            fdigit[i] = '\0';
            break;
          } else {
            break;
          }
        }
      }
    }
  }

  int len = my_strlen(fdigit);
  int i = 0;
  if (structure->space && structure->width <= len && !structure->neg_number) {
    *str = ' ';
    str++;
  }
  if (!structure->minus) {
    while (i < structure->width - (structure->neg_number || structure->plus) -
                   len - structure->case_e * 4) {
      if (structure->zero)
        *str++ = '0';
      else
        *str++ = ' ';
      i++;
    }
  }
  i = 0;
  if (structure->neg_number) {
    *str = '-';
    str++;
  } else if (structure->plus) {
    *str = '+';
    str++;
  }
  str = string_insert(str, fdigit);
  if (structure->case_g) {
    structure->precision = len;
  }
  while (i < structure->precision - len) {
    *str = '0';
    str++;
    i++;
  }
  if (structure->minus) {
    if (structure->case_e) {
      if (structure->upper) {
        *str = 'E';
        str++;
      } else {
        *str = 'e';
        str++;
      }
      if (structure->stepE == 1) {
        *str = '+';
        str++;
      }
      if (structure->stepE == 2) {
        *str = '-';
        str++;
      }
      *str = '0' + count / 10;
      str++;
      *str = '0' + count % 10;
      str++;
    }
    while (i < structure->width - (structure->neg_number || structure->plus) -
                   len - structure->case_e * 4) {
      if (structure->zero)
        *str++ = '0';
      else
        *str++ = ' ';
      i++;
    }
  }

  if (structure->case_e && !structure->minus) {
    if (structure->upper) {
      *str = 'E';
      str++;
    } else {
      *str = 'e';
      str++;
    }
    if (structure->stepE == 1) {
      *str = '+';
      str++;
    }
    if (structure->stepE == 2) {
      *str = '-';
      str++;
    }
    *str = '0' + count / 10;
    str++;
    *str = '0' + count % 10;
    str++;
  }

  return str;
}

char *g_case(struct specifier *structure, long double fnum, char *str) {
  structure->case_g = 1;
  char gdigit[MAX_DIGITS] = "";
  int num_of_ints = -1;
  long long int intnum;
  intnum = (long long int)fnum;
  if (intnum > 0) {
    my_utoa(intnum, gdigit);
  } else {
    intnum *= -1;
    my_utoa(intnum, gdigit);
  }
  if (intnum == 0)
    num_of_ints = 0;
  else
    num_of_ints = my_strlen(gdigit);
  my_ftoa(gdigit, fnum, structure->precision);
  structure->precision = structure->precision - num_of_ints;
  if (structure->oldPrecision != 0) {
    if (num_of_ints > structure->oldPrecision || fabsl(fnum) < 1e-4) {
      structure->case_e = 1;
      if (structure->oldPrecision == 0) {
        structure->precision = 5;
      } else {
        structure->precision = structure->oldPrecision - 1;
      }
      str = float_case(structure, fnum, str);
    } else {
      str = float_case(structure, fnum, str);
    }
  } else {
    if (num_of_ints > 6 || fabsl(fnum) < 1e-4) {
      structure->case_e = 1;
      if (structure->oldPrecision == 0) {
        structure->precision = 5;
      } else {
        structure->precision = structure->oldPrecision - 1;
      }
      str = float_case(structure, fnum, str);
    } else {
      str = float_case(structure, fnum, str);
    }
  }

  return str;
}

char *uint_case(struct specifier *structure, long long unsigned num,
                char *str) {
  char digit[MAX_DIGITS] = "";
  my_utoa(num, digit);
  int len = my_strlen(digit);
  int i = 0;

  // Пробел
  if (structure->space && structure->width <= len && !structure->neg_number) {
    *str++ = ' ';
  }

  // точность
  if (!structure->width && !structure->precision) {
    if (structure->neg_number)
      *str++ = '-';
    else if (structure->plus)
      *str++ = '+';

    if (structure->hashtag) *str++ = '0';

    str = string_insert(str, digit);
  } else if (structure->precision &&
             (structure->precision >= structure->width)) {
    if (structure->neg_number)
      *str++ = '-';
    else if (structure->plus)
      *str++ = '+';

    while (i < structure->precision - len) {
      *str++ = '0';
      i++;
    }

    if (structure->hashtag) *str++ = '0';

    str = string_insert(str, digit);
  } else {
    // вместе точность и длина
    if (structure->is_precision && (structure->precision < len))
      structure->precision = len;

    if (!structure->minus) {
      int padding = structure->width -
                    (structure->neg_number || structure->plus) -
                    structure->precision - len * !structure->is_precision -
                    structure->hashtag;
      while (i < padding) {
        *str++ = (structure->zero) ? '0' : ' ';
        i++;
      }
    }

    if (structure->neg_number)
      *str++ = '-';
    else if (structure->plus)
      *str++ = '+';

    // точность
    if (structure->precision) {
      while (i < structure->precision - len) {
        *str++ = '0';
        i++;
      }
    }

    if (structure->hashtag) *str++ = '0';

    str = string_insert(str, digit);

    // минус
    if (structure->minus) {
      int padding = structure->width -
                    (structure->neg_number || structure->plus) -
                    structure->precision - len * !structure->is_precision;
      while (i < padding) {
        *str++ = (structure->zero) ? '0' : ' ';
        i++;
      }
    }
  }
  return str;
}

char *string_case(struct specifier *structure, char *inserted_str, char *str) {
  int i = 0;
  int added_len = my_strlen(inserted_str);
  int count = 0;
  if (structure->case_x || structure->case_o) {
    if (structure->precision >= added_len) {
      count = structure->precision - added_len - structure->hashtag;
    }
  }
  if ((structure->precision > added_len) || !structure->precision ||
      structure->case_x || structure->case_o)
    structure->precision = added_len;
  if (structure->width) {
    if (!structure->minus) {
      while (i < structure->width - structure->precision - structure->hashtag -
                     structure->case_p * 2 -
                     (structure->hashtag && structure->case_x) - count) {
        if (structure->zero)
          *str++ = '0';
        else
          *str++ = ' ';
        i++;
      }
      i = 0;
      while (i < count) {
        *str = '0';
        str++;
        i++;
      }
      i = 0;
      if (structure->hashtag) {
        if (structure->case_o)
          *str++ = '0';
        else if (structure->case_x && structure->upper) {
          *str++ = '0';
          *str++ = 'X';
        }
      }
      if (structure->case_p ||
          (structure->hashtag && structure->case_x && !structure->upper)) {
        *str++ = '0';
        *str++ = 'x';
      }
      while (i < structure->precision) {
        *str++ = *inserted_str++;
        i++;
      }
    } else {
      if (structure->hashtag) {
        if (structure->case_o)
          *str++ = '0';
        else if (structure->case_x && structure->upper) {
          *str++ = '0';
          *str++ = 'X';
        }
      }
      if (structure->case_p ||
          (structure->hashtag && structure->case_x && !structure->upper)) {
        *str++ = '0';
        *str++ = 'x';
      }
      while (i < count) {
        *str = '0';
        str++;
        i++;
      }
      i = 0;
      while (i < structure->precision) {
        *str++ = *inserted_str++;
        i++;
      }
      i = 0;
      while (i < structure->width - structure->precision - structure->hashtag -
                     structure->case_p * 2 -
                     (structure->hashtag && structure->case_x) - count) {
        if (structure->zero)
          *str++ = '0';
        else
          *str++ = ' ';
        i++;
      }
    }
  } else {
    if (structure->hashtag) {
      if (structure->case_o)
        *str++ = '0';
      else if (structure->case_x && structure->upper) {
        *str++ = '0';
        *str++ = 'X';
      }
    }
    if (structure->case_p ||
        (structure->hashtag && structure->case_x && !structure->upper)) {
      *str++ = '0';
      *str++ = 'x';
    }
    while (i < count) {
      *str = '0';
      str++;
      i++;
    }
    i = 0;
    while (i < structure->precision) {
      *str++ = *inserted_str++;
      i++;
    }
  }
  return str;
}

char *case_x(struct specifier *structure, long long int num, char *str) {
  if (num == 0) structure->hashtag = 0;
  char digit[MAX_DIGITS] = "";
  my_decimal(num, digit, structure->upper);
  str = string_case(structure, digit, str);
  return str;
}

char *case_o(struct specifier *structure, long long int num, char *str) {
  if (num == 0) structure->hashtag = 0;
  char digit[MAX_DIGITS] = "";
  my_decimalo(num, digit);
  str = string_case(structure, digit, str);
  return str;
}