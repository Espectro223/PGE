#pragma once
#include <iostream>
#include <string>
#include "CarritoDeCompras.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();

	void cargarProductos(string nombre, float precio, int cantidad, int indice);

private:
	const int size = 3;
	CarritoDeCompras* carrito = new CarritoDeCompras(size);
	Producto* producto = new Producto[size];
};