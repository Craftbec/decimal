#include "s21_decimal.h"

int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  result->bits[0] = result->bits[1] = result->bits[2] = result->bits[3] = 0;
  int res = 0;
  int sign_result = 5;
  if (get_sign(&value_1) != get_sign(&value_2)) {
    sign_result = 1;
  } else {
    sign_result = 0;
  }
  set_sign(&value_1, 0);
  set_sign(&value_2, 0);
  int bit1 = last_bit(value_1);

  for (int i = 0; i <= bit1; i++) {
    s21_decimal tmp_res = {{0, 0, 0, 0}};
    int value_bit_1 = get_bit(value_1, i);

    if (value_bit_1) {
      tmp_res = value_2;
      left(&tmp_res, i);
      res = bit_addition(result, &tmp_res, result);
    }
  }
  if (res) {
    while (get_scale(&value_1) > 0 || get_scale(&value_2) > 0) {
      s21_decimal *value_1_1, *value_2_1;
      if (last_bit(value_1) > last_bit(value_2) && get_scale(&value_1) > 0) {
        value_1_1 = &value_1;
        value_2_1 = &value_2;
      } else if (last_bit(value_2) > last_bit(value_1) &&
                 get_scale(&value_2) > 0) {
        value_1_1 = &value_2;
        value_2_1 = &value_1;
      } else {
        break;
      }
      int scale2 = get_scale(value_1_1);
      s21_scale_decrease(value_1_1, 1);
      set_scale(value_1_1, --scale2);
      return s21_mul(*value_1_1, *value_2_1, result);
    }
  }

  int scale = get_scale(&value_1) + get_scale(&value_2);
  set_scale(result, scale);
  set_sign(result, sign_result);
  if (res && sign_result) res = 2;
  return res;
}
