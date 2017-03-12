#include <stdio.h> //memorias
void main(){
 int a=5;
 int b=10; 
 int* p=&a;
 printf("direccion de memoria de &a= %p\n",&a);
 printf("valor de a=%d\n",a );
 printf("valor de p=%p\n",p);
 printf("valor al que apunta *p=%d\n",*p );
 puts("");
 p=&b;
 printf("direccion de memoria de &b= %p\n",&b);
 printf("valor de b=%d\n",b );
 printf("valor de p=%p\n",p);
 printf("valor al que apunta *p=%d\n",*p );
 puts("");
 printf("direccion de memoria de p=%p\n",&p );
  
}