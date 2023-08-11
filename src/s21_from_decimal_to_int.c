#include "s21_decimal.h"

int s21_from_decimal_to_int(s21_decimal src, int *dst) {
  int result = 1;
  if (!src.bits[1] && !src.bits[2]) {
    *dst = src.bits[0];
    if (get_sign(&src)) {
      *dst = *dst * -1;
    }
    *dst /= (int)pow(10, get_scale(&src));
    result = 0;
  }
  return result;
}
