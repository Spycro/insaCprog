#include <stdio.h>
int main()
{
  printf("0. %c\n", 'a' );
  printf("1. %c\n", 65);
  printf("2. %d\n", 100);
  printf("3. %x\n", 100);
  printf("4. %o\n", 100);
  printf("5. %#x\n", 100);
  printf("6. %#o\n", 100);
  printf("7. %4.2f \n", 3.1416);
  printf("8. %E \n", 3.1416);
  printf("9. %*d \n", 5, 10);
  return 0;
}
