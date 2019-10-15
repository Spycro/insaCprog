#include <stdio.h>
#include <stdlib.h>




int main(int argc, char const *argv[]) {


  const char * path = argv[1];

  FILE * fichier = fopen("texte1.txt", "r");
  FILE * newFile = fopen(path, "w");
  char c;
  while((c = fgetc(fichier)) != EOF)
  {
    fputc(c, newFile);
  }

  fclose(fichier);

  return 0;
}
