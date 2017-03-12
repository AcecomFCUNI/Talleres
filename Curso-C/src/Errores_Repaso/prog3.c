#include <stdio.h>
void ingresar_datos(int* a, int*b){
	printf("ingrese el primer numero\t");
		scanf("%d",*a);
	printf("ingrese el segundo numero\t");
		scanf("%d",*b)
}

int main()
{
	int x,y;
	ingresar_datos(x,y);
	return 0;
}