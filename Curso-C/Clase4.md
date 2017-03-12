## Funciones

Una función es una porción de código escrita para realizar una tarea determinada, pueden ser usadas múltiples veces en un programa. Hasta ahora ya hemos utilizados funciones definidas en la librería stdio como el printf y scanf ahora comenzaremos a definir nuestras propias funciones para que realicen las tareas que nosotros deseemos.

## Definición de una función
```c
int funcion(char arg1, float arg2, ...){
    int retorno;
    /*
    declaraciones y operaciones
    */
    return retorno;

}
```
- int : indica el tipo de dato que debe devolver la función. En caso no devuelve nada usar tipo **void**.
- funcion: es el nombre que posee la función para futuras llamadas.
- arg1,arg2,.. : son argumentos de las funciones pueden ser de distintos tipos. **Una función puede o no tener argumentos**

## Ejemplo función
```c
long factorial(int n){
	
	long fact=1;
	for (int i = 1; i <= n; ++i)
		fact=fact*i;
	return fact;
}
```

En el ejemplo
- long: indica el tipo de retorno que coincide con tipo de dato de fact.
- factorial: es el nombre de la función que sirve de identificador para futuras llamadas.
- n: es el único argumento en esta función.

**Notas:**
- Es importante definir una función antes de llamarla en el código.
- Una función puede llamar a otras funciones.
- No pueden existir 2 funciones con el mismo nombre.
- La función principal es el main, a partir del main se llaman a las otras funciones.

## Prototipos de funciones 
Son parecidos a la definición de una función pero terminan con punto y coma luego de los parentesis. Luego se define la función despues del main.
**Nota**: En los propotipos no es necesarios especificar los argumentos.
- **Función con prototipo**
```c
#include<stdio.h>
int sumar();//prototipo de la función
int main(){
	int n;
	n=sumar(5,7);//llamada a la función
	printf("el valor de la suma=%d\n",n );	
}
int sumar(int a,int b){
	return a+b;
}
```
- **Funcion sin prototipo**
```c
#include <stdio.h>
int sumar(int a,int b){
	return a+b;
}

int main(){
	int n;
	n=sumar(5,7);//llamada a la función
	printf("el valor de la suma=%d\n",n );	
}
```
##Tipos de Parámetros
- **Parámetros por valor:** son copias de las variables que son pasadas a la función cualquier cambio interno que se haga en la función no afectan las variables que fueron pasadas.
- **Parámetros por referencia:** poseen la dirección de memoria de las variables que son pasadas los cambios que se realicen en la función afectaran a las variables originales. Para los llamada a la función se debe usar el & con se muestra a continuación.
```c
#include <stdio.h>
void funcion1(int a,int b){//funcion con parametros por valor
  a=a*b;
}

void funcion2(int*a,int*b){//funcion con parametros por referencia
  *a=*a * *b;
}

int main(){
  int a=4;
  int b=5;
  funcion1(a,b);//paso de parametros por valor
  printf("\n valor de a después de llamada a funcion1 es %d\n",a);
  funcion2(&a,&b);//paso de parametros por referencia
  printf("\n valor de a después de llamada a funcion2 es %d\n\n",a);

}
```
## Variables globales y locales
- **Locales:** las variables locales son definidas dentro de una función incluso la principal(main). Solo existen dentro de la función, si se intenta llamar fuera de la función ocurrirá un error.
```c
int f1(){
	int a=5; // a es una variable local solo existe dentro de f1
	return 1;
}
```
- **Globales:** Todas las variables que sean declaras fuera de la función main y/o otras funciones sera una variable global lo cual significa que su valor y dirección de memoria es conocido en cada parte programa.
```c
float b=3.2;// variable global
int f2(){//
	float a=5*b; // podemos hacer uso de la variable b ya que fue declarada globalmente
	return a;
}
```
## Funciones Recursivas
Es un tipo de función que realiza llamadas a si misma dentro de su definición, lo que quiere decir que llamara a la función con otros parámetros. La siguiente imagen muestra la definición recursiva de fibonacci.
<br>
<img src="https://upload.wikimedia.org/math/7/6/f/76f99713cf111eb035d908228c351710.png" width="500">

<br>
<img src="https://i.stack.imgur.com/UYuFl.png" width="1200">
<br>
Anteriormente se definió una función factorial la definición recursiva sería:
```c
long factorial(int n){
   if(n==0) //caso base finaliza la recursividad
     return 1;
   else 
    return n*factorial(n-1);//llamda recursiva
}
```
- El if contiene el caso base que asegura que la recursividad termine en algún momento,
- En el return del else está la llamada de recursiva.
    En el caso de n=4 al ser 4 diferente de 0 retornada 4 x factorial(3)
    	    Al ser 3 diferente de 0 retornada 3xfactorial(2) …. asi sucesivamente hasta que tengamos
	   4x3x2x1xfactorial(0) al ser 0 igual a cero retorna 1 y tendremos que el valor que retornada  
	   4x3x2x1x1 =24
<br>
<img src="http://godieboy.com/wp-content/uploads/2009/12/graficoFactorial.png" width="700">
<br>
