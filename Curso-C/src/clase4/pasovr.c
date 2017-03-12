#include <stdio.h>
void funcion1(int a,int b){//funcion con parametros por valor
  a=a*b;
}

void funcion2(int*a,int*b){//funcion con parametros por referencia
  *a=*a * *b;
}

int main(){
  int a=4;
  int b=5;
  funcion1(a,b);//paso de parametros por valor
  printf("\n valor de a después de llamada a funcion1 es %d\n",a);
  funcion2(&a,&b);//paso de parametros por referencia
  printf("\n valor de a después de llamada a funcion2 es %d\n\n",a);

}
