// Juego.h //

#include <iostream>
#include <string>
#include "Perro.h"
#include "Gato.h"
#include "Veterinario.h"
#include "Separacion.h"
using namespace std;

class Juego {
	private:
		string NombrePJ;
		int Vidas = 3;
		int Puntaje = 0;
		int AnimalesCurados = 0;
		float DineroObtenido = 0;

	public:
		// Constructores: //
		Juego(string NombrePJ);

		// Setters de las Variables: //
		void setVidas(int Vidas);
		void setPuntaje(int Puntaje);
		void setAnimalesCurados(int AnimalesCurados);
		void setDineroObtenido(float DineroObtenido);
		void setNombrePJ(string NombrePJ);

		// Getters de las Variables: //
		int getVidas();
		int getPuntaje();
		int getAnimalesCurados();
		float getDineroObtenido();
		string getNombrePJ();

		// Otros Metodos: //
		void ponerEnfermo(Perro* perro);
		void ponerEnfermo(Gato* gato);
};