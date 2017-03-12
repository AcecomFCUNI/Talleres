#Arrays de punteros
Es un vector o arreglos que tiene por elementos punteros es decir almacenara direcciones de memoria.
Ejemplo:
```c
#include <stdio.h>
void main(){
	int a, b,c,d,e;
	int* p[5];
	p[0]=&a;
	p[1]=&b;
	p[2]=&c;
	p[3]=&d;
	p[4]=&e;
	*p[0]=6;//cambio valor de a
	*p[3]=10;//cambio valor de d
	printf("valor de a=%d\n",a );
	printf("valor de d=%d\n",d );
}
```
#Dobles Punteros
Son variables que almacenan direcciones de memoria de otras variables punteros. Es decir punteros que apunten a otros punteros.
```c
#include <stdio.h>//doble puntero
int main()
{
	int a=5;
	int* p1;
	int** p2;
	p1=&a;
	p2=&p1;
	printf("valor de **p2=%d\n",**p2 );
	printf("valor de a=%d\n",a );
	**p2=10;
	printf("valor de **p2=%d\n",**p2 );
	printf("valor de a=%d\n",a );
	printf("ingrese valor **p2\t");
	scanf("%d",*p2);
	printf("valor de **p2=%d\n",**p2 );
	printf("valor de a=%d\n",a );


	return 0;
}
```
- p1 es un puntero que almacenara la dirección de memoria de p1.
- p2 es puntero que almacenara la dirección de memoria del puntero p1 por lo tanto es un doble puntero ya que apunta a un punero
<br>
<img src="https://4.bp.blogspot.com/_vooP-k3QJww/RyVGqdozgzI/AAAAAAAAABg/4BYR3CjB7to/s320/Array2d.png" width="600"> <br>

##Ejercicios
1. Dado 2 punteros p1 que apunta a **a** y p2 que apunta a **b** realizar una funcion que haga que p1 apunte a donde apuntaba p2(b) y que p2 apunte a donde apuntaba p1(a)
2. Dado un array con elementos del 0 al 9 verificar si el numero es capicua ejemplo a[]={6,1,2,1,6}; seria capicua.
3. Verificar si una cadena es palindrome por ejemplo hoaoh es palindrome ya que si lo inviertes es la misma cadena.
