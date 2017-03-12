#include <stdio.h>
int perfecto(int n){
	int s=0;
	for (int i = 1; i <= n/2; ++i){
		if (n%i==0)
			s+=i;
	}
	return s==n?1: 0;
}

void main(){
	int a;
	printf("ingrese un numero\t");
	scanf("%d",&a);
	if(perfecto(a)) printf("el numero %d es perfecto\n",a);
	else printf("el numero %d no es perfecto\n",a);

}