#include <stdio.h>

/*
#define MIN(a, b) ((a < b) ? a : b)
#define MAX(a, b) ((a > b) ? a : b)
*/


int main(int argc, char const *argv[])
{
	int a, b;
	int mayor;

	printf("Ingresa dos numeros : ");
	scanf("%d%d",&a,&b);

	mayor = a > b ? a : b ; 

	printf("El mayor entre %d y %d es : %d \n",a,b,mayor;


	return 0;
}