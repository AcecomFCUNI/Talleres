emana 2 - Introducción a la POO
## 1.1 Introducción
Del alcance de la clase pasada hacemos énfasis en la comparación entre un lenguaje secuencial y estructurado, y uno con una lógica no lineal basado en unidades independientes y bien definidas. Es necesario un poco de abstracción para poder programar utilizando principios orientados a objetos, pero al invertirle el suficiente tiempo de planificación podremos implementar cualquier proyecto como una tarea rutinaria análoga al mundo tangible.
## 1.2 Definiciones
### 1.2.1 Clase
Una clase es una estructura de datos capaz de almacenar tanto data como métodos. Es la abstracción necesaria para generar un modelo en el que podamos basar un objetos.

### 1.2.2 Objeto
Es la representación de la clase producida en función a esta. Logramos darle un sentido operable a la clase de la que deriva especificando sus atributos y funcionalidades.

### 1.2.3 Instancia
Es la representación "real" de un objeto. Al instanciar una clase la dotamos de "realismo" o __particularización__ operable mediante código.

### 1.2.4 Herencia
La herencia es una propiedad presente en este paradigma. Permite ligar una dependencia vertical entre clases, extendiendo definiciones de clases ancestrales, modificando métodos y atributos con el fin de dotar al código de **modulación**.

### 1.2.5 Polimorfismo
Es otra propiedad presente en los lenguajes orientados a objetos. Gracias a este principio podemos declarar mismas operaciones, con estructuras similares o casi idénticas, y el compilador podrá discriminar a qué elemento nos referimos **sin ambigüedad** alguna. Su implementación en clases va de la mano al concepto de herencia y permite una legibilidad del código impecable.

## 1.3 Sintaxis
> Análisis 1 - Sintaxis general
```
clase Nombre_Clase{
	// Sin orden especifico
	etiqueta publica:
	...

	etiqueta privada:
	...

	etiqueta protegida:
	...
};
```
### 1.3.1 Operador punto e introducción al acceso por referencia
Debemos entender que un objeto funciona como la instanciación de una clase (mucho se discute si el término "instancia" es equivalente a "objeto", pero no nos preocuparemos por estas tecnicidades), por lo que debemos tener alguna herramienta que permita acceder a sus parámetros y métodos durante la implementación. El operador punto '.' permite operar sobre una instancia manipulando sus campos creados en la definición de la clase.

> Análisis 2 - Etiqueta 'public' y operador punto

```cpp
#include <iostream>

using namespace std;

class Rectangulo{ // clase
	public: // etiqueta
	int largo, ancho;
	
	Rectangulo(int a, int b){
		largo = a;
		ancho = b;
	}

	int area(){
		return(largo*ancho);
	}

	int perimetro(){
		return(2*largo + 2*ancho);
	}

	void printInfo(){
		cout << "Largo : " << largo << endl;
		cout << "Ancho: " << ancho << endl;
	}
};

void modif_rec(Rectangulo R);

int main(){
	Rectangulo r1(13, 4); // objeto o instancia de la clase
	r1.printInfo();

	cout << "A: " << r1.area() << endl;
	cout << "2P: " << r1.perimetro() << endl;
}
```

> Análisis 3 - Etiqueta private
```cpp
class DateClass {
    int mes; 
    int dia; 
    int año;
};
 // Por defecto todos los miembros de una clase son privados
int main(){
    DateClass date;
    date.mes = 10; 
    date.dia = 20; 
    date.año = 2017; 
 
    return 0;
}
```
```cpp
#include <iostream>
 
class DateClass {
    int mes; 
    int dia; 
    int año; 
 
public:
    void setDate(int month, int day, int year){
        mes = month;
        dia = day;
        año = year;
    }
 
    void print() {
        std::cout << mes << "/" << dia << "/" << año;
    }
};
 
int main(){
    DateClass date;
    date.setDate(10, 20, 2017); 
    date.print(); 
    return 0;
}
```
> Análisis 4 - Alteración de instancias

```cpp
#include <iostream>

using namespace std;

class Rectangulo{ // clase
	public:
	int largo, ancho;
	
	Rectangulo(int a, int b){
		largo = a;
		ancho = b;
	}

	int area(){
		return(largo*ancho);
	}

	int perimetro(){
		return(2*largo + 2*ancho);
	}

	void printInfo(){
		cout << "Largo : " << largo << endl;
		cout << "Ancho: " << ancho << endl;
	}
};

void modif_rec(Rectangulo &R);

int main(){
	Rectangulo r1(13, 4); // objeto o instancia de la clase
	r1.printInfo();
	modif_rec(r1);
	r1.printInfo();
	cout << "A: " << r1.area() << endl;
	cout << "2P: " << r1.perimetro() << endl;
}


void modif_rec(Rectangulo &R){
	R.largo++;
}
```
# Introducción a Herencia
> Análisis 5- Herencia
```cpp
#include <string>
class Persona{
public:
    std::string name;
    int age;
    Persona(std::string nombre = "", int edad = 0) : name(nombre), age(edad){
    }
    std::string getName() const { return name; }
    int getAge() const { return age; }
};
class Empleado: public Persona{
public:
    double Salario;
    long empleado_ID;
    //constructor
    Empleada(double Salary, long empleadoID): Salario(Salary), empleado_ID(empleadoID){
    }
 
    void printNameAndSalary() const{
        std::cout << name << ": " << Salario << '\n';
    }
};

//La herencia nos permite reutilizar las clases haciendo que otras clases hereden sus miembros
```
## A.1  Introducción a MACROS
Se pueden considerar los MACROS de preprocesamiento como métodos literales que sirven de herramienta de código en un entorno de trabajo previo a la compilación de un programa en C o C++. Las directivas (o métodos) funcionan de manera secuencial

