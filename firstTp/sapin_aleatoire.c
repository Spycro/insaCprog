#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>


int main(int argc, char const *argv[]) {
  int cone;
  int largeurTronc;
  int hauteurTronc;

  int etageBoule;
  int emplacementBoule;


    /* initialiser le generateur de nombres aleatoires */
  srand((unsigned) time(NULL));

  /* afficher 5 nombres entiers aleatoires compris 0 et 49 */


  while(1){

    //Generation des carac du sapins
    cone = rand()%40 +1 ;
    largeurTronc = rand()%5 + 1;
    hauteurTronc = rand()%4 +1;

    etageBoule = rand() % cone +1;
    emplacementBoule = rand() % etageBoule + 1;

    //affichage du sapin

    for(int i = 0; i<cone;i++){
      for(int j = 0; j<cone-i;j++){
        printf(" ");
      }
      for (int k = 0; k < (i*2)+1; k++) {
        if (etageBoule-1 == i && emplacementBoule-1 == k) {
          printf("O");
        }
        else{
          printf("*");
        }
      }
      printf("\n");
    }
    for (size_t i = 0; i < hauteurTronc; i++) {
      for (size_t k = 0; k < cone - largeurTronc/2; k++) {
        printf(" ");
      }
      for (size_t l = 0; l < largeurTronc; l++) {
        printf("|");
      }
      printf("\n");
    }
    sleep(1);
  }
  return 0;
}
