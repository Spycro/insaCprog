#include <stdio.h>
#include <string.h>
#include <stdlib.h>




typedef struct File {
  int debut;
  int fin;
  int tab[100];
}File;

void queue(File * file, int val);
int dequeue(File * file, int * val);




int main(int argc, char const *argv[]) {
  char lecture[100];
  int val;

  File * maFile;
  maFile = malloc(sizeof(File));
  maFile->debut = 0;
  maFile->fin = 0;

  scanf("%s", lecture);
  while (strcmp(lecture,"bye")!=0) {
    if (strcmp(lecture,"queue")==0) {
      /*fscanf(stdin,"%99s",lecture);
      val = strtol(lecture,NULL,10);*/
      scanf("%d", &val);

      queue(maFile,val);
      //printf("%d, %d, %d\n", maFile->debut, maFile->fin, val);
    } else if (strcmp(lecture,"dequeue")==0) {
      if(dequeue(maFile,&val))
      {
        //printf("%d, %d\n", maFile->debut, maFile->fin);
        //printf("On dequeue!\n");
        printf("%d\r\n",val);
      }
    }
    //fscanf(stdin,"%99s",lecture);
    scanf(" %s", lecture);
  }
  return 0;
}


void queue(File * file, int val){
  //file pleine
  if((file->debut-file->fin)%100==1){
    //printf("file pleine");
  }else{
    file->tab[file->fin]=val;
    file->fin++;
    if(file->fin==100){
      file->fin=0;
    }
  }

}

int dequeue(File * file, int * val){
  if(file->debut == file->fin){
  //  printf("file vide\n");
    return 0;
  }
  else{
    *val=file->tab[file->debut];
    file->debut++;
    if(file->debut==100){
      file->debut=0;
    }
    return 1;
  }
}
