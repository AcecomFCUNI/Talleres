#include <stdio.h>

enum DiasSemanas{
	Domingo = -2,
	Lunes,
	Marte,
	Miercoles,
	Jueves,
	Viernes,
	Sabado
};

int main(int argc, char** argv){

	enum DiasSemanas dia;

	for (dia = Domingo; dia <= Sabado; dia++){
		printf("%d ", dia);
	}

	return 0;
}
