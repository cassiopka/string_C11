#include "my_string.h"

int my_memcmp(const void *str1, const void *str2, my_size_t n) {
  my_size_t i = 1;
  while (i < n && *(unsigned char *)str1 == *(unsigned char *)str2) {
    i++;
    str1++;
    str2++;
  }

  return *(unsigned char *)str1 - *(unsigned char *)str2;
}

int my_strcmp(const char *str1, const char *str2) {
  for (; *str1 && *str1 == *str2; str1++, str2++) {
  }
  return *str1 - *str2;
}

int my_strncmp(const char *str1, const char *str2, my_size_t n) {
  my_size_t i = 1;
  while (i < n && *str1 == *str2 && (*str1 != '\0' && *str2 != '\0')) {
    i++;
    str1++;
    str2++;
  }
  return (n == 0) ? 0 : (unsigned char)(*str1) - (unsigned char)(*str2);
}

char *my_strtok(char *str, const char *delim) {
  static char *token = NULL;

  if (str != NULL) {
    token = str;
  }

  for (; *token != '\0' && my_strchr(delim, *token) != NULL; token++)
    ;

  if (*token == '\0') {
    return NULL;
  }

  char *start = token;
  for (; *token != '\0' && my_strchr(delim, *token) == NULL; token++)
    ;

  if (*token != '\0') {
    *token = '\0';
    token++;
  }

  return start;
}

void *my_memchr(const void *str, int c, size_t n) {
  const unsigned char *s1 = (const unsigned char *)str;
  for (my_size_t i = 0; i < n; i++) {
    if (c == *s1) {
      return (void *)s1;
    }
    s1++;
  }
  return NULL;
}

char *my_strchr(const char *str, int c) {
  if (c == '\0') {
    return "";
  }
  int n = my_strlen(str);
  for (int i = 0; i < n; i++) {
    if (c == *str) {
      return (char *)str;
    }
    str++;
  }
  return NULL;
}

char *my_strpbrk(const char *str1, const char *str2) {
  int n1 = my_strlen(str1);
  int n2 = my_strlen(str2);

  for (int i = 0; i < n1; i++) {
    const char *temp = str2;
    for (int i = 0; i < n2; i++) {
      if (*str1 == *temp) {
        return (char *)str1;
      }
      temp++;
    }
    str1++;
  }
  return NULL;
}

char *my_strrchr(const char *str, int c) {
  if (c == '\0') {
    return (char *)(str + my_strlen(str));
  }
  const char *temp = str + my_strlen(str) - 1;
  int n = my_strlen(str);
  for (int i = n - 1; i >= 0; i--) {
    if (c == *temp) {
      return (char *)temp;
    }
    temp--;
  }
  return NULL;
}

char *my_strstr(const char *haystack, const char *needle) {
  int n1 = my_strlen(haystack);
  int n2 = my_strlen(needle);
  int count = 0;
  if (n2 == 0) {
    return (char *)haystack;
  }
  for (int i = 0; i < n1; i++) {
    const char *temp = needle;
    const char *tempHaystack = haystack;
    for (int j = 0; j < n2; j++) {
      if (*tempHaystack == *temp) {
        count++;
      }
      if (count == n2) {
        return (char *)haystack;
      }
      tempHaystack++;
      temp++;
    }
    count = 0;
    haystack++;
  }

  return NULL;
}

my_size_t my_strlen(const char *str) {
  my_size_t length = 0;

  while (*str != '\0') {
    ++length;
    ++str;
  }

  return length;
}

my_size_t my_strspn(const char *str1, const char *str2) {
  my_size_t count = 0;

  while (*str1 != '\0' && my_strchr(str2, *str1) != NULL) {
    ++count;
    ++str1;
  }

  return count;
}

my_size_t my_strcspn(const char *str1, const char *str2) {
  my_size_t count = 0;

  while (*str1 != '\0' && my_strchr(str2, *str1) == NULL) {
    ++count;
    ++str1;
  }

  return count;
}

void *my_memcpy(void *dest, const void *src, my_size_t n) {
  unsigned char *destination = (unsigned char *)dest;
  unsigned char *source = (unsigned char *)src;

  for (my_size_t i = 0; i < n; ++i) {
    destination[i] = source[i];
  }

  return destination;
}

void *my_memset(void *str, int c, my_size_t n) {
  unsigned char *string = (unsigned char *)str;

  for (my_size_t i = 0; i < n; ++i) {
    string[i] = c;
  }

  return string;
}

char *my_strncpy(char *dest, const char *src, my_size_t n) {
  my_memcpy(dest, src, n);

  return dest;
}

char *my_strncat(char *dest, const char *src, size_t n) {
  char *start = dest;
  for (; *start != '\0'; start++)
    ;

  for (my_size_t i = 0; *src != '\0' && i < n; src++, start++, i++) {
    *start = *src;
  }
  *start = '\0';
  return dest;
}

