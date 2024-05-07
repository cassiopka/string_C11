#include "my_sscanf.h"

int my_sscanf(const char *str, const char *format, ...) {
  va_list args;
  va_start(args, format);
  int error = 0;
  const char *s = str;
  const char *f = format;
  int count = 0;

  while (*f && !error) {
    if (*f != '%') {
      s++;
      f++;
    } else {
      f++;
      int ignor = 0;
      if (*f == '*') {
        ignor = 1;
        f++;
        count--;
      }
      int width = 0;
      while (isdigit(*f)) {
        width = width * 10 + (*f - '0');
        f++;
      }
      width = (width == 0) ? MAXWIDTH : width;
      if (*f == 'L' || *f == 'l' || *f == 'h') {
        f++;
      }
      switch (*f) {
        case 'd': {
          long int *num = (ignor == 1) ? NULL : va_arg(args, long int *);
          d_(&s, num, ignor, width);
          break;
        }
        case 'c': {
          char *symb = (ignor == 1) ? NULL : va_arg(args, char *);
          cC_(&s, symb, ignor, width);
          break;
        }
        case 'i': {
          int *num = (ignor == 1) ? NULL : va_arg(args, int *);
          i_(&s, num, ignor, width);
          break;
        }
        case 'f': {
          float *num = (ignor == 1) ? NULL : va_arg(args, float *);
          f_(&s, num, ignor, width);
          break;
        }
        case 'e': {
          float *nume = (ignor == 1) ? NULL : va_arg(args, float *);
          e_(&s, nume, ignor, width);
          break;
        }
        case 'E': {
          float *numE = (ignor == 1) ? NULL : va_arg(args, float *);
          e_(&s, numE, ignor, width);
          break;
        }
        case 'g': {
          float *numg = (ignor == 1) ? NULL : va_arg(args, float *);
          e_(&s, numg, ignor, width);
          break;
        }
        case 'G': {
          float *numG = (ignor == 1) ? NULL : va_arg(args, float *);
          e_(&s, numG, ignor, width);
          break;
        }
        case 'o': {
          unsigned int *num =
              (ignor == 1) ? NULL : va_arg(args, unsigned int *);
          o_(&s, num, ignor, width);
          break;
        }
        case 's': {
          char *str_arg = (ignor == 1) ? NULL : va_arg(args, char *);
          sSpecifier(&s, str_arg, ignor, width);
          break;
        }
        case 'u': {
          unsigned int *num =
              (ignor == 1) ? NULL : va_arg(args, unsigned int *);
          u_(&s, num, ignor, width);
          break;
        }
        case 'p': {
          void **ptr = (ignor == 1) ? NULL : va_arg(args, void **);
          p_(&s, ptr, ignor);
          break;
        }
        case '%': {
          count--;
          procent_(&s, width);
          break;
        }
        case 'n': {
          int *count = (ignor == 1) ? NULL : va_arg(args, int *);
          n_(&s, count, str);
          break;
        }
        case 'x': {
          unsigned int *num =
              (ignor == 1) ? NULL : va_arg(args, unsigned int *);
          x_(&s, num, ignor, width);
          break;
        }
        case 'X': {
          unsigned int *num =
              (ignor == 1) ? NULL : va_arg(args, unsigned int *);
          x_(&s, num, ignor, width);
          break;
        }
        default:
          return -1;
      }
      count++;
      f++;
    }
  }

  va_end(args);

  return count;
}

int normis(const char **s) {
  const char *str = NULL;
  if (!my_strchr(*s, 'e'))
    str = my_strchr(*s, 'E');
  else
    str = my_strchr(*s, 'e');
  str += 2;
  int count = 0;
  while (*str != '\0' && (*str >= '0' && *str <= '9')) {
    count = count * 10 + (*str - '0');
    str++;
  }

  return count;
}