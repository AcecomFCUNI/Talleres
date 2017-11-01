# Semana 5 - Sobrecarga y Templates

## 1. Sobrecarga de operadores
Retornando al polimorfismo __en tiempo de compilación__ teníamos pendiente revisar el concepto de **sobrecarga** de operadores. Un concepto bastante poderos y simple que busca dotar de una mejor abstracción al código escrito.

Imaginemos el caso de un automovil "vacío", al que aún falta *adicionarle* autopartes como un motor, chasis, etc. Si desearamos implementar el escenario bastaría implementar dos clases:

* Clase _automovil_ al que se le pueden añadir objetos _autoparte_
* Clase _autoparte_ como unidades diferentes de lo que necesita un automovil

Ahora bien, durante la implementación se nos ocurre una manera de hacer mas legible el código: ¿Que tal si a un objecto de _automovil_ pudiece sumarle _autopartes_? De tal manera un proceso como:

```
automovil A;
A.addAutoparte("Motor");
A.addAutoparte("Chasis");
A.addAutoparte("Suspension");
A.addAutoparte("Ruedas");
...
```

Sería equivalente a:
```
automovil A;
A += Motor;
A += Chasis;
A += Suspension;
A += Ruedas;
```

En el fondo, pareciese que estamos sumando aritmeticamente objetos, pero gracias a la sobrecarga, podemos dotar de sentido a estas expresiones.

> Análisis 1 - Sobrecarga

```c++
#include <iostream>
#include <vector>

using namespace std;

class Autoparte{
	string fabricante;
	
	public:
	Autoparte(string n){
		fabricante = n;
	}
	
	string getFabricante(){
		return fabricante;
	}
};

class Automovil{
	string modelo;
	vector <Autoparte> autoparte_vec;
	
	public:
	Automovil(string n){
		modelo = n;
	}
	
	void addAutoparte(Autoparte au){
		autoparte_vec.push_back(au);
	}
	
	
	// Sintaxis estandar para sobrecarga de operadores
	void operator+=(const Autoparte& au){
		this->addAutoparte(au);
	}
	
	friend ostream& operator<<(ostream& my_cout, const Automovil& autom){
		my_cout << "=============== " << autom.modelo << " ===============" << endl;
		my_cout << "Contiene :" << endl;
		
		for(Autoparte au: autom.autoparte_vec){
			my_cout << "- " << au.getFabricante() << endl;
		}
		
		return my_cout;
	} 
};

int main(){
	Automovil a1("Toyoya Supra");
	a1 += Autoparte("Motor V8");
	a1 += Autoparte("NOS");
	a1 += Autoparte("Susp. hidraulica H&R");
	cout << a1 << endl;
}
```

Si bien esto dota de una flexibilidad y elegancia superior a nuestro código, debemos entender que no todo es posible. Las siguientes dos tablas listan qué operadores somos capaces de sobrecargar y cuáles no.

**T1: Operadores sobrecargables**

|+|-|*|/|%|^|
|-|--|-|-|-|-|
|&|\||~|!|,|=|
|<|>|<=|>=|++|--|
|<<|>>|==|!=|&&|\|\||
|+=|-=|/=|%=|^=|&=|
|\|=|*=|<<=|>>=|[]|()|
|->|->*|new|new[]|delete|delete []|

**T2: Operadores no sobrecargables**
* Operador _namespace_ (::)
* Operador indirección (.*)
* Operador punto (.)
* Operador ternario (?:)

