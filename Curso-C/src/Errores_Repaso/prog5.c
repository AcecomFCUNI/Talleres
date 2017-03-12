#include <stdio.h>
long potencia(int n,int c){
	return n*pontencia(n,c+1)
}
int main()
{	
	long p;
	printf("ingrese el valor n\t");
	scanf("%d",&n);
	p=potencia(n);
	printf("la potencia de n es:\t",p);

	return 0;
}