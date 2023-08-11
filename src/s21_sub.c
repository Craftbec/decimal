#include "s21_decimal.h"

int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
  int res = 5;
  int result_sign = 5;
  int sign1 = get_sign(&value_1);
  int sign2 = get_sign(&value_2);
  scale_equalize(&value_1, &value_2);
  if (sign1 != sign2) {
    result_sign = sign1;
    set_sign(&value_1, 0);
    set_sign(&value_2, 0);
    res = s21_add(value_1, value_2, result);
    set_sign(result, result_sign);
  } else {
    if (s21_is_equal(value_1, value_2)) {
      result->bits[0] = 0;
      result->bits[1] = 0;
      result->bits[2] = 0;
      result->bits[3] = 0;
      res = 0;
    } else {
      set_sign(&value_1, 0);
      set_sign(&value_2, 0);
      s21_decimal *small, *big;
      if (s21_is_less(value_1, value_2)) {
        small = &value_1;
        big = &value_2;
        result_sign = !sign2;
      } else {
        small = &value_2;
        big = &value_1;
        result_sign = sign1;
      }
      convert(small);
      res = s21_add(*small, *big, result);
      set_sign(result, result_sign);
    }
  }
  if (res && result_sign) res = 2;
  return res;
}
