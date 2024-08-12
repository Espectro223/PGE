// CuentaBancaria.h //

#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
	// Variables: //
	float Saldo;
	int Numero_Cuenta; // Numero de Cuenta es RANDOM
	string Password;

public:
	// Constructores: //
	CuentaBancaria();
	CuentaBancaria(float Saldo, string Password);

	// Setters de las Variables: //
	void setSaldo(float Saldo);
	void setNumero_Cuenta();
	void setPassword(string Password);

	// Getters de las Variables: //
	float getSaldo();
	int getNumeroCuenta();
	string getPassword();
};