### Ejemplos:
* Incluir headers:
```cpp
#include <iostream>
```
* Definir constantes
```cpp
#define EULER 2.71828
#define CUSTOM_STRING "Acecom - C++"
```
* Definir funciones macro
```cpp
#define MY_MACRO_PRINT(...) printf(__VA_ARGS__) 
```


> Análisis A.1 - Inclusión y definición
```cpp
// Ejemplo 1
#include <iostream> // Incluyendo el header de la libreria "iostream" para usar std::cout
#define PI 3.14159

using namespace std;

int main(){
	cout << "El area de un circulo de radio r = 2 es: " << PI*2*2 << endl;
}
```
```
output~: El area de un circulo de radio r = 2 es: 12.5664
```
> Análisis A.2 - Función MACRO
```cpp
// Ejemplo 2
#include <iostream>
#define MAX(a,b) (a > b) ? a : b

using namespace std;

int main(){
	int result = MAX(45, 93);
	cout << "El máximo entre los numeros 45 y 93 es: " << result << endl;
}
```
```
output~: El máximo entre los numeros 45 y 93 es: 93
```

### Operadores:
Existen 4 operadores básicos en preprocesamiento con los que podemos trabajar:
* **#define**
* **Stringize** (#) (Crear un string luego del simbolo '#' y envolverlo con comillas)
* **Token de pegado** ('##')  (pega los valores a la izquierda y derecha del operador tal cual)
* **Next-line macro** ('\\') (Herramienta de formateo para construir macros en lineas posteriores)

### Pasos de expansión
1. Se procesan los tokens precedidos por '#' o '##'
2. Se aplica el reemplazo MACRO a todos los argumentos
3. Se reemplaza cada parámetro con el resultado de la expansión MACRO
4. Se escanea para nuevos MACROS

> Análisis A.3 - Operadores y secuencia de expansión

#### 1. **#define**
MACRO de definción de parámetros en preprocesamiento; uno de los más comúnmente usados cuando se desea crear una clase y no queremos depender del compilador (solo como seguridad), o para definir funciones MACRO o constantes de pp.

#### 2. **stringize ('#')**
MACRO que convierte todo argumento en un string y lo envuelve en comillas dobles. Usado muchas veces cuando se requiere trabajar con strings constantes.
```cpp
#include <iostream>
#define to_string(value) #value
#define to_string_2(value) to_string(value)
#define x 5

using namespace std;

int main(){
	cout << "[" << to_string(x) << "]" << endl;
	cout << "[" << to_string_2(x) << "]" << endl;
}
```
```
output~:
[x]
[5]
```

#### 3. **Token de pegado ('##')**
También llamado token MACRO de concatenación. Concatena
```cpp
#include <iostream>
#define get(x,y) x##y

using namespace std;

int main(){
	int my_var = 30;
	cout << "Valor de my_var: " << get(my, _var) << endl;
}
```
```
output~: Valor de my_var: 30
```

#### 4. **Next line macro(\\)**
Permite escribir sentencias MACRO en multilínea para presentar el código de manera mas ordenada

```cpp
#include <iostream>
#define print_seq(a, b) \ //Obviar este comentario
for(int i = a; i <= b; i++){\
	cout << i << " ";\
}\
cout << endl;\

using namespace std;

int main(){
	print_seq(1, 20)
}
```

```
output~: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
```

## A.2 MACROS condicionales en C/C++
Herramienta de código ejecutable en el entorno de precompilamiento con estructura condicional sobre los macros definidos

### 1. Condicional de definición
Bloque condicional de código que depende de el estado de definición de algún MACRO
### Ejemplo:
``` cpp
#include <iostream>
#define INDEX 9 // Definicion de INDEX presente

using namespace std;

int main(){
	int array[10];
	array[9] = 0;

	#ifdef INDEX // Bloque de pp. condicional
	array[INDEX] = 123;
	#endif // Cerradura del bloque
	
	cout << array[9] << endl;
}
```

```
output~: 123
```

### 2. Condicional complementario de definición
Similar al bloque anterior, solo que en este caso se revisa si la no existe la definición del MACRO en cuestión.
```cpp
#include <iostream>
#define VAR -1 // Definicion de VAR presente

using namespace std;

int main(){
	#ifndef VAR // Bloque de pp. condicional
	cout << "Si lees esto, no se definio VAR" << endl;
	return 0;
	#endif // Cerradura del bloque
	
	cout << "Si lees esto, se definio VAR" << endl;
	return 0;
}
```

```
output~: Si lees esto, se definio VAR
```

### 3. Condicionales generales
Análogo al caso tradicional de un bloque condicional de código en C/C++, estos bloques de pp. condicionales responden ante el valor booleano que se presente.

```cpp
#include <iostream>
#define VAR 1

#if VAR > 0
#undef VAR
#define VAR -1
#endif

using namespace std;

int main(){
	cout << VAR << endl;
}
```

```
output~: -1
```
### 4. Condicionales generales compuestas
Se adiciona la cláusula de complemento "ELSE" a la estructura
```cpp
#include <iostream>
#define VAR 0

#if VAR > 0
#undef VAR
#define VAR 100

#elif VAR == 0
#undef VAR
#define VAR 1

#else
#undef VAR
#define VAR -100
#endif

using namespace std;

int main(){
	cout << VAR << endl;
}
```
```
output~: -1
```
