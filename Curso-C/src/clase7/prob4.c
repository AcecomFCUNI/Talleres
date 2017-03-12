#include <stdio.h> 
#define TAM 20
void main(){
	int a[TAM],i,cont=0;
	int* p=&a[0];
 	for (i = 0; i < TAM; ++i)
 	{
 		*p=i*i;
 		p++;
 		printf("%d ",a[i] );
 	}
 	puts("");
}
