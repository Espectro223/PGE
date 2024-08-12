// Menu.cpp //

#include <iostream>
#include <string>
#include "Menu.h"
using namespace std;

Menu::Menu() {
	Nombre = "default";
	cuenta = new CuentaCorriente(0, "Veterinaria");
	menuPrincipal();
}

Menu::Menu(string Nombre) {
	this->Nombre = Nombre;
	cuenta = new CuentaCorriente(0, "Veterinaria");
	menuPrincipal();
}

void Menu::setNombre(string Nombre) {
	this->Nombre = Nombre;
}

string Menu::getNombre() {
	return Nombre;
}

void Menu::menuPrincipal() {
	while (true) {
		int Seleccion = 0;
		cout << "BIENVENIDO A LA VETERINARIA" << endl;
		cout << "EL JUEGO DEL VETERINARIO!" << endl;
		Separacion();

		if (puntajeTotal != 0) {
			cout << "Puntaje hasta ahora: " << puntajeTotal << endl;
		}

		cout << "Hola, " << this->Nombre << " presione la Opcion que desee" << endl;
		cout << "1 - Comenzar el Juego" << endl;
		cout << "2 - Ver la Tienda";

		if (cuenta->getSaldo() != 0) {
			cout << " ($" << cuenta->getSaldo() << ")";
		}
		cout << endl;

		cout << "3 - Salir" << endl;
		Separacion();
		cin >> Seleccion;
		Separacion();
		switch (Seleccion) {
			case 1:
				iniciarJuego();
				break;

			case 2:
				irTienda();
				break;

			case 3:
				cout << "Saliendo..." << endl;
				Separacion();
				return;
				break;

			default:
				cout << "Ingreso Incorrecto! Vuelva a Intentarlo" << endl;
				Separacion();
				break;
		}
	}
}

void Menu::iniciarJuego() {
	juego = new Juego(Nombre);
	puntajeTotal += juego->getPuntaje();
	float saldoTemporal = cuenta->getSaldo();
	saldoTemporal = saldoTemporal + juego->getDineroObtenido();
	cuenta->setSaldo(saldoTemporal);
}

void Menu::irTienda() {
	tienda = new Tienda(this->cuenta);
	puntajeTotal += tienda->getpuntajeObtenido();
}