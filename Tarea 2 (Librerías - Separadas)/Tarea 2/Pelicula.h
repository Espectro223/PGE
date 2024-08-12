// Pelicula.h //

#include <iostream>
#include <string>
using namespace std;

class Pelicula {
	private:
		// Variables: //
		string Titulo, Director, Genero;
		int Year;

	public:
		// Constructores: //
		Pelicula();
		Pelicula(string Titulo, string Director, string Genero, int Year);

		// Setters de las Variables: //
		void setTitulo(string Titulo);
		void setDirector(string Director);
		void setGenero(string Genero);
		void setYear(int Year);

		// Getters de las Variables: //
		string getTitulo();
		string getDirector();
		string getGenero();
		int getYear();
};