Puede revisar [esta](https://www.tutorialspoint.com/cplusplus/cpp_overloading.htm) documentación para estudiar la sintaxis de sobrecarga de cada operador.

## 2. Templates
Un template en C++ es un tipo de atributo que permite la programación META de funciones, clases y (desde C++14) variables. Los templates resuelven la siguiente dificultad: ¿Qué tal si deseo implementar una función capaz de operar cualquier tipo de variable? ¿Debo hacer una función para cada tipo, sabiendo que todas en el fondo hacen lo mismo? Gracias a los templates podemos sentenciar el **tipo** como otra varible.

### 2.1 Templates de funciones
Supongamos que queremos implementar una función de potencia al cuadrado, y la necesitamos para todo numero (entero, flotante, doble, long, etc); en lugar de implementar una por cada tipo, podemos declarar el tipo como otra variable:

```
tipo-de-variable potCuadrado(tipo-de-variable num){
	retornar num*num
}
```

Traduciendo la idea a C++:

```c++
#include <iostream>

using namespace std;

template <typename T> T cuad(T num);

int main(){
	cout << cuad<double>(4.1) << endl;
}

template <typename T>
T cuad(T num){
	return num*num;
}
```

### 2.2 Templates de clases
Un template de clase proporciona una especificación para generar clases basadas en parámetros. Generalmente se usan para implementar **containers** y se instancian al pasarle un conjunto de tipos como argumentos de template.

```c++
#include <iostream>
#include <vector>

using namespace std;

template <class T>
class Lista{
	vector<T> data_vec;
	
	public:	
	void addData(T new_data); // prototipo
	void printData(){
		cout << "{";
		for(T d: data_vec){
			cout << d << ",";
		}
		cout << "}" << endl;
	}
};

// Funcion declarada fuera de la instanciacion de la clase
template <class T>
void Lista<T>::addData(T new_data){
	data_vec.push_back(new_data);
}


int main(){
	Lista<string> mi_lista_st;
	mi_lista_st.addData("Hola");
	mi_lista_st.addData("Mundo");
	mi_lista_st.addData("Otro elemento");	
	mi_lista_st.printData();
	
	Lista<int> mi_lista_int;
	mi_lista_int.addData(1);
	mi_lista_int.addData(2);
	mi_lista_int.addData(7);
	mi_lista_int.printData();
}
```

## A.5 Introduccion a iteradores
Un iterador es un objeto ligado a un _conteiner_, que no es otra cosa mas que una estructura de datos dedicada a almacenar información;
dicho objeto permite su recorrido y acceso a la información de una manera vérsatil que C++ no tuvo sino hasta hace unas versiones.

> Análisis 1 - Sintáxis e intuición de tipos

```cpp
#include <iostream>
#include <vector>

// no incluimos el namespace 'std' para observar en crudo
// las dependencias reales de algunos objetos comunes

int main(){
	std::vector<std::string> v_nombres = {"PEDRO", "PABLO", "CARLOS", "JACINTO"};
	// Creando iterador 'i_nom' para un vector de string's
	std::vector<std::string>::iterator i_nom;

	std::cout << "{";
	for(i_nom = v_nombres.begin(); i_nom != v_nombres.end(); i_nom++){
		std::cout << *i_nom + ",";
	}
	std::cout << "}" << std::endl;
}
```

Dependiendo de su funcionalidad se definen 4 tipos de iteradores, siendo uno más robusto que el otro y albergando todas sus funcionalidades de manera jerárquica.

### A.5.1 Tipos
* __Iterador de entrada__: Son los más simples y menos flexibles de todos. Solo se usan en algoritmos que necesitan acceder (modificar) a los elementos del _conteiner_ una sola vez
* __Iterador de salida__: Idénticos a los de entrada con la diferencia de que estos solo sirven para leer los datos del _conteiner_ y no modificarlos
Por lo general estos dos primeros se utilizan sin saber que los estamos usando, dado que al usar un iterador de mayor jerarquía (cualquiera de los 3 expuestos a continuación) utilizan ambos y al mismo tiempo
* __Iterador hacia adelante__: Propio de los _conteiners_ basados en listas enlazadas simples. Solo se puede revisar elementos hacia adelante
* __Iterador bidireccional__: Este puede revisar elementos en ambas direcciones
* __Iterador de acceso aleatorio__: El mas flexible de todos. Capaz de evaluar cualquier posicion de un _conteiner_


Si usted tiene conocimientos de punteros y revisó la clase anterior en la que creabamos un vector de objetos, puede entender estos tipos de la siguiente manera:

Sea un __contenier__ (en su forma más simple puede imaginar un arreglo) arr
```
arr[]
```

* Para it. hacia adelante: Es análogo a un puntero (*ptr) al que, para acceder a sus valores, solo somos capaces de iterar con __ptr++__
* Para it. bidireccional: Es análogo a un puntero (*ptr) al que, para acceder a sus valores, somos capaces de iterar con __ptr++__ y __ptr--__
* Para it. de acceso aleatorio: Es análogo a un puntero (*ptr) al que, para acceder a sus valores, podemos utilizar __ptr + i__ para cualquier valor de i (admisible)

<center>

![tipos_jerarquia](http://contribute.geeksforgeeks.org/wp-content/uploads/1-300x162.jpg)
</center>

Profundizar más sobre los 3 tipos (importantes) de iteradores no esta en el alcance de este curso, dado que implicaría explicar librerias de otros _conteiners_. Si bien ya utilizamos __vector__ y su iterador (de tipo unidireccional o hacia adelante), existen otros como los listados en la siguiente tabla.

<center>

![tabla_tipos](http://contribute.geeksforgeeks.org/wp-content/uploads/2-7-279x300.jpg)
</center>

Luego, para crear un iterador de otro tipo solo bastara especificar a que __conteiner__ pertenece; sin embargo se motiva al lector a que, utilizando solo los conceptos expuestos, entienda que en el fondo un iterador es un __puntero__


Si se desea profundizar en los temas mencionados que no tocaremos en este curso, puede revisar la siguiente documentación (en inglés):

* [Introducción a iteradores](http://www.geeksforgeeks.org/introduction-iterators-c/)
* [Iteradores hacia adelante](http://www.geeksforgeeks.org/forward-iterators-in-cpp/)
* [Iteradores bidireccionales](http://www.geeksforgeeks.org/bidirectional-iterators-in-cpp/)
* [Iteradores de acceso aleatorio](http://www.geeksforgeeks.org/random-access-iterators-in-cpp/)
