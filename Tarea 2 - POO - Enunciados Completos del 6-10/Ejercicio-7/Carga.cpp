#include "Carga.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Carga::Carga() {

	Linea();

	cout << "ANALISIS DEL VETERINARIO\n\n";
	string nombre = animal->getNombre();
	cout << "* La mascota " << nombre << endl;
	animal->Comer();
	animal->Dormir();

	cout << "\nConclusion: ";
	veterinario->examinarAnimal(*animal);
	Linea();
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}