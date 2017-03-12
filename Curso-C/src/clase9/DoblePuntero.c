/*Identidad.c*/
/*Matrix Identidad*/
#include <stdio.h>
#include <stdlib.h>

void imprimir(int **p, int n)
{
    int i,j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%5d",*(*(p+i)+j));
        }
        printf("\n");
    }
}

int main()
{
    int i=0,j=0,n;
    printf("Ingrese el numero de filas y de columnas de la matrix:\n");
    do{
    scanf("%d",&n);
    }while(n<0);
    int **p1;
    p1=malloc(sizeof(int*)*n);
    for(i=0;i<n;i++)
	{
        p1[i]=malloc(sizeof(int)*n);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(i==j)
                *(*(p1+i)+j)=1;
            else
                *(*(p1+i)+j)=0;
        }
    }
    imprimir(p1,n);
    for(i=0;i<n;i++)
        free(p1[i]);
    free(p1);
    return 0;
}
