#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char const *argv[]) {
  srandom(time(NULL));
  FILE* discours=fopen("ldb/discours.txt","w");
  FILE* file1=fopen("ldb/1","r");
  FILE* file2=fopen("ldb/2","r");
  FILE* file3=fopen("ldb/3","r");
  FILE* file4=fopen("ldb/4","r");

  FILE* tabFile[4]={file1,file2,file3,file4};
  char* phrase;
  phrase=malloc(sizeof(char)*1000);

  for(int j=0;j<5;j++){
  rewind(file1);
  rewind(file2);
  rewind(file3);
  rewind(file4);



    int ligne;
    char c;
    for(int i=0;i<4;i++){
      ligne=1;
      int ligneVoulu=(int)((random()%8)+1);
      while(ligne!=ligneVoulu){
        c=fgetc(tabFile[i]);
        if(c==10) ligne++;
      }
      fgets(phrase,1000,tabFile[i]);
      printf("%s",phrase);
      fputs(phrase,discours);
      printf("yolo\n" );
    }
  }


  free(phrase);
  fclose(file1);
  fclose(file2);
  fclose(file3);
  fclose(file4);
  fclose(discours);

  return 0;
}
