# Punteros 
## Conceptos Previos
- **Tipos de variables:** las variables pueden almacenar solo el tipo de valores con el que fueron declaradas entre este tipos tenemos: int,float,long y ahora int**, float ***,etc.
- **Dirección de Memoria:** Es la referencia al espacio de memoria donde se almacena una variable. Al declarar una variable automaticamente se le asigna una dirección de memoria. En la siguiente imagen vemos como se declara la variable y luego se imprime el valor de la dirección de memoria.
```c
int a;
printf("la direccion de memoria de la variable a es : %p \n",&a);
```
- **Contenido o valor de la variable:** es el valor que almacena la variable en su espacio de memoria.
```c
  int a=5; //la variable a de tipo entero almacena el valor entero 5.
  int* b=&a;// la variable b de tipo int* almacena la dirección de memoria de la variable a
```
##Definición
Los punteros son variables que contienen una dirección de memoria. Los punteros trabajan a nivel de memoria su
incorrecta manipulación o falta de conceptos suelen ocasionar errores al programar.
<br>
<img src="https://upload.wikimedia.org/wikipedia/commons/b/b4/Pointers.svg" width="500"> <br>
**Descripción de la imagen:**
- En la imagen anterior tenemos 2 variables a y b.
- La variable **a** posee una dirección de memoria 0002 y en el valor de su contenido es **1008**
- La variable **b** posee una dirección de memoria **1008**(el valor del contenido de la variable **a**).
- Al **a** almacenar la dirección de memoria de **b** se dice que **a** apunta a **b** al tener su dirección de memoria **puede acceder
al contenido de la variable b y modificarlo**.

##Declaración de un puntero
```c
int* p1; //declaración de un puntero a un entero
float* p2;//declaración de un puntero a un flotante
```
##Asignación 

```c
int* p=&a;//primera forma
p=&b;//2da forma
```
- En la primera forma de asignación la hacemos al momento de la declaración, el puntero **p** apuntara a la variable **a**.
- En la segunda forma se realiza a lo largo del programa en este caso se cambio el puntero **p** que apuntaba a la variable a ahora apunta a la variable **b**.

##Conceptos
**Operadores**

- Operador Dirección (&): devuelve la dirección de memoria de una variable. Se usa este operador para asignar valores a variables de tipo puntero.
- Operador Indirección(*): devuelve el contenido del objeto referencia por el puntero.

```c
  int a;
  int*p
  p=&a;//& operador dirección devuelve dirección de memoria de a
  *p=5;//operador indireccion cambio el valor de la variable a al valor de 5
```

## NULL
Debido a que el sistema operativo se encarga de administrar las direcciones de memorias  que se pueden usar no se podria realizar la siguiente asignación.

```c
int *puntero=0xbf1b2c8;
```
La asignación seria incorrecta debido a que este espacio de memoria puede estar ocupado o no existir por lo cual se puede usar el puntero NULL. 
```c
int *puntero=NULL;
```
**NULL** es un espacio de memoria con dirección que existe y pertenece al sistema por lo cual podemos usarlo. Es comumente usado para decir que el puntero no apunta a ninguna dirección.

##Errores Comunes

+ Asignar punteros de distintos tipos.
```c
int a;
float b;
int* p1=&a;
float* p2=&b
p1=p2;//error tipo int * y tipo float*
```
+ Utilizar punteros no inicializados.
```c
int *p1;
*p1=5;//error hacia donde esta apuntado p1??
```
+ Asignar valor a un puntero y no a la variable a la que esta apuntando
```c
int a;
int *p=&a;
p=5;//error p es dirección de memoria usar operador indireccion para cambio *p
```
+ Intentar asignarle un dato a un puntero cuando este esta apuntando a NULL.
```c
int *puntero=NULL;
*puntero=5;//error
```
##Punteros y Arrays
Podemos usar los punteros para recorrer los arrays. Esto con la ayuda de aritmetica de punteros la cual consiste en sumar o restar numeros enteros al puntero lo cual nos permite movernos a las siguientes direcciones de memoria.

```c
  int a[50];
  int* p=&a[0];// el puntero apunta al primer elemento de indice 0
  p=a;// es equivalente a la expresion p=&a[0]
  *p=1;// el puntero asigna a[0]=1
  p++; el puntero se desplaza hacia la siguiente dirección de memoria
  *p=5;//asigna a[1]=5;
  p=p+2;// el puntero se desplaza 2 posiciones de memoria 
  *p=10;//asigna a[3]=10;
  p=p-1;//el puntero retrocede una posición ahora apunta a  a[2]
```

Analogamente para cadenas

```c
char* p="hola mundo";
```
**Notas:**
```c
	int* p1=&a;
	int* p2;
	p2=p1;
```

En la imagen superior vemos p2=p1 lo cual significa que p2 guardara la direccion de memoria que estaba guardando p1 ,es decir **p2 apunta a donde esta apuntando p1**
```c
if(p1==p2){
printf("apunta al mismo valor\n");
}
```
Podemos comparar direcciones de memoria al igual cualquier tipo de datos.

##Problemas Propuestos
1. **Realizar un problema que llene un array y que muestre el array de forma ordenada y a continuación de forma de invertida es decir si el array es 1 4 6 7 4 debera imprimir 1 4 6 7 4 7 6 4 1**
```c
#include <stdio.h>
#define TAM 10
int main()
{
	int paso=1;
	int cont=0,i=0;
	int a[TAM]={6,2,4,5,1,6,3,8,2,1};
	int*p=&a[0];
	while(cont!=2){
		if(i==0) cont++;
		printf("%d ",*p );
		if(i==TAM-1) paso=-1;
		p=p+paso;
		i=i+paso;

	}
	puts("");
	return 0;
}
```
2. **Se dispone de una cadena de caracteres, leída de teclado y correctamente almacenada (con su marcador de fin de cadena). Se pide escribir una función que muestre en pantalla la cadena caráctere a carácter**
3. **Realizar una función que realice el paso por referencia para obtener el numero que mas se repite en una array**
4. **Usando el puntero NULL verificar si en array de tamaño 50 existen un numero 3°+2 y 5°+1 si es asi que el puntero apunte a el sino mostrar en consola que no existe**
5. **Se dispone de dos listas de enteros de tamaño 10, y se desea conocer la suma de productos de elementos homólogos. Se pide construir una función que calcule este valor**

[Ejercicios Punteros](https://github.com/AcecomFCUNI/Talleres/tree/master/Curso-C/src/clase7)
