#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  dst->bits[0] = dst->bits[1] = dst->bits[2] = dst->bits[3] = 0;
  int result = 1, sign = getFSign(&src), exp = getExp(&src);
  if (dst && src != 0 && (src != S21_INF || src != -S21_INF)) {
    double temp = (double)fabs(src);
    int scale = 0;
    for (; scale < 28 && (int)temp / (int)pow(2, 21) == 0;
         temp *= 10, scale++) {
    }
    temp = round(temp);
    if (scale <= 28 && (exp > -94 && exp < 96)) {
      floatbits mant;
      temp = (float)temp;
      for (; fmod(temp, 10) == 0 && scale > 0; scale--, temp /= 10) {
      }
      mant.fl = temp;
      exp = getExp(&mant.fl);
      set_bit(dst, exp, 1);
      for (int i = exp - 1, j = 22; j >= 0; i--, j--) {
        if ((mant.ui & (1 << j)) != 0) {
          set_bit(dst, i, 1);
        }
      }
      if (sign) {
        set_sign(dst, 1);
      }
      set_scale(dst, scale);
      result = 0;
    }
  }
  return result;
}
