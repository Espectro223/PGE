// Funciones de Coche.h //

#include <iostream>
#include <string>
#include "Coche.h"
using namespace std;

Coche::Coche(string Marca, string Modelo, int Year, int NumeroPuertas, float Cilindrada, float Potencia) {
	setMarca(Marca);
	setModelo(Modelo);
	setYear(Year);
	this->NumeroPuertas = NumeroPuertas;
	this->Cilindrada = Cilindrada;
	this->Potencia = Potencia;
}

void Coche::setNumeroPuertas(int Puertas) {
	NumeroPuertas = Puertas;
}

void Coche::setCilindrada(float Cilindrada) {
	this->Cilindrada = Cilindrada;
}

void Coche::setPotencia(float Potencia) {
	this->Potencia = Potencia;
}

int Coche::getNumeroPuertas() {
	return NumeroPuertas;
}

float Coche::getCilindrada() {
	return Cilindrada;
}

float Coche::getPotencia() {
	return Potencia;
}

