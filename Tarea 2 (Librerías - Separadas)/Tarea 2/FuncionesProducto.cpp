// Funciones de Producto.h //

#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

Producto::Producto() {
	Nombre = "default";
	Precio = 0;
	Cantidad = 0;
}

Producto::Producto(string Nombre, float Precio, int Cantidad) {
	this->Nombre = Nombre;
	this->Precio = Precio;
	this->Cantidad = Cantidad;
}

void Producto::setNombre(string Nombre) {
	this->Nombre = Nombre;
}

void Producto::setPrecio(float Precio) {
	this->Precio = Precio;
}

void Producto::setCantidad(int Cantidad) {
	this->Cantidad = Cantidad;
}

string Producto::getNombre() {
	return Nombre;
}

float Producto::getPrecio() {
	return Precio;
}

int Producto::getCantidad() {
	return Cantidad;
}