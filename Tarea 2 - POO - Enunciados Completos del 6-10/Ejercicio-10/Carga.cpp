#include "Carga.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Carga::Carga() {

	string nombre;
	int cantidad;
	float precio;
	int indicador;
	float precioXcantidad = 0;
	float precioTotal = 0;

	int tamaño = carrito->getSize();

	for (int i = 0; i < tamaño; i++) {

		cout << "-> Ingresando Datos del Producto N°" << i + 1 << endl;
		cout << "Ingrese el nombre: "; cin >> nombre;

		cout << "Indique la cantidad: "; cin >> cantidad;
		while (cantidad <= 0) {
			cout << "Indique la cantidad: "; cin >> cantidad;
		}

		cout << "Indique el precio del producto: "; cin >> precio;
		while (precio <= 0) {
			cout << "Indique el precio del producto: "; cin >> precio;
		}

		cargarProductos(nombre, precio, cantidad, i);
		carrito->pushProducto(*(producto + i));

	}

	cout << "*\t*\t* MOSTRANDO PRODUCTOS DEL CARRITO *\t*\t*\n\n";
	cout << "Nombre	  Cantidad   Precio   Precio x Cantidad\n";
	for (int x = 0; x < tamaño; x++) {

		nombre = (producto + x)->getNombre();
		precio = (producto + x)->getPrecio();
		cantidad = (producto + x)->getCantidad();
		precioXcantidad = cantidad * precio;
		cout << "+ " << nombre << " | " << cantidad << " X  | " << precio << " || " << precioXcantidad << endl;

		precioTotal += precioXcantidad;
	}

	cout << "\n\nEl precio total del carrito es: " << precioTotal << endl;
	Linea();
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}

void Carga::cargarProductos(string nombre, float precio, int cantidad, int indice){

	(producto + indice)->setNombre(nombre);
	(producto + indice)->setCantidad(cantidad);
	(producto + indice)->setPrecio(precio);
}