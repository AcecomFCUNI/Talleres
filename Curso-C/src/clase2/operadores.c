/* operadores.c*/
#include <stdio.h>

int main()
{
    int a=5;/* Declaración de un entero */

    printf("%25s %5d\n","Pre-incremento",++a);
    printf("%25s %5d\n","Post-incremento",a++);
    printf("%25s %5d\n","Luego del Post-incremento",a);
    printf("%25s %5d\n","Menos unario",-a);
    printf("%25s %5d\n","Multiplicacion por dos",a*2);
    printf("%25s %5d\n","Division por dos",a/2);
    printf("%25s %5d\n","Modulo dos",a%2);
    printf("%25s %5d\n","Suma con tres",a+3);
    printf("%25s %5d\n","Resta con tres",a-3);
}
