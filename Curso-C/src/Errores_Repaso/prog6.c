#include <stdio.h>
#define TAM 10
int i=0;
void llenar_array(int a[TAM]){
	for (; i < TAM; ++i)
	{
		printf("ingrese el elemento %d\t",i );
		scanf("%d",&a[i]);
	}
}
void imprimir_array(int b[TAM]){
	for (; i < TAM; ++i)
	{
		printf("%d ",a[i]);
	}
	printf("\n");
}
int main()
{	
	int a[TAM];
	llenar_array(a);
	imprimir_array(a);
	return 0;
}