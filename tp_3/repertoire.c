#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAILLE 10


typedef struct Personne
{
  char num[11];
  char * nom;
} Personne ;



int main(int argc, char const *argv[]) {


  Personne repertoire[TAILLE];



  for (int i = 0; i < TAILLE; i++) {
    char numero [11];
    char nom[100];
    scanf("%s", nom);
    scanf("%s", numero);
    /*printf("%s === ", nom);
    printf("%s\n", numero);*/

    repertoire[i].nom = malloc(sizeof(char) * strlen(nom));
    for (size_t j = 0; j < strlen(nom); j++) {
      *(repertoire[i].nom + j) = *(nom+j);
    }


    for (size_t k = 0; k < 11; k++) {
      repertoire[i].num[k] = numero[k];
    }
  }

  for (int k = 0; k < TAILLE; k++) {
    printf("%s: %s\n", repertoire[k].nom, repertoire[k].num);
  }

  for (size_t i = 0; i < TAILLE; i++) {
    free(repertoire[i].nom);
  }
  
  return 0;
}
