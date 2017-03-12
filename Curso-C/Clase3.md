# CursoC 
Curso C acecom

Estructuras de Control
===

##Estructuras de control condicionales

### Sentencias if else

![if flow](/images/decision_making.jpg)

### Estructura de las sentencias if

```c
if(expresion){
    /*
    Sentencias
    */
}

// Cuando solo hay una sentencia dentro

if(expresion)
    //Sentencia
```
Cuando la expresión dentro de los paréntesis del if sea verdadera (en C un valor numérico es verdadero cuando es distinto de 0 ), se ejecuta el bloque de código que está dentro de las llaves. Si solo se tiene una sentencia se pueden omitir las llaves.

```c
if(expresion){
    /*
    Sentencias
    */
}

else{
    /*
    Sentencias
    */
}
```
Cuando hay solo una sentencia dentro de else

```c
if
    //sentencia
else
    //sentencia
```
Si la expresión en el if es falsa entonces se ejecutará el bloque de código que pertenece al else. Si solo hay una sentencia en el else se pueden omitir las llaves. 

Un else siempre debe estar emparejado con un if, no puede ir solo.

### Ejemplo 

```c
    #include <stdio.h>
    
    int main(){
        int numero;
        
        printf("Ingresa un numero: ");
        scanf("%d",&numero)
        
        if(numero%2 == 0)
            printf("El numero es par\n");
        else
            printf("El numero es impar\n");
        return 0;
    }
   ``` 
![if else flow](/images/if_else_statement.jpg)

### ¿A qué if pertenecen los siguientes else?

```c
if(expresion)
    if(expresion)
        //sentencia
else
    //sentencia
```

```c
if(expresion){
    if(expresion)
        //sentencia
}

else
    //sentencia

```

### Sentencias else-if

```c
if(expresion){
    /*
    Sentencias
    */
}

else if(expresion){
    /*
    Sentencias
    */
}

else if(expresion){
    /*
    Sentencias
    */
}

/*
Pueden haber n else if
*/

else {
    /*
    Sentencias
    */
}
```

### Ejemplo: Programa que diga si  una ecuación de segundo grado tiene soluciones reales,  única solución o no tiene solución real

```c
    #include <stdio.h> 
    
    int main (){
    
        int a, b, c, d;
            
        printf("Ingrese a, b y c");
        scanf("%d %d %d",&a,&b,&c);
        
        d = b*b - 4*a*c;
        
        if (d > 0)
            printf("Tiene raices reales distintas \n");
        else if (d < 0 )
            printf("Tiene raices complejas\n");
        else 
            printf("Tiene solucion real unica\n");
        
        return 0;
    }
```


### La sentencia de selección switch

## Estructura de una sentencia switch

Si el valor de la expresión coincide con uno de los casos se ejecuta el bloque de código, caso contrario se ejecuta el default , el cual es opcional. La sentencia break sirve para salir del switch, los valores de los casos son etiquetas, por ello si no se pone una sentencia break se seguirán ejecutando las sentencias de los demás casos hasta que se ejecute un break. Los valores de los casos son constantes. 

```c 
switch(expresion){

    case valor1:
        /* Sentencias */
        break;
    case valor2:
        /* Sentencias */
        break;
    
    /*mas casos*/
    
    case valorn:
        /* Sentencias */
        break;
    
    default:
        /* Sentencias */
        break;

}
```
Se ejecutará un bloque de código de cada caso en función del valor de la variable opción. Si no se cumple ningún caso, se ejecuta el bloque de código de default. El bloque default es opcional. 

![switch statemente](/images/switch_statement.jpg)

### Operador ternario

```c
expr1 ? expr2 : expr3;
```

### Ejemplo
```c 
/* Programa que ve devuelve el mayor de dos numeros*/

mayor = a > b ? a : b ;

```
Mismo ejemplo con if else

/* Mismo ejemplo con if else*/
```c
if( a > b )
    return a ; 
    
else 
    return b ; 
```
## Bucles While y for
```c
while(expresion){
    /*
    Sentencias
    */
}

/*La expresion se evalua, si esta es distinta de cero, se ejecutan las sentencias
  Se ejecutan las sentencias mientras que la expresion sea distinta de cero.
*/

for(expresion1 ; expresion2 ; expresion3){
    /*
    Sentencias
    */
}

// Es equivalente a

expresion1;
while(expresion2){
    /*
    Sentencias
    */
    expresion3;
}

// expresion 1 es de asignacion
// expresion 2 es la condicion
//expresion 3 es la actualizacion

// Cuidado con los bucles infinitos :'v

//Ejemplo 
for (; ; ) {

}


while(1){

}

// Bucles anidados
```
## Bucles do while

Los bucles do while ejecutan las sentencias y luego evaluan la expresion.

```c
do {
/*
Sentencias
*/
}while(expresion);

```

[Libro de C Dennis Ritchie ](https://www.ime.usp.br/~pf/Kernighan-Ritchie/C-Programming-Ebook.pdf)

[Gif](https://gfycat.com/HorribleMealyJunco)

[Intro a la programacion en C](http://www.losersjuegos.com.ar/_media/referencia/libros/c/c.pdf)

