// Tienda.cpp //

#include <iostream>
#include <string>
#include "Tienda.h"
using namespace std;

Tienda::Tienda(CuentaCorriente* cuenta) {
	this->cuenta = cuenta;
	producto = new Producto("Puntos", 100, 5);
	while (true) {
		int Seleccion = 0;
		cout << "LA TIENDA" << endl;
		Separacion();
		cout << "1 - Comprar " << producto->getNombre() << " por el Precio de " << producto->getPrecio() << endl;
		cout << "2 - Irse" << endl;
		Separacion();
		cin >> Seleccion;
		Separacion();
		switch (Seleccion) {
			case 1:
				if (cuenta->getSaldo() < producto->getPrecio()) {
					cout << "Vaya a Trabajar Veterinario..." << endl;
					Separacion();
				}
				else {
					comprarCosas();
				}
				break;

			case 2:
				return;
				break;

			default:
				cout << "Ingreso Incorrecto. Vuelva a Intentarlo" << endl;
				Separacion();
				break;
		}
	}
}

void Tienda::setCuenta(CuentaCorriente* cuenta) {
	this->cuenta = cuenta;
}

void Tienda::setpuntajeObtenido(int puntajeObtenido) {
	this->puntajeObtenido = puntajeObtenido;
}

CuentaCorriente* Tienda::getCuenta() {
	return cuenta;
}

int Tienda::getpuntajeObtenido() {
	return puntajeObtenido;
}

void Tienda::comprarCosas() {
	float saldoTemporal = cuenta->getSaldo();
	saldoTemporal = saldoTemporal - producto->getPrecio();
	cuenta->setSaldo(saldoTemporal);
	puntajeObtenido += producto->getCantidad();
}