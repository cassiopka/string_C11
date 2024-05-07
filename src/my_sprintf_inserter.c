#include "my_sprintf.h"

char *string_insert(char *str, char *add_str) {
  while (*add_str) *str++ = *add_str++;
  return str;
}

int parse_config(struct specifier *structure, char c, va_list arg) {
  switch (c) {
    case '-':
      structure->minus = 1;
      break;
    case '+':
      structure->plus = 1;
      break;
    case ' ':
      structure->space = 1;
      break;
    case '#':
      structure->hashtag = 1;
      break;
    case '*':
      int length = va_arg(arg, int);
      if (structure->is_precision)
        structure->precision = length;
      else if (length < 0) {
        structure->minus = 1;
        length *= -1;
        structure->width = length;
      } else {
        structure->width = length;
      }
      break;
    case '0':
      if (!structure->width && !structure->is_precision)
        structure->zero = 1;
      else {
        if (my_is_digit(c) && !structure->is_precision)
          structure->width = structure->width * 10 + (c - '0');
        if (my_is_digit(c) && structure->is_precision)
          structure->precision = structure->precision * 10 + (c - '0');
      }
      break;
    case 'L':
    case 'l':
      structure->is_long = 1;
      break;
    case 'h':
      structure->is_short = 1;
      break;
    case '.':
      structure->is_precision = 1;
      break;
    default:
      if (my_is_digit(c) && !structure->is_precision)
        structure->width = structure->width * 10 + (c - '0');
      if (my_is_digit(c) && structure->is_precision)
        structure->precision = structure->precision * 10 + (c - '0');
      break;
  }
  return 0;
}

