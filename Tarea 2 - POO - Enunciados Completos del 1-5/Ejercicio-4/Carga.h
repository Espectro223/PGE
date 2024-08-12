#pragma once
#include <iostream>
#include <string>
#include "Perro.h"
#include "Gato.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();

	void cargarGato(bool duerme, bool come);
	void cargarPerro(bool duerme, bool come);

	void mostrarGato();
	void mostrarPerro();

private:
	Perro* perro = new Perro("Firulais");
	Gato* gato = new Gato("Kira");
};