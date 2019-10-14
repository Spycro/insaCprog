#include "bitwise.h"
#include <stdio.h>

int main(int argc, char const *argv[]) {
  char a = 0;
  a = set_bit(a, 1);
  printf("%d\n", a);
  return 0;
}
