// Estudiante.h //

#include <iostream>
#include <string>
using namespace std;

class Estudiante {
	private:
		// Variables: //
		string Nombre;
		string Apellido;
		int Edad;
		int Nota;

	public:
		// Constructores: //
		Estudiante();
		Estudiante(string Nombre, string Apellido, int Edad, int Nota);

		// Setters de las Variables: //
		void setNombre(string Nombre);
		void setApellido(string Apellido);
		void setEdad(int Edad);
		void setNota(int Nota);

		// Getters de las Variables: //
		string getNombre();
		string getApellido();
		int getEdad();
		int getNota();
};