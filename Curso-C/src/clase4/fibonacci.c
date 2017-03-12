#include <stdio.h>
int fibonacci();
int main()
{
	printf("Los 10 primeros numeros de fibonacci son:\n");
	for (int i = 1; i <= 10; ++i)
	{
		printf("%d ", fibonacci(i));
	}
	puts("");
	return 0;
}
int fibonacci(int n){//devuelve el n-esimo termino de fibonnacci
	if(n==1||n==2)
		return 1;
	else return fibonacci(n-1)+fibonacci(n-2);
}