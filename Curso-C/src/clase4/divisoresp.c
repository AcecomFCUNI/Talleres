#include <stdio.h>
void divisores(int n,int div){
if(div==n)
  printf(" ");
else
{ 
	if (n%div==0)
	{
	printf(" %d es divisor propio de %d\n",div,n);
 	 divisores(n,div+1);
	}
	else
	 divisores(n,div+1);
}
}
int main(){
	int n,divisor;
	printf("ingrese un numero:");
	scanf("%d",&n);
	divisores(n,1);
	return 0;
}
