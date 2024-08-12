#include "Carga.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Carga::Carga() {

	Linea();
	int numCuenta;
	string password;
	float saldo,intereses;

	cout << "\t DATOS DE LA CUENTA DE AHORRO \t\n\n";
	intereses = ahorro->getInteres();
	numCuenta = ahorro->getNumeroCuenta();
	password = ahorro->getPassword();
	saldo = ahorro->getSaldo();
	cout << "La cuenta de ahorro numero " << numCuenta << " de contraseña " << password << endl;
	cout << "tiene un saldo de " << saldo << " pesos ARG\n";
	ahorro->cobrarComision();
	saldo = ahorro->getSaldo();
	cout << "Con un interes del " << intereses << "%, la comision seria de " << saldo << endl << endl;
	Linea();

	cout << "\t DATOS DE LA CUENTA CORRIENTE \t\n\n";
	intereses = corriente->getInteres();
	numCuenta = corriente->getNumeroCuenta();
	password = corriente->getPassword();
	saldo = corriente->getSaldo();
	cout << "La cuenta corriente numero " << numCuenta << " de contraseña " << password << endl;
	cout << "tiene un saldo de " << saldo << " pesos ARG\n";
	corriente->cobrarComision();
	saldo = corriente->getSaldo();
	cout << "Con un interes del " << intereses << "%, la comision seria de " << saldo << endl << endl;
	Linea();
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}