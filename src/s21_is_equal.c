#include "s21_decimal.h"

int s21_is_equal(s21_decimal a, s21_decimal b) {
  int res = 1;
  if (get_sign(&a) == get_sign(&b)) {
    scale_equalize(&a, &b);
    for (int i = 95; i >= 0; i--) {
      int bit1 = get_bit(a, i);
      int bit2 = get_bit(b, i);
      if (bit1 != bit2) {
        res = 0;
      }
    }
  } else if (!a.bits[0] && !a.bits[1] && !a.bits[2] && !b.bits[0] &&
             !b.bits[1] && !b.bits[2]) {
    res = 1;
  } else {
    res = 0;
  }
  return res;
}
