// Funciones de Persona.h //

#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

Persona::Persona() {
	Nombre = "default";
	Apellido = "default";
	Edad = 0;
	Genero = 0;
	DNI = 0;
}

Persona::Persona(string Nombre, string Apellido, int Edad, bool Genero, double DNI) {
	this->Nombre = Nombre;
	this->Apellido = Apellido;
	this->Edad = Edad;
	this->Genero = Genero;
	this->DNI = DNI;
}

void Persona::setNombre(string Nombre) {
	this->Nombre = Nombre;
}

void Persona::setApellido(string Apellido) {
	this->Apellido = Apellido;
}

void Persona::setEdad(int Edad) {
	this->Edad = Edad;
}

void Persona::setGenero(bool Genero) {
	this->Genero = Genero;
}

void Persona::setDNI(double DNI) {
	this->DNI = DNI;
}

string Persona::getNombre() {
	return Nombre;
}

string Persona::getApellido() {
	return Apellido;
}

int Persona::getEdad() {
	return Edad;
}

bool Persona::getGenero() {
	return Genero;
}

double Persona::getDNI() {
	return DNI;
}