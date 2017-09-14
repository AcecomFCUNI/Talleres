# Semana 1 - Introducción estructural al lenguaje
## 1.1 Introducción
El presente es un curso planeado e impartido por miembros del grupo estudiantil ACECOM de la Facultad de Ciencias de la Universidad Nacional de Ingeniería (Lima, Perú). En el transcurso de **7 semanas** desarrollaremos temas correspondientes al lenguaje C++, los paradigmas computacionales del mismo y algunos temas pertinentes fuera del lenguaje. Este curso esta dirigido a aquellas personas con poca o ninguna experiencia en lenguajes formales de programación pero que sí tienen alguna noción previa de teoría algoritmica muy básica. Si bien todo este material escrito esta disponible al público, solamente los asistentes a las clases tendrán el beneficio de recibir una explicación detallada de los apartados señalizados por un __quote de análisis__ antepuesto.

> Análisis 0 - Quote de ejemplo

## 1.2 Aspectos del lenguaje
### 1.2.1 ¿Qué es un lenguaje orientado a objetos?
Partiendo de la idea básica de los primeros lenguajes como Assembly o C, inicialmente se implementaba código como una lista enorme de instrucciones que se ejecutarían una detrás de otra. Esto tiene sus ventajas y desventajas al momento de trabajar en proyectos. C++, al ser un lenguaje OOP, permite la programación de manera __modulada__, siendo capaz de encapsular unidades de código independiente para ser reutilizado luego en otro contexto sin preocuparnos cómo fue que se implementó (eso si fue correctamente implementado en un principio). Estas unidades se denominan __clases__ y las introduciremos en semanas posteriores.
C++ es un lenguaje _compilado_, por lo que necesitaremos un compilador instalado y su propia documentación para ejecutar los programas. En nuestro caso utilizaremos los comandos básicos de _GNU_ en una distro de linux (a su preferencia).

### 1.2.2 Comparación diferencias y beneficios respecto al estructurado
Al margen del cambio de estilo de codificación de los lenguajes ya explicada, al pasar de un formato secuencial a _orientado a objetos_, podemos también listar algunos contrastes entre estos:

> BENEFICIOS
* Modulamiento de código
* Facilidad de abstracción
* Orden y consistencia (conceptos DRY y WET)
* Existencia de librerías precompiladas con herramientas muy útiles

> DIFICULTADES
* Puede resultar complejo de dominar
* Más dificil de debugear

## 1.3 Sintaxis de estructuras básicas

### 1.3.1 Plantilla básica, variables y aritmética-lógica general
Asumiendo que posee un compilador viable (como GNU) procedemos a mostrar el esqueleto básico de todo programa en C++. En un archivo llamado "hello.cpp" escribimos el siguiente código:

> Análisis 1 - Estructura general
```cpp
#include <iostream>  //Directivas del preprocesador
 
int main()
{
   std::cout << "Hello world!";  //<< operador de salida 
   return 0;    // instrucción de retorno 
}
```
```
> g++ hello.cpp
> ./a.out
```
O alternativamente
```
> g++ hello.cpp -o mi_exe
> ./mi_exe
```
Ahora bien, para implementar operaciones aritmetico-lógicas en c++ es oportuno revisar los tipos de variables disponibles:
> Análisis 2 - Introducción a tipos de variables

