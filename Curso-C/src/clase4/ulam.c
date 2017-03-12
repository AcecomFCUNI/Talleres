#include <stdio.h>
void ulam();
int num_positivo();

void main(){
	printf("\n\t\tConjetura de ULAM\n\n");
	int n=num_positivo();
	ulam(n);

}
void ulam(int n){

	printf("%d ",n );//primera impresion del n
	do{
		if(n%2==0) n=n/2;
		else n=n*3+1;
		printf("%d ",n);
	}while(n!=1);
	puts("");

}
int num_positivo(){
	int n;
	printf("ingrese numero positivo\t");
	do{
		scanf("%d",&n);
		if (n<=0) printf("Error ingrese otro numero\t");	
	}while(n<=0);
}