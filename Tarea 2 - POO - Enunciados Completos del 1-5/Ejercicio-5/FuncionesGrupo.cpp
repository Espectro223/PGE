// Funciones de Grupo.h //

#include <iostream>
#include <string>
#include "Grupo.h"
using namespace std;

Grupo::Grupo(int Size) {
	this->Size = Size;
	Estudiantes = new Estudiante[Size];
}

void Grupo::setSize(int Size) {
	this->Size = Size;
	Estudiantes = new Estudiante[Size];
}

int Grupo::getSize() {
	return Size;
}

Estudiante* Grupo::getEstudiantes() {
	return Estudiantes;
}

int Grupo::sacarPromedioNotas() {
	int Total = 0;
	for (int x = 0; x != Size; x++) {
		Total += (Estudiantes + x)->getNota();
	}
	int Promedio = Total / Size;
	return Promedio;
}

bool Grupo::pushEstudiante(Estudiante estudiante) {
	for (int x = 0; x != Size; x++) {
		if ((Estudiantes + x)->getNombre() == "default" && (Estudiantes + x)->getEdad() == 0) {
			*(Estudiantes + x) = estudiante;
			return true;
		}
	}
	return false;
}