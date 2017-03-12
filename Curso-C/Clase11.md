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


