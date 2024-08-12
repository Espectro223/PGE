#pragma once
#include <iostream>
#include <string>
#include "Triangulo.h"
#include "Circulo.h"
#include "Cuadrado.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();
	void cargarCuadrado(float L1, float L2);
	void cargarCirculo(float diametro);
	void cargarTriangulo(float Altura, float Base, float L1, float L2, float L3);
	void mostrarCuadrado();
	void mostrarCirculo();
	void mostrarTriangulo();

private:
	Circulo* circulo = new Circulo();
	Cuadrado* cuadrado = new Cuadrado();
	Triangulo* triangulo = new Triangulo();
};