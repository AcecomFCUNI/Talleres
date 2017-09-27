# Semana 3 - Programación basada en clases
## 1. Definición
De lo estudiado en la clase pasada sabemos que una clase es el objetivo representativo al que debemos proyectarnos durante la fase de planeamiento de un proyecto (o código) para aprovechar el nivel de abstracción que nos ofrece c++ al modular nuestros programas. Hoy nos enfocaremos más en dos aspectos: el uso de las clases dinámicamente y su implementación modular

### 1.1 Repaso de clases y tipos de etiqueta
Al derivar una clase, heredando los atributos de su clase padre, debemos tener cuidado de la manera en la que implementamos dicha clase (la derivada). Como un repaso de la consecuencia de aplicar las etiquetas _private_, _public_ y _protected_ podemos comprender mejor su comportamiento a partir de la siguiente tabla:

> Análisis 1 - Correspondencia de comportamiento de etiquetas

|  __Acceso__      | _public_   | _protected_  | _private_|
|:----------------:|:--------:|:----------:|:------:|
| Misma clase	   | SI       | SI         | SI     |
| Clase derivada   | SI       | SI         | NO     |
| Contexto externo | SI       | NO         | NO     |

Rara vez se utiliza la implementación _protected_ o _private_ de una clase derivada, pero dependiendo el contexto de trabajo puede ser útil (porque al final, podríamos declarar todo como _public_ y olvidarnos de los problemas de seguriidad, pero no es la idea). La más utilizada es la implementación _public_ de dicha clase, pero aún así no está de más explicar que significa sentenciarla utilizando cada una de estas definiciones.

**Herencia pública:** Al derivar de una clase, los parámetros _public_ de la clase base (padre) se vuelven públicos en la clase hijo; los parámetros _protected_
también se vuelven protegidos en la clase derivada.

**Herencia protegida:** Al derivar de una clase, los parámetros _public_ y _protected_ se vuelven _protected_ en la clase derivada. 

**Herencia protegida:** Al derivar de una clase, los parámetros _public_ y _protected_ se vuelven _private_ en la clase derivada.

> Análisis 2 - Repaso de sintaxis: Herencia

```cpp
#include <iostream>

using namespace std;

class Rectangulo{ // clase
	protected: // etiqueta
	int largo, ancho;
	
	public:
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

class Cuadrado: public Rectangulo{
	public:
	Cuadrado(int l): Rectangulo(l, l){ // llamada a la clase original
		// nada, si asi lo deseamos
	}

	void printInfo(){
		cout << "Soy un cuadrado y derivo de un rectangulo" << endl;
		cout << "Lado : " << ancho << endl; // Pudimos usar largo tambien
	}
};

int main(){
	Rectangulo r1(13, 4); // objeto o instancia de la clase
	r1.printInfo();

	Cuadrado c1(5); // objeto o instancia de la clase derivada
	c1.printInfo();
}
```

### 1.2 Constructores y destructores
Al implementar una clase en la fase de planificación de la misma debemos enfocarnos en dos métodos principales: __constructor__ y __destructor__. Debido a que el lenguaje permite la abstracción hasta un nivel que no se lograba con otros lenguajes anteriores, se añadió estas dos herramientas para resolver las preguntas:
* ¿Qué es necesario para crear un objeto?
* ¿Qué debe suceder cuando el objeto deja de existir?

**Constructor:** Método utilizado, principalmente, para inicializar los parámetros mínimos necesarios para que una clase esté bien definida por sí misma.

**Destructor:** Método utilizado como gatillo al destruir un objeto sobre el runtime de un programa.
    
## 2. Manejo de memoria
Debido a que los métodos, variables y en general tipo de estructura de datos usada al programar ocupa un lugar en la memoria, es importante gestionar la cantidad que usamos para proyectos que demanden una potencia de procesamiento y almacenamiento altos. Para ello, contamos con instrucciones que permiter alocar memoria dinámicamente, dotando así un poder mayor al programador para gestionar la memoria

### 2.1 Implementación con new y delete
> Análisis 3 - Resumen de punteros, new y delete
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

	~Rectangulo(){
		cout << "Se elimino el rectangulo" << endl;
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

int main(){
	Rectangulo *r1 = new Rectangulo(13, 4); // instanciacion dinamica de la clase
	r1->printInfo();
	delete r1; // eliminacion de la informacion
	r1->printInfo();
}
```


## A.3 Clases reusables y compilación
Hasta ahora hemos visto como implementar clases, crear derivadas y utilizarlas en la función **main** de un programa .cpp, pero la sintaxis que hemos estado viendo hasta ahora es poco práctica si se quiere trabajar en un proyecto grande. Cuando se tiene un trabajo que exige muchas clases, es conveniente ordenarlas en archivos separados y solo dotar de información mínima a nuestro compañeros de proyecto para optimizar la implementación; así dotaremos de _reusabilidad_ a nuestras clases.

Supongamos la estructura más simple para implementar clases reusables:

```
Carpeta
|-principal.cpp
|-CARPETA1
|---CARPETA2
|-----Rectangulo.hpp
|-----Rectangulo.cpp
```

Y los archivos correspondientes poseen la siguiente información:

> Análisis A.1 - Clases reusables (ext.)

```hpp
//En carpeta1/carpeta2/Rectangulo.hpp

#ifndef RECTANGULO_H
#define RECTANGULO_H

class Rectangulo{
	public:
		int largo, ancho;
		Rectangulo(int a, int b);
		~Rectangulo();
		int area();
		int perimetro();
		void printInfo();
};

#endif
```

```cpp
//En carpeta1/carpeta2/Rectangulo.cpp

#include <iostream>
#include "Rectangulo.hpp"

using namespace std;

Rectangulo::Rectangulo(int a, int b){
	largo = a;
	ancho = b;
}

Rectangulo::~Rectangulo(){
	cout << "Se elimino el rectangulo" << endl;
}

int Rectangulo::area(){
	return(largo*ancho);
}

int Rectangulo::perimetro(){
	return(2*largo + 2*ancho);
}

void Rectangulo::printInfo(){
	cout << "Largo : " << largo << endl;
	cout << "Ancho: " << ancho << endl;
}
```

```cpp
//En principal.cpp
#include "carpeta1/carpeta2/Rectangulo.hpp"
#include <iostream>

int main(){
	Rectangulo *r1 = new Rectangulo(13, 4); // instanciacion dinamica de la clase
	r1->printInfo();
	delete r1; // eliminacion de la informacion
	r1->printInfo();
}
```


