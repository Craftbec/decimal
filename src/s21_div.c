#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
  int res = 1;
  int sign = 0;
  int sign1 = get_sign(&value_1);
  int sign2 = get_sign(&value_2);
  if (sign1 != sign2) sign = 1;
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  if (!value_2.bits[0] && !value_2.bits[1] && !value_2.bits[2]) {
    res = 3;
  } else {
    s21_decimal tmp = {0};
    set_scale(&value_1, 0);
    set_scale(&value_2, 0);
    s21_div1(value_1, value_2, result, &tmp);
    res = 0;
  }
  set_sign(result, sign);
  return res;
}

int s21_div1(s21_decimal value_1, s21_decimal value_2, s21_decimal *result,
             s21_decimal *tmp) {
  int res = 0;
  for (int i = last_bit(value_1); i >= 0; i--) {
    if (get_bit(value_1, i)) set_bit(tmp, 0, 1);
    if (s21_is_greater_or_equal(*tmp, value_2)) {
      s21_sub(*tmp, value_2, tmp);
      if (i != 0) left(tmp, 1);
      if (get_bit(value_1, i - 1)) set_bit(tmp, 0, 1);
      left(result, 1);
      set_bit(result, 0, 1);
    } else {
      left(result, 1);
      if (i != 0) left(tmp, 1);
      if ((i - 1) >= 0 && get_bit(value_1, i - 1)) set_bit(tmp, 0, 1);
    }
  }
  return res;
}
