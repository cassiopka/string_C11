#include <check.h>
#include <math.h>
#include <string.h>

#include "my_string.h"

START_TEST(test_my_memchr) {
  char src1_def[15] = "1234567890";
  char src1_s21[15] = "1234567890";
  ck_assert_str_eq(memchr(src1_def, '4', 10), my_memchr(src1_s21, '4', 10));

  char str1[10] = "Hello";
  ck_assert_mem_eq(my_memchr(str1, 'H', 5), memchr(str1, 'H', 5), 5);

  char str2[10] = "Hellosdsfq";
  ck_assert_mem_eq(my_memchr(str2, 'l', 0), memchr(str2, 'l', 0), 0);
}
END_TEST

START_TEST(test_my_memcmp) {
  char src1[15] = "12345678901";
  char dst1[15] = "12345678901";
  ck_assert_msg(memcmp(src1, dst1, 15) == 0 && my_memcmp(src1, dst1, 15) == 0,
                "no");

  char src2[15] = "12345678901";
  char dst2[15] = "tertertet";
  ck_assert_int_eq(memcmp(src2, dst2, 15), my_memcmp(src2, dst2, 15));

  char src3[15] = "12345678901";
  char dst3[15] = "werwe";
  ck_assert_msg(memcmp(src3, dst3, 15) <= 0 && my_memcmp(src3, dst3, 15) <= 0,
                "No");

  char src4[15] = "erteterteqwe";
  char dst4[15] = "erteterte";
  ck_assert_msg(memcmp(src4, dst4, 15) >= 0 && my_memcmp(src4, dst4, 15) >= 0,
                "No");
}
END_TEST

START_TEST(test_my_memcpy) {
  char str1_def[80], str1_s21[80], str1_text[] = "123456";
  memcpy(str1_def, str1_text, 7);
  my_memcpy(str1_s21, str1_text, 7);
  ck_assert_str_eq(str1_def, str1_s21);

  char str2_def[] = "aaaaaaaaaaaaaaaaaaaaaaaaa";
  char str2_s21[] = "aaaaaaaaaaaaaaaaaaaaaaaaa";
  char str2_text[] = "Hello, I am from America.";
  memcpy(str2_def, str2_text, 10);
  my_memcpy(str2_s21, str2_text, 10);
  ck_assert_str_eq(str2_def, str2_s21);
}
END_TEST

START_TEST(test_my_memset) {
  unsigned char src1[15] = "1234567890";
  unsigned char src2[15] = "1234567890";
  ck_assert_str_eq(memset(src1, '1', 10), my_memset(src2, '1', 10));

  unsigned char src3[25] = "gergeebdjnyjtykxhdurnr";
  unsigned char src4[25] = "gergeebdjnyjtykxhdurnr";
  ck_assert_str_eq(memset(src3, '1', 20), my_memset(src4, '1', 20));
}
END_TEST

START_TEST(test_my_strlen) {
  char str1[11] = "0123456789";
  ck_assert_int_eq(strlen(str1), my_strlen(str1));

  char str2[12] = "";
  ck_assert_int_eq(strlen(str2), my_strlen(str2));

  char str3[12] = "\n";
  ck_assert_int_eq(strlen(str3), my_strlen(str3));
}
END_TEST

START_TEST(test_my_strncat) {
  char src1_def[10] = "000";
  char app1_def[10] = "12345";
  char src1_s21[10] = "000";
  char app1_s21[10] = "12345";
  ck_assert_str_eq(strncat(src1_def, app1_def, 3),
                   my_strncat(src1_s21, app1_s21, 3));

  char src2_def[10] = "000";
  char app2_def[10] = "12345";
  char src2_s21[10] = "000";
  char app2_s21[10] = "12345";
  ck_assert_str_eq(strncat(src2_def, app2_def, 7),
                   my_strncat(src2_s21, app2_s21, 7));
}
END_TEST

START_TEST(test_my_strcmp) {
  char str1[10] = "abc";
  char str2[10] = "abc";
  ck_assert_int_eq(strcmp(str1, str2), my_strcmp(str1, str2));
  char str3[10] = "abc";
  char str4[10] = "dfg";
  ck_assert_int_eq(strcmp(str3, str4), my_strcmp(str3, str4));
}
END_TEST

START_TEST(test_my_strcspn) {
  char str[13] = "0123456789";
  char sym[10] = "9876";
  ck_assert_int_eq(strcspn(str, sym), my_strcspn(str, sym));

  char str1[13] = "xyzbxz";
  char sym1[10] = "abc";
  ck_assert_int_eq(strcspn(str1, sym1), my_strcspn(str1, sym1));

  char str2[13] = "xyzbxz";
  char sym2[10] = "xyzbxz";
  ck_assert_int_eq(strcspn(str2, sym2), my_strcspn(str2, sym2));

  char str3[13] = "xyzbxz";
  char sym3[10] = "no match";
  ck_assert_int_eq(strcspn(str3, sym3), my_strcspn(str3, sym3));

  char str4[13] = "xyzbxz";
  char sym4[10] = "";
  ck_assert_int_eq(strcspn(str4, sym4), my_strcspn(str4, sym4));

  char str5[13] = "";
  char sym5[10] = "abc";
  ck_assert_int_eq(strcspn(str5, sym5), my_strcspn(str5, sym5));

  char str6[13] = "";
  char sym6[10] = "";
  ck_assert_int_eq(strcspn(str6, sym6), my_strcspn(str6, sym6));
}
END_TEST

START_TEST(test_my_strpbrk) {
  char string[100] = "The 3 men and 2 boys ate 5 pigs\n";
  char *result = NULL;
  char *result_1 = NULL;
  ;
  result = strpbrk(string, "0123456789");
  result_1 = my_strpbrk(string, "0123456789");
  ck_assert_str_eq(result, result_1);

  result = strpbrk(result, "0123456789");
  result_1 = my_strpbrk(result_1, "0123456789");
  ck_assert_str_eq(result, result_1);

  result_1 = my_strpbrk(result_1, "0123456789");
  result = strpbrk(result, "0123456789");
  ck_assert_str_eq(result, result_1);

  result_1 = my_strpbrk(result_1, "9");
  result = strpbrk(result, "9");
  ck_assert_msg(result == NULL && result_1 == NULL, "Return not NULL");
}
END_TEST

START_TEST(test_my_strspn) {
  char string[] = "cabbebage";
  ck_assert_int_eq(strspn(string, "abc"), my_strspn(string, "abc"));
  ck_assert_int_eq(strspn(string, "cab"), my_strspn(string, "cab"));
  ck_assert_int_eq(strspn(string, "1"), my_strspn(string, "1"));
}
END_TEST

START_TEST(test_my_strchr) {
  char str1[11] = "23456789";
  int ch1 = '4';
  char *ach1_def;
  char *ach1_s21;
  ach1_def = strchr(str1, ch1);
  ach1_s21 = my_strchr(str1, ch1);
  ck_assert_str_eq(ach1_def, ach1_s21);

  char str2[11] = "23456789";
  int ch2 = '1';
  char *ach2_def;
  char *ach2_s21;
  ach2_def = strchr(str2, ch2);
  ach2_s21 = my_strchr(str2, ch2);
  ck_assert(ach2_def == ach2_s21);

  char str3[] = "Hello world";
  int ch = '\0';
  ck_assert_str_eq(my_strchr(str3, ch), strchr(str3, ch));

  char str4[] = "";
  int ch12 = '\0';
  ck_assert_str_eq(my_strchr(str4, ch12), strchr(str4, ch12));
}
END_TEST

START_TEST(test_my_strncpy) {
  char src[] = "12345\0006789";
  char dst1[] = "aaaaaaaaaa";
  char dst2[] = "aaaaaaaaaa";
  char dst3[] = "aaaaaaaaaa";
  char dst4[] = "aaaaaaaaaa";
  ck_assert_str_eq(strncpy(dst1, src, 3), my_strncpy(dst3, src, 3));
  ck_assert_str_eq(strncpy(dst2, src, 7), my_strncpy(dst4, src, 7));
}
END_TEST

