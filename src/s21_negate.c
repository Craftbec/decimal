#include "./s21_decimal.h"

int s21_negate(s21_decimal value, s21_decimal *result) {
  int err_code = 0;
  s21_copy(value, result);
  int sign = get_sign(result);
  if (sign)
    set_sign(result, 0);
  else
    set_sign(result, 1);
  return err_code;
}
