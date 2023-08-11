#include "s21_decimal.h"

int s21_from_decimal_to_float(s21_decimal src, float *dst) {
  int result = 1;
  if (dst != NULL) {
    double tmp = 0;
    int e = 0;
    for (int i = 0; i < 96; i++) {
      if ((src.bits[i / 32] & (1 << i % 32)) != 0) tmp += pow(2, i);
    }
    if ((e = get_scale(&src)) > 0) {
      for (int i = e; i > 0; i--) tmp /= 10.0;
    }
    *dst = (float)tmp;
    if (get_sign(&src)) {
      *dst *= -1;
    }
    result = 0;
  }
  return result;
}
