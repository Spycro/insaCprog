#include <stdio.h>

int main(int argc, char const *argv[]) {
  while(1){
    printf("Entrer votre valeur : \n");
    int val = 0;
    scanf("%d", &val);
    printf("Votre valeur : %d\n", val);
    if(val == 1000){
      printf("Dans le mille !\n" );
    }
    else if(val <1000 && val >101){
      printf("Valeur trop petite !\n");
    }
    else if(val <=100){
      printf("Valeur beaucoup trop petite !\n");
    }
    else if(val>1000 && val <10000){
      printf("Valeur trop grande !\n" );
    }
    else{
      printf("Valeur beaucoup trop grande !\n" );
    }
}
  return 0;
}
