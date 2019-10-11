#include <stdio.h>
#include <string.h>
#include <math.h>
#include <errno.h>
#include <assert.h>

#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))


void swap(int * a, int * b);
int TP_strcmp(char* a,char* b);
int atoi(char* a);
void itoa(int a);
double div(double a, double b);

int main(int argc, char const *argv[]) {
/*
  double d = 13.12;
  printf("%lf %p\n", d, &d);
  double* ptr_d=&d;
  printf("%p %p\n",ptr_d,&ptr_d );
  *ptr_d =58.3;
  printf("%lf %p\n", d, &d);
  double* bob;
  printf("%lf\n",*bob );

  float f;
  void * pf;

  //double tab[10]={1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
  int tab2[9]={1,2,3,4,5,6,7,8,9};
  int tab3[10]={101,102,103,104,105,106,107,108,109,110};
  double multitab[10][2];
  double vect [20];


  //pf=tab;

  //double * pd = tab;

  for (int i = 0; i < 10; i++) {
    printf("adresse de ligne : %p\n",&multitab[i]);
    for (int k = 0; k < 2; k++) {
      printf("adress de case : %p\n",&multitab[i][k]);
    }

  }

  for(int i=0;i<20;i++){

    printf("%p\n",(vect+i));

  }
*/

  /*
  printf("a=%d addr : %p\nb=%d addr : %p\n",a,&a,b,&b);
  printf("----------------------------\n" );
  swap(&a,&b);
  printf("----------------------------\n" );
  printf("a=%d addr : %p\nb=%d addr : %p\n",a,&a,b,&b);
  */
/*  char my_string[]="1254854";
  printf("%d\n",atoi(my_string));
  char my_str2[] = "cacahuete";

  printf("%d\n", TP_strcmp(my_string,my_str2));


  int test = -1524;
  itoa(test);*/

  sqrt(-1);
  printf("%s\n", strerror(errno));

  double a = 5;
  double b = 0;
  printf("%lf\n", div(a,b));
  return 0;
}


void swap(int * a, int * b){
  printf("ptr a : %p \nptr b : %p\n",a,b );
  int c=*a;
  *a=*b;
  *b=c;
  printf("ptr a : %p \nptr b :  %p\n",a,b );
}


int TP_strcmp(char* a,char* b){


  for (size_t i = 0; i < MAX(strlen(a),strlen(b)); i++) {
      if(*(a+i) > *(b+i)){
        return 1;
      }
      else if(*(a+i) < *(b+i)){
        return -1;
      }
  }


  return 0;
}

int atoi(char* a){
  int out=0;
  for(int i=0;i<strlen(a);i++){
    if((*(a+i)<48)||(*(a+i)>57)){
      return 0;
    }
    out += (*(a+i) - 48)*pow(10, strlen(a)-i-1);
  }
  return out;
}

void itoa(int a){
  short neg = 0;
  if(a<0){
    neg = 1;
    a = -a;
  }
  char out[11] = "0000000000";
  int b = 0;
  int i = 10;
  while(a > 0){
    b = a%10;
    out[i] = 48 + b;
    a = a / 10;
    i--;
  }
  if(neg)
    printf("-%s\n", out);
  else
    printf("%s\n", out);
}

double div(double a, double b){
  double ret = 0;
  assert(b != 0);

  ret = a/b;
  return ret;
}
