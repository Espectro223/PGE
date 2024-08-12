// Perro.h //

#include <iostream>
#include <string>
#include "Animal.h"
using namespace std;

class Perro : public Animal {
	public:
		// Constructores: //
		Perro(string Nombre);

		// Otros Metodos: //
		void Ladrar();
};
