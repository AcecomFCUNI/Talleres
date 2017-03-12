/*argumentos.c*/
/*Programa que recibe argumentos desde el terminal*/

#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("Ingreso %d argumentos y el segundo de estos es %s\n",argc,argv[1]);

    return 0;
}
