#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  int i,n;
  n=5;


    /* initialiser le generateur de nombres aleatoires */
  srand((unsigned) time(NULL));

  /* afficher 5 nombres entiers aleatoires compris 0 et 49 */
  for( i = 0 ; i < n ; i++ ) {
    printf("%d\n", rand());
  }

  printf("The maximum random number is : %d\n",RAND_MAX);

  return 0;
}
