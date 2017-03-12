## Estructuras

Las estructuras nos permiten agrupar varios datos, que mantengan algún tipo de relación en la resolución de un problema, aunque sean de distinto tipo, permitiendo manipularlos todos juntos, usando un mismo identificador, o cada uno por separado. A cada variable creada dentro de la estructura se le llama campo(field).


Declaramos una estructura de la siguiente forma:

```
    struct persona{
        char name[20];
        int edad;
        char codigo[10];
    }alumno;
```

"alumno" es una instancia de "persona" y no es necesario ponerla aquí. Se podria omitir de la declaracion de "mystruct" y más tarde declararla usando:

```
    struct persona{
        char name[20];
        int edad;
        char codigo[10];
    };
    struct persona alumno;
```

También es una práctica muy común asignarle un alias o sinónimo al nombre de la estructura, para evitar el tener que poner "struct persona" cada vez. C nos permite la posibilidad de hacer esto usando la palabra clave typedef, lo que crea un alias a un tipo:

```
    typedef struct persona{
         ...
    } Alumno;
```

> OBS: Dentro del campo de un estructura se puede declarar una variable de tipo estructura.


## Estructura Anidadas

Anteriormente ya vimos la estructura en la que guardamos el nombre y edad de un alumno. Pero que pasa si queremos además agregar su dirección, si lo hicieramos en la misma estructura esto se vuelve un poco pesado, por ello se utilizan la estructuras anidadas. En la cual podemos declarar un estructura como campo de otra estructura.

```
	typedef struct direccion{
    	char manzana;
        char lote;
    }Direccion;
    }
    typedef struct persona{
        char name[20];
        int edad;
        char codigo[10];
        Direccion direc;
    }Alumno;
```

## Uniones

La definición de "unión" es similar a la de "estructura", La diferencia entre las dos es que en una estructura, los miembros ocupan diferentes áreas de la memoria, pero en una unión, los miembros ocupan la misma área de memoria. Entonces como ejemplo:

```
	union{
        int i;
        double d;
    } u;
```

El programador puede acceder a través de "u.i" o de "u.d", pero no de ambos al mismo tiempo. Como "u.i" y "u.d" ocupan la misma área de memoria, modificar uno modifica el valor del otro, algunas veces de maneras impredecibles.

> El tamaño de una unión es el de su miembro de mayor tamaño.

## Enumeraciones

Una enumeracion (enum) es un tipo definido con constante de tipo entero. En la declaracion de un tipo enum creamos una lista de tipo de datos que se asocian con las constantes enteras 0, 1, 2, 3, 4, 5.... Su forma de definirlas es la siguiente:

```
    enum {
        enumerador1, enumerador2, … enumeradorn
    };
```


REFERENCIAS:
* [Diferencia entre scanf, gets y fgets]()
* [C fputs() fgets() function](www.tutorialdost.com/C-Programming-Tutorial/C-file-io-fgets-fputs-function.aspx)
* [Estructura_de_datos](https://es.wikipedia.org/wiki/Estructura_de_datos)