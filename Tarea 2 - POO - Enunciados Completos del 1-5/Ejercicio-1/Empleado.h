// Persona.h //

#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

class Empleado : public Persona {
	private:
		float Salario;
		string Cargo;

	public:
		// Constructores: //
		Empleado();
		Empleado(string Nombre, string Apellido, int Edad, bool Genero, double DNI, float Salario, string Cargo);

		// Setters de las Variables: //
		void setSalario(float Salario);
		void setCargo(string Cargo);

		// Getters de las Variables: //
		float getSalario();
		string getCargo();
};