#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main(){
	srand(time(NULL));
	int n=rand()%11;
	int x,i;
	printf("----------Adiniva el numero----------\n");
	i=0;
	do{
		printf("Cual es el número misterioso? Pista: el número esta entre 0 a 10  \t");
		scanf("%d",&x);
		i++;
		if(x!=n)
		printf("error intente otro numero\n");
	}while(x!=n);

	printf("adivinaste el numero en el intento %d\n",i );
}