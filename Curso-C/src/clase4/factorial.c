#include <stdio.h>

long factorial(int n){
		
		long fact=1;
		for (int i = 1; i <= n; ++i)
			fact=fact*i;
		return fact;
	}

int ingresar_numero(){
	long n;
	do{
		printf("ingrese un numero positivo\t");
		scanf("%ld",&n);
	}while(n<0);
}

int main(){
	long n;
	n=ingresar_numero();
	printf("factorial %ld\n",factorial(n) );	
}
