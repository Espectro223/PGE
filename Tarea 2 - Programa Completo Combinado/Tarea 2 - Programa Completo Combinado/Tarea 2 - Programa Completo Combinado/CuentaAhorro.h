// CuentaAhorro.h //

#include <iostream>
#include <string>
#include "CuentaBancaria.h"
using namespace std;

class CuentaAhorro : public CuentaBancaria {
	private:
		// Variables: //
		float Interes = 2.5;

	public:
		// Constructores: //
		CuentaAhorro(float Saldo, string Password);

		// Getters de las Variables: //
		float getInteres();

		// Otros Metodos:: //
		void cobrarComision();
};