# Listas 
## Introducción
En esta clase iniciaremos con el estudio de las estructuras de datos dinámicas. Al contrario que
las estructuras estáticas de datos estáticas [ arrays (vectores y tablas ) y estructuras ]en las que su
tamaño en memoria se establece en la compilación y permanece inalterable durante la ejecución
del programa, la estructura de datos dinámica crecen y se contraen a medida que se ejecuta el
programa.
La estructura de datos que estudiaremos en esta clase se llaman listas enlazadas que es una
colección de elementos, denominados nodos, dispuestos uno a continuación de otro, cada uno de
ellos conectado al siguiente por un “enlace” o “puntero”. Las listas enlazadas son estructuras muy
flexibles y con numerosas aplicaciones en el mundo de la programación.

## Fundamentos Teóricos
En clases anteriores estudiamos estructuras lineales de elementos homogéneos ( tablas, vectores )
y se usaban arrays para implementar tales estructuras. Esta técnica obliga a fijar por adelantado
el espacio ocupado en memoria, de modo que cuando se desea añadir un elemento nuevo que
rebase el tamaño pre fijado del array, no es posible realizar la operación sin que se produzca un
error e tiempo de ejecución. Ello se debe a que los arrays hacen un uso ineficiente de la memoria.
Por ello se recurre a los “punteros” que hacen un uso más eficiente de la memoria.
Una lista enlazada es una colección o secuencia de elementos dispuestos uno detrás de otro en
el que cada elemento se conecta al otro por un “enlace” o “puntero”. La idea básica consiste
en construir una lista cuyos elementos llamados nodos se componen de dos partes o campos: la
primera contiene la información y es, por consiguiente, un valor de tipo genérico (denominado
Dato, TipoElemento, Info, etc) y la segunda parte o campo es un puntero (denominado enlace,
next, sgte) que apunta al siguiente elemento de la lista.


Los enlaces se representan por flechas para facilitar la compresión de la conexión entre los nodos;
ello indica que el enlace tiene la dirección en memoria del siguiente nodo. En la figura 1 los nodos
forman una secuencia desde el primer elemento, al último de ellos. El primer nodo se enlaza al
segundo, el segundo al tercero y así sucesivamente hasta el último nodo. El nodo último ha de
ser representado de forma diferente para significar que este nodo no se enlaza a ningún otro.
## Clasificación de las listas enlazadas
Se pueden dividir en 4 categorías:
- **Listas simplemente enlazadas:** Cada nodo contiene un único enlace que conecta ese nodo
al nodo siguiente; es eficiente en recorridos directos.
- **Listas doblemente enlazadas:** Cada nodo contiene dos enlaces uno a su nodo predecesor y
el otro a su nodo sucesor; la lista es eficiente en recorrido directo e inverso.
- **Lista circular simplemente enlazada:** Una lista enlazada simplemente en la que el último
elemento (cola) se enlaza al primer elemento (cabeza) de tal modo que la lista puede ser
recorrida en modo circular.
- **Lista circular doblemente enlazada:** Una lista doblemente enlazada en la que el último
elemento (cola) se enlaza al primer elemento y viceversa.

Para cada tipo de estas cuatro estructuras de listas, se pueden elegir una implementación basada
en arrays o una implementación basada en punteros. Estas implementaciones difieren en el modo
en que se asigna la memoria para los datos de los elementos, como se enlazan juntos los elementos
y como se accede a dichos elementos.
Conceptos básicos sobre listas:
Una lista enlazada consta de un conjunto de nodos. Un nodo consta de un campo dato y un
puntero que apunta al “siguiente” elemento de la lista. El primer nodo, frente, es el apuntado
por cabeza. La lista encadena nodos juntos desde el frente al final (cola) de la lista. El final se
identifica como el nodo cuyo campo tiene el valor NULL = 0. La lista se recorre desde el primero
al último nodo; en cualquier punto del recorrido la posición actual se referencia por el puntero
“Ptr_actual”. En el caso que la lista no contiene nodo (está vacía), el puntero cabeza es nulo.
## Operaciones en las listas enlazadas:
Una lista enlazada requiere unos controles para la gestión de los elementos contenidos en ellas.
Estos controles se manifiestan en forma de operaciones que tendrán las siguientes funciones:

**1. Declaración de un nodo:**
Una lista se compone de una serie de nodos enlazados mediante punteros. En C podemos declarar
un nuevo tipo de dato por un nodo mediante las palabras reservadas struct que contendrá las
partes de nuestro nodo.
```c 
struct Nodo
{
int dato;
struct Nodo* enlace;
};
typedef struct Nodo
{
int dato;
struct Nodo enlace;
}NODO;
```
Dado que los tipos de datos que se puede incluir en una lista pueden ser de cualquier tipo, con
el objetivo de que el tipo de que el tipo de dato de cada nodo se pueda cambiar con facilidad, se
suele utilizar una sentencia typedef para declarar el nombre de “elemento” como un sinónimo del
tipo de dato de cada campo. Como se muestra a continuación:
```c
typedef double Elemento;
struc nodo
{
Elemento dato;
struct nodo *enlace;
};
```

