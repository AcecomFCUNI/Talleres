#include <stdio.h>
int primo(int n){
	int cont=0;
	for (int i = 1; i <=n/2 ; ++i){
		if(n%i==0) cont++;
		if(cont>1)return 0;
	}
	return 1;
}
int golbach(int n){
	for (int i = 2; i < n; ++i)
		for (int j = 2; j < n; ++j)
			if(primo(i)&&primo(j)&&i+j==n){
				printf("%d = %d + %d\n",n,i,j );
				return 1;
			}
}
void main(){
	printf("conjetura de golbach hasta el numero 100\n");
	for (int i = 4; i <= 100; i+=2)
		golbach(i);
}