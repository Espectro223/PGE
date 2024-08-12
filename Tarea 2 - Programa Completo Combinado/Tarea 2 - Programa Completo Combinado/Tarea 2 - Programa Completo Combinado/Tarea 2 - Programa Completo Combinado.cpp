// Tarea 2.cpp //
// Enunciados Elegidos: 4, 6, 7, 10   //
// Programación Generica y Eventos /
// Edgar Karpowicz y Tomas Molina //

#include <iostream>
#include <string>
#include "Menu.h"
using namespace std;

void Separacion() {
	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << endl;
}

int main()
{
	string suNombre;
	cout << "Ingrese el Nombre de su Veterinario" << endl;
	cin >> suNombre;
	Separacion();
	Menu* menu = new Menu(suNombre);
	cout << "Fin del Juego" << endl;
}
