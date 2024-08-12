// Funciones de FiguraGeometrica.h //

#include <iostream>
#include <string>
#include "FiguraGeometrica.h"
using namespace std;

FiguraGeometrica::FiguraGeometrica() {
	Area = 0;
	Perimetro = 0;
}

FiguraGeometrica::FiguraGeometrica(float Area, float Perimetro) {
	this->Area = Area;
	this->Perimetro = Perimetro;
}

void FiguraGeometrica::setArea(float Area) {
	this->Area = Area;
}

void FiguraGeometrica::setPerimetro(float Perimetro) {
	this->Perimetro = Perimetro;
}

float FiguraGeometrica::getArea() {
	return Area;
}

float FiguraGeometrica::getPerimetro() {
	return Perimetro;
}