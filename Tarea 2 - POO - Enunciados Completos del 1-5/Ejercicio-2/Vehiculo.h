// Vehiculo.h //
#ifndef VEHICULO_H
#define VEHICULO_H

#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
	private:
		// Variables: //
		string Marca;
		string Modelo;
		int Year;

	public:
		// Constructores: //
		Vehiculo();
		Vehiculo(string Marca, string Modelo, int Year);

		// Setters de las Variables: //
		void setMarca(string Marca);
		void setModelo(string Modelo);
		void setYear(int Year);

		// Getters de las Variables: //
		string getMarca();
		string getModelo();
		int getYear();
}; 

#endif // VEHICULO_H