**Puntero de cabeza y cola:**
Normalmente, los programas no declaran realmente variables de tipo nodo. En su lugar cuando
se construye y manipula una lista enlazada, a la lista se accede a través de uno o más punteros a
los nodos. El acceso más frecuente a una lista enlaza es a través del primer nodo de la lista que
se llama “cabeza” de la lista. En ocasiones se mantiene también u puntero al último nodo de una
lista enlazada “cola”.
```c
//declaracion del nodo
typedef double elemento
struct nodo
{
elemento dato;
struct nodo *enlace;
};
//definicion de punteros
struct nodo *ptr_cabeza;
struct nodo *ptr_cola;cada puntero a un nodo debe ser declarado como una variable puntero:
struct nodo *ptr_cabeza;
struct nodo *ptr_cola;
```

El último elemento de la lista contiene un valor de 0, esto es, un puntero (NULL) que señala el
final de la lista.
El puntero nulo:
La palabra NULL, representa el puntero nulo, que es una constante especial de C. se puede
usar el puntero nulo para cualquier valor de puntero que no apunte a ningún sitio. Se utiliza
normalmente en dos situaciones:
- Usar el puntero nulo en el campo enlace o siguiente del nodo final de una lista enlazada.
- Cuando una lista enlazada no tiene ningún nodo, se utiliza el puntero NULL como puntero
de cabeza y de cola. Tal lista se denomina lista vacia.
En un programa, el puntero nulo se puede escribir como NUL, que es una constante de la biblioteca
estándar stdlib.h. El operador (->) de selección de un miembro: Si p es un puntero a una
estructura y m es un miembro de la estructura, entonces p->m accede al miembro m de la
estructura apuntada por p. Suponiendo que un programa ha de construir un alista enlazada y
crear un puntero de cabecera ptr_cabeza a un nodo Nodo, el operador * de dirección aplicado
a una variable puntero representa el contenido del nodo apuntador por ptr_cabeza. Es decir
*ptr_cabeza es un tipo de dato Nodo. Al igual que cualquier otro objeto se puede acceder a los
miembros de *ptr_cabeza; por ejemplo:
```c
printf(“%1f”,(*ptr_cabeza).dato);
```
Sin los paréntesis, el significado de ptr_cabeza producirá un error de sintaxis, al intentar evaluar
ptr_cabeza.dato antes de la indirección.
p->m significa lo mismo que (*P).m
podemos reescribir la orden anterior de la siguiente manera:
```c
printf("%1f",ptr_cabeza->dato);
```
**2. Construcción de una lista:**
Un algoritmo para la creación de una lista enlazada entraña los siguientes pasos:
Paso 1: Declaración del tipo de dato y el puntero de cabeza.
Paso 2: Asignar memoria para un elemento del tipo definido anteriormente utilizando alguna de
las funciones de asignación de memoria y un cast para la conversión de void* al tipo puntero a
nodo; la dirección del nuevo elemento es ptr_nuevo.Paso 3: Crear iterativamente el primer elemento (cabeza) y los elemento sucesivos de una enlazada
simple.
Paso 4: repetir hasta que no haya más entradas para el elemento.
EJEMPLO:
Crear una lista enlazada de elementos que almacenen datos de tipo entero.
Un elemento de la lista se puede definir con la ayuda de la estructura siguiente:
```c
struct Elemento
{
Int dato;
struct Elemento *siguiente;
};
typedef struct Elemento Nodo;
```
El siguiente paso para construir la lista es declarar la variable Primero que apuntara al primer
elemento de la lista: Nodo *Primero = NULL;
El puntero primero se ha iniciado a un valor nulo, lo que implica que la lista esta vacia. Ahora
se crea un elemento de la lista, para ello hay que reservar memoria, y asignar la dirección de
memoria al puntero Primero:
```c
Primero = (Nodo*)malloc(sizeof(Nodo));
//Ahora podemos asignar un valor al campo:
Primero->dato = 11;
Primero->siguiente = NULL;
```
La operación de crear nodo se puede hacer en una función a la que se pasa el valor del campo
dato y el campo siguiente. La función devuelve un puntero al nodo creado:
```c
Nodo* crearnodo(int x , Nodo* enlace)
{
Nodo *p;
P = (Nodo*)malloc(sizeof(Nodo));
p->dato = x;
p->siguiente = enlace;
return p;
}
//Usamos la función que creamos para crear el primer nodo de la lista:
Primero = Crearnodo(11,NULL);
//Si ahora queremos añadir un nuevo elemento con valor 6 y situarlo en el primer lugar de la lista:
Primero = Crearnodo(6,Primero);
```
**3. Insertar un elemento en la lista:**
El algoritmo empleado para añadir o insertar un elemento en una lista enlazada varía dependiendo
de la posición en que se desea insertar el elemento. La posición de inserción puede ser:
• En la cabeza.
• En el final.
• Antes de un elemento especificado.
• Después de un elemento especificado.
Insertar un elemento en la cabeza de una lista:
• Asignar un nuevo nodo apuntador por nuevo que es una variable puntero local que apunta
al nuevo nodo que se va a insertar en la lista.
• Situar el nuevo elemento en el campo dato del nuevo nodo.
• Hacer que el campo enlace siguiente del nuevo nodo apunte a la cabeza de la lista original.
• Hacer que cabeza apunte al nuevo nodo que se ha creado.
EJEMPLO: Una lista enlazada contiene elementos 10,25 y 40 insertar un nuevo elemento 4 en la
cabeza de la lista.
```c
typedef int Item;
typedf struct tipo-nodo
{
Item dato;
struct tipo-nodo* siguiente;
} Nodo;
Nodo* nuevo;
nuevo = (Nodo*)malloc(sizeof(Nodo));
nuevo -> dato = entrada;
```
El campo enlace del nuevo nodo apunta a la cabeza actual de la lista:
Nuevo -> siguiente = cabeza;Se cambia el puntero de cabeza para apuntar al nuevo nodo creado: es decir, el puntero de cabeza
apunta al mismo sitio que apunte nuevo
cabeza = nuevo;
Vemos el código fuente de InsertarCabezaLista:
```c
void InsertarCabezaLista(Nodo** cabeza, Item entrada)
{
Nodo *nuevo ;
nuevo = (Nodo*)malloc(sizeof(Nodo)); / * asigna nuevo nodo * /
nuevo -> dato = entrada; /* pone elemento en nuevo * /
nuevo -> siguiente = *cabeza; / * enlaza nuevo nodo al frente de la lista * /
*cabeza = nuevo; / * mueve puntero cabeza y apunta al nuevo nodo * /
}
```

