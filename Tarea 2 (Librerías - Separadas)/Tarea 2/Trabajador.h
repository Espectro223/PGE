// Trabajador.h //

#include <iostream>
#include <string>
#include "Persona.h"
using namespace std;

class Trabajador {
private:
	// Variables: //
	Persona* Individuo;
	string Cargo; 
	float Salario; // Que tan largo es el String define el Salario

public:
	// Constructores: //
	Trabajador(Persona Individuo, string Cargo);

	// Setters de las Variables: //
	void setIndividuo(Persona Individuo);
	void setCargo(string Cargo);

	// Getters de las Variables: //
	Persona* getIndividuo();
	string getCargo();
	float getSalario();

	// Otros Metodos: //
	void updateSalario(); // Se llama cada vez que se cambia el Cargo o se setea
};