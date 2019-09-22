#include <stdio.h>

int main(int argc, char const *argv[]) {
  int cone;
  int largeurTronc;
  int hauteurTronc;

  int etageBoule;
  int emplacementBoule;

  printf("Taille du cone : ");
  scanf("%d", &cone);
  printf("Largeur du tronc : ");
  scanf("%d", &largeurTronc);
  printf("Hauteur du tronc : ");
  scanf("%d", &hauteurTronc);
  printf("Etage de la boule : ");
  scanf("%d", &etageBoule);
  printf("Emplacement boule : ");
  scanf("%d", &emplacementBoule);

  printf("%d %d %d\n",cone, largeurTronc, hauteurTronc);

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
      printf(" " );
    }
    for (size_t l = 0; l < largeurTronc; l++) {
      printf("|");
    }
    printf("\n");
  }

  return 0;
}
