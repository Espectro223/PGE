#include "Carga.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Carga::Carga(){

	string Marca, Modelo;
	float Cilindrada, Potencia;
	int NumeroPuertas, Año;
	int indicador;
	
	Linea();
	cout << "-> Primero, indique que tipo de Vehiculo carga a continuacion: \n"; 
	cout << "0 - Moto\n";
	cout << "1 - Coche\n";
	cin >> indicador;

	while (indicador != 0 && indicador != 1) {
		cout << "Indique un tipo de Vehiculo valido\n";
		cout << "0 - Moto\n";
		cout << "1 - Coche\n";
		cin >> indicador;
	}

	cout << "-> Indique la Marca del Vehiculo: "; cin >> Marca;
	cout << "-> Indique el Modelo: "; cin >> Modelo;
	cout << "-> Indique el Año de Fabricacion del Vehiculo: "; 
	cin >> Año;

	while (Año < 0) {
		cout << "Indique una Fecha valida\n";
		cin >> Año;
	}

	if (indicador == 1) {

		error_coche_2:
		cout << "-> Indique la Cilindrada: "; cin >> Cilindrada;
		while (Cilindrada <= 0) {
			cout << "Indique una Cilindrada valida\n";
			cin >> Cilindrada;
		}

		cout << "-> Indique la potencia de coche: "; cin >> Potencia;
		while (Potencia <= 0) {
			cout << "Indique una Potencia valida\n";
			cin >> Potencia;
		}

		cout << "-> Indique el numero de puertas del coche: "; cin >> NumeroPuertas;
		while (NumeroPuertas < 0) {
			cout << "Indique una Cantidad de Puertas valida\n";
			cin >> NumeroPuertas;
		}

		cargarVehiculo(Marca, Modelo, Año, Cilindrada, Potencia, NumeroPuertas);
	}
	else {

		cout << "-> Indique la Cilindrada: "; cin >> Cilindrada;
		while (Cilindrada <= 0) {
			cout << "Indique una Cilindrada valida\n";
			cin >> Cilindrada;
		}

		cout << "-> Indique la Potencia de la Moto: "; cin >> Potencia;
		while (Potencia <= 0) {
			cout << "Indique una Potencia valida\n";
			cin >> Potencia;
		}
		cargarVehiculo(Marca, Modelo, Año, Cilindrada, Potencia);
	}
	Linea();
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}

void Carga::cargarVehiculo(string Marca, string Modelo, int Año, float cilindrada, float potencia){

	moto->setMarca(Marca);
	moto->setModelo(Modelo);
	moto->setYear(Año);
	moto->setCilindrada(cilindrada);
	moto->setPotencia(potencia);
	mostrarVehiculo(0);
}

void Carga::cargarVehiculo(string Marca, string Modelo, int Año, float cilindrada, float potencia, int numeroPuertas){
	
	coche->setMarca(Marca);
	coche->setModelo(Modelo);
	coche->setYear(Año);
	coche->setCilindrada(cilindrada);
	coche->setPotencia(potencia);
	coche->setNumeroPuertas(numeroPuertas);
	mostrarVehiculo(1);
}

void Carga::mostrarVehiculo(bool indicador)
{
	string marca = "default", modelo = "default";
	int year = 0, numPuertas = 0;
	float cilindrada = 0, potencia = 0;
	if (indicador == 0) {

		marca = moto->getMarca();
		modelo = moto->getModelo();
		year = moto->getYear();
		cilindrada = moto->getCilindrada();
		potencia = moto->getPotencia();

	}
	else if (indicador == 1) {
		//(string Marca, string Modelo, int Año, float cilindrada, float potencia, int numeroPuertas) {
		marca = coche->getMarca();
		modelo = coche->getModelo();
		year = coche->getYear();
		cilindrada = coche->getCilindrada();
		potencia = coche->getPotencia();
		numPuertas = coche->getNumeroPuertas();

	}

	Linea();
	cout << "\nLos datos del Vehiculo que fueron cargados son los siguientes: \n";
	if (indicador == 0) {
		cout << "---->\t\t Moto  \t\t<----\n";
	}
	else {
		cout << "---->\t\t Coche \t\t<----\n";
	}
	cout << "* " << marca << ", " << modelo << " del " << year << endl;
	cout << "* Con una cilindrada de " << cilindrada << " | Una potencia de " << potencia;
	if (indicador == 1) {
		cout << " | La cantidad de puertas son " << numPuertas;
	}
	cout << endl;
}
