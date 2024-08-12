// Funciones de Moto.h //

#include <iostream>
#include <string>
#include "Moto.h"
using namespace std;

Moto::Moto(){}

Moto::Moto(string Marca, string Modelo, int Year, float Cilindrada, float Potencia) {
	setMarca(Marca);
	setModelo(Modelo);
	setYear(Year);
	this->Cilindrada = Cilindrada;
	this->Potencia = Potencia;
}

void Moto::setCilindrada(float Cilindrada) {
	this->Cilindrada = Cilindrada;
}

void Moto::setPotencia(float Potencia) {
	this->Potencia = Potencia;
}

float Moto::getCilindrada() {
	return Cilindrada;
}

float Moto::getPotencia() {
	return Potencia;
}
