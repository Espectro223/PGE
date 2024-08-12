// Funciones de Triangulo.h //

#include <iostream>
#include <string>
#include "Triangulo.h"
using namespace std;

Triangulo::Triangulo(float Altura, float Base, float L1, float L2, float L3) {
	this->Altura = Altura;
	this->Base = Base;
	this->L1 = L1;
	this->L2 = L2;
	this->L3 = L3;
	sacarArea();
	sacarPerimetro();
}

void Triangulo::setAltura(float Altura) {
	this->Altura = Altura;
}

void Triangulo::setBase(float Base) {
	this->Base = Base;
}

float Triangulo::getAltura() {
	return Altura;
}

float Triangulo::getBase() {
	return Base;
}

float Triangulo::sacarArea() {
	setArea(((Base * Altura) / 2));
	return getArea();
}

float Triangulo::sacarPerimetro() {
	setPerimetro((L1 + L2 + L3));
	return getPerimetro();
}