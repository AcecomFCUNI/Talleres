/*logaritmo.c*/
/*Programa que hace cambio de base con logaritmos*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	float base , x;
	float log;

	printf("Ingresar el numero y la base:\n");
	scanf("%f%f",&x,&base);	
	log = log10(x) / log10(base);

	printf("El logaritmo de %f en base %f es %f \n",x,base,log);
	
	return 0;
}
