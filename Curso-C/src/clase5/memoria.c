#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 10
int a[TAM];
void imprimir_direcciones(){
	int i;
	for (i = 0; i < TAM; ++i)
		printf("%p \n",&a[i] );
	printf("\n");
}
void main(){
	imprimir_direcciones();

}