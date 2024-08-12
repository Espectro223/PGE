// CuentaCorriente.h //

#include <iostream>
#include <string>
#include "CuentaBancaria.h"
using namespace std;

class CuentaCorriente : public CuentaBancaria {
	private:
		// Variables: //
		float Interes = 5;

	public:
		// Constructores: //
		CuentaCorriente(float Saldo, string Password);

		// Getters de las Variables: //
		float getInteres();

		// Otros Metodos:: //
		void cobrarComision();
};