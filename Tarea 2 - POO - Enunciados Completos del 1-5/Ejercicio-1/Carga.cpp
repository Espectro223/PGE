#include "Carga.h"
#include <iostream>
#include <string>
using namespace std;

Carga::Carga(){

	string nombre, cargo, apellido;
	int edad = -1;
	bool genero;
	double dni = -1;
	float salario = -1;

	Linea();
	cout << "-> Ingrese el nombre del Empleado: "; cin >> nombre;
	cout << "-> Ingrese el apellido de " << nombre << ": "; cin >> apellido;

	while (edad <= 0) {
		cout << "-> Ingrese la edad: "; cin >> edad;
	}

	cout << "-> Ingrese el genero del Empleado (0 = mujer - 1 = Hombre): "; cin >> genero;

	while (dni <= 0) {
		cout << "-> Ingrese el DNI: "; cin >> dni;
	}

	while (salario < 0) {
		cout << "-> Ingrese el Salario que le corresponde al Empleado: "; cin >> salario;
	}

	cout << "-> Ingrese el Cargo que ocupa el empleado: "; cin >> cargo;
	Linea();
	cargarEmpleado(nombre, apellido, edad, genero, dni, salario, cargo);
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}

void Carga::cargarEmpleado(string nombre, string apellido, int edad, bool genero, double dni, float salario, string cargo){

	empleado->setNombre(nombre);
	empleado->setApellido(apellido);
	empleado->setEdad(edad);
	empleado->setGenero(genero);
	empleado->setDNI(dni);
	empleado->setSalario(salario);
	empleado->setCargo(cargo);
}

void Carga::mostrarEmpleado()
{
	string nombre = empleado->getNombre();
	string apellido = empleado->getApellido();
	int edad = empleado->getEdad();
	bool genero_auxiliar = empleado->getGenero();
	string genero;
	if (genero_auxiliar == 0) {

		genero = "Mujer";

	}
	else {
		genero = "Hombre";
	}
	double dni = empleado->getDNI();
	float salario = empleado->getSalario();
	string cargo = empleado->getCargo();

	cout << "Los datos del Empleado que fueron cargados son los siguientes: \n";
	cout << "* " << nombre << ", " << apellido << endl;
	cout << "* " << edad << " de edad | " << genero << " | " << dni << endl;
	cout << "* Ocupa el cargo de: " << cargo << " con un sueldo de: " << salario << endl;
}
