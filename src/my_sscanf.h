#ifndef MY_SSCANF_H
#define MY_SSCANF_H

#include "my_string.h"

#define MAXWIDTH 100

void d_(const char **s, long int *res, int ingor, int width);
void cC_(const char **s, char *res, int ingor, int width);
void i_(const char **s, int *res, int ingor, int width);
void f_(const char **s, float *res, int ingor, int width);
void o_(const char **s, unsigned int *res, int ingor, int width);
void sSpecifier(const char **s, char *res, int ingor, int width);
void u_(const char **s, unsigned int *res, int ingor, int width);
void p_(const char **s, void **res, int ingor);
void procent_(const char **s, int width);
void n_(const char **s, int *count, const char *str);
void x_(const char **s, unsigned int *res, int ingor, int width);
void e_(const char **s, float *res, int ingor, int width);
int normis(const char **s);

#endif