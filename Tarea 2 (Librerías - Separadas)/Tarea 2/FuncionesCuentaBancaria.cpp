// Funciones de CuentaBancaria.h //

#include <iostream>
#include <string>
#include "CuentaBancaria.h"
using namespace std;

CuentaBancaria::CuentaBancaria() {
	Saldo = 0;
	Numero_Cuenta = rand() % 100000;
	Password = "Password";
}

CuentaBancaria::CuentaBancaria(float Saldo, string Password) {
	this->Saldo = Saldo;
	this->Numero_Cuenta = rand() % 100000;
	this->Password = Password;
}

void CuentaBancaria::setSaldo(float Saldo) {
	this->Saldo = Saldo;
}

void CuentaBancaria::setNumero_Cuenta() {
	Numero_Cuenta = rand() % 100000;
}

void CuentaBancaria::setPassword(string Password) {
	this->Password = Password;
}

float CuentaBancaria::getSaldo() {
	return Saldo;
}

int CuentaBancaria::getNumeroCuenta() {
	return Numero_Cuenta;
}

string CuentaBancaria::getPassword() {
	return Password;
}