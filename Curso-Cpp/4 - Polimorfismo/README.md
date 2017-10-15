# Semana 4 - Polimorfismo

## 1. Vectores
Para el desarrollo del siguiente capítulo se ve necesario (al menos para no distraernos con dificultades de implementación complementarias) aprender a utilizar una nueva librería que permita manipular los objetos de manera más flexible. Revisaremos qué es un vector y como se utilizan sus operaciones básicas.

> Análisis 1 - Introducción a \<vector>

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<float> v1 = {1.3, 4.6, -2.4, 6.2};
	
	// Iterando sobre elementos
	cout << "Elementos: " << flush;
	for(float element : v1){
		cout << element << "  " << flush;
	}
	cout << endl;

	cout << "Parte entera: " << flush;
	for(float element : v1){
		cout << (int)element << "  " << flush;
	}
	cout << endl;
	
	// Concatenando elementos
	for(float i = 0; i < 4.5; i += .5){
		v1.push_back(i);
	}
	
	cout << "Vector resultante: " << flush;
	for(float element : v1){
		cout << element << "  " << flush;
	}
	cout << endl;
	
}
```
Para ver otras maneras de inicializar un vector en  C++ revisar [esta](http://thispointer.com/5-different-ways-to-initialize-a-vector-in-c/) referencia

> Análisis 2 - Vectores para objetos
```cpp
#include <iostream>
#include <vector>

using namespace std;

class usuario{
	string nombre;
	int edad;

	public:
		void setData(string n, int e){
			nombre = n;
			edad = e;
		}

		void printData(){
			cout << "Usuario:" << nombre << " :: Edad:" << edad << endl;
		}

};

int main(){
	usuario u1;
	usuario u2;
	
	u1.setData("Pepe", 30);
	u2.setData("Mario", 45);
	
	vector<usuario> my_users;
	my_users.push_back(u1);
	my_users.push_back(u2);
	
	for(usuario u: my_users){
		u.printData();
	}
}

```

## 2. Polimorfismo
Ya discutimos en el pasado las ventajas de implementar código orientado al polimorfismo y cómo su uso correcto manejaba ambigüedades y generaba un código mejor estructurado. Ahora toca profundizar estos conocimientos. Existen dos tipos de polimorfismo:

### 2.1 Polimorfismo en tiempo de compilación (Compile polymorphism)
Es aquél tipo de polimorfismo manejado por el compilador; también conocido como enlazado estático, enlazado temprano o **sobrecarga**, consiste en implementar métodos con identificador (nombre) pero de argumentos y tipos de retorno diferentes. Esta tarea es lograda mediante la sobrecarga de **funciones** y **operadores**. Este tipo de polimorfismo es **rápido** y **poco flexible**

### 2.2 Polimorfismo en tiempo de ejecución (Runtime polymorphism)
No lo maneja el compilador. Es conocido también como enlazado dinámico, enlazado tardío o **sobreescritura**, la cual consiste en valernos de la _herencia_ de clases para implementar métodos con los mismos parámetros, pero asociados y dependientes de las clases y subclases respectivas. Esta tarea es lograda mediante implementaciones **virtuales** y **punteros**. Este tipo d epolimorfismo es **lento** y **muy flexible**.

El tema de esta semana se enfocará más en el segundo tipo, dado que el primero ya lo revisamos en su mayoría y la **sobrecarga** se discutirá en clases posteriores. Imaginemos el siguiente escenario: Durante el desarrollo de un videojuego deseamos actualizar el estado de "ataque" de todos los enemigos sobre el jugador; teniendo como atacantes a todo tipo de criaturas. Si estas fuesen de una misma clase podríamos iterar sobre una función de actualización y el problema quedaría resuelto, pero estamos limitados a iterar solo sobre atacantes de misma naturaleza

> Análisis 3 - Introducción a virtualización

```cpp
#include <iostream>

using namespace std;

class Soldado{
	int damage;

	public:
		void setDamage(int d){
			damage = d;
		}

		void dealDamage(){
			cout << "Soldado golpea infligiendo dano: " << damage << endl;
		}
};

class Arquero{
	int damage;

	public:
		void setDamage(int d){
			damage = d;
		}

		void dealDamage(){
			cout << "Arquero dispara inflingiendo dano: " << damage << endl;
		}
};

class Bestia{
	int damage;

	public:
		void setDamage(int d){
			damage = d;
		}

		void dealDamage(){
			cout << "Bestia muerde inflingiendo dano: " << damage << endl;
		}
};

int main(){
	// Creamos arreglos para cada tipo de enemigo
	Soldado s_array[2];
	Arquero a_array[2];
	Bestia b_array[2];

	// Inicializamos los valores de daño que inflingiran
	for (int i = 0; i < 2; i++){
		s_array[i].setDamage(12);
		a_array[i].setDamage(7);
		b_array[i].setDamage(9);
	}

	// Aplicamos el daño
	for (int i = 0; i < 2; i++){
		s_array[i].dealDamage();
		a_array[i].dealDamage();
		b_array[i].dealDamage();
	}
}
```
El primer alcance que presentamos para resolver el problema es el de manipular un arreglo por cada tipo de enemigo, alcance que resultaría inútil si tenemos decenas de tipos disponibles (cosa que ocurre usualmente según la magnitud del juego). Entonces, un segundo alcance consistiría en utilizar nuestros conocimientos de herencia para definir una clase general sobre la cual iterar; así, podríamos usar una estrucutra sobre Enemigos y solo particularizar que tipo de enemigo refereneciar:

```c++
#include <iostream>
#include <vector>

