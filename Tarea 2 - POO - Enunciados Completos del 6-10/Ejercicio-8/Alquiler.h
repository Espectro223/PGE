// Alquiler.h //

#include <iostream>
#include <string>
#include "Pelicula.h"
using namespace std;

class Alquiler {
	private:
		// Variables: //
		Pelicula pelicula;
		int DuracionAlquiler; // En Dias

	public:
		// Constructores: //
		Alquiler(Pelicula pelicula, int DuracionAlquiler);

		// Setters de las Variables: //
		void setPelicula(Pelicula pelicula);
		void setDuracionAlquiler(int DuracionAlquiler);

		// Getters de las Variables: //
		Pelicula getPelicula();
		int getDuracionAlquiler();

		// Otros Metodos: //
		float calcularCostoAlquiler();
};