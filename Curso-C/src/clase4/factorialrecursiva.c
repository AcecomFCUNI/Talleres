#include <stdio.h>
long factorial(int n){
   if(n==0) //caso base finaliza la recursividad
     return 1;
   else 
    return n*factorial(n-1);//llamda recursiva
}
void main(){

 printf("factorial de 5= %ld\n",factorial(5));
}
