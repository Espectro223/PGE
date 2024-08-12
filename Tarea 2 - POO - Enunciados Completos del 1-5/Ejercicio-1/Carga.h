#include <iostream>
#include <string>
#include "Empleado.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();
	void cargarEmpleado(string nombre, string apellido, int edad, bool genero, double dni, float salario, string cargo);
	void mostrarEmpleado();

private:
	Empleado* empleado = new Empleado();
};