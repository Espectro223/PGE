// Moto.h //

#include <iostream>
#include <string>
#include "Vehiculo.h"
using namespace std;

class Moto : public Vehiculo {
	private:
		// Variables: //
		float Cilindrada;
		float Potencia;

	public:
		// Constructores: //
		Moto(string Marca, string Modelo, int Year, float Cilindrada, float Potencia);

		// Setters de las Variables: //
		void setCilindrada(float Cilindrada);
		void setPotencia(float Potencia);

		// Getters de las Variables: //
		float getCilindrada();
		float getPotencia();
};

