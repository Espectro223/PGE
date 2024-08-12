// Funciones de Vehiculo.h //

#include <iostream>
#include <string>
#include "Vehiculo.h"
using namespace std;

Vehiculo::Vehiculo() {
	setMarca("default");
	setModelo("default");
	setYear(0);
}

Vehiculo::Vehiculo(string Marca, string Modelo, int Year) {
	setMarca(Marca);
	setModelo(Modelo);
	setYear(Year);
}

void Vehiculo::setMarca(string Marca) {
	this->Marca = Marca;
}

void Vehiculo::setModelo(string Modelo) {
	this->Modelo = Modelo;
}

void Vehiculo::setYear(int Year) {
	this->Year = Year;
}

string Vehiculo::getMarca() {
	return Marca;
}

string Vehiculo::getModelo() {
	return Modelo;
}

int Vehiculo::getYear() {
	return Year;
}