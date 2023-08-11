#include "s21_decimal.h"

int s21_round(s21_decimal value, s21_decimal *result) {
  int err_code = 0;
  s21_decimal value2 = {0};
  s21_decimal value3 = {0};
  s21_decimal add = {.bits[0] = 1, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  s21_decimal compare = {
      .bits[0] = 5, .bits[1] = 0, .bits[2] = 0, .bits[3] = 0};
  int sign = s21_get_sign(value);
  int scale = s21_get_scale(value);
  if (scale) {
    if (sign) s21_setbit(&value, 127, 0);
    s21_truncate(value, &value2);
    s21_sub(value, value2, &value3);
    s21_set_scale(&value3, s21_get_scale(value3) - 1);
    s21_truncate(value3, &value3);
    if (s21_is_less(value3, compare)) {
      if (sign) s21_setbit(&value2, 127, 1);
      s21_copy(value2, result);
    } else {
      if (s21_is_equal(value3, compare)) {
        if (s21_checkbit(value2, 0)) {
          s21_add(value2, add, result);
          if (sign) s21_setbit(result, 127, 1);
        } else {
          s21_copy(value2, result);
          if (sign) s21_setbit(result, 127, 1);
        }
      } else {
        s21_add(value2, add, result);
        if (sign) s21_setbit(result, 127, 1);
      }
    }
  } else {
    s21_copy(value, result);
  }
  if (sign) s21_setbit(&value, 127, 1);
  return err_code;
}
