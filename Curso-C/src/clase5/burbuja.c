#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 20

void burbuja();
void imprimir_arreglo();
void main()
{
	srand(time(NULL));
	int i,arreglo[TAM];
	printf("arreglo sin ordenar\n");
	for (i = 0; i < TAM; ++i){
		arreglo[i]=rand()%100+1;
		printf("%d ",arreglo[i] );
	}
	burbuja(arreglo);
	printf("\narreglo ordenado\n");
	imprimir_arreglo(arreglo);

}

void burbuja(int a[TAM]){
	int aux,i,j;
	for (i = 0; i < TAM; ++i)
		for (j = 1; j < TAM-i; ++j)
		{
			if (a[j-1]>a[j])
			{
				aux=a[j-1];
				a[j-1]=a[j];
				a[j]=aux;
			}
		}
}	

void imprimir_arreglo(int a[TAM]){
	int i;
	for (i = 0; i < TAM; ++i)
		printf("%d ",a[i] );
	printf("\n");
}