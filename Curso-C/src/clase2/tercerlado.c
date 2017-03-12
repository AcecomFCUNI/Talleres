/*tercerlado.c*/
/*Programa para calcular el lado de un triangulo
usando la ley de cosenos*/

#include <stdio.h>
#include <math.h>

#define PI 3.14

int main(int argc, char const *argv[])
{
    float a, b, c;
    float angle;

    printf("Ingresa 2 lados y el angulo entre ellos:\n");
    scanf("%f%f%f",&a,&b,&angle);

    c = sqrt(a*a + b*b - 2*a*b*cos(angle*PI/180));

    printf("El tercer lado es %.5f\n", c);

    return 0;
}
