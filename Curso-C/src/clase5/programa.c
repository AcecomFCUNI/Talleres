#include <stdio.h>
#define TAM 10
void imprimir_arreglo(int a[TAM]){
	int i;
	for (i = 0; i < TAM; ++i)
		printf("%d ",a[i] );
	printf("\n");
}
int fibonacci(int n){//devuelve el n-esimo termino de fibonnacci
	if(n==1||n==2)
		return 1;
	else return fibonacci(n-1)+fibonacci(n-2);
}
int main()
{	
	int i;
	int nterm=0;//el numero de termino de fibonacci
	int a[TAM];
	for (i = 0; i < TAM; ++i)
	{
		if(i%3==0){//tendran secuencia de fibonacci
			nterm=nterm+1;//cada vez que sea multiplo de 3 el contador se incrementara 
			a[i]=fibonacci(nterm);//se guarda ese termino en los multiplos de 3
		}
		else if(i%3==1)
			a[i]=i*2;
		else
			a[i]=i*i*i;
	}
	imprimir_arreglo(a);
	return 0;
}