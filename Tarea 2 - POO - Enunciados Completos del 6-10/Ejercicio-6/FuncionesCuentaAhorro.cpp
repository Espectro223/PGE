// Funciones de CuentaAhorro.h //

#include <iostream>
#include <string>
#include "CuentaAhorro.h"
using namespace std;

CuentaAhorro::CuentaAhorro(float Saldo, string Password) {
	this->setSaldo(Saldo);
	this->setPassword(Password);
	this->setNumero_Cuenta();
}

float CuentaAhorro::getInteres() {
	return Interes;
}

void CuentaAhorro::cobrarComision() {
	float cobrarEsteValor = 0;
	float tempSaldo = this->getSaldo();
	cobrarEsteValor = ((Interes * tempSaldo) / 100);

	this->setSaldo((tempSaldo - cobrarEsteValor));
}