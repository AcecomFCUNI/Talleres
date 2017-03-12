#include<stdio.h>
struct persona{
  char nombre[20];
  int edad;
} alumno1 ={"Enrique Alexis", 20}, alumno2 ={"Acecom", 20};

void main(){
  printf("Su nombre es: ");
  fputs(alumno1.nombre,stdout);
  printf("\nSu edad es: ");
  printf("%d\n",alumno1.edad);
  
  printf("Su nombre es: ");
  fputs(alumno2.nombre,stdout);
  printf("\nSu edad es: ");
  printf("%d\n",alumno2.edad);
}