void *my_to_upper(const char *str) {
  if (str == NULL) {
    return NULL;
  }
  char *result = malloc(sizeof(char) * my_strlen(str) + 1);
  char *start = result;

  while (*str != '\0') {
    if (*str > 96 && *str < 123) {
      *result = *str - 32;
    } else
      *result = *str;

    str++;
    result++;
  }
  *result = '\0';

  return start;
}

void *my_to_lower(const char *str) {
  if (str == NULL) {
    return NULL;
  }
  char *result = malloc(sizeof(char) * my_strlen(str) + 1);
  char *start = result;

  while (*str != '\0') {
    if (*str > 64 && *str < 91) {
      *result = *str + 32;
    } else
      *result = *str;

    str++;
    result++;
  }

  *result = '\0';
  return start;
}

int my_is_digit(char c) {
  int res = 0;
  if (c >= '0' && c <= '9') res = 1;
  return res;
}

void my_utoa(long long unsigned num, char *str) {
  int i = 0;
  if (num == 0) str[i++] = '0';
  while (num != 0) {
    str[i++] = '0' + num % 10;
    num = num / 10;
  }
  str[i] = '\0';
  int start = 0;
  int end = i - 1;
  while (start < end) {
    char temp = str[start];
    str[start++] = str[end];
    str[end--] = temp;
  }
}

void my_decimal(long long unsigned num, char *str, int upper) {
  int i = 0;
  if (num == 0) str[i++] = '0';
  while (num != 0) {
    int ostatok = num % 16;
    if (ostatok < 10) {
      str[i++] = ostatok + '0';
    } else if (upper) {
      str[i++] = ostatok - 10 + 'A';
    } else {
      str[i++] = ostatok - 10 + 'a';
    }
    num = num / 16;
  }
  str[i] = '\0';
  int start = 0;
  int end = i - 1;
  while (start < end) {
    char temp = str[start];
    str[start++] = str[end];
    str[end--] = temp;
  }
}

void my_decimalo(long long unsigned num, char *str) {
  int i = 0;
  if (num == 0) str[i++] = '0';
  while (num != 0) {
    int ostatok = num % 8;

    str[i++] = ostatok + '0';

    num = num / 8;
  }
  str[i] = '\0';
  int start = 0;
  int end = i - 1;
  while (start < end) {
    char temp = str[start];
    str[start++] = str[end];
    str[end--] = temp;
  }
}

void my_ftoa(char *str, long double num, int precision) {
  int point = 0;
  long long int intnum;
  int flag = 0;
  intnum = (long long int)num;
  my_utoa(intnum, str);
  point = my_strlen(str);
  num -= intnum;

  str[point++] = '.';

  for (int power = 0; power < precision + 1; power++) {
    num *= 10.0;
    intnum = (long long int)num;
    str[point++] = intnum + '0';
    num -= intnum;
  }

  str[point] = '\0';
  round_float(str, &flag);
  if (!precision) {
    if (flag)
      str[point - 1] = '\0';
    else
      str[point - 2] = '\0';
  }
}

int countZero(long double num) {
  int count = 0;
  int isDecimal = 0;
  num = fabsl(num);
  while (num < 1) {
    if (!isDecimal) {
      isDecimal = 1;
    }

    if (isDecimal) {
      num *= 10;
      int digit = (int)num;
      if (digit == 0) {
        count++;
      } else {
        break;
      }
      num -= digit;
    }
  }

  return count;
}

void round_float(char *str, int *flag) {
  int length = my_strlen(str);
  if (str[length - 1] > '4') {
    for (int i = (int)length - 2; i >= 0; --i) {
      if (str[i] == '.') {
        --i;
      }
      if (str[i] != '9') {
        str[i] = str[i] + 1;
        break;
      } else if (i != 0) {
        str[i] = '0';
      } else if (str[i] != '0') {
        *flag = 1;
        for (i = (int)length; i > 0; --i) {
          str[i] = str[i - 1];
        }
        str[1] = '0';
        str[0] = '1';
        break;
      } else {
        str[i] = '1';
      }
    }
  }
  if ((int)my_strlen(str) > length)
    str[length] = '\0';
  else
    str[length - 1] = '\0';
}

char *my_strerror(int errnum) {
  char *result = my_NULL;
  char error_msg[100] = "";

  char *my_error[] = my_errors;
  if (errnum < 0 || errnum > my_N_error) {
    if (my_N_error == 133) {
      my_sprintf(error_msg, "Unknown error %d", errnum);
    } else {
      my_sprintf(error_msg, "Unknown error: %d", errnum);
    }
  } else {
    my_sprintf(error_msg, my_error[errnum]);
  }

  result = error_msg;
  return result;
}