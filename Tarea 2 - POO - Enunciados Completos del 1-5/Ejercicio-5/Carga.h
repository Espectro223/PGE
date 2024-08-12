#pragma once
#include <iostream>
#include <string>
#include "Grupo.h"
#include "Estudiante.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();

	void cargarEstudiante(string nombre, string apellido, int edad, int nota, int indice);

private:
	const int size = 3;
	Grupo* grupo = new Grupo(size);
	Estudiante* estudiante = new Estudiante[size];
};