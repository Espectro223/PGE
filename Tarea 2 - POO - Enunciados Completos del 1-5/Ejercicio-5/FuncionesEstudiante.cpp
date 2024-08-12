// Funciones de Estudiante.h //

#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;

Estudiante::Estudiante() {
	this->Nombre = "default";
	this->Apellido = "default";
	this->Edad = 0;
	this->Nota = 0;
}

Estudiante::Estudiante(string Nombre, string Apellido, int Edad, int Nota) {
	this->Nombre = Nombre;
	this->Apellido = Apellido;
	this->Edad = Edad;
	this->Nota = Nota;
}

void Estudiante::setNombre(string Nombre) {
	this->Nombre = Nombre;
}

void Estudiante::setApellido(string Apellido) {
	this->Apellido = Apellido;
}

void Estudiante::setEdad(int Edad) {
	this->Edad = Edad;
}

void Estudiante::setNota(int Nota) {
	this->Nota = Nota;
}

string Estudiante::getNombre() {
	return Nombre;
}

string Estudiante::getApellido() {
	return Apellido;
}

int Estudiante::getEdad() {
	return Edad;
}

int Estudiante::getNota() {
	return Nota;
}