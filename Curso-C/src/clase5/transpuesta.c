	#include <stdio.h>
	#include <stdlib.h>
	void llenarM();
	void mostrar();
	void ingresar_orden_matriz();
	void transpuesta();
	int main(){
		int m,n;
		ingresar_orden_matriz(&m,&n);
		float a[m][n],t[n][m];
		llenarM(m,n,a);
		mostrar(m,n,a);
		transpuesta(m,n,a,t);
		mostrar(n,m,t);
		return 0;
	}
	void mostrar(int f,int c,float M[f][c]){
		puts("");
		int i,j;
		for (i = 0; i <f; ++i){
			for (j = 0; j < c; ++j)
			{
				printf("%.1f ",M[i][j] );
			}
			printf("\n");
		}
		puts("");
	}

	void ingresar_orden_matriz(int*m,int*n){
		int m1,n1;
		do{
			printf("ingrese el orden de la Matriz A\n");
			  scanf("%d %d",&m1,&n1);

		}while(n1<1||m1<1);
		*m=m1;
		*n=n1;
	}

	void llenarM(int f,int c,float M[f][c]){
		int i,j;
		for (i = 0; i < f; ++i)
			for (j = 0; j < c; ++j)
				M[i][j]=rand()%10;

	}

	void transpuesta(int f,int c,float M[f][c],float T[c][f]){
		int i,j;
		for (i = 0; i < f; ++i)
			for (j = 0; j < c; ++j)
				T[j][i]=M[i][j];
	}
