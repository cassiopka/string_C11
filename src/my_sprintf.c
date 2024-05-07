#include "my_sprintf.h"

int my_sprintf(char *str, const char *format, ...) {
  va_list ap;

  size_t res = -1;
  char *start = str;
  char *format_specifiers = "cdieEfgGosuxXp";

  va_start(ap, format);

  while (*format) {
    if (*format == '%') {
      format++;
      if (*format == '%') {
        *str = *format;
        str++;
        format++;
        continue;
      }

      struct specifier structure = {0};

      while (my_strchr(format_specifiers, *format) == NULL) {
        parse_config(&structure, *format, ap);
        format++;
      }
      if (my_strchr(format_specifiers, *format) != NULL) {
        str = arg_inserter(&structure, *format, ap, str);
      }
    } else {
      *str = *format;
      str++;
    }

    format++;
  }

  *str = '\0';
  va_end(ap);

  res = my_strlen(start);
  return res;
}