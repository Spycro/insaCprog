#include <stdio.h>

int facto(int n);
int factoRec(int n);

int main(int argc, char const *argv[]) {
  int nombre = factoRec(8);
  printf("%d\n", nombre);
  return 0;
}


int facto(int n){
  int tab[n];
  for(int i =0; i<n; i++) {
    tab[i] = i+1;
  }
  int fact = 1;
  for(int i =0; i<n; i++){
    fact *= tab[i];
    printf("%d  ", fact);
  }
  printf("Factorielle de %d : %d\n", n, fact);
  return fact;
}

int factoRec(int n){
  if(n==0){
    return 1;
  }
  else{
    return n*factoRec(n-1);
  }
}
