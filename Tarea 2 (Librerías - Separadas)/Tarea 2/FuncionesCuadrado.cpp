// Funciones de Cuadrado.h //

#include <iostream>
#include <string>
#include "Cuadrado.h"
using namespace std;

Cuadrado::Cuadrado(float L1, float L2) {
	this->L1 = L1;
	this->L2 = L2;
	sacarArea();
	sacarPerimetro();
}

void Cuadrado::setL1(float L1) {
	this->L1 = L1;
}

void Cuadrado::setL2(float L2) {
	this->L2 = L2;
}

float Cuadrado::getL1() {
	return L1;
}

float Cuadrado::getL2() {
	return L2;
}

float Cuadrado::sacarArea() {
	setArea((L1 * L2));
	return getArea();
}

float Cuadrado::sacarPerimetro() {
	float Perim = (L1 * 2) + (L2 * 2);
	setPerimetro(Perim);
	return getPerimetro();
}