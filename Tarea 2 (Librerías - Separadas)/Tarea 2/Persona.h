// Persona.h //

#include <iostream>
#include <string>
using namespace std;

class Persona { 
	private:
		// Variables: //
		string Nombre;
		string Apellido;
		int Edad;
		bool Genero; // 1 = Masculino, 0 = Femenino
		double DNI;

	public:
		// Constructores: //
		Persona();
		Persona(string Nombre, string Apellido, int Edad, bool Genero, double DNI);

		// Setters de las Variables: //
		void setNombre(string Nombre);
		void setApellido(string Apellido);
		void setEdad(int Edad);
		void setGenero(bool Genero);
		void setDNI(double DNI);

		// Getters de las Variables: //
		string getNombre();
		string getApellido();
		int getEdad();
		bool getGenero();
		double getDNI();
};