#include <stdio.h>
#include <stdlib.h>

typedef struct Complexe {

  float re;
  float im;

} Complexe;

void affiche(Complexe bob);
Complexe multiplication(Complexe c,Complexe d);
Complexe somme(Complexe c,Complexe d);

int main(int argc, char const *argv[]) {
  Complexe nb1;
  Complexe nb2;
  float a;
  float b;
  float c;
  float d;
  scanf("%f%f%f%f",&a,&b,&c,&d);

  nb1.re=a;
  nb1.im=b;
  nb2.re=c;
  nb2.im=d;

  affiche(multiplication(nb1,nb2));
  return 0;
}


  void affiche (Complexe bob){
    if(bob.im<0){
      printf("%f-%f*i\n",bob.re,-bob.im);
    }
    else{
      printf("%f+%f*i\n",bob.re,bob.im );
    }
  }

  Complexe somme(Complexe c,Complexe d){
    Complexe result;
    result.re=c.re+d.re;
    result.im=c.im+d.im;
    return result;
  }

  Complexe multiplication(Complexe c,Complexe d){
    Complexe result;
    result.re=c.re*d.re-c.im*d.im;
    result.im=c.im*d.re+d.im*c.re;
    return result;

  }
