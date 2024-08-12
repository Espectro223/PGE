#include "Carga.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Carga::Carga() {

	string nombre, apellido;
	int nota, edad;
	int indicador;
	bool bucle = true;

	int tamaño = grupo->getSize();

	for (int i = 0; i < tamaño; i++) {

		cout << "-> Ingresando Datos del Estudiante N°" << i + 1 << endl;
		cout << "Ingrese el nombre: "; cin >> nombre;
		cout << "Ingrese el apellido: "; cin >> apellido;

		cout << "Indique la edad: "; cin >> edad;
		while (edad <= 0) {
			cout << "Indique la edad: "; cin >> edad;
		}

		cout << "Indique su nota: "; cin >> nota;
		while (nota < 1) {
			cout << "Indique su nota: "; cin >> nota;
		}

		cargarEstudiante(nombre, apellido, edad, nota, i);
		grupo->pushEstudiante(*(estudiante+i));

	}

	cout << "*\t*\t* MOSTRANDO ESTUDIANTES DEL GRUPO *\t*\t*\n\n";

	for (int x = 0; x < tamaño; x++) {

		nombre = (estudiante + x)->getNombre();
		apellido = (estudiante + x)->getApellido();
		edad = (estudiante + x)->getEdad();
		nota = (estudiante + x)->getNota();

		cout << "+ " << nombre << "," << apellido << " con una edad de " << edad << endl;
		cout << "Con nota de " << nota << endl << endl;
	}

	float promedio = grupo->sacarPromedioNotas();
	cout << "\nEl promedio general del grupo es: " << promedio << endl;
	Linea();
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}

void Carga::cargarEstudiante(string nombre, string apellido, int edad, int nota, int indice){

	(estudiante+indice)->setNombre(nombre);
	(estudiante + indice)->setApellido(apellido);
	(estudiante + indice)->setEdad(edad);
	(estudiante + indice)->setNota(nota);
}