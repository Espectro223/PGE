// Funciones de Triangulo.h //

#include <iostream>
#include <string>
#include "Triangulo.h"
using namespace std;

Triangulo::Triangulo() {}

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

void Triangulo::setL1(float L1) {
	this->L1 = L1;
}

void Triangulo::setL2(float L2) {
	this->L2 = L2;
}

void Triangulo::setL3(float L3) {
	this->L3 = L3;
}

void Triangulo::setBase(float Base) {
	this->Base = Base;
}

float Triangulo::getAltura() {
	return Altura;
}

float Triangulo::getL1() {
	return L1;
}

float Triangulo::getL2() {
	return L2;
}

float Triangulo::getL3() {
	return L3;
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