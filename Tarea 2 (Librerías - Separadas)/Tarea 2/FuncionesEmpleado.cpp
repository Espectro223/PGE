// Funciones de Empleado.h //

#include <iostream>
#include <string>
#include "Empleado.h"
using namespace std;

Empleado::Empleado(string Nombre, string Apellido, int Edad, bool Genero, double DNI, float Salario, string Cargo) {
	setNombre(Nombre);
	setApellido(Apellido);
	setEdad(Edad);
	setGenero(Genero);
	setDNI(DNI);
	this->Salario = Salario;
	this->Cargo = Cargo;
}

void Empleado::setSalario(float Salario) {
	this->Salario = Salario;
}

void Empleado::setCargo(string Cargo) {
	this->Cargo = Cargo;
}

float Empleado::getSalario() {
	return Salario;
}

string Empleado::getCargo() {
	return Cargo;
}