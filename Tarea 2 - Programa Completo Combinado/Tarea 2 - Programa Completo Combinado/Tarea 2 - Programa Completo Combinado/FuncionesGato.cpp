// Funciones de Gato.h //

#include <iostream>
#include <string>
#include "Gato.h"
using namespace std;

Gato::Gato(string Nombre) {
	setNombre(Nombre);
}

void Gato::Maullar() {
	cout << getNombre() << " maulla" << endl;
}