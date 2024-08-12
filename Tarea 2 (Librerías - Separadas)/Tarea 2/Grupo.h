// Grupo.h //

#include <iostream>
#include <string>
#include "Estudiante.h"
using namespace std;

class Grupo {
	private:
		// Variables: //
		int Size = 0;
		Estudiante* Estudiantes = new Estudiante[Size];

	public:
		// Constructores: //
		Grupo(int Size);

		// Setters de las Variables: //
		void setSize(int Size);

		// Getters de las Variables: //
		int getSize();
		Estudiante* getEstudiantes();
		int sacarPromedioNotas();

		// Otros Metodos: //
		bool pushEstudiante(Estudiante estudiante);
};