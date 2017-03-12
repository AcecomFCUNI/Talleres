#include <stdio.h>

void menu_impresion(){
	printf("\tMenu\n");	
	printf("1.Conjetura de ulam \n");
	printf("2.Primo \n");
	printf("3.Perfecto \n");		
 	printf("0. Salir\n");
}

int num_positivo(){
	int n;
	printf("ingrese numero positivo\t");
	do{
		scanf("%d",&n);
		if (n<=0) printf("Error ingrese otro numero\t");	
	}while(n<=0);
}

void ulam(){
	printf("\n\t\tConjetura de ULAM\n\n");
	int n=num_positivo();
	printf("%d ",n );//primera impresion del n
	do{
		if(n%2==0) n=n/2;
		else n=n*3+1;
		printf("%d ",n);
	}while(n!=1);
	puts("");

}

void primo(){
	printf("\n\t\tNumero Primo\n\n");
	int n=num_positivo();
	int cont=1;
	for (int i = 2; i <= n/2; ++i)
	{
		if(n%i==0) cont++;
		if(cont>1) i=n;
	}
	if (cont==1) printf("el numero %d es primo\n",n);
	else printf("el numero %d no es primo\n",n);

}

void perfecto(){
	printf("\n\t\tNumero Perfecto\n\n");
	int n=num_positivo();
	int s=0;
	for (int i = 1; i <= n/2; ++i){
		if (n%i==0)
			s+=i;
	}
	if(s==n) printf("el numero %d es perfecto\n",n);
	else printf("el numero %d no es perfecto\n",n);

}
void menu(){
	int opcion;
	do{
		menu_impresion();
		printf("elija una opcion\t");
		scanf("%d",&opcion);
		switch(opcion){
			case 1:ulam();
			  break;
			case 2:primo();
			  break;
			case 3:perfecto();
			  break;
			case 0:;
			  break;
			default:printf("opcion invalida\n");
			  break;
		}
	}while(opcion!=0);
}

void main()
{
	menu();
	
}