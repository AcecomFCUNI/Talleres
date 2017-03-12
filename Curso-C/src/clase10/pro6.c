#include <stdio.h>
#include <string.h>
union frases {
	char mensajes[50];
	char ayudas[50];
	char lineas[50];
} palabra;

struct comparte{
	char mensajes[50];
	char ayudas[50];
	char lineas[50];
}Sistema;


int main(int argc, char** argv){
	strcpy(palabra.mensajes, "Primer Mensaje");
	strcpy(palabra.ayudas, "Una Ayuda");
	
	printf("\nFrases en Union: ");
	printf("\n1- %s", palabra.mensajes);
	printf("\n2- %s", palabra.ayudas);
	
	
	strcpy(Sistema.mensajes, "Primer Mensaje");
	strcpy(Sistema.ayudas, "Una Ayuda");
	
	printf("\n\nFrases en Struct: ");
	printf("\n1- %s", Sistema.mensajes);
	printf("\n2- %s\n", Sistema.ayudas);
	return 0;
}
