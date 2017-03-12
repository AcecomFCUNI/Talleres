#include <stdio.h>
void mayor(int a,int b){
	if (a>b)
		printf("%d mayor que %d\n",a,b );
	if(b>a)
		printf("%d mayor que %d\n",a,b);
	if(b=a)
		printf("los numeros %d  y %dson iguales\n"&a,&b);
}


int main()
{
	float x,y;
	printf("ingrese el 1er numero\t");
		scanf("%d",x);
	printf("ingrese el 2do numero\t");
		scanf("%d",y);
	mayor(x,y);
	return 0;
}