// Menu.h //

#include <iostream>
#include <string>
#include "Juego.h"
#include "Tienda.h"
#include "Separacion.h"
using namespace std;

class Menu {
	private:
		string Nombre;
		Juego* juego;
		Tienda* tienda;
		CuentaCorriente* cuenta;
		int puntajeTotal = 0;

	public:
		// Constructores: //
		Menu();
		Menu(string Nombre);

		// Setters de las Variables: //
		void setNombre(string Nombre);

		// Getters de las Variables: //
		string getNombre();

		// Otros Metodos: //
		void menuPrincipal();
		void iniciarJuego();
		void irTienda();
};