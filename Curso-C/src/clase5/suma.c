#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void llenar_matriz(int f, int c,int m[f][c]){
	int i,j;
	for(i=0;i<f;i++)
	  for(j=0;j<c;j++)
	    m[i][j]=rand()%100;
}
void mostrar_matriz(int m[3][3]){
	int i,j;
	for(i=0;i<3;i++){
	  for(j=0;j<3;j++)
	    printf("%d ",m[i][j]);	
	  printf("\n");	 
	}
	puts("");
}

void sumar(int f,int c,int a[f][c],int b[f][c],int d[f][c]){
	int i,j;	
	for(i=0;i<f;i++)
	  for(j=0;j<c;j++)
		d[i][j]=a[i][j]+b[i][j];			
}

void main(){
	srand(time(NULL));
	int a[3][3];
	int b[3][3];
	int c[3][3];
	puts("");
	llenar_matriz(3,3,a);
	llenar_matriz(3,3,b);
	mostrar_matriz(a);
	mostrar_matriz(b);
	sumar(3,3,a,b,c);
	mostrar_matriz(c);

}
