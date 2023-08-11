#include "./s21_decimal.h"

int s21_truncate(s21_decimal value, s21_decimal *result) {
  int err_code = 0;
  int scale = get_scale(&value);
  if (scale) {
    s21_decimal tmp = {0};
    s21_copy(value, &tmp);
    s21_scale_decrease(&tmp, scale);
    s21_copy(tmp, result);
  } else {
    s21_copy(value, result);
  }
  return err_code;
}