Ahora digamos que queremos insertar un nodo entre dos nodos ya existentes. El algoritmo de la
nueva operación insertar requiere las siguientes etapas:
1. Asignar el nuevo nodo apuntado por el puntero nuevo.
2. Situar el nuevo elemento en el campo dato (Info) del nuevo nodo.
3. Hacer que el campo enlace siguiente del nuevo nodo apunte al nodo que va después de
la posición del nuevo nodo (o bien a NULL si no hay ningún nodo después de la nueva
posición).
4. En la variable puntero anterior tener la dirección del nodo que está antes de la posición
deseada para el nuevo nodo. Hacer que anterior -> siguiente apunte al nuevo nodo que se
acaba de crear.
El código sería el siguiente:
```c
void InsertarLista(Nodo* anterior,Item entrada)
{
Nodo *nuevo;
nuevo = (Nodo*)malloc(sizeof(Nodo));
nuevo -> dato = entrada;
nuevo -> siguiente = anterior -> siguiente;
anterior -> siguiente = nuevo;
}
```
**4. Búsqueda de un elemento**
Dado que una función en C puede devolver un puntero, el algoritmo que sirva para localizar un
elemento en una lista enlazada puede devolver un puntero a ese elemento.
La función BuscarLista utiliza una variable puntero denominada indice que va recorriendo la
lista nodo a nodo. Mediante un bucle, Indice apunta a los nodos de la lista de modo que si se
encuentra el nodo buscado, se devuelve un puntero al nodo buscado con la sentencia de retorno
(return); en el caso de no encontrarse el nodo buscado la función debe devolver NULL(return
NULL).
El código es como sigue:
```c
Nodo* BuscarLista (Nodo* cabeza, item destino)
{
Nodo *indice;
for (indice = cabeza; indice != NULL; indice = indice -> siguiente)
if (destino == índice -> dato)
return indice;
return NUll;
}
```
**5. Supresión de un nodo en una lista**
La operación de eliminar un nodo de una lista enlazada supone enlazar el nodo anterior con
el nodo siguiente al que se desea eliminar y liberar la memoria que ocupa. El algoritmo para
eliminar un nodo que contiene un dato se puede expresar en estos pasos:
1. Búsqueda del nodo que contiene el dato. Se ha de tener la dirección del nodo a eliminar.
2. El puntero siguiente del nodo anterior ha de apuntar al siguiente del nodo a eliminar.
3. En caso de que el nodo a eliminar sea el primero, cabeza, se modifica cabeza para que tenga
4. Por último, se libera la memoria ocupada por el nodo.
A continuación se escribe una función que recibe la cabeza de la lista y el dato del nodo que se
quiere borrar.
```c
void eliminar (Nodo* * cabeza, item entrada)
{
Nodo* actual, anterior;
int encontrado = O;
actual = *cabeza; anterior = NULL;while ((actual!=NULL) && (!encontrado))
{
encontrado = (actual->dato = = entrada);
if (!encontrado)
{
anterior = actual;
actual = actual -> siguiente;
}
if (actual != NULL)
{
if (actual == *cabeza)
*cabeza = actual->siguiente;
else
{
anterior -> siguiente = actual ->siguiente
free(actua1);
}
```
