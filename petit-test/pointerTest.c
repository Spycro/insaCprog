#include <stdio.h>
#include <stdlib.h>


void changeInt(int * pointer);

int main(int argc, char const *argv[]) {



  printf("\n");


  int i = 5;
  int * a = &i;
  char t = 'a';
  char * c = &t;
  printf("%p\n", a);
  printf("%p\n", c);
  c = c+1;
  a = a + 1;
  printf("%p\n", a);
  printf("%p\n", c);

  return 0;
}

void changeInt(int * pointer){
  *pointer = 10;
}
