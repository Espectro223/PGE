#include <iostream>
#include <string>
#include "Trabajador.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();
	void cargarEmpleado(string nombre, string apellido, int edad, bool genero, double dni, string cargo);
	void mostrarEmpleado();

private:
	Persona* individuo = new Persona();
	Trabajador* trabajador = new Trabajador(*individuo);
};