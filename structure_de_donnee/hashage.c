#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/* mettez ici vos déclarations de fonctions et types */

typedef char * Key;

typedef struct {
  char state; // 'E'; 'S' ; 'R'
  Key key;
  char * value;
} Cell;

typedef struct{
    int size;
    Cell * tab;
    int used;
} Hash;


void inserer(Hash * hashTable, Key key, char * val);
void delete(Hash * hashTable, Key key);
void query(Hash * hashTable, Key key);
void destroy(Hash * hashTable);
void stat(Hash* hashTable);

void error(void);

int main(void)
{
   int size;
   char lecture[100];
   char * key;
   char * val;
   Hash * hashTable;

   if (fscanf(stdin,"%99s",lecture)!=1)
      error();
   while (strcmp(lecture,"bye")!=0)
   {
      if (strcmp(lecture,"init")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         size = atoi(lecture);
         /* mettre le code d'initialisation ici */
         hashTable = malloc(sizeof(Hash));
         hashTable->size = size;
         hashTable->tab = malloc(sizeof(Cell) * size);
         hashTable->used = 0;
         uint i;
         for(i = 0; i < size; i++){
           // init a empty pour chaque case
           hashTable->tab[i].state = 'E';
         }
      }
      else if (strcmp(lecture,"insert")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         val = strdup(lecture);

         inserer(hashTable, key, val);
      }
      else if (strcmp(lecture,"delete")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);

         delete(hashTable, key);

         free(key);
      }
      else if (strcmp(lecture,"query")==0)
      {
         if (fscanf(stdin,"%99s",lecture)!=1)
            error();
         key = strdup(lecture);

         query(hashTable, key);

         free(key);


      }
      else if (strcmp(lecture,"destroy")==0)
      {
         /* mettre ici le code de destruction */
         destroy(hashTable);

      }
      else if (strcmp(lecture,"stats")==0)
      {
         /* mettre ici le code de statistiques */
         stat(hashTable);
      }

      if (fscanf(stdin,"%99s",lecture)!=1)
         error();
   }
   return 0;
}

/* fonction de décalage de bit circulaire */
unsigned int shift_rotate(unsigned int val, unsigned int n)
{
  n = n%(sizeof(unsigned int)*8);
  return (val<<n) | (val>> (sizeof(unsigned int)*8-n));
}

/* fonction d'encodage d'une chaîne de caractères */
unsigned int Encode(Key key)
{
   unsigned int i;
   unsigned int val = 0;
   unsigned int power = 0;
   for (i=0;i<strlen(key);i++)
   {
     val += shift_rotate(key[i],power*7);
     power++;
   }
   return val;
}

/* fonction de hachage simple qui prend le modulo */
unsigned int hash(unsigned int val, unsigned int size)
{
   return val%size;
}

/* fonction de hachage complète à utiliser */
unsigned int HashFunction(Key key, unsigned int size)
{
   return hash(Encode(key),size);
}

/* placer ici vos définitions (implémentations) de fonctions ou procédures */

void inserer(Hash * hashTable, Key key, char * val){
  //printf("Debut insertion !\n");
  if(hashTable->used != hashTable->size){
    uint hKey = HashFunction(key, hashTable->size);
    while(hashTable->tab[hKey].state == 'S'){

      if(strcmp(key, hashTable->tab[hKey].key) == 0){
        hashTable->used--;
        break;
      }
      hKey++;
      if(hKey == hashTable->size) hKey = 0;
    }
    hashTable->tab[hKey].value = val;
    hashTable->tab[hKey].key = key;
    hashTable->used++;
    hashTable->tab[hKey].state='S';
    //printf("valeur inserer : %s\n", val);
  }
}

void delete(Hash * hashTable, Key key){
  uint hKey=HashFunction(key, hashTable->size);
  int cmt=0;
  while(cmt!=hashTable->size&&hashTable->tab[hKey].state!='E'){
    if(hashTable->tab[hKey].state!='R'&&strcmp(hashTable->tab[hKey].key,key)==0){
      free(hashTable->tab[hKey].value);
      free(hashTable->tab[hKey].key);
      hashTable->used--;
      hashTable->tab[hKey].state='R';
      //printf("Setting a state to R\n");
    }
    hKey++;
    cmt++;
  }
}

void query(Hash * hashTable, Key key){
  uint hKey = HashFunction(key, hashTable->size);
  int cmt=0;
  short found = 0;
  while(cmt!=hashTable->size&&hashTable->tab[hKey].state!='E'){
    if(hashTable->tab[hKey].state!='R'&&strcmp(hashTable->tab[hKey].key,key)==0){
      found = 1;
      printf("%s\r\n", hashTable->tab[hKey].value);
    }
    hKey++;
    cmt++;
  }
  if(!found){
    printf("Not Found\r\n");
  }
}

void destroy(Hash * hashTable){
  uint i;
  for(i=0;i<hashTable->size;i++){
    if(hashTable->tab[i].state=='S'){

      free(hashTable->tab[i].value);
      free(hashTable->tab[i].key);
   }
  }
  free(hashTable->tab);
  free(hashTable);
}


void stat(Hash* hashTable){
  printf("size    : %d\r\n",hashTable->size);
  uint cmtE=0;
  uint i;
  for(i=0;i<hashTable->size;i++){
    if(hashTable->tab[i].state=='E'){
      cmtE++;
    }
  }
  printf("empty   : %d\r\n",cmtE);
  printf("deleted : %d\r\n",hashTable->size-cmtE-hashTable->used);
  printf("used    : %d\r\n",hashTable->used);

}

void error(void)
{
   printf("input error\r\n");
   exit(0);
}
