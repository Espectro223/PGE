#include "Carga.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Carga::Carga() {

	int indicador;
	bool bucle = true;
	bool come, duerme;
	do {
		Linea();
		cout << "-> Que tipo de Mascota prefieres: \n";
		cout << "1 - Gato\n";
		cout << "2 - Perro\n";
		cout << "3 - Salir\n";
		cout << "--> "; cin >> indicador;

		switch (indicador) {

		case 1:
			
			come = false;
			duerme = true;
			cargarGato(duerme,come);
			gato->Maullar();
			mostrarGato();
			break;

		case 2:
			
			come = true;
			duerme = false;
			cargarPerro(duerme, come);
			perro->Ladrar();
			mostrarPerro();
			break;

		case 3:
			bucle = false;
			cout << "Saliendo del programa...\n";
			break;

		default:
			cout << "La opcion indicada no esta disponible. Eliga una de las validas\n";
			break;
		}

	} while (bucle);
	Linea();
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}

void Carga::cargarGato(bool duerme, bool come){

	gato->setsiCome(come);
	gato->setsiDuerme(duerme);
}

void Carga::cargarPerro(bool duerme, bool come){

	perro->setsiCome(come);
	perro->setsiDuerme(duerme);
}

void Carga::mostrarGato(){

	gato->Comer();
	gato->Dormir();
	Linea();
}

void Carga::mostrarPerro(){

	perro->Comer();
	perro->Dormir();
	Linea();
}