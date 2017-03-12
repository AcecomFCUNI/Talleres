#Ficheros
La libreria estandar (stdio) posse funciones que permiten el manejo de ficheros.
##Manejo del fichero
Para manejar un fichero debemos realizar las siguientes operaciones.
- Abrir el fichero.
- Leer o escribir en el fichero.
- Cerrar el fichero.

##Funciones para el manejo de ficheros.
- **fopen:** se utiliza para abrir o crear ficheros en el disco.
  ```c
    File* f;
    f= fopen("nombre","opcion");
    
  ```
  Se muestra el uso de la función fopen que necesita un puntero de tipo FILE el cual sera el apuntador a la informacion que posee el fichero.
  + **nombre:** es determinado por el usuario si este crea el fichero en el programa o sera igual al nombre del fichero que deseemos leer.
  + **opcion:** son los distintos tipos de operaciones que deseemos hacer con los ficheros.
  
      Entre las distintas opciones tenemos:
      1. **r :** abre un archivo para lectura, **el fichero debe existir**.
      2. **w :** abre un archivo para escritura, sino existe se crea el fichero y si existe se sobreescribe.
      3. **a :** abre un archivo para escritura a final del contenido sino existe se crea.
      4. **r+:** abre un archivo para lectura y escritura, el archivo debe existir.
      5. **w+:** abre un archivo para lectura y escritura, si no existe se crea el archivo si existe se sobreescribe.
      
- **fclose:** se utliza para cerrar un fichero abierto.
  ```c
   
    fclose(f);
    
  ```
  - **feof:** se utliza para saber si el cursor dentro del archivo encontro el final del archivo(**e**nd **o**f **f**ile). feof devuelve 0 siempre y cuando 
  no haya encontrado el final del archivo si lo encuentra devolvera un numero distinto de 0.
  - **fgets:** esta funcion sirve para leer una cadena de caracteres, leera hasta n-1 si es de tamaño fijo el elemento, hasta el final de linea 
  ```c
#include <stdio.h>
#include <stdlib.h>
 
int main()
{
 	FILE *archivo;
 	
 	char caracteres[100];
 	
 	archivo = fopen("prueba.txt","r");
 	
 	if (archivo == NULL)
 		exit(1);
 	
 	printf("\nEl contenido del archivo de prueba es \n\n");
 	while (feof(archivo) == 0)
 	{
 		fgets(caracteres,100,archivo);
 		printf("%s",caracteres);
 	}

        fclose(archivo);
	return 0;
}
  ```
  - **fscanf:** es una función similar a la scanf pero como pero como parametro de entrada toma un fichero.
  ```c
#include <stdio.h>
int main ( )
{
 	FILE *f;
 	char buffer[100];
 	f= fopen ( "fichero.txt", "r" );
 	fscanf(f, "%s" ,buffer);
 	printf("%s",buffer);
 	
 	fclose (f);
 	return 0;
}
  ```
- **fputc:** Esta función escribe un carácter a la vez del archivo que esta siendo señalado con el puntero FILE. El valor de retorno es el carácter escrito, si la operación fue completada con éxito, en caso contrario será EOF.
```c
#include <stdio.h>
 
int main ()
{
 	FILE *fp;
 	char caracter;
 		
 	fp = fopen ( "fichero.txt", "a+t" ); //parametro para escritura al final y para file tipo texto
 	printf("\nIntroduce un texto al fichero: ");
 	while((caracter = getchar()) != '\n')
 	{
 		printf("%c", fputc(caracter, fp));
 	}
 	fclose ( fp );
 	return 0;
}
```
- **fputs:** escribe una cadena en un fichero , si ocurre un erro la función devuelve un negativo o EOF.
```c
#include <stdio.h>
 
int main ( int argc, char **argv )
{
 	FILE *fp;
 	
 	char cadena[] = "Mostrando el uso de fputs en un fichero.\n";
 	
 	fp = fopen ( "fichero.txt", "r+" );
 	
 	fputs( cadena, fp );
 	
 	fclose ( fp );
 	
 	return 0;
}
```

- **fprintf:** es similar al printf pero la salida va hacia un fichero en lugar de la pantalla.

```c
#include <stdio.h>
int main ()
{
 	FILE *fp;
 	fp = fopen ( "fichero.txt", "r+" );
 	fprintf(fp, "%s", "Esto es otro texto dentro del fichero");
 	fclose ( fp );
 	return 0;
}```
