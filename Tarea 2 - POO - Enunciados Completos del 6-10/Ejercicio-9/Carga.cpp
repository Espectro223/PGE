#include "Carga.h"
#include <iostream>
#include <string>
using namespace std;

Carga::Carga(){

	string nombre, cargo, apellido;
	int edad;
	bool genero;
	double dni;

	Linea();
	cout << "-> Ingrese el nombre del Empleado: "; cin >> nombre;
	cout << "-> Ingrese el apellido de " << nombre << ": "; cin >> apellido;

	cout << "-> Ingrese la edad: "; cin >> edad;
	while (edad <= 0) {
		cout << "-> Ingrese la edad: "; cin >> edad;
	}

	cout << "-> Ingrese el genero del Empleado (0 = mujer - 1 = Hombre): "; cin >> genero;

	cout << "-> Ingrese el DNI: "; cin >> dni;
	while (dni < 0) {
		cout << "-> Ingrese el DNI: "; cin >> dni;
	}

	cout << "-> Ingrese el Cargo que ocupa el empleado: "; cin >> cargo;
	Linea();
	cargarEmpleado(nombre, apellido, edad, genero, dni, cargo);
	mostrarEmpleado();
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}

void Carga::cargarEmpleado(string nombre, string apellido, int edad, bool genero, double dni, string cargo){

	individuo->setNombre(nombre);
	individuo->setApellido(apellido);
	individuo->setEdad(edad);
	individuo->setGenero(genero);
	individuo->setDNI(dni);
	trabajador->setCargo(cargo);
}

void Carga::mostrarEmpleado()
{
	string nombre = individuo->getNombre();
	string apellido = individuo->getApellido();
	int edad = individuo->getEdad();
	bool genero_auxiliar = individuo->getGenero();
	string genero;
	if (genero_auxiliar == 0) {

		genero = "Mujer";

	}
	else {
		genero = "Hombre";
	}
	double dni = individuo->getDNI();
	float salario = trabajador->getSalario();
	string cargo = trabajador->getCargo();

	cout << "Los datos del Trabajador que fueron cargados son los siguientes: \n";
	cout << "* " << nombre << ", " << apellido << endl;
	cout << "* " << edad << " años | " << genero << " | " << dni << endl;
	cout << "* Ocupa el cargo de: " << cargo << " con un sueldo de: " << salario << endl;
}
