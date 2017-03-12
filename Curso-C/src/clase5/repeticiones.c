#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100
int a[TAM];
void imprimir_arreglo(){
	int i;
	for (i = 0; i < TAM; ++i)
		printf("%d ",a[i] );
	printf("\n");
}
void llenarArray(){
	int i;
	srand(time(NULL));
	for (i = 0; i < TAM; ++i)
		a[i]=1+rand()%50;
}
void contador(int n){
	int cont=0,i;
	for (i = 0; i <TAM; ++i){
		if (a[i]==n)
		  cont++;
	}
	printf("\ncantidad de %d=%d\n",n,cont);
}
void main(){
	int i;
	llenarArray();
	imprimir_arreglo();
	for (i = 1; i <=10 ; ++i)
		contador(i);
}