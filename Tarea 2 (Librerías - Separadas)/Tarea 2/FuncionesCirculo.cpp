// Funciones de Circulo.h //

#include <iostream>
#include <string>
#include "Circulo.h"
using namespace std;

Circulo::Circulo(float Diametro) {
	this->Diametro = Diametro;
	sacarArea();
	sacarPerimetro();
}

void Circulo::setDiametro(float Diametro) {
	this->Diametro = Diametro;
}

float Circulo::getDiametro() {
	return this->Diametro;
}

float Circulo::sacarArea() {
	float Areatemp = (3.14 * (Diametro * Diametro));
	setArea((Areatemp));
	return getArea();
}

float Circulo::sacarPerimetro() {
	float Perimtemp = 3.14 * Diametro;
	setPerimetro(Perimtemp);
	return getPerimetro();
}