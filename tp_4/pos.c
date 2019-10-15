#include <stdio.h>

void affiche(FILE * stream);
void replace(FILE * stream, char k, int offset);


int main(int argc, char const *argv[]) {
  FILE * flot = fopen("flot.txt", "w+");
  for(int i = 0; i<20; i++){
    for (size_t k = 0; k < 40; k++) {
      fputc('_', flot);
    }
    fputc('\n', flot);
  }
  rewind(flot);

  int offset;
  char c = 'a';
  while(c != 'q')
  {
      affiche(flot);
      printf("\n");
      printf("charactère que vous voulez ajoutez : ");
      scanf(" %c", &c);
      printf("\nOffset : ");
      scanf("%d", &offset);
      printf("\n");
      replace(flot, c, offset);
  }

  fclose(flot);
  return 0;
}


void affiche(FILE * stream){
  char c;
  while((c = fgetc(stream)) != EOF)
  {
    printf("%c", c);
  }
  rewind(stream);
}

void replace(FILE * stream, char k, int offset){
  fseek(stream, offset, SEEK_SET);
  printf("Charactere que l'on remplace : %d\n", fgetc(stream));
  fseek(stream, offset, SEEK_SET);
  fputc(k, stream);
  rewind(stream);


}
