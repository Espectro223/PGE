// Funciones de CuentaCorriente.h //

#include <iostream>
#include <string>
#include "CuentaCorriente.h"
using namespace std;

CuentaCorriente::CuentaCorriente(float Saldo, string Password) {
	this->setSaldo(Saldo);
	this->setPassword(Password);
	this->setNumero_Cuenta();
}

float CuentaCorriente::getInteres() {
	return Interes;
}

void CuentaCorriente::cobrarComision() {
	float cobrarEsteValor = 0;
	float tempSaldo = this->getSaldo();
	cobrarEsteValor = ((Interes * tempSaldo) / 100);

	this->setSaldo((tempSaldo - cobrarEsteValor));
}