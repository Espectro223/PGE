// Funciones de Trabajador.h //

#include <iostream>
#include <string>
#include "Trabajador.h"
using namespace std;

Trabajador::Trabajador(Persona Individuo, string Cargo) {
	this->Individuo = &Individuo;
	setCargo(Cargo);
}

void Trabajador::setIndividuo(Persona Individuo) {
	this->Individuo = &Individuo;
}

void Trabajador::setCargo(string Cargo) {
	this->Cargo = Cargo;
	updateSalario();
}

Persona* Trabajador::getIndividuo() {
	return Individuo;
}

string Trabajador::getCargo() {
	return Cargo;
}

float Trabajador::getSalario() {
	return Salario;
}

void Trabajador::updateSalario() {
	int Size = Cargo.size(); // Obtenemos Tamaño del String

	if (Cargo == "Politico") {
		Salario = (Size * 10000); // Politicos tienen privilegios
	}
	else {
		Salario = (Size * 1000); // Sacamos Salario multiplicando el Tamaño del String por 1000, para los Comunes
	}
}