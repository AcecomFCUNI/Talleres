/*norma.c*/
/*Programa que calcula la norma de un vector*/

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{

    float x , y ; 
    float norm;

    printf("Ingresar x e y :\n");
    scanf("%f%f",&x,&y);
    norm = sqrt(x*x + y*y);

    printf("La norma del vector es %.3f\n", norm); 

    return 0;
}
