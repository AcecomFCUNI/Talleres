#include <stdio.h>
void menormayor(int*men,int*may){
	int n;
	printf("ingrese el 1 numero\t" );
	scanf("%d",&n);
	*men=n;*may=n;
	for (int i = 2; i <= 10; ++i){
	  printf("ingrese el %d numero\t",i );
	  scanf("%d",&n);
	  if(n>*may) *may=n;
	  if(n<*men) *men=n;

	}
}
float potencia(int b,int e){
	int ban=1;
	float potencia=1;
	if(e==0) return 1;
	else{
	   if(e<0) ban=-1;
	   for(int i=1;i<=e*ban;i++)
		potencia*=b;
	   if(e<0) return 1.0/potencia;
	   else return potencia;
	}

	
}
void main(){
 	int menor;
 	int mayor;
	float p;
 	menormayor(&menor,&mayor);
 	printf("el menor valor es: %d\n",menor);
 	printf("el mayor valor es: %d\n",mayor);
	p=potencia(mayor,menor);
	printf("%d^%d= %f",mayor,menor,p);
	
}
