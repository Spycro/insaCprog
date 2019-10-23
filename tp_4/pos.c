#include <stdio.h>
#include <stdlib.h>


#define buff


void remplissage(FILE * flot,char * buffer);
char* bufferize(FILE* file);
void affiche(FILE * stream);
void replace(FILE * stream, char k, int offset);
void replaceBuffer(char * stream, char k, int offset);
void afficheBuffer(char * stream);


int main(int argc, char const *argv[]) {
/*
  #ifdef noBuff
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
  #endif

*/
  #ifdef buff
  FILE * flot = fopen("flot.txt", "w+");
  for(int i = 0; i<20; i++){
    for (size_t k = 0; k < 40; k++) {
      fputc('_', flot);
    }
    fputc('\n', flot);
  }
  rewind(flot);
  char * buffer = bufferize(flot);
  int offset;
  char c = 'a';


  while(c != 'q')
  {
      afficheBuffer(buffer);
      printf("\n");
      printf("charactère que vous voulez ajoutez : ");
      scanf(" %c", &c);
      printf("\nOffset : ");
      scanf("%d", &offset);
      printf("\n");
      replaceBuffer(buffer, c, offset);
  }
  printf("Sortie de la boucle\n");
  remplissage(flot, buffer);
  free(buffer);

  rewind(flot);
  fputc('a', flot);
  fclose(flot);
  #endif
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

void afficheBuffer(char * stream){
  int i = 0;
  while(*(stream + i) != '\0')
  {
    printf("%c", *(stream + i));
      i++;
  }
}

void replace(FILE * stream, char k, int offset){
  if(offset >= 40){
    offset  += offset/40;
  }


  fseek(stream,offset, SEEK_SET);
  printf("Charactere que l'on remplace : %d\n", fgetc(stream));
  fseek(stream,offset, SEEK_SET);
  fputc(k, stream);
  rewind(stream);
}

char * bufferize(FILE* fp){
  char *source = NULL;
  if (fp != NULL) {
      /* Go to the end of the file. */
      if (fseek(fp, 0L, SEEK_END) == 0) {
          /* Get the size of the file. */
          long bufsize = ftell(fp);
          if (bufsize == -1) { /* Error */ }

          /* Allocate our buffer to that size. */
          source = malloc(sizeof(char) * (bufsize + 1));

          /* Go back to the start of the file. */
          if (fseek(fp, 0L, SEEK_SET) != 0) { /* Error */ }

          /* Read the entire file into memory. */
          size_t newLen = fread(source, sizeof(char), bufsize, fp);
          if ( ferror( fp ) != 0 ) {
              fputs("Error reading file", stderr);
          } else {
              source[newLen++] = '\0'; /* Just to be safe. */
          }
      }
  }

  return source;
}

void replaceBuffer(char * stream, char k, int offset){
  if(offset >= 40){
    offset  += offset/40;
  }
  *(stream + offset) = k;
}

void remplissage(FILE * flot,char * buffer){
  int i = 0;
  rewind(flot);
  printf("remplissage en cours\n");
  while(*(buffer + i) != '\0'){
    fputc((int)*(buffer + i), flot);
    i++;
  }
}
