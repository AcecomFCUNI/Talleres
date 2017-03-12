#include <stdio.h>//doble puntero
int main()
{
	int a=5;
	int* p1;
	int** p2;
	p1=&a;
	p2=&p1;
	printf("valor de **p2=%d\n",**p2 );
	printf("valor de a=%d\n",a );
	**p2=10;
	printf("valor de **p2=%d\n",**p2 );
	printf("valor de a=%d\n",a );
	printf("ingrese valor **p2\t");
	scanf("%d",*p2);
	printf("valor de **p2=%d\n",**p2 );
	printf("valor de a=%d\n",a );


	return 0;
}