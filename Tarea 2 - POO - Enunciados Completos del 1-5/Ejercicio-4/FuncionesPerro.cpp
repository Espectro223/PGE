// Funciones de Perro.h //

#include <iostream>
#include <string>
#include "Perro.h"
using namespace std;

Perro::Perro(string Nombre) {
	setNombre(Nombre);
}

void Perro::Ladrar() {
	cout << getNombre() << " ladra" << endl;
}