![ScreenShot](https://raw.github.com/BitzerAr/Acecom/master/fotos/tipo.png)

Trabajando ahora con algunas operaciones aritméticas básicas, creemos el archivo "operac.cpp" y escribamos como sigue:
> Análisis 3 - Declaración, inicializacion, asignacion
```cpp
// Declaracion
bool bValue;
char chValue;
int nValue;
float fValue;
double dValue;
```
```c++
// Inicializacion
int valor = 5;
```
```c++
// Asignacion
int valor;
valor = 5;
```

```cpp
#include <iostream>  //Directivas del preprocesador
 
int main()
{
	// Creando e inicializando variables
	bool bValue = true;
	char chValue = 'm';
	int nValue = 31;
	float fValue = 3.14159;

	// Mostrando en terminal
	std::cout << bValue << std::endl;
	std::cout << chValue << std::endl;
	std::cout << nValue << std::endl;
	std::cout << fValue << std::endl;
}
```
```
> ./a.out
1
m
31
3.14159
```
> Análisis 4 - Operador Sizeof

La cantidad de memoria que utiliza una variable se basa en su tipo de datos.
Una variable con n bits puede contener 2^n valores posibles.

El tamaño de un determinado tipo de datos depende del compilador y / o de la arquitectura de la computadora
### Sizeof
El operador sizeof es un operador unitario que tiene o bien un tipo o una variable, y devuelve su tamaño en bytes.
#### Entero
![ScreenShot](https://raw.github.com/BitzerAr/Acecom/master/fotos/entero.png)

El rango de una variable de número entero se determina por dos factores: su tamaño (en bits), y su signo
```c++
char c;
short int si;
short s;     
int i;
long int li; 
long l;      
long long int lli; 
long long ll; 
```
#### Float 
![ScreenShot](https://raw.github.com/BitzerAr/Acecom/master/fotos/float.png)

Grandes números o números con un componente fraccional.

```c++
float fvalor;
double dValor;
long double dValur2;
```
#### NaN e Inf
La primera es Inf , que representa el infinito. La segunda es NaN , que significa “no es un número”

#### Boolean
Variables booleanas son variables que pueden tener sólo dos valores posibles: true (1), y falso (0).
```c++
bool b=true;
bool c;
c = false
```
#### Char
Es un número entero y, por lo tanto sigue todas las reglas normales enteros. A pesar de ello se suelen trabajar de una manera diferente a los números enteros normales.
```c++
char ch1 = 97;
char ch2 = 'a';
```

> Análisis 5 - Constantes

Son aquellas 'variables' con valores que no se pueden cambiar.

#### Sentencia const
```c++
const double gravedad = 9.8;
```

#### Constantes simbólicas
```c++
#define MAX_STUDENTS_PER_CLASS 30
```

> Análisis 6 - Operadores aritméticos

#### Operadores Aritmeticos
![ScreenShot](https://raw.github.com/BitzerAr/Acecom/master/fotos/operadores.png)

#### Operadores de asignación aritméticas
![ScreenShot](https://raw.github.com/BitzerAr/Acecom/master/fotos/asignacion.png)

#### Operadores de incremento
```c++
int x = 5;
int y = x++; 
```
* Secuencia
1. El compilador hace una copia temporal de x que comienza con el mismo valor original (5).
2. Se incrementa el x original a partir de 5 a 6.
3. El compilador evalúa la copia temporal, que vale 5, y asigna este valor a y.

```c++
int x = 5, y = 5;
cout << x << " " << y << endl;
cout << ++x << " " << --y << endl; // prefix
cout << x << " " << y << endl;
cout << x++ << " " << y-- << endl; // postfix
cout << x << " " << y << endl
```
> Análisis 7 - Operadores lógicos
Las siguientes operaciones se revisarán a detalle en el próximo apartado
#### Operador ternario
x = (condición)? valor_a: valor_b;
```c++
valor = (x > y) ? x : y;
```
#### Operadores Relacionales 
```c++
#include <cmath> // for fabs()
bool isAlmostEqual(double a, double b, double epsilon)
{
    return fabs(a - b) <= epsilon;
}
```

### 1.3.2 Estructuras selectivas
Como una herramienta de control del flujo de la lectura de nuestros programas, introducimos la __estructura selectiva__. Éstas permiten que, de cumplirse una o varias condiciones, podamos ejecutar diferentes partes de nuestro código. Utilizando la sintaxis de c++:
```cpp
if(condicion cumplida){
	ejecutar_codigo();
}
```
> Análisis 8 - Estructuras selectivas
#### Estructura if
```cpp
if(condicion cumplida){
	ejecutar_codigo();
}
```
#### Estructura if-else
```cpp
if(condicion cumplida){
	ejecutar_codigo();
} else {
	ejecutar_otro_codigo();
}
```
#### Estructura switch
```cpp
switch(variable_evaluada){
	case a_1:
		ejecutar_1();
	case a_2:
		ejecutar_2();
	case a_3:
		ejecutar_3();
	default:
		ejecutar_por_defecto();
}
```

### 1.3.3 Estructuras iterativas
Una estructura iterativa o conocida comunmente como un bucle hace que el programa ejecute repetidamente una serie de instrucciones hasta que una condición dada sea falsa. C ++ proporciona 3 tipos de bucles: while , do while , y for loops. 

#### While
```cpp
while (condicion cumplida){
    iterar_codigo();
}
```
#### do while (siempre se ejecuta al menos una vez.)
```cpp
do{
    iterar_codigo();
}while(condicio cumplida);
```
#### for 
```cpp
for( inicializacion ; condicion logica ; operado){
    iterar_codigo();
}
```
### 1.3.4 Funciones
Una función es una secuencia de declaraciones diseñadas para realizar un trabajo en particular y pueden ser reutilizables en varios casos.
#### Parametro y Argumento
Variable declarada en la declaración de función.
El valor que se pasa a la función por la persona que llama.

#### Argumentos por valor
Cuando un argumento se pasa por valor , el valor del argumento se copia en el parámetro de la función.
```cpp
void function(int variable1 , ...){
    estructura_funcion();
}
```
#### Argumentos por referencia
Para pasar una variable por referencia, simplemente declaramos los parámetros de la función como referencias en lugar de variables normales.
```cpp
void funcion(int &valor){
    valor = 6;
}
int main(){
    int var1 = 5;
    cout << "var1 = " << var1 << '\n';
    funcion(var1);
    cout << "var1 = " << var1 << '\n';
    return 0;
}
```
#### Argumentos por direccion
 Pasar un argumento por dirección implica pasar la dirección de la variable de argumento en lugar de la variable de argumento en si.
El paso por dirección suele utilizarse con punteros, y con mayor frecuencia se utilizan para señalar arrays integrados. 
```cpp
void funcion(int *valor){
    *valor = 6;
}
int main(){
    int var1 = 5;
    cout << "var1 = " << var1 << '\n';
    funcion(&var1);
    cout << "var1 = " << var1 << '\n';
    return 0;
}
```
#### Sobrecarga de Funciones
Permite crear múltiples funciones con el mismo nombre, siempre y cuando tengan diferentes parámetros. 
```cpp
int add(int x, int y){
    return x+y;
}
double add(double x, double y){
    return x+y;
}
int add(int x, int y, int z){
    return x + y + z;
}

```
### 1.3.5 Notas
Una variable en C ++ es simplemente un objeto que tiene un nombre.
Después de definir una variable, se le puede asignar un valor mediante el operador de asignación (el signo =):
```cpp
int x;
x=5;
```
C ++ te permitirá definir una variable y darle un valor inicial en el mismo paso. Esto se llama inicialización .
```cpp
int x = 5;
```
Una sentencia sin cuerpo se denomina declaración nula y se declara usando un punto y coma único en lugar de la sentencia. 
```cpp
if (x > 10)
    ;
```
Las direcciones se pasan realmente por valor, cuando pasa un puntero a una función por dirección, el valor del puntero (la dirección a la que apunta) se copia desde el argumento al parámetro de la función. En otras palabras, se pasa por valor! Si cambia el valor del parámetro de función, sólo está cambiando una copia, en consecuencia, no se cambiará el argumento de puntero original.