char *arg_inserter(struct specifier *structure, char c, va_list arg,
                   char *str) {
  switch (c) {
    case 'c':
      char ch = va_arg(arg, int);
      str = char_case(structure, ch, str);
      break;
    case 'd':
      short int short_num = 0;
      int num = 0;
      long int long_num = 0;
      if (structure->is_short) {
        short_num = va_arg(arg, int);
        str = int_case(structure, short_num, str);
      } else if (structure->is_long) {
        long_num = va_arg(arg, long);
        str = int_case(structure, long_num, str);
      } else {
        num = va_arg(arg, int);
        str = int_case(structure, num, str);
      }
      break;
    case 'i':
      short int ishort_num = 0;
      int inum = 0;
      long int ilong_num = 0;
      if (structure->is_short) {
        ishort_num = va_arg(arg, int);
        str = int_case(structure, ishort_num, str);
      } else if (structure->is_long) {
        ilong_num = va_arg(arg, long);
        str = int_case(structure, ilong_num, str);
      } else {
        inum = va_arg(arg, int);
        str = int_case(structure, inum, str);
      }
      break;
    case 'f':
      double fnum = 0;
      long double lfnum = 0;
      if (!structure->is_precision)
        structure->precision = 6;
      else if (structure->precision < 0)
        structure->precision = 6;
      if (structure->is_long) {
        lfnum = va_arg(arg, long double);
        str = float_case(structure, lfnum, str);
      } else {
        fnum = va_arg(arg, double);
        str = float_case(structure, fnum, str);
      }
      break;
    case 'g':
      int countZeros;
      double gfnum = 0;
      long double glfnum = 0;
      if (structure->is_precision != 0) {
        structure->oldPrecision = structure->precision;
      }
      if (!structure->is_precision)
        structure->precision = 6;
      else if (structure->precision < 0)
        structure->precision = 6;
      if (structure->is_long) {
        glfnum = va_arg(arg, long double);
        countZeros = countZero(glfnum);
        if (countZeros < 4) {
          structure->precision = structure->precision + countZeros;
        }
        if (!structure->hashtag) {
          structure->precision = structure->precision + countZeros;
        }
        str = g_case(structure, glfnum, str);
      } else {
        gfnum = va_arg(arg, double);
        countZeros = countZero(gfnum);
        if (countZeros < 4) {
          structure->precision = structure->precision + countZeros;
        }
        if (!structure->hashtag) {
          structure->precision = structure->precision + countZeros;
        }
        str = g_case(structure, gfnum, str);
      }
      break;
    case 'G':
      structure->upper = 1;
      double ggfnum = 0;
      int gcountZeros;
      long double gglfnum = 0;
      if (structure->is_precision != 0) {
        structure->oldPrecision = structure->precision;
      }
      if (!structure->is_precision)
        structure->precision = 6;
      else if (structure->precision < 0)
        structure->precision = 6;
      if (structure->is_long) {
        gglfnum = va_arg(arg, long double);
        gcountZeros = countZero(gglfnum);
        if (gcountZeros < 4) {
          structure->precision = structure->precision + gcountZeros;
        }
        if (!structure->hashtag) {
          structure->precision = structure->precision + gcountZeros;
        }
        str = g_case(structure, gglfnum, str);
      } else {
        ggfnum = va_arg(arg, double);
        gcountZeros = countZero(ggfnum);
        if (gcountZeros < 4) {
          structure->precision = structure->precision + gcountZeros;
        }
        if (!structure->hashtag) {
          structure->precision = structure->precision + gcountZeros;
        }
        str = g_case(structure, ggfnum, str);
      }
      break;
    case 's':
      char *add_str = va_arg(arg, char *);
      str = string_case(structure, add_str, str);
      break;
    case 'u':
      unsigned short ushort;
      unsigned int unum;
      unsigned long long_unum;
      if (structure->is_short) {
        ushort = va_arg(arg, int);
        str = uint_case(structure, ushort, str);
      } else if (structure->is_long) {
        long_unum = va_arg(arg, long);
        str = uint_case(structure, long_unum, str);
      } else {
        unum = va_arg(arg, int);
        str = uint_case(structure, unum, str);
      }
      break;
    case 'e':
      structure->case_e = 1;
      double eefnum = 0;
      long double eelfnum = 0;
      if (!structure->is_precision)
        structure->precision = 6;
      else if (structure->precision < 0)
        structure->precision = 6;
      if (structure->is_long) {
        eelfnum = va_arg(arg, long double);
        str = float_case(structure, eelfnum, str);
      } else {
        eefnum = va_arg(arg, double);
        str = float_case(structure, eefnum, str);
      }
      break;
    case 'E':
      structure->case_e = 1;
      structure->upper = 1;
      double efnum = 0;
      long double elfnum = 0;
      if (!structure->is_precision)
        structure->precision = 6;
      else if (structure->precision < 0)
        structure->precision = 6;
      if (structure->is_long) {
        elfnum = va_arg(arg, long double);
        str = float_case(structure, elfnum, str);
      } else {
        efnum = va_arg(arg, double);
        str = float_case(structure, efnum, str);
      }
      break;
    case 'x':
      unsigned short ushortx;
      structure->case_x = 1;
      unsigned int unumx;
      unsigned long long_unumx;
      if (structure->is_short) {
        ushortx = va_arg(arg, int);
        str = case_x(structure, ushortx, str);
      } else if (structure->is_long) {
        long_unumx = va_arg(arg, long);
        str = case_x(structure, long_unumx, str);
      } else {
        unumx = va_arg(arg, int);
        str = case_x(structure, unumx, str);
      }
      break;
    case 'X':
      structure->case_x = 1;
      structure->upper = 1;
      unsigned short ushortxx;
      unsigned int unumxx;
      unsigned long long_unumxx;
      if (structure->is_short) {
        ushortxx = va_arg(arg, int);
        str = case_x(structure, ushortxx, str);
      } else if (structure->is_long) {
        long_unumxx = va_arg(arg, long);
        str = case_x(structure, long_unumxx, str);
      } else {
        unumxx = va_arg(arg, int);
        str = case_x(structure, unumxx, str);
      }
      break;
    case 'o':
      unsigned short ushortxq;
      unsigned int unumxq;
      unsigned long long_unumxq;
      structure->case_o = 1;
      if (structure->is_short) {
        ushortxq = va_arg(arg, int);
        str = case_o(structure, ushortxq, str);
      } else if (structure->is_long) {
        long_unumxq = va_arg(arg, long);
        str = case_o(structure, long_unumxq, str);
      } else {
        unumxq = va_arg(arg, int);
        str = case_o(structure, unumxq, str);
      }
      break;
    case 'p':
      unsigned long int pt = (unsigned long int)va_arg(arg, unsigned long int);
      structure->case_p = 1;
      str = case_x(structure, pt, str);
      break;
    default:
      break;
  }
  return str;
}

long double normalize(long double *number, struct specifier *structure) {
  int count = 0;
  if (fabsl(*number) >= 1) {
    structure->stepE = 1;
    while (fabsl(*number) > 10) {
      *number /= 10;
      count++;
    }
  } else {
    while (fabsl(*number) < 0.999999) {
      *number *= 10;
      structure->stepE = 2;
      count++;
    }
  }
  return count;
}