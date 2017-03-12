#include <stdio.h>
void main(){
	int a, b,c,d,e;
	int* p[5];
	p[0]=&a;
	p[1]=&b;
	p[2]=&c;
	p[3]=&d;
	p[4]=&e;
	*p[0]=6;//cambio valor de a
	*p[3]=10;//cambio valor de d
	printf("valor de a=%d\n",a );
	printf("valor de d=%d\n",d );
}