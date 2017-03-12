#include <stdio.h>//cambiar valores
int main()
{
	float a;
	float* p;
	p=&a;
	printf("ingrese el un valor para la variable a\t");
	scanf("%f",&a);
	printf("el valor a donde apunta p es %f\t",*p);
	a=a*5;//al cambiar el apuntar sabra que se realizo un cambio
	puts("");
	printf("el valor a donde apunta p es %f\t",*p);

	puts("");
	return 0;
}