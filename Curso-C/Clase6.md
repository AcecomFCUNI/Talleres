#Cadenas
## Autor: Daniel Hidalgo
Al igual que un arreglo que guarda tipos de datos, sea int, float, double, etc. Las cadenas (strings) son un tipo de arreglo que guardan "chars" (caracteres). La particularidad del arreglo tipo cadena es que no es obligatorio declarar el tamaño de este. 
OJO: Al igual que un arreglo, el último “casillero” es un nulo ( '\0' ).
## Ejemplo
```c
#include <stdio.h>
void main(){
	char cad1[] = " "; // Inicializamos la cadena
  gets(cad1); // Le pedimos al usuario que ingrese los caracteres de la cadena 
  //(pueden contener números como elementos en la cadena los cuales se almacenarán como caracteres
	puts(cad1); // Esta función imprime el contenido de la cadena en la consola
}
```

###LIBRERÍA <STRING.H>:
Esta librería contiene una variedad de funciones útiles y prácticas para las cadenas, las más usadas son:
- **strcmp():** Esta función compara 2 cadenas y evalúa cual es mayor. 

**Syntax:**

int strcmp(cad1,cad2); Esta función devuelve una variable entera, será 0 (cero) si las cadenas son iguales, 1 si cad1 es mayor a cad2 y -1 si cad2 es mayor a cad1

- **strcat():** Esta función “concatena” 2 cadenas en una sola.

**Syntax:**

char strcat(cad1,cad2); // Todo el contenido de cad2 se concatenará al final de cad1

- **strcpy():** Esta función copia todo el contenido de una cadena a otra.

**Syntax:**

char strcpy(cad1,cad2); //El contenido de cad2 es copiado en cad1

- **strlen():** Esta función evalúa y devuelve el tamaño de una cadena.

**Syntax:**

Int strlen(cad1); // Devuelve el tamaño (en enteros) de la cadena


###EJERCICIOS:

1. Invertir el orden de los caracteres de las siguiente frase: “Talk is cheap. Show me the code”.
2. Contar cuantas palabras existe en la frase anterior y, además, agregar después de cada palabra el número de letras que contiene dicha palabra en vez de los espacios que separan dichas palabras: “Talk is cheap …” -> “Talk4is2cheap5…”
3. Invertir el orden de las palabras de la frase usada anterior mente: “Talk is cheap…” -> “klaT si paehc…”
4. Invertir el orden de las palabras de la misma frase: “Talk is cheap. Show me the code”  -> “code the me Show .cheap is Talk”
5. De la frase anterior, agregar las palabras de la frase: “To iterate is human, to recurse is divine” de forma intercalada (“Talk To cheap Iterate ...)
