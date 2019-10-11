#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define TAILLE 10

int main(int argc, char const *argv[]) {

  int n;
  scanf("%d\n", &n);
  int * tab = malloc(sizeof(int) * n);


  for(int i=0;i<n;i++){
    scanf("%d",tab+i);
  }


  int max=INT_MIN;
  int min=INT_MAX;
  int sum=0;
  for(int i = 0; i<n; i++){
    if(min>tab[i]){
      min=tab[i];
    }
    if(max<tab[i]){
      max=tab[i];
    }
    sum+=tab[i];
  }


  printf("min : %d max : %d moy : %lf\n",min,max,((double)sum/n));
  return 0;
}
