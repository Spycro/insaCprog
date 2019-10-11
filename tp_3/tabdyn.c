#include <stdio.h>
#include <stdlib.h>
#define TAILLE 10

int main(int argc, char const *argv[]) {

  int i = 0;

  int * tabOld = malloc(sizeof(int) * TAILLE);
  int * tabNew;
  int tailleTotale = TAILLE;
  int k = 0;

  while (1)
  {
    int number;
    int nbtokens = scanf("%d", &number);
    if(nbtokens != 1 || feof(stdin))
      break;

    if(i == tailleTotale){
        tabNew = malloc(sizeof(int) * tailleTotale * 2);

        for (k = 0; k < tailleTotale; k++) {
          tabNew[k] = tabOld[k];
        }
        free(tabOld);
        tabOld = tabNew;
        tailleTotale *= 2;
    }

    tabOld[i] = number;

    i++;
  }

  int max=tabOld[0];
  int min=tabOld[0];
  int sum=0;
  int j=0;
  for(j=0; j<tailleTotale; j++){
    if(min>*(tabOld+j)){
      min=tabOld[j];
    }
    if(max<tabOld[j]){
      max=tabOld[j];
    }
    sum+=tabOld[j];
  }


  printf("min : %d max : %d moy : %d\n",min,max,(sum/tailleTotale));
  free(tabOld);
  return 0;
}
