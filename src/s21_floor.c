#include "./s21_decimal.h"

int s21_floor(s21_decimal value, s21_decimal *result) {
  int err_code = 0;
  int scale = get_scale(&value);
  if (scale) {
    s21_decimal sub = {.bits[0] = 1, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
    s21_truncate(value, result);
    int sign = get_sign(&value);
    if (sign) {
      set_sign(result, 0);
      s21_add(*result, sub, result);
      set_sign(result, 1);
    }
  } else {
    s21_copy(value, result);
  }
  return err_code;
}
