#include <stdio.h> 
#define TAM 20
void main(){
	int a=5;
	int* p1=&a;
	int* p2;
	p2=p1;
	if(p2==p1)
	printf("los puntero apunta al mismo valor\n *p1=%d\n*p2=%d\n",*p1,*p2 );

}