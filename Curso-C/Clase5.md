## Arrays

En ciertos casos necesitamos almacenar una gran cantidad de valores pero definir múltiples variables no es lo ideal. Para estos casos debemos usar los arrays o vectores que nos permiten almacenar múltiples datos del mismo tipo de manera continua y nos permite un fácil acceso a ellos.

## Declaración de un Array.
```c
int A[TAM];

```

+ int es el tipo de dato del array puede ser float, long, char, etc.
+ A es el nombre del array.
+ TAM es el tamaño del array

**Nota:** Los arrays usan memoria estática, eso quiere decir que no se pueden guardan mas elementos que el tamaño del array ese tamaño no puede ser cambiado.

```c
int a[]={2,1,3,5,6};
int b[10]={5,6,7,2,1,7,5,4,3};
```
- En la declaración del array **a** no se especifico el tamaño del array pero al realizar la asignación de los 5 números el tamaño se asignará automáticamente al valor de la cantidad de elementos ingresados.

- En la declaración del array **b** se asigno el tamaño 10 y se asignó una cantidad de elementos que no excediera ese tamaño.
<br>
<img src="http://cforbeginners.com/selectsort.jpg" width="500">


En la imagen se muestra una representación de como se distribuyen los datos en un array de tamaño 5. Los arrays usan indices para manipular su valores los indices toman valores de **0 hasta TAM-1** en este array de 0 a 4.

```c
  int n=10,i;
  int a[n];
  for (i=0;i<n;i++){
     a[i]=(i+1)*2;
     printf("%d\n",a[i]);	  
  }
```
En el código anterior se realizo asignaciones usando el contador i y el array se va llenando desde i=0 es común usar un bucle para llenar valores del array.

# Ordenamiento de burbuja
Es común que en muchos problemas se tenga un array desordenado y el problema solicita que ordenes dicho array. El ordenamiento de burbuja va comparando cada par de elementos múltiples veces y según sea el caso realiza un ordenamiento ascendente o descendente de modo que llevara el mayor o menor valor al final del arreglo.
```c
void burbuja(int a[TAM]){
	int aux,i,j;
	for ( i = 0; i < TAM; ++i)
		for (j = 1; j < TAM-i; ++j)
		{
			if (a[j-1]>a[j])
			{
				aux=a[j-1];
				a[j-1]=a[j];
				a[j]=aux;
			}
		}
}
```
**Descripción del Programa**
El programa realiza multiples intercambios para realizar un ordenamiento ascendente.
- El primer **for** es la cantidad de verificaciones que realizará el programa.
- El segundo **for** depende del i ya que a medida que el i se incremente realizará menos comparaciones.
- El **if** verifica si el anterior es mayor que actual y procede a realizar el intercambio de esta manera el mayor terminara al final del array.

# Matrices
Al igual que los arrays son espacios de memorias que nos permiten almacenar datos de un mismo tipo. La diferencia con los arrays es que los elementos están organizados de una forma bidimensional.

<br>
<img src="http://www.guiky.com.br/wp-content/uploads/2011/12/matriz.jpg" width="400">
<br>
<br>
La imagen superior es la representación de la matriz , cuando almacenamos datos en los arrays se utilizaba los indices a partir de 0 hasta tamaño -1 para acceder a los datos , en las matrices se deben usar 2 indices para poder acceder al dato.

# Declaración  de una matriz
Para declarar una matriz debemos indicar el numero de filas y columnas entre corchetes debido a que las matriz son una arreglo bidimensional.

```c
float A[F][C];
```
- float es el tipo de datos que guardará el array pueden ser int, char,long ,etc.
- A es el nombre del array.
- **F** es el número de filas y **C** es el número de columnas del arrays.

**Ejemplo de asignación**
```c
   //la 1ra terna sera para la fila 1 y la 2da para la fila 2..
   int a[2][3]={{2,2,3},{5,6,9}};

   printf("%d",a[1][1]);//imprimira el elemento en los indice 1 y 1
  ```
**Nota:** En las funciones tanto arrays como matrices se pasan por referencia lo que quiere  decir que cualquier cambio en la función afectara directamente al array o matriz.

# Operaciones con Matrices

**Suma de Matrices**
La suma de matrices requiere que las 2 matrices sean del mismo tamaño  y realizara la suma elemento a elemento es decir: Sean 2 matrices A y B de orden FxC.
```c
void sumar(int f,int c,int a[f][c],int b[f][c],int d[f][c]){

	for(int i=0;i<f;i++)
	  for(int j=0;j<c;j++)
		d[i][j]=a[i][j]+b[i][j];			
}
```
La imagen anterior muestra la función sumar donde f y c son argumentos debido a que se debe conocer el tamaño de la matriz que sera recibida. Los 2 for anidados verifican que se realice la operación suma de las matrices en caso que se desee realizar la diferencia de matrices solo se cambia de operador.
# Multiplicación de Matrices
<img src="https://github.com/Visot/Curso-C/blob/master/ima/imagen1.png" width="350">

```c
	void multiplicar(int m,int n,int p,float A[m][n],float B[n][p],float C[m][p]){
		for (int i = 0; i < m; ++i)
			for (int j= 0; j <p; ++j)
			{	
				C[i][j]=0;
				for (int k = 0; k <n ; ++k)
					C[i][j]+=A[i][k]*B[k][j];
			}
	}

```
En el código de C la matriz C[ i ][ j ] se inicializa en dentro del segundo for debido a la matriz C puede contener otros valores lo cual daría un resultado incorrecto.

# Transpuesta de Matriz
Para realizar la transpuesta de una matriz se realiza se necesita de M una matriz ingresada y T matriz transpuesta donde se guardará los elementos de la transpuesta.
<br>
<img src="https://github.com/Visot/Curso-C/blob/master/ima/imagen2.png" width="350">

```c
	void transpuesta(int f,int c,float M[f][c],float T[c][f]){
		for (int i = 0; i < f; ++i)
			for (int j = 0; j < c; ++j)
				T[j][i]=M[i][j];
	}
```