using namespace std;

class Enemigo{
	protected:
		int damage;
};

class Soldado: public Enemigo{
	public:
		void setDamage(int d){
			damage = d;
		}

		void dealDamage(){
			cout << "Soldado golpea infligiendo dano: " << damage << endl;
		}
};

class Arquero: public Enemigo{
	public:
		void setDamage(int d){
			damage = d;
		}

		void dealDamage(){
			cout << "Arquero dispara inflingiendo dano: " << damage << endl;
		}
};

class Bestia: public Enemigo{
	public:
		void setDamage(int d){
			damage = d;
		}

		void dealDamage(){
			cout << "Bestia muerde inflingiendo dano: " << damage << endl;
		}
};

int main(){
	// Creamos arreglos para cada tipo de enemigo
	vector<Enemigo*> eVector;
	
	for(int i = 0; i < 6; i++){
		if(0 <= i < 2) {
			eVector.push_back(new Soldado);
			eVector[i]->setDamage(15);
		}
		else if (2 <= i < 4) {
			eVector.push_back(new Arquero);
			eVector[i]->setDamage(7);
		}
		else {
			eVector.push_back(new Bestia);
			eVector[i]->setDamage(9);
		}
	}
}
```
![vector_enemigos](https://imgur.com/iP44CA7.png)

Sin embargo, el compilador nos retorna errores que indican una falta en la clase padre (Enemigo); algo de esperarse dado que nuestro vector en sí es de Enemigos y nunca implementamos un método "setDamage" dentro de su definición.

```rb
test2.cc: In function ‘int main()’:
test2.cc:51:16: error: ‘class Enemigo’ has no member named ‘setDamage’
    eVector[i]->setDamage(15);
                ^
test2.cc:55:16: error: ‘class Enemigo’ has no member named ‘setDamage’
    eVector[i]->setDamage(7);
                ^
test2.cc:59:16: error: ‘class Enemigo’ has no member named ‘setDamage’
    eVector[i]->setDamage(9);

```
Es aquí donde entra a actuar la virtualización de métodos.
```c++
#include <iostream>
#include <vector>

using namespace std;

class Enemigo{
	protected:
		int damage;
	public:
		virtual void setDamage(int d){};
		virtual void dealDamage(){};
};

class Soldado: public Enemigo{
	public:
		void setDamage(int d){
			damage = d;
		}

		void dealDamage(){
			cout << "Soldado golpea infligiendo dano: " << damage << endl;
		}
};

class Arquero: public Enemigo{
	public:
		void setDamage(int d){
			damage = d;
		}

		void dealDamage(){
			cout << "Arquero dispara inflingiendo dano: " << damage << endl;
		}
};

class Bestia: public Enemigo{
	public:
		void setDamage(int d){
			damage = d;
		}

		void dealDamage(){
			cout << "Bestia muerde inflingiendo dano: " << damage << endl;
		}
};

int main(){
	// Creamos arreglos para cada tipo de enemigo
	vector<Enemigo*> eVector;
	
	for(int i = 0; i < 6; i++){
		if(0 <= i && i < 2) {
			eVector.push_back(new Soldado);
			eVector[i]->setDamage(15);
		}
		else if (2 <= i && i < 4) {
			eVector.push_back(new Arquero);
			eVector[i]->setDamage(7);
		}
		else {
			eVector.push_back(new Bestia);
			eVector[i]->setDamage(9);
		}
	}

	for (Enemigo* e_ptr: eVector){
		e_ptr->dealDamage();
	}
}
```

Si bien el siguiente apartado puede ser un poco más complejo de entender y no revisaremos una aplicación práctica para este (debido a que siempre se puede evitar utilizar), no está demás introducirla para que se sepa de su existencia


<center>

![clase_virtual](https://www.ibm.com/support/knowledgecenter/SSLTBW_2.3.0/com.ibm.zos.v2r3.cbclx01/xcpvirt1.gif)
</center>

> Análisis 4 - Clases virtuales

```cpp
#include <iostream>
#include <vector>

using namespace std;

class Enemigo{
	public:
		Enemigo(){ // Constructor de la clase padre
			cout << "Enemigo creado."<< endl;
		}
};

class Soldado: public Enemigo{
	public:
		// Constructor de la clase heredada invoca a la del padre
		Soldado(): Enemigo(){
			cout << "Soldado generado" << endl;
		}
};

class Noble: public Enemigo{
	public:
		// Constructor de la clase heredada invoca a la del padre
		Noble(): Enemigo(){
			cout << "Noble generado" << endl;
		}
};

class Paladin: public Soldado, public Noble{
	public:
	// Paladin hereda de Soldado y Noble
	// y su constr. llama al de ambos
	Paladin(): Soldado(), Noble(){
		cout << "Paladin generado" << endl;
	}
};

int main(){
	Paladin p;
	// Enemigo * e_ptr = &p;
}
```
