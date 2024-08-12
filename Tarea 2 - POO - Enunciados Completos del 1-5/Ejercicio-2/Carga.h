#include <iostream>
#include <string>
#include "Moto.h"
#include "Coche.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();
	void cargarVehiculo(string Marca, string Modelo, int Año, float cilindrada, float potencia);
	void cargarVehiculo(string Marca, string Modelo, int Año, float cilindrada, float potencia, int numeroPuertas);
	void mostrarVehiculo(bool indicador);

private:
	Moto* moto = new Moto();
	Coche* coche = new Coche();
};