#include <stdio.h>
#define TAM 100
void mostrar(int n,int M[TAM][TAM]){
		puts("");
		int i,j;
		for (i = 0; i <n; ++i){
			for (j = 0; j < n; ++j)
			{
				printf("%d ",M[i][j] );
			}
			printf("\n");
		}
		puts("");
}
void ingresar_val(int n,int M[TAM][TAM]){
		int i,j;
		for (i = 0; i <n; ++i){
			for (j = 0; j < n; ++j)
			{
				printf("M[%d][%d]=\t",i,j);
				scanf("%d",&M[i][j]);
			}
		}
}
int simetrica(int n ,int M[TAM][TAM]){
	int i,j;
	int ban=1;
	for (i = 0; i < n && ban==1; ++i)
		for (j = 0; j < n && ban==1; ++j)
		{
			if(M[i][j]!=M[j][i])
				ban=0;
		}
	return ban;
}
void main()
{
	int n;
	printf("ingrese el tamaño de la matriz\n");
	scanf("%d",&n);
	int a[TAM][TAM];
	ingresar_val(n,a);
	mostrar(n,a);
	if (simetrica(n,a))
		printf("matriz simetrica\n");
	else printf("matriz no simetrica\n");

}