#ifndef SRC_S21_DECIMAL_H_
#define SRC_S21_DECIMAL_H_

#include <math.h>
#include <stdio.h>

typedef struct {
  unsigned int bits[4];
} s21_decimal;

typedef union {
  int ui;
  float fl;
} floatbits;

#define S21_INT_MAX 2147483647
#define S21_INT_MIN -2147483648
#define S21_INF 1.0 / 0.0
#define S21_MAX_UINT 4294967295

int s21_is_less(s21_decimal a, s21_decimal b);
int s21_is_greater(s21_decimal a, s21_decimal b);
int s21_is_equal(s21_decimal a, s21_decimal b);
int s21_is_not_equal(s21_decimal a, s21_decimal b);
int s21_is_less_or_equal(s21_decimal a, s21_decimal b);
int s21_is_greater_or_equal(s21_decimal a, s21_decimal b);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

//////////////////////////////////////// Вспомогательные функции #1
int getFSign(float *src);
int get_sign(s21_decimal *d);
int get_bit(s21_decimal d, int bit);
int get_scale(s21_decimal *d);
int getExp(float *src);
int last_bit(s21_decimal number);
int zero(s21_decimal a, s21_decimal b);
int scale_equalize(s21_decimal *a, s21_decimal *b);
int bit_addition(s21_decimal *a, s21_decimal *b, s21_decimal *res);
int s21_div1(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
             s21_decimal *tmp);
void set_bit(s21_decimal *d, int bit, int value);
void set_sign(s21_decimal *d, int sign);
void set_scale(s21_decimal *d, int scale);
void s21_print_decimal(s21_decimal value);
void s21_scale_decrease(s21_decimal *value, int shift);
void s21_scale_increase(s21_decimal *value, int shift);
void s21_scale_increase1(s21_decimal *value, int shift);
void bits_copy(s21_decimal *dest, s21_decimal src);
void right(s21_decimal *d, int g);
void convert(s21_decimal *d);
void left(s21_decimal *d, int g);

//////////////////////////////////////// Вспомогательные функции #2
void s21_copy(s21_decimal from, s21_decimal *to);
int s21_get_scale(s21_decimal value);
void s21_set_scale(s21_decimal *value, int size);
int s21_get_sign(s21_decimal value);
int s21_checkbit(s21_decimal value, int bit);
void s21_setbit(s21_decimal *value, unsigned int bit, int size);
int s21_only_sign(s21_decimal first, s21_decimal second);

#endif  // SRC_S21_DECIMAL_H_