START_TEST(test_my_strstr1) {
  char str1[] = "0123456789";
  char str2[] = "345";
  ck_assert_str_eq(my_strstr(str1, str2), strstr(str1, str2));
}
END_TEST
START_TEST(test_my_strstr2) {
  char str3[] = "0123456789";
  char str4[] = "256";
  char *istr3 = strstr(str3, str4);
  char *istr4 = my_strstr(str3, str4);
  ck_assert_int_eq(istr3 - str3 + 1, istr4 - str3 + 1);

  char str1[10] = "hello";
  char str2[10] = "";
  ck_assert_msg(my_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST
START_TEST(test_my_strstr3) {
  char str5[] = "hello";
  char str6[] = "";
  ck_assert_str_eq(my_strstr(str5, str6), strstr(str5, str6));
}
END_TEST
START_TEST(test_my_strstr4) {
  char str1[10] = "hello";
  char str2[10] = "he";
  ck_assert_msg(my_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST
START_TEST(test_my_strstr5) {
  char str1[10] = "hello";
  char str2[10] = "qw";
  ck_assert_msg(my_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST
START_TEST(test_my_strstr6) {
  char str1[10] = "hello";
  char str2[10] = "hellp";
  ck_assert_msg(my_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST
START_TEST(test_my_strstr7) {
  char str1[1024] = "hello sweet hello";
  char str2[10] = "hello";
  ck_assert_msg(my_strstr(str1, str2) == strstr(str1, str2), "failed");
}
END_TEST

START_TEST(test_my_to_upper) {
  char str1[] = "adgreg";
  char *d1 = my_to_upper(str1);
  ck_assert_str_eq(d1, "ADGREG");
  free(d1);

  char str2[] = "adg23/";
  char *d2 = my_to_upper(str2);
  ck_assert_str_eq(d2, "ADG23/");
  free(d2);

  char str3[] = "";
  char *d3 = my_to_upper(str3);
  ck_assert_str_eq(d3, "");
  free(d3);

  char *d4 = my_to_upper(NULL);
  ck_assert(d4 == NULL);
  free(d4);
}
END_TEST

START_TEST(test_my_to_lower) {
  char str1[] = "ADGREG";
  char *d1 = my_to_lower(str1);
  ck_assert_str_eq(d1, "adgreg");
  free(d1);

  char str2[] = "ADG23/";
  char *d2 = my_to_lower(str2);
  ck_assert_str_eq(d2, "adg23/");
  free(d2);

  char str3[] = "";
  char *d3 = my_to_lower(str3);
  ck_assert_str_eq(d3, "");
  free(d3);

  char *d4 = my_to_lower(NULL);
  ck_assert(d4 == NULL);
  free(d4);
}
END_TEST

START_TEST(test_my_strrchr1) {
  char str[] = "0163456769";
  int ch = '6';
  char *ach;
  char *ach2;
  ach = strrchr(str, ch);
  ach2 = my_strrchr(str, ch);
  ck_assert_str_eq(ach, ach2);

  char str2[] = "erterterty";
  int ch2 = '6';
  char *ach3;
  char *ach4;
  ach3 = strrchr(str2, ch2);
  ach4 = my_strrchr(str2, ch2);
  ck_assert(ach3 == ach4);

  char str1[] = "Hello";
  int c = 0;
  ck_assert_ptr_eq(my_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(test_my_strrchr2) {
  char str1[] = "Hello, Mel";
  int c = 'e';
  ck_assert_ptr_eq(my_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(test_my_strrchr3) {
  char str1[] = "Hello, Mel";
  int c = 'p';
  ck_assert_ptr_eq(my_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(test_my_strrchr4) {
  char str1[] = "";
  int c = 'l';
  ck_assert_ptr_eq(my_strrchr(str1, c), strrchr(str1, c));
}
END_TEST
START_TEST(test_my_strrchr5) {
  char str1[] = "Hello";
  int c = 'o';
  ck_assert_ptr_eq(my_strrchr(str1, c), strrchr(str1, c));
}
END_TEST

START_TEST(test_my_strncmp1) {
  char str1[16] = "1234567890";
  char str2[16] = "1234567890";
  ck_assert_int_eq(strncmp(str1, str2, 5), my_strncmp(str1, str2, 5));

  char str3[16] = "1234567890";
  char str4[16] = "1334567890";
  ck_assert_int_eq(strncmp(str3, str4, 5), my_strncmp(str3, str4, 5));

  char str5[20] = "12345678901234";
  char str6[10] = "1234567890";
  ck_assert_int_eq(strncmp(str5, str6, 15), my_strncmp(str5, str6, 15));

  char str7[10] = "1234567890";
  char str8[16] = "12345678901234";
  ck_assert_int_eq(strncmp(str7, str8, 16), my_strncmp(str7, str8, 16));

  char str9[10] = "1234567890";
  char str10[16] = "02";
  ck_assert_int_eq(strncmp(str9, str10, 0), my_strncmp(str9, str10, 0));
}
END_TEST
START_TEST(test_my_strncmp2) {
  char *str1 = "1234567890";
  char *str2 = "1234567890";
  ck_assert_msg(my_strncmp(str1, str2, 5) == strncmp(str1, str2, 5),
                "Failed on 1");
}
END_TEST
START_TEST(test_my_strncmp3) {
  char *str1 = "1234567890";
  char *str2 = "1224567890";
  ck_assert_msg(my_strncmp(str1, str2, 5) == strncmp(str1, str2, 5),
                "Failed on 2");
}
END_TEST
START_TEST(test_my_strncmp4) {
  char *str1 = "1224567890";
  char *str2 = "1234567890";
  ck_assert_msg(my_strncmp(str1, str2, 5) == strncmp(str1, str2, 5),
                "Failed on 3");
}
END_TEST
START_TEST(test_my_strncmp5) {
  char *str1 = "";
  char *str2 = "";
  ck_assert_msg(my_strncmp(str1, str2, 5) == strncmp(str1, str2, 5),
                "Failed on 4");
}
END_TEST
START_TEST(test_my_strncmp6) {
  char *str1 = "1224567890";
  char *str2 = "";
  ck_assert_msg(my_strncmp(str1, str2, 5) == strncmp(str1, str2, 5),
                "Failed on 5");
}
END_TEST
START_TEST(test_my_strncmp7) {
  char *str1 = "122";
  char *str2 = "345";
  ck_assert_msg(my_strncmp(str1, str2, 5) == strncmp(str1, str2, 5),
                "Failed on 6");
}
END_TEST
START_TEST(test_my_strncmp8) {
  char *str1 = "test\0abc";
  char *str2 = "test\0";
  ck_assert_msg(my_strncmp(str1, str2, 6) == strncmp(str1, str2, 6),
                "Failed on 7");
}
END_TEST

START_TEST(test_my_strtok1) {
  char str1_def[] = "test1/test2/test3/test4";
  char str1_s21[] = "test1/test2/test3/test4";
  char sep1[] = "/";
  char *istr1_def;
  char *istr1_s21;
  istr1_def = strtok(str1_def, sep1);
  istr1_s21 = my_strtok(str1_s21, sep1);
  ck_assert((istr1_def != NULL) && (istr1_s21 != NULL));
  while ((istr1_def != NULL) && (istr1_s21 != NULL)) {
    ck_assert_str_eq(istr1_def, istr1_s21);
    istr1_def = strtok(NULL, sep1);
    istr1_s21 = my_strtok(NULL, sep1);
  }

  char *str2_def = NULL;
  char *str2_s21 = NULL;
  char sep2[] = "/";
  char *istr2_def;
  char *istr2_s21;
  istr2_def = strtok(str2_def, sep2);
  istr2_s21 = my_strtok(str2_s21, sep2);
  ck_assert(istr2_def == NULL && istr2_s21 == NULL);

  char str3_def[] = "test1/test2/test3/test4";
  char str3_s21[] = "test1/test2/test3/test4";
  char sep3[] = "est";
  char *istr3_def;
  char *istr3_s21;
  istr3_def = strtok(str3_def, sep3);
  istr3_s21 = my_strtok(str3_s21, sep3);
  ck_assert((istr3_def != NULL) && (istr3_s21 != NULL));
  while ((istr3_def != NULL) && (istr3_s21 != NULL)) {
    ck_assert_str_eq(istr3_def, istr3_s21);
    istr3_def = strtok(NULL, sep3);
    istr3_s21 = my_strtok(NULL, sep3);
  }

  char str4_def[] = "test1/test2/test3/test4";
  char str4_s21[] = "test1/test2/test3/test4";
  char sep4[] = "ret";
  char *istr4_def;
  char *istr4_s21;
  istr4_def = strtok(str4_def, sep4);
  istr4_s21 = my_strtok(str4_s21, sep4);
  ck_assert((istr4_def != NULL) && (istr4_s21 != NULL));
  while ((istr4_def != NULL) && (istr4_s21 != NULL)) {
    ck_assert_str_eq(istr4_def, istr4_s21);
    istr4_def = strtok(NULL, sep4);
    istr4_s21 = my_strtok(NULL, sep4);
  }

  char str5_def[] = "test1/test2/test3/test4";
  char str5_s21[] = "test1/test2/test3/test4";
  char sep5[] = "";
  char *istr5_def;
  char *istr5_s21;
  istr5_def = strtok(str5_def, sep5);
  istr5_s21 = my_strtok(str5_s21, sep5);
  ck_assert((istr5_def != NULL) && (istr5_s21 != NULL));
  while ((istr5_def != NULL) && (istr5_s21 != NULL)) {
    ck_assert_str_eq(istr5_def, istr5_s21);
    istr5_def = strtok(NULL, sep5);
    istr5_s21 = my_strtok(NULL, sep5);
  }
}
END_TEST
START_TEST(test_my_strtok2) {
  char str2_def[] = "";
  char str2_s21[] = "";
  char sep2[] = "/";
  char *istr2_def;
  char *istr2_s21;
  istr2_def = strtok(str2_def, sep2);
  istr2_s21 = my_strtok(str2_s21, sep2);
  ck_assert_msg(istr2_def == NULL && istr2_s21 == NULL, "Return not NULL");
}
START_TEST(test_my_strtok3) {
  char str[30] = "test1/test2/test3/test4";
  char delim = ',';
  ck_assert_msg(my_strtok(str, &delim) == strtok(str, &delim), "Failed on 2");
}
END_TEST
START_TEST(test_my_strtok4) {
  char str[30] = "test1/test2/test3/test4";
  char delim = 'e';
  ck_assert_msg(my_strtok(str, &delim) == strtok(str, &delim), "Failed on 3");
}
END_TEST
START_TEST(test_my_strtok5) {
  char str[30] = "AadacAdxa";
  char delim = 'a';
  ck_assert_msg(my_strtok(str, &delim) == strtok(str, &delim), "Failed on 4");
}
END_TEST
START_TEST(test_my_strtok6) {
  char str[30] = "ased dse c sze wsew";
  char delim = 'e';
  ck_assert_msg(my_strtok(str, &delim) == strtok(str, &delim), "Failed on 5");
}
END_TEST
START_TEST(test_my_strtok7) {
  char str[30] = "test1,test2/test3.test4";
  char delim[] = ",/.";
  ck_assert_str_eq(my_strtok(str, delim), strtok(str, delim));
}
END_TEST

START_TEST(test_my_strerror) {
  for (int i = -1000; i < 150; i++) {
    ck_assert_str_eq(strerror(i), my_strerror(i));
  }
}
END_TEST

START_TEST(test_my_sprintf_di_test1) {
  int iii = 12723;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %d", iii);
  sprintf(str2, "Hello %d", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test2) {
  int iii = -12723;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %d", iii);
  sprintf(str2, "Hello %d", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test3) {
  int iii = 12723;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %.3d", iii);
  sprintf(str2, "Hello %.3d", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test4) {
  int iii = -12346;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %5.2d", iii);
  sprintf(str2, "Hello %5.2d", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test5) {
  int iii = 123;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %.d", iii);
  sprintf(str2, "Hello %.d", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test6) {
  int iii = 0;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %i", iii);
  sprintf(str2, "Hello %i", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test7) {
  int iii = -1444;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %+i", iii);
  sprintf(str2, "Hello %+i", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test8) {
  int iii = 5421;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %+3.i", iii);
  sprintf(str2, "Hello %+3.i", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test9) {
  long int iii = 23568251976105;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %ld", iii);
  sprintf(str2, "Hello %ld", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test10) {
  long int iii = 21231231976105;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %.12ld", iii);
  sprintf(str2, "Hello %.12ld", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test11) {
  short iii = 21231;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %.12hi", iii);
  sprintf(str2, "Hello %.12hi", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_di_test12) {
  short iii = 21231;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %hd", iii);
  sprintf(str2, "Hello %hd", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_di_test13) {
  int iii = 21231;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %+20d", iii);
  sprintf(str2, "Hello %+20d", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_di_test14) {
  int iii = 21231;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %-20d", iii);
  sprintf(str2, "Hello %-20d", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_di_test15) {
  int iii = 21231;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %020d", iii);
  sprintf(str2, "Hello %020d", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_di_test16) {
  int iii = 21231;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello % 20d", iii);
  sprintf(str2, "Hello % 20d", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_di_test17) {
  long int iii = 212312132321;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello % li", iii);
  sprintf(str2, "Hello % li", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_di_test18) {
  long int iii = 212312132321;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %20li", iii);
  sprintf(str2, "Hello %20li", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_di_test19) {
  int iii = 2123121;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %+4.11i", iii);
  sprintf(str2, "Hello %+4.11i", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_di_test20) {
  int iii = -2123121;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %+4.11i", iii);
  sprintf(str2, "Hello %+4.11i", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_c_test1) {
  char iii = '$';
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %c", iii);
  sprintf(str2, "Hello %c", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_с_test2) {
  char iii = '$';
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %-15c", iii);
  sprintf(str2, "Hello %-15c", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_с_test3) {
  char iii = '$';
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %6c", iii);
  sprintf(str2, "Hello %6c", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_s_test1) {
  char iii[] = "VASOS";
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %s", iii);
  sprintf(str2, "Hello %s", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_s_test2) {
  char iii[] = "VASOS";
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %7s", iii);
  sprintf(str2, "Hello %7s", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_s_test3) {
  char iii[] = "VASOS";
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %.4s", iii);
  sprintf(str2, "Hello %.4s", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_s_test4) {
  char fff[] = "uuuu";
  char outStr[100];
  my_sprintf(outStr, "Hello %s world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %s world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_s_test5) {
  char fff[] = "uuuu";
  char outStr[100];
  my_sprintf(outStr, "Hello %10s world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %10s world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_s_test6) {
  char fff[] = "uuuu";
  char outStr[100];
  my_sprintf(outStr, "Hello %-10s world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %-10s world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_u_test1) {
  int iii = -14234;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %-7.35u", iii);
  sprintf(str2, "Hello %-7.35u", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_u_test2) {
  int iii = 2314;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %.u", iii);
  sprintf(str2, "Hello %.u", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_u_test3) {
  int iii = -31124;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %-3u", iii);
  sprintf(str2, "Hello %-3u", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST
START_TEST(test_my_sprintf_u_test4) {
  int iii = 123;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %4.1u", iii);
  sprintf(str2, "Hello %4.1u", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_u_test5) {
  int iii = 123;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %4.1hu", iii);
  sprintf(str2, "Hello %4.1u", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_u_test6) {
  long iii = 1233123123321;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %4.1lu", iii);
  sprintf(str2, "Hello %4.1lu", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_u_test7) {
  unsigned iii = -12331;
  char outStr1[100];
  char *str1 = outStr1;
  char outStr2[100];
  char *str2 = outStr2;
  my_sprintf(str1, "Hello %4.11u", iii);
  sprintf(str2, "Hello %4.11u", iii);
  ck_assert_str_eq(str1, str2);
}
END_TEST

START_TEST(test_my_sprintf_float_1) {
  double fff = 127.56;
  char outStr[100];
  my_sprintf(outStr, "Hello %f", fff);
  char str_check[100];
  sprintf(str_check, "Hello %f", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_2) {
  double fff = 127.56;
  char outStr[100];
  my_sprintf(outStr, "Hello %f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_3) {
  double fff = -127.56;
  char outStr[100];
  my_sprintf(outStr, "Hello %f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_4) {
  double fff = -9.099;
  char outStr[100];
  my_sprintf(outStr, "Hello %+f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %+f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_5) {
  double fff = 127.56;
  char outStr[100];
  my_sprintf(outStr, "Hello %+f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %+f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_6) {
  double fff = 127.56;
  char outStr[100];
  my_sprintf(outStr, "Hello % f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello % f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_7) {
  double fff = -127.56;
  char outStr[100];
  my_sprintf(outStr, "Hello % f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello % f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_8) {
  double fff = 127.56;
  char outStr[100];
  my_sprintf(outStr, "Hello %.f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %.f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_9) {
  double fff = -127.56;
  char outStr[100];
  my_sprintf(outStr, "Hello %.f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %.f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_10) {
  double fff = 127.468;
  char outStr[100];
  my_sprintf(outStr, "Hello %.0f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %.0f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_11) {
  double fff = -127.468;
  char outStr[100];
  my_sprintf(outStr, "Hello %.0f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %.0f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_12) {
  double fff = 127.468;
  char outStr[100];
  my_sprintf(outStr, "Hello %.5f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %.5f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_13) {
  double fff = -127.468;
  char outStr[100];
  my_sprintf(outStr, "Hello %.5f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %.5f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_14) {
  double fff = 0.468;
  char outStr[100];
  my_sprintf(outStr, "Hello %.5f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %.5f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_15) {
  double fff = -0.468;
  char outStr[100];
  my_sprintf(outStr, "Hello %.5f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %.5f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_16) {
  double fff = 0.468;
  char outStr[100];
  my_sprintf(outStr, "Hello %.5f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %.5f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_17) {
  double fff = -0.468;
  char outStr[100];
  my_sprintf(outStr, "Hello % .5f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello % .5f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_18) {
  double fff = 0.468;
  char outStr[100];
  my_sprintf(outStr, "Hello %+.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %+.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_19) {
  double fff = -0.468;
  char outStr[100];
  my_sprintf(outStr, "Hello %+.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %+.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_20) {
  double fff = 0.568;
  char outStr[100];
  my_sprintf(outStr, "Hello %+.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %+.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_21) {
  double fff = -0.568;
  char outStr[100];
  my_sprintf(outStr, "Hello %+.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %+.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_22) {
  double fff = 0.568;
  char outStr[100];
  my_sprintf(outStr, "Hello %10.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_23) {
  double fff = -0.568;
  char outStr[100];
  char str_check[100];
  int res = my_sprintf(outStr, "Hello %10.1f world!", fff);
  int res1 = sprintf(str_check, "Hello %10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
  ck_assert_int_eq(res, res1);
}
END_TEST
START_TEST(test_my_sprintf_float_24) {
  double fff = 0.568;
  char outStr[100];
  int res = my_sprintf(outStr, "Hello %+10.1f world!", fff);
  char str_check[100];
  int res1 = sprintf(str_check, "Hello %+10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
  ck_assert_int_eq(res, res1);
}
END_TEST
START_TEST(test_my_sprintf_float_25) {
  double fff = -0.568;
  char outStr[100];
  my_sprintf(outStr, "Hello %+10.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %+10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_26) {
  double fff = 0.568;
  char outStr[100];
  my_sprintf(outStr, "Hello %% %-10.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %% %-10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_27) {
  double fff = -0.568;
  char outStr[100];
  my_sprintf(outStr, "Hello %-10.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %-10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_28) {
  double fff = 1.568;
  char outStr[100];
  my_sprintf(outStr, "Hello %-10.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %-10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_29) {
  double fff = -1.568;
  char outStr[100];
  my_sprintf(outStr, "Hello %-10.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %-10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_30) {
  double fff = 0.56823;
  char outStr[100];
  my_sprintf(outStr, "Hello %-10.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %-10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_31) {
  double fff = 0.56823;
  char outStr[100];
  my_sprintf(outStr, "Hello %-3.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %-3.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_32) {
  double fff = 1.56823;
  char outStr[100];
  my_sprintf(outStr, "Hello %-10.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %-10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_33) {
  double fff = 1.568;
  char outStr[100];
  my_sprintf(outStr, "Hello %-3.10f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %-3.10f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_34) {
  double fff = 1.56823;
  char outStr[100];
  my_sprintf(outStr, "Hello % .1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello % .1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_35) {
  double fff = -1.5807;
  char outStr[100];
  my_sprintf(outStr, "Hello % .10f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello % .10f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_36) {
  double fff = -9.0989;
  char outStr[100];
  my_sprintf(outStr, "Hello %.*f world!", 10, fff);
  char str_check[100];
  sprintf(str_check, "Hello %.*f world!", 10, fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_37) {
  double fff = -1.56844;
  char outStr[100];
  my_sprintf(outStr, "Hello %10f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %10f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_38) {
  double fff = -1.56823;
  char outStr[100];
  my_sprintf(outStr, "Hello %10.f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %10.f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_39) {
  double fff = -1.56823;
  char outStr[100];
  my_sprintf(outStr, "Hello %10.1f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %10.1f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_40) {
  double fff = 9.9999999;
  char outStr[100];
  my_sprintf(outStr, "Hello %5f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %5f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_41) {
  double fff = 1.5;
  char outStr[100];
  my_sprintf(outStr, "Hello %0.f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %0.f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_42) {
  double fff = 1.5;
  char outStr[100];
  my_sprintf(outStr, "Hello %0.f world!", fff);
  char str_check[100];
  sprintf(str_check, "Hello %0.f world!", fff);
  ck_assert_str_eq(outStr, str_check);
}
END_TEST
START_TEST(test_my_sprintf_float_43) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%f", 324.34);
  sprintf(data1, "%f", 324.34);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_44) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%10f", 324.343);
  sprintf(data1, "%10f", 324.343);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_45) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%10.3f", 324.343);
  sprintf(data1, "%10.3f", 324.343);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_46) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%1.9f", 324.343);
  sprintf(data1, "%1.9f", 324.343);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_47) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%-1.10f", 324.343);
  sprintf(data1, "%-1.10f", 324.343);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_48) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%-1.10f", -324.343);
  sprintf(data1, "%-1.10f", -324.343);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_49) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%.10f", -324.343);
  sprintf(data1, "%.10f", -324.343);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_50) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%.10f", 324.343);
  sprintf(data1, "%.10f", 324.343);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_51) {
  char data[100];
  char data1[100];
  my_sprintf(data, "% 10f", 324.1);
  sprintf(data1, "% 10f", 324.1);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_52) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%+10f", 324.1);
  sprintf(data1, "%+10f", 324.1);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_53) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%#10f", 324.1);
  sprintf(data1, "%#10f", 324.1);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_54) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%#10f", 324.1123132);
  sprintf(data1, "%#10f", 324.1123132);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_55) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%#10.15f", 324.1123132);
  sprintf(data1, "%#10.15f", 324.1123132);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_56) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%.0f", 324.1123132);
  sprintf(data1, "%.0f", 324.1123132);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_58) {
  //
  char data[100];
  char data1[100];
  my_sprintf(data, "%10.10f", 320.3);
  sprintf(data1, "%10.10f", 320.3);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_59) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%-10.10f", 320.3);
  sprintf(data1, "%-10.10f", 320.3);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_60) {
  //
  char data[100];
  char data1[100];
  my_sprintf(data, "%-10.10f", 320.3);
  sprintf(data1, "%-10.10f", 320.3);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_61) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%-10.10f", -320.3);
  sprintf(data1, "%-10.10f", -320.3);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_62) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%.0f", -320.3);
  sprintf(data1, "%.0f", -320.3);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_63) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%.0f", -320.3);
  sprintf(data1, "%.0f", -320.3);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(test_my_sprintf_float_64) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%5.1f", 324.324);
  sprintf(data1, "%5.1f", 324.324);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_65) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%5.3f", 0.0001);
  sprintf(data1, "%5.3f", 0.0001);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_66) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%5.*f", 10, 0.0001);
  sprintf(data1, "%5.*f", 10, 0.0001);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_67) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%5.*f", -10, 0.0001);
  sprintf(data1, "%5.*f", -10, 0.0001);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_68) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%*.*f", 23, -10, 0.0001);
  sprintf(data1, "%*.*f", 23, -10, 0.0001);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_69) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%*.*f", -23, -10, 0.0001);
  sprintf(data1, "%*.*f", -23, -10, 0.0001);
  ck_assert_str_eq(data, data1);
}
END_TEST
START_TEST(test_my_sprintf_float_70) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%*.*f", 0, -10, 0.0001);
  sprintf(data1, "%*.*f", 0, -10, 0.0001);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(test_my_sprintf_float_71) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%f", 9.60705);
  sprintf(data1, "%f", 9.60705);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(test_my_sprintf_float_72) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%020f", 9.60705);
  sprintf(data1, "%020f", 9.60705);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(test_my_sprintf_float_73) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%Lf", 92323.60705L);
  sprintf(data1, "%Lf", 92323.60705L);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(test_my_sprintf_float_74) {
  char data[100];
  char data1[100];
  my_sprintf(data, "%.11f", 93.5);
  sprintf(data1, "%.11f", 93.5);
  ck_assert_str_eq(data, data1);
}
END_TEST

START_TEST(test_my_sprintf_X_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%X", 0);
  my_sprintf(str2, "%X", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%X", 4);
  my_sprintf(str2, "%X", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%X", -4);
  my_sprintf(str2, "%X", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3X", 4);
  my_sprintf(str2, "%-10.3X", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3hX", 4);
  my_sprintf(str2, "%-10.3hX", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3X", -4);
  my_sprintf(str2, "%-10.3X", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3hX", -4);
  my_sprintf(str2, "%-10.3hX", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10X", 4);
  my_sprintf(str2, "%-3.10X", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10X", -4);
  my_sprintf(str2, "%-3.10X", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", 4000000);
  my_sprintf(str2, "%+2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", -4000000);
  my_sprintf(str2, "%+2.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2X", 4000000);
  my_sprintf(str2, "%+.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.X", 4000000);
  my_sprintf(str2, "%+2.X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2X", -4000000);
  my_sprintf(str2, "%.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15X", 4000000);
  my_sprintf(str2, "%15.15X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%16.15X", -4000000);
  my_sprintf(str2, "%16.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15X", -4000000);
  my_sprintf(str2, "%15.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2X", -4000000);
  my_sprintf(str2, "%12.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2X", 4000000);
  my_sprintf(str2, "%12.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12X", 4000000);
  my_sprintf(str2, "%2.12X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12X", -4000000);
  my_sprintf(str2, "%2.12X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", 4000000);
  my_sprintf(str2, "%2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", -4000000);
  my_sprintf(str2, "%2.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", 4000000);
  my_sprintf(str2, "%2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", -4000000);
  my_sprintf(str2, "%2.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2X", 4000000);
  my_sprintf(str2, "%.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2X", 4000000);
  my_sprintf(str2, "%-2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2X", -4000000);
  my_sprintf(str2, "%-2.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15X", 4000000);
  my_sprintf(str2, "%-15.15X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15X", -4000000);
  my_sprintf(str2, "%-15.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2X", -4000000);
  my_sprintf(str2, "%-12.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2X", 4000000);
  my_sprintf(str2, "%-12.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12X", 4000000);
  my_sprintf(str2, "%-2.12X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12X", -4000000);
  my_sprintf(str2, "%-2.12X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2X", 4000000);
  my_sprintf(str2, "%-2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2X", 4000000);
  my_sprintf(str2, "%-2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.2X", 4000000);
  my_sprintf(str2, "%-.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2X", 4000000);
  my_sprintf(str2, "%-2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10X", 4000000);
  my_sprintf(str2, "%-10X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2X", 4000000);
  my_sprintf(str2, "%-2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10X", 4000000);
  my_sprintf(str2, "%-10X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%11.10X", 4000000);
  my_sprintf(str2, "%11.10X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2X", 4000000);
  my_sprintf(str2, "% 2.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15X", -4000000);
  my_sprintf(str2, "%.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15X", 4000000);
  my_sprintf(str2, "%.15X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15X", 4000000);
  my_sprintf(str2, "%.15X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15X", -4000000);
  my_sprintf(str2, "%.15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2X", 4000000);
  my_sprintf(str2, "%15.2X", 4000000);
  sprintf(str, "%15.2X", 4000000);
  my_sprintf(str2, "%15.2X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2X", -4000000);
  my_sprintf(str2, "%15.2X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.8X", -4000000);
  my_sprintf(str2, "%15.8X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8X", -4000000);
  my_sprintf(str2, "%-.8X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.8X", 4000000);
  my_sprintf(str2, "%.8X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8X", 4000000);
  my_sprintf(str2, "%-.8X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11X", -4000000);
  my_sprintf(str2, "%-11X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5X", -4000000);
  my_sprintf(str2, "%-5X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8X", -4000000);
  my_sprintf(str2, "%-10.8X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8X", 4000000);
  my_sprintf(str2, "%-10.8X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8X", -4000000);
  my_sprintf(str2, "%-10.8X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-#15X", -4000000);
  my_sprintf(str2, "%-#15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#15X", -4000000);
  my_sprintf(str2, "%#15X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#X", -4000000);
  my_sprintf(str2, "%#X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%13.10X", -4000000);
  my_sprintf(str2, "%13.10X", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11.11X", 4000000);
  my_sprintf(str2, "%-11.11X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5.11X", 4000000);
  my_sprintf(str2, "%-5.11X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-9.7X", 4000000);
  my_sprintf(str2, "%-9.7X", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%u", (unsigned int)-4000000);
  my_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%lX", 213232132312);
  my_sprintf(str2, "%lX", 213232132312);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%lX", -213232132312);
  my_sprintf(str2, "%lX", -213232132312);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_sprintf_o_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%#o", 0);
  my_sprintf(str2, "%#o", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%o", 4);
  my_sprintf(str2, "%o", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%o", -4);
  my_sprintf(str2, "%o", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#-10.3o", 4);
  my_sprintf(str2, "%#-10.3o", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3o", -4);
  my_sprintf(str2, "%-10.3o", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3ho", -4);
  my_sprintf(str2, "%-10.3ho", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10o", 4);
  my_sprintf(str2, "%-3.10o", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10ho", 4);
  my_sprintf(str2, "%-3.10ho", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10o", -4);
  my_sprintf(str2, "%-3.10o", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  my_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", -4000000);
  my_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2o", 4000000);
  my_sprintf(str2, "%.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.o", 4000000);
  my_sprintf(str2, "%2.o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2o", -4000000);
  my_sprintf(str2, "%.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15o", 4000000);
  my_sprintf(str2, "%15.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%16.15o", -4000000);
  my_sprintf(str2, "%16.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15o", -4000000);
  my_sprintf(str2, "%15.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2o", -4000000);
  my_sprintf(str2, "%12.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2o", 4000000);
  my_sprintf(str2, "%12.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12o", 4000000);
  my_sprintf(str2, "%2.12o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12o", -4000000);
  my_sprintf(str2, "%2.12o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  my_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", -4000000);
  my_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  my_sprintf(str2, "%2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", -4000000);
  my_sprintf(str2, "%2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2o", 4000000);
  my_sprintf(str2, "%.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", 4000000);
  my_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", -4000000);
  my_sprintf(str2, "%-2.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15o", 4000000);
  my_sprintf(str2, "%-15.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15o", -4000000);
  my_sprintf(str2, "%-15.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2o", -4000000);
  my_sprintf(str2, "%-12.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2o", 4000000);
  my_sprintf(str2, "%-12.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12o", 4000000);
  my_sprintf(str2, "%-2.12o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12o", -4000000);
  my_sprintf(str2, "%-2.12o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", 4000000);
  my_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2o", 4000000);
  my_sprintf(str2, "%-2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.2o", 4000000);
  my_sprintf(str2, "%-.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2o", 4000000);
  my_sprintf(str2, "%-2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10o", 4000000);
  my_sprintf(str2, "%-10o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2o", 4000000);
  my_sprintf(str2, "%-2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10o", 4000000);
  my_sprintf(str2, "%-10o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%11.10o", 4000000);
  my_sprintf(str2, "%11.10o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2o", 4000000);
  my_sprintf(str2, "% 2.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15o", -4000000);
  my_sprintf(str2, "%.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15o", 4000000);
  my_sprintf(str2, "%.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15o", 4000000);
  my_sprintf(str2, "%.15o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15o", -4000000);
  my_sprintf(str2, "%.15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2o", 4000000);
  my_sprintf(str2, "%15.2o", 4000000);
  sprintf(str, "%15.2o", 4000000);
  my_sprintf(str2, "%15.2o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2o", -4000000);
  my_sprintf(str2, "%15.2o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.8o", -4000000);
  my_sprintf(str2, "%15.8o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8o", -4000000);
  my_sprintf(str2, "%-.8o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.8o", 4000000);
  my_sprintf(str2, "%.8o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8o", 4000000);
  my_sprintf(str2, "%-.8o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11o", -4000000);
  my_sprintf(str2, "%-11o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5o", -4000000);
  my_sprintf(str2, "%-5o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8o", -4000000);
  my_sprintf(str2, "%-10.8o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8o", 4000000);
  my_sprintf(str2, "%-10.8o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8o", -4000000);
  my_sprintf(str2, "%-10.8o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%13.10o", -4000000);
  my_sprintf(str2, "%13.10o", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11.11o", 4000000);
  my_sprintf(str2, "%-11.11o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5.11o", 4000000);
  my_sprintf(str2, "%-5.11o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-#11o", -4000000);
  my_sprintf(str2, "%-#11o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%0#15o", -4000000);
  my_sprintf(str2, "%0#15o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#11o", -4000000);
  my_sprintf(str2, "%#11o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-9.7o", 4000000);
  my_sprintf(str2, "%-9.7o", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%o", (unsigned int)-4000000);
  my_sprintf(str2, "%o", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%lo", 213232132312);
  my_sprintf(str2, "%lo", 213232132312);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%lo", -213232132312);
  my_sprintf(str2, "%lo", -213232132312);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_sprintf_x_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%x", 0);
  my_sprintf(str2, "%x", 0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#x", 4);
  my_sprintf(str2, "%#x", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%x", -4);
  my_sprintf(str2, "%x", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3x", 4);
  my_sprintf(str2, "%-10.3x", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3hx", 4);
  my_sprintf(str2, "%-10.3hx", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%015hx", 4);
  my_sprintf(str2, "%015hx", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3x", -4);
  my_sprintf(str2, "%-10.3x", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.3hx", -4);
  my_sprintf(str2, "%-10.3hx", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10x", 4);
  my_sprintf(str2, "%-3.10x", 4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-3.10x", -4);
  my_sprintf(str2, "%-3.10x", -4);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", 4000000);
  my_sprintf(str2, "%2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", -4000000);
  my_sprintf(str2, "%2.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2x", 4000000);
  my_sprintf(str2, "%.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.x", 4000000);
  my_sprintf(str2, "%2.x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2x", -4000000);
  my_sprintf(str2, "%.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15x", 4000000);
  my_sprintf(str2, "%15.15x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%16.15x", -4000000);
  my_sprintf(str2, "%16.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.15x", -4000000);
  my_sprintf(str2, "%15.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2x", -4000000);
  my_sprintf(str2, "%12.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%12.2x", 4000000);
  my_sprintf(str2, "%12.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12x", 4000000);
  my_sprintf(str2, "%2.12x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.12x", -4000000);
  my_sprintf(str2, "%2.12x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", 4000000);
  my_sprintf(str2, "%2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", -4000000);
  my_sprintf(str2, "%2.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", 4000000);
  my_sprintf(str2, "%2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", -4000000);
  my_sprintf(str2, "%2.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2x", 4000000);
  my_sprintf(str2, "%.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#11x", -4000000);
  my_sprintf(str2, "%#11x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2x", 4000000);
  my_sprintf(str2, "%-2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2x", -4000000);
  my_sprintf(str2, "%-2.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15x", 4000000);
  my_sprintf(str2, "%-15.15x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-15.15x", -4000000);
  my_sprintf(str2, "%-15.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2x", -4000000);
  my_sprintf(str2, "%-12.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-12.2x", 4000000);
  my_sprintf(str2, "%-12.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12x", 4000000);
  my_sprintf(str2, "%-2.12x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.12x", -4000000);
  my_sprintf(str2, "%-2.12x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2x", 4000000);
  my_sprintf(str2, "%-2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2.2x", 4000000);
  my_sprintf(str2, "%-2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.2x", 4000000);
  my_sprintf(str2, "%-.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2x", 4000000);
  my_sprintf(str2, "%-2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10x", 4000000);
  my_sprintf(str2, "%-10x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-2x", 4000000);
  my_sprintf(str2, "%-2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10x", 4000000);
  my_sprintf(str2, "%-10x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%11.10x", 4000000);
  my_sprintf(str2, "%11.10x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%2.2x", 4000000);
  my_sprintf(str2, "% 2.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15x", -4000000);
  my_sprintf(str2, "%.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15x", 4000000);
  my_sprintf(str2, "%.15x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15x", 4000000);
  my_sprintf(str2, "%.15x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.15x", -4000000);
  my_sprintf(str2, "%.15x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2x", 4000000);
  my_sprintf(str2, "%15.2x", 4000000);
  sprintf(str, "%15.2x", 4000000);
  my_sprintf(str2, "%15.2x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.2x", -4000000);
  my_sprintf(str2, "%15.2x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%15.8x", -4000000);
  my_sprintf(str2, "%15.8x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8x", -4000000);
  my_sprintf(str2, "%-.8x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.8x", 4000000);
  my_sprintf(str2, "%.8x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-.8x", 4000000);
  my_sprintf(str2, "%-.8x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11x", -4000000);
  my_sprintf(str2, "%-11x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-#11x", -4000000);
  my_sprintf(str2, "%-#11x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5x", -4000000);
  my_sprintf(str2, "%-5x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8x", -4000000);
  my_sprintf(str2, "%-10.8x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8x", 4000000);
  my_sprintf(str2, "%-10.8x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10.8x", -4000000);
  my_sprintf(str2, "%-10.8x", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%13.10x", -4000000);
  my_sprintf(str2, "%13.10x", -4000000);
  ck_assert_str_eq(str, str2);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-11.11x", 4000000);
  my_sprintf(str2, "%-11.11x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-5.11x", 4000000);
  my_sprintf(str2, "%-5.11x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-9.7x", 4000000);
  my_sprintf(str2, "%-9.7x", 4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%u", (unsigned int)-4000000);
  my_sprintf(str2, "%u", -4000000);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%hx", 21323);
  my_sprintf(str2, "%hx", 21323);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%hx", -21323);
  my_sprintf(str2, "%hx", -21323);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%lx", 213232132312);
  my_sprintf(str2, "%lx", 213232132312);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%lx", -213232132312);
  my_sprintf(str2, "%lx", -213232132312);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_sprintf_e_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%.2e", 4000.1);
  my_sprintf(str2, "%.2e", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2e", -4000.1);
  my_sprintf(str2, "%.2e", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.*e", -2, -4000.1);
  my_sprintf(str2, "%.*e", -2, -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%10e", 1.0);
  my_sprintf(str2, "%10e", 1.0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10e", 1.0);
  my_sprintf(str2, "%-10e", 1.0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%e", 1.123123);
  my_sprintf(str2, "%e", 1.123123);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%e", 0.123123);
  my_sprintf(str2, "%e", 0.123123);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#.10e", 0.10000000001);
  my_sprintf(str2, "%#.10e", 0.10000000001);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%Le", 4123123123123.3123123L);
  my_sprintf(str2, "%Le", 4123123123123.3123123L);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#e", 40.32);
  my_sprintf(str2, "%#e", 40.32);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.6e", 5.99);
  my_sprintf(str2, "%.6e", 5.99);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-6e", 0.009);
  my_sprintf(str2, "%-6e", 0.009);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_sprintf_E_check) {
  char str[100];
  char str2[100];
  sprintf(str, "%.2E", 4000.1);
  my_sprintf(str2, "%.2E", 4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.2E", -4000.1);
  my_sprintf(str2, "%.2E", -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.*E", -2, -4000.1);
  my_sprintf(str2, "%.*E", -2, -4000.1);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%10E", 1.0);
  my_sprintf(str2, "%10E", 1.0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%-10E", 1.0);
  my_sprintf(str2, "%-10E", 1.0);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%E", 1.123123);
  my_sprintf(str2, "%E", 1.123123);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%E", 0.123123);
  my_sprintf(str2, "%E", 0.123123);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#.10E", 0.10000000001);
  my_sprintf(str2, "%#.10E", 0.10000000001);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%LE", 4123123123123.3123123L);
  my_sprintf(str2, "%LE", 4123123123123.3123123L);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%#E", 40.32);
  my_sprintf(str2, "%#E", 40.32);
  ck_assert_str_eq(str, str2);
  sprintf(str, "%.6E", 5.99);
  my_sprintf(str2, "%.6E", 5.99);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_sprintf_g_check) {
  char str[100];
  char str2[100];
  my_sprintf(str, "%g", 0.12345);
  sprintf(str2, "%g", 0.12345);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%.10g", 0.12345);
  sprintf(str2, "%.10g", 0.12345);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%.3g", 1.12345);
  sprintf(str2, "%.3g", 1.12345);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%g", 0.000000000000000000000003);
  sprintf(str2, "%g", 0.000000000000000000000003);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%Lg", (long double)0.000000000000000000000003);
  sprintf(str2, "%Lg", (long double)0.000000000000000000000003);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%.0Lg", (long double)0.000000000000000000000003);
  sprintf(str2, "%.0Lg", (long double)0.000000000000000000000003);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%g", 0.3);
  sprintf(str2, "%g", 0.3);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%g", 1.3);
  sprintf(str2, "%g", 1.3);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%g", -1.3);
  sprintf(str2, "%g", -1.3);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%Lg", -0.03L);
  sprintf(str2, "%Lg", -0.03L);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_sprintf_G_check) {
  char str[100];
  char str2[100];
  my_sprintf(str, "%G", 0.12345);
  sprintf(str2, "%G", 0.12345);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%G", 0.000000000000000000000003);
  sprintf(str2, "%G", 0.000000000000000000000003);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%LG", (long double)0.000000000000000000000003);
  sprintf(str2, "%LG", (long double)0.000000000000000000000003);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%G", -1.3);
  sprintf(str2, "%G", -1.3);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%LG", -0.03L);
  sprintf(str2, "%LG", -0.03L);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_sprintf_p_check) {
  char str[100];
  char str2[100];
  my_sprintf(str, "%*p", 20, str);
  sprintf(str2, "%*p", 20, str);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%-20p", str);
  sprintf(str2, "%-20p", str);
  ck_assert_str_eq(str, str2);
  my_sprintf(str, "%p", str);
  sprintf(str2, "%p", str);
  ck_assert_str_eq(str, str2);
}
END_TEST

START_TEST(test_my_sscanf_test1_d) {
  char str[] = "123 -11 0 999.12";
  int a = 0, b = 0, c = -1, d = 0, e = 0;
  int status = my_sscanf(str, "%d %d %*d %2d%d%d", &a, &b, &c, &d, &e);
  ck_assert_int_eq(status, 5);
  ck_assert_int_eq(a, 123);
  ck_assert_int_eq(b, -11);
  ck_assert_int_eq(c, 99);
  ck_assert_int_eq(d, 9);
  ck_assert_int_eq(e, 0);
}
END_TEST

START_TEST(test_my_sscanf_test2_f) {
  char str[] = "12.311 -11.5 0.123 999.12 0.1";
  float a = 0, b = 0, c = -1, d = 0, e = 0;
  int status = my_sscanf(str, "%f %f %*f %2f%f %f", &a, &b, &c, &d, &e);
  ck_assert_int_eq(status, 5);
  ck_assert_float_eq_tol(a, 12.311, 1e-6);
  ck_assert_float_eq_tol(b, -11.5, 1e-6);
  ck_assert_float_eq_tol(c, 99.0, 1e-6);
  ck_assert_float_eq_tol(d, 9.12, 1e-6);
  ck_assert_float_eq_tol(e, 0.1, 1e-6);
}
END_TEST

START_TEST(test_my_sscanf_test3_i) {
  char str[] = "123 -11 28384 213 321 8";
  int a = 0, b = 0, c = -1, d = 0, e = 0;
  int status = my_sscanf(str, "%i %i %*i %6i %i %i", &a, &b, &c, &d, &e);
  ck_assert_int_eq(status, 5);
  ck_assert_int_eq(a, 123);
  ck_assert_int_eq(b, -11);
  ck_assert_int_eq(c, 213);
  ck_assert_int_eq(d, 321);
  ck_assert_int_eq(e, 8);
}
END_TEST

START_TEST(test_my_sscanf_test3_u) {
  char str[] = "123 -11 28384 11111111 777 228";
  unsigned int a1 = 0, b1 = 0, c1 = -1, d1 = 0, e1 = 0;
  unsigned int a2 = 0, b2 = 0, c2 = -1, d2 = 0, e2 = 0;
  int n1 = 0, n2 = 0;
  sscanf(str, "%u %u %*u %6u%u%n %u", &a1, &b1, &c1, &d1, &n1, &e1);
  int status =
      my_sscanf(str, "%u %u %*u %6u%u%n %u", &a2, &b2, &c2, &d2, &n2, &e2);
  ck_assert_int_eq(status, 6);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(b1, b2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
  ck_assert_int_eq(n1, n2);
  ck_assert_int_eq(e1, e2);
}
END_TEST

START_TEST(test_my_sscanf_test4_s) {
  char str[] = "Helloworld sss sss aboba";
  char str11[11] = {'\0'};
  char str12[10] = {'\0'};
  char str13[10] = {'\0'};
  char str21[11] = {'\0'};
  char str22[10] = {'\0'};
  char str23[10] = {'\0'};
  int status1 = sscanf(str, "%s %*s %2s%s", str11, str12, str13);
  int status2 = my_sscanf(str, "%s %*s %2s%s", str21, str22, str23);

  ck_assert_int_eq(status1, status2);
  ck_assert_str_eq(str11, str21);
  ck_assert_str_eq(str12, str22);
  ck_assert_str_eq(str13, str23);
}
END_TEST

START_TEST(test_my_sscanf_test5_c) {
  char str[] = "Helloworld sss sss aboba";
  char str11;
  char str12;
  char str13[10] = {'\0'};
  char str21;
  char str22;
  char str23[10] = {'\0'};
  int status1 = sscanf(str, "%c%*c%c%c", &str11, str13, &str12);
  int status2 = my_sscanf(str, "%c%*c%c%c", &str21, str23, &str22);

  ck_assert_int_eq(status1, status2);
  ck_assert_int_eq(str11, str21);
  ck_assert_int_eq(str12, str22);
  ck_assert_str_eq(str13, str23);
}
END_TEST

START_TEST(test_my_sscanf_test6_X) {
  char str[] = "0x01010abc 0x10234e +0x11 11aB";
  unsigned int a1 = 0, a2 = 0, a3 = 0, a4 = 0, b1 = 0, b2 = 0, b3 = 0, b4 = 0;
  int status1 = sscanf(str, "%x %X %x %x", &a1, &a2, &a3, &a4);
  int status2 = my_sscanf(str, "%x %X %x %x", &b1, &b2, &b3, &b4);
  ck_assert_int_eq(status1, status2);
  ck_assert_int_eq(a1, b1);
  ck_assert_int_eq(a4, b4);
  ck_assert_int_eq(a3, b3);
  ck_assert_int_eq(a2, b2);
}
END_TEST

START_TEST(test_my_sscanf_test7_p) {
  void *p1;
  void *p2;
  char str[] = "0x001eca01";
  int status1 = sscanf(str, "%p", &p1);
  int status2 = my_sscanf(str, "%p", &p2);
  ck_assert_int_eq(status1, status2);
  ck_assert_ptr_eq(p1, p2);
}
END_TEST

START_TEST(test_my_sscanf_test8_e) {
  char str[] = "12.31e+01";
  char str1[] = "-11.5e+03";
  char str2[] = "999.12";
  char str3[] = "999.12";
  char str4[] = "0.1e+05";
  float a = 0, b = 0, c = -1, d = 0, e = 0;
  my_sscanf(str, "%e", &a);
  my_sscanf(str1, "%E", &b);
  my_sscanf(str2, "%2e", &c);
  my_sscanf(str3, "%*e %e", &d);
  my_sscanf(str4, "%e", &e);
  ck_assert_float_eq_tol(a, 123.1, 1e-6);
  ck_assert_float_eq_tol(b, -11500.0, 1e-6);
  ck_assert_float_eq_tol(c, 99.0, 1e-6);
  ck_assert_float_eq_tol(d, 10000, 1e-6);
  ck_assert_float_eq_tol(e, 10000, 1e-6);
}
END_TEST

START_TEST(test_my_sscanf_test9_g) {
  char str[] = "12.311 -11.5 0.123 999.12 0.1";
  float a = 0, b = 0, c = -1, d = 0, e = 0;
  int status = my_sscanf(str, "%g %G %*g %2G%g %G", &a, &b, &c, &d, &e);
  ck_assert_int_eq(status, 5);
  ck_assert_float_eq_tol(a, 12.311, 1e-6);
  ck_assert_float_eq_tol(b, -11.5, 1e-6);
  ck_assert_float_eq_tol(c, 99.0, 1e-6);
  ck_assert_float_eq_tol(d, 9.12, 1e-6);
  ck_assert_float_eq_tol(e, 0.1, 1e-6);
}
END_TEST

START_TEST(test_my_sscanf_test10_o) {
  char str[] = "12345 777 111324";
  int a1 = 0, c1 = 0, d1 = 0;
  int a2 = 0, c2 = 0, d2 = 0;
  int status1 = my_sscanf(str, "%o %*o %2o%o", &a1, &c1, &d1);
  int status2 = sscanf(str, "%o %*o %2o%o", &a2, &c2, &d2);
  ck_assert_int_eq(status1, status2);
  ck_assert_int_eq(a1, a2);
  ck_assert_int_eq(c1, c2);
  ck_assert_int_eq(d1, d2);
}
END_TEST

START_TEST(test_my_sscanf_test11_percent) {
  char str[] = "% 15";
  int a1 = 0, a2 = 0;
  int status1 = my_sscanf(str, "%% %d", &a1);
  int status2 = sscanf(str, "%% %d", &a2);
  ck_assert_int_eq(status1, status2);
  ck_assert_int_eq(a1, a2);
}
END_TEST

START_TEST(test_my_sscanf_test12_c_width) {
  char str[] = "aaa";
  char c1, c2;
  my_sscanf(str, "%2c", &c1);
  sscanf(str, "%2c", &c2);
  ck_assert_int_eq(c1, c2);
}
END_TEST

START_TEST(test_my_sscanf_test13_default) {
  void *p1;
  char str[] = "001eca01";
  int status = my_sscanf(str, "%r", &p1);
  ck_assert_int_eq(status, -1);
}
END_TEST

Suite *my_string_suite(void) {
  Suite *suite = suite_create("Test of my_string");
  TCase *tcase_core = tcase_create("Core of my_string");
  tcase_add_test(tcase_core, test_my_memchr);
  tcase_add_test(tcase_core, test_my_memcmp);
  tcase_add_test(tcase_core, test_my_memcpy);
  tcase_add_test(tcase_core, test_my_memset);
  tcase_add_test(tcase_core, test_my_strlen);
  tcase_add_test(tcase_core, test_my_strncat);
  tcase_add_test(tcase_core, test_my_strcmp);
  tcase_add_test(tcase_core, test_my_strcspn);
  tcase_add_test(tcase_core, test_my_strpbrk);
  tcase_add_test(tcase_core, test_my_strspn);
  tcase_add_test(tcase_core, test_my_strchr);
  tcase_add_test(tcase_core, test_my_strncpy);
  tcase_add_test(tcase_core, test_my_strstr1);
  tcase_add_test(tcase_core, test_my_strstr2);
  tcase_add_test(tcase_core, test_my_strstr3);
  tcase_add_test(tcase_core, test_my_strstr4);
  tcase_add_test(tcase_core, test_my_strstr5);
  tcase_add_test(tcase_core, test_my_strstr6);
  tcase_add_test(tcase_core, test_my_strstr7);
  tcase_add_test(tcase_core, test_my_to_upper);
  tcase_add_test(tcase_core, test_my_to_lower);
  tcase_add_test(tcase_core, test_my_strrchr1);
  tcase_add_test(tcase_core, test_my_strrchr2);
  tcase_add_test(tcase_core, test_my_strrchr3);
  tcase_add_test(tcase_core, test_my_strrchr4);
  tcase_add_test(tcase_core, test_my_strrchr5);
  tcase_add_test(tcase_core, test_my_strncmp1);
  tcase_add_test(tcase_core, test_my_strncmp2);
  tcase_add_test(tcase_core, test_my_strncmp3);
  tcase_add_test(tcase_core, test_my_strncmp4);
  tcase_add_test(tcase_core, test_my_strncmp5);
  tcase_add_test(tcase_core, test_my_strncmp6);
  tcase_add_test(tcase_core, test_my_strncmp7);
  tcase_add_test(tcase_core, test_my_strncmp8);
  tcase_add_test(tcase_core, test_my_strtok1);
  tcase_add_test(tcase_core, test_my_strtok2);
  tcase_add_test(tcase_core, test_my_strtok3);
  tcase_add_test(tcase_core, test_my_strtok4);
  tcase_add_test(tcase_core, test_my_strtok5);
  tcase_add_test(tcase_core, test_my_strtok6);
  tcase_add_test(tcase_core, test_my_strtok7);
  tcase_add_test(tcase_core, test_my_strerror);
  tcase_add_test(tcase_core, test_my_sprintf_di_test1);
  tcase_add_test(tcase_core, test_my_sprintf_di_test2);
  tcase_add_test(tcase_core, test_my_sprintf_di_test3);
  tcase_add_test(tcase_core, test_my_sprintf_di_test4);
  tcase_add_test(tcase_core, test_my_sprintf_di_test5);
  tcase_add_test(tcase_core, test_my_sprintf_di_test6);
  tcase_add_test(tcase_core, test_my_sprintf_di_test7);
  tcase_add_test(tcase_core, test_my_sprintf_di_test8);
  tcase_add_test(tcase_core, test_my_sprintf_di_test9);
  tcase_add_test(tcase_core, test_my_sprintf_di_test10);
  tcase_add_test(tcase_core, test_my_sprintf_di_test11);
  tcase_add_test(tcase_core, test_my_sprintf_di_test12);
  tcase_add_test(tcase_core, test_my_sprintf_di_test13);
  tcase_add_test(tcase_core, test_my_sprintf_di_test14);
  tcase_add_test(tcase_core, test_my_sprintf_di_test15);
  tcase_add_test(tcase_core, test_my_sprintf_di_test16);
  tcase_add_test(tcase_core, test_my_sprintf_di_test17);
  tcase_add_test(tcase_core, test_my_sprintf_di_test18);
  tcase_add_test(tcase_core, test_my_sprintf_di_test19);
  tcase_add_test(tcase_core, test_my_sprintf_di_test20);
  tcase_add_test(tcase_core, test_my_sprintf_c_test1);
  tcase_add_test(tcase_core, test_my_sprintf_с_test2);
  tcase_add_test(tcase_core, test_my_sprintf_с_test3);
  tcase_add_test(tcase_core, test_my_sprintf_s_test1);
  tcase_add_test(tcase_core, test_my_sprintf_s_test2);
  tcase_add_test(tcase_core, test_my_sprintf_s_test3);
  tcase_add_test(tcase_core, test_my_sprintf_s_test4);
  tcase_add_test(tcase_core, test_my_sprintf_s_test5);
  tcase_add_test(tcase_core, test_my_sprintf_s_test6);
  tcase_add_test(tcase_core, test_my_sprintf_u_test1);
  tcase_add_test(tcase_core, test_my_sprintf_u_test2);
  tcase_add_test(tcase_core, test_my_sprintf_u_test3);
  tcase_add_test(tcase_core, test_my_sprintf_u_test4);
  tcase_add_test(tcase_core, test_my_sprintf_u_test5);
  tcase_add_test(tcase_core, test_my_sprintf_u_test6);
  tcase_add_test(tcase_core, test_my_sprintf_u_test7);
  tcase_add_test(tcase_core, test_my_sprintf_float_1);
  tcase_add_test(tcase_core, test_my_sprintf_float_2);
  tcase_add_test(tcase_core, test_my_sprintf_float_3);
  tcase_add_test(tcase_core, test_my_sprintf_float_4);
  tcase_add_test(tcase_core, test_my_sprintf_float_5);
  tcase_add_test(tcase_core, test_my_sprintf_float_6);
  tcase_add_test(tcase_core, test_my_sprintf_float_7);
  tcase_add_test(tcase_core, test_my_sprintf_float_8);
  tcase_add_test(tcase_core, test_my_sprintf_float_9);
  tcase_add_test(tcase_core, test_my_sprintf_float_10);
  tcase_add_test(tcase_core, test_my_sprintf_float_11);
  tcase_add_test(tcase_core, test_my_sprintf_float_12);
  tcase_add_test(tcase_core, test_my_sprintf_float_13);
  tcase_add_test(tcase_core, test_my_sprintf_float_14);
  tcase_add_test(tcase_core, test_my_sprintf_float_15);
  tcase_add_test(tcase_core, test_my_sprintf_float_16);
  tcase_add_test(tcase_core, test_my_sprintf_float_17);
  tcase_add_test(tcase_core, test_my_sprintf_float_18);
  tcase_add_test(tcase_core, test_my_sprintf_float_19);
  tcase_add_test(tcase_core, test_my_sprintf_float_20);
  tcase_add_test(tcase_core, test_my_sprintf_float_21);
  tcase_add_test(tcase_core, test_my_sprintf_float_22);
  tcase_add_test(tcase_core, test_my_sprintf_float_23);
  tcase_add_test(tcase_core, test_my_sprintf_float_24);
  tcase_add_test(tcase_core, test_my_sprintf_float_25);
  tcase_add_test(tcase_core, test_my_sprintf_float_26);
  tcase_add_test(tcase_core, test_my_sprintf_float_27);
  tcase_add_test(tcase_core, test_my_sprintf_float_28);
  tcase_add_test(tcase_core, test_my_sprintf_float_29);
  tcase_add_test(tcase_core, test_my_sprintf_float_30);
  tcase_add_test(tcase_core, test_my_sprintf_float_31);
  tcase_add_test(tcase_core, test_my_sprintf_float_32);
  tcase_add_test(tcase_core, test_my_sprintf_float_33);
  tcase_add_test(tcase_core, test_my_sprintf_float_34);
  tcase_add_test(tcase_core, test_my_sprintf_float_35);
  tcase_add_test(tcase_core, test_my_sprintf_float_36);
  tcase_add_test(tcase_core, test_my_sprintf_float_37);
  tcase_add_test(tcase_core, test_my_sprintf_float_38);
  tcase_add_test(tcase_core, test_my_sprintf_float_39);
  tcase_add_test(tcase_core, test_my_sprintf_float_40);
  tcase_add_test(tcase_core, test_my_sprintf_float_41);
  tcase_add_test(tcase_core, test_my_sprintf_float_42);
  tcase_add_test(tcase_core, test_my_sprintf_float_43);
  tcase_add_test(tcase_core, test_my_sprintf_float_44);
  tcase_add_test(tcase_core, test_my_sprintf_float_45);
  tcase_add_test(tcase_core, test_my_sprintf_float_46);
  tcase_add_test(tcase_core, test_my_sprintf_float_47);
  tcase_add_test(tcase_core, test_my_sprintf_float_48);
  tcase_add_test(tcase_core, test_my_sprintf_float_49);
  tcase_add_test(tcase_core, test_my_sprintf_float_50);
  tcase_add_test(tcase_core, test_my_sprintf_float_51);
  tcase_add_test(tcase_core, test_my_sprintf_float_52);
  tcase_add_test(tcase_core, test_my_sprintf_float_53);
  tcase_add_test(tcase_core, test_my_sprintf_float_54);
  tcase_add_test(tcase_core, test_my_sprintf_float_55);
  tcase_add_test(tcase_core, test_my_sprintf_float_56);
  tcase_add_test(tcase_core, test_my_sprintf_float_58);
  tcase_add_test(tcase_core, test_my_sprintf_float_59);
  tcase_add_test(tcase_core, test_my_sprintf_float_60);
  tcase_add_test(tcase_core, test_my_sprintf_float_61);
  tcase_add_test(tcase_core, test_my_sprintf_float_62);
  tcase_add_test(tcase_core, test_my_sprintf_float_63);
  tcase_add_test(tcase_core, test_my_sprintf_float_64);
  tcase_add_test(tcase_core, test_my_sprintf_float_65);
  tcase_add_test(tcase_core, test_my_sprintf_float_66);
  tcase_add_test(tcase_core, test_my_sprintf_float_67);
  tcase_add_test(tcase_core, test_my_sprintf_float_68);
  tcase_add_test(tcase_core, test_my_sprintf_float_69);
  tcase_add_test(tcase_core, test_my_sprintf_float_70);
  tcase_add_test(tcase_core, test_my_sprintf_float_71);
  tcase_add_test(tcase_core, test_my_sprintf_float_72);
  tcase_add_test(tcase_core, test_my_sprintf_float_73);
  tcase_add_test(tcase_core, test_my_sprintf_float_74);
  tcase_add_test(tcase_core, test_my_sprintf_o_check);
  tcase_add_test(tcase_core, test_my_sprintf_x_check);
  tcase_add_test(tcase_core, test_my_sprintf_X_check);
  tcase_add_test(tcase_core, test_my_sprintf_e_check);
  tcase_add_test(tcase_core, test_my_sprintf_E_check);
  tcase_add_test(tcase_core, test_my_sprintf_p_check);
  tcase_add_test(tcase_core, test_my_sprintf_g_check);
  tcase_add_test(tcase_core, test_my_sprintf_G_check);
  tcase_add_test(tcase_core, test_my_sscanf_test1_d);
  tcase_add_test(tcase_core, test_my_sscanf_test2_f);
  tcase_add_test(tcase_core, test_my_sscanf_test3_i);
  tcase_add_test(tcase_core, test_my_sscanf_test3_u);
  tcase_add_test(tcase_core, test_my_sscanf_test4_s);
  tcase_add_test(tcase_core, test_my_sscanf_test5_c);
  tcase_add_test(tcase_core, test_my_sscanf_test6_X);
  tcase_add_test(tcase_core, test_my_sscanf_test7_p);
  tcase_add_test(tcase_core, test_my_sscanf_test8_e);
  tcase_add_test(tcase_core, test_my_sscanf_test9_g);
  tcase_add_test(tcase_core, test_my_sscanf_test10_o);
  tcase_add_test(tcase_core, test_my_sscanf_test11_percent);
  tcase_add_test(tcase_core, test_my_sscanf_test12_c_width);
  tcase_add_test(tcase_core, test_my_sscanf_test13_default);
  suite_add_tcase(suite, tcase_core);
  return suite;
}

int main(void) {
  Suite *suite = my_string_suite();
  SRunner *suite_runner = srunner_create(suite);
  srunner_run_all(suite_runner, CK_VERBOSE);
  int failed_count = srunner_ntests_failed(suite_runner);
  srunner_free(suite_runner);
  return failed_count != 0 ? 1 : 0;
}
