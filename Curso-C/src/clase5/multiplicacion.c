	#include <stdio.h>
	#include <stdlib.h>
	void llenarM();
	void mostrar();
	void multiplicar();
	void ingresar_orden_matriz();
	int main(){
		int m,n,p;
		ingresar_orden_matriz(&m,&n,&p);
		float a[m][n],b[n][p],c[m][p];
		llenarM(m,n,a);
		llenarM(n,p,b);
		mostrar(m,n,a);
		mostrar(n,p,b);
		multiplicar(m,n,p,a,b,c);
		mostrar(m,p,c);
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

	void ingresar_orden_matriz(int*m,int*n,int*p){
		int m1,n1,m2,n2;
		do{
			printf("ingrese el orden de la Matriz A\n");
			  scanf("%d %d",&m1,&n1);
			printf("ingrese el orden de la Matriz B\n");
			  scanf("%d %d",&m2,&n2);
			if(n1!=m2) printf("Error elija otros valores las matrices no se pueden multiplicar\n");
		}while(n1!=m2);
		*m=m1;
		*n=n1;
		*p=n2;
	}

	void llenarM(int f,int c,float M[f][c]){
		int i,j;
		for (i = 0; i < f; ++i)
			for (j = 0; j < c; ++j)
				M[i][j]=rand()%10;

	}

	void multiplicar(int m,int n,int p,float A[m][n],float B[n][p],float C[m][p]){
		int i,j,k;
		for (i = 0; i < m; ++i)
			for (j= 0; j <p; ++j)
			{	
				C[i][j]=0;
				for (k = 0; k <n ; ++k)
					C[i][j]+=A[i][k]*B[k][j];
			}
	}





