// Funciones de CarritoDeCompras.h //

#include <iostream>
#include <string>
#include "CarritoDeCompras.h"
using namespace std;

CarritoDeCompras::CarritoDeCompras(int Size) {
	this->Size = Size;
	carro = new Producto[Size];
}

void CarritoDeCompras::setSize(int Size) {
	this->Size = Size;
	carro = new Producto[Size];
}

int CarritoDeCompras::getSize() {
	return Size;
}

Producto* CarritoDeCompras::getCarro() {
	return carro;
}

bool CarritoDeCompras::pushProducto(Producto producto) {
	for (int x = 0; x != Size; x++) {
		if ((carro + x)->getNombre() == "default") {
			*(carro + x) = producto;
			return true;
		}
	}
	return false;
}
