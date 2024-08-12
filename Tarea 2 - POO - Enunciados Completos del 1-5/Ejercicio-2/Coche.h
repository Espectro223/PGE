// Coche.h //

#include <iostream>
#include <string>
#include "Vehiculo.h"
using namespace std;

class Coche : public Vehiculo {
	private:
		// Variables: //
		int NumeroPuertas;
		float Cilindrada;
		float Potencia;

	public:
		// Constructores: //
		Coche();
		Coche(string Marca, string Modelo, int Year, int NumeroPuertas, float Cilindrada, float Potencia);

		// Setters de las Variables: //
		void setNumeroPuertas(int Puertas);
		void setCilindrada(float Cilindrada);
		void setPotencia(float Potencia);

		// Getters de las Variables: //
		int getNumeroPuertas();
		float getCilindrada();
		float getPotencia();
};
