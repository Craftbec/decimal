#include "s21_decimal.h"

int s21_is_greater(s21_decimal a, s21_decimal b) {
  int res = 0;
  int sign1 = get_sign(&a);
  int sign2 = get_sign(&b);
  if (!zero(a, b)) {
    if (sign1 == 0 && sign2 == 1) {
      res = 1;
    } else if (sign1 == 1 && sign2 == 0) {
      res = 0;
    } else if (sign1 == sign2) {
      scale_equalize(&a, &b);
      for (int i = 95; i >= 0; i--) {
        int bit1 = get_bit(a, i);
        int bit2 = get_bit(b, i);
        if (bit1 != bit2) {
          if (!(bit1 == 0) && bit2 == 0 && sign1 == 0) {
            res = 1;
            break;
          } else if (!(bit1 == 0) && bit2 == 0 && sign1 == 1) {
            res = 0;
            break;
          } else if (!(bit2 == 0) && sign1 == 0) {
            res = 0;
            break;
          } else if (!(bit2 == 0) && sign1 == 1) {
            res = 1;
            break;
          }
        }
      }
    }
  }
  return res;
}
