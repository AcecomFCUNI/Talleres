/*Girlfriend Algorithm*/
#include <stdio.h>

#define error 1
#define false 0

int main(){

	int opcion = 1;

	if(opcion){
		printf("Te parece atractiva ? s/n :  ");
		scanf("%d",&opcion);

		if(opcion){
			printf("Tiene buen caracter ? s/n :  ");
			scanf("%d",&opcion);

			if(opcion){
				printf("Es inteligente ? s/n :  ");
				scanf("%d",&opcion);
			}else	
				return false;

		}else
			return false;
	}else
		return false;


}