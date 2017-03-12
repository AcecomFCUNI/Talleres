#include <stdio.h>
int primo();
int num_positivo();

void main(){
	printf("\n\t\tNumero primo\n\n");
	int n=num_positivo();
	if(primo(n)) 
		printf("el numero %d es primo\n",n );
	else 
		printf("el numero %d no es primo\n",n );

}
int primo(int n){
	int cont=1;
	for (int i = 2; i <= n/2; ++i)
	{
		if(n%i==0) cont++;
		if(cont>1) break;//termina el bucle
	}
	if (cont==1) return 1;
	else return 0;

}
int num_positivo(){
	int n;
	printf("ingrese numero positivo\t");
	do{
		scanf("%d",&n);
		if (n<=0) printf("Error ingrese otro numero\t");	
	}while(n<=0);
}