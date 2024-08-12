// Tienda.h //

#include <iostream>
#include <string>
#include "CuentaCorriente.h"
#include "Producto.h"
#include "Separacion.h"
using namespace std;

class Tienda {
	private:
		CuentaCorriente* cuenta;
		int puntajeObtenido;
		Producto* producto;

	public:
		// Constructores: //
		Tienda(CuentaCorriente* cuenta);

		// Setters de las Variables: //
		void setCuenta(CuentaCorriente* cuenta);
		void setpuntajeObtenido(int puntajeObtenido);

		// Getters de las Variables: //
		CuentaCorriente* getCuenta();
		int getpuntajeObtenido();

		// Otros Metodos: //
		void comprarCosas();
};