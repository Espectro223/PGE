// Gato.h //

#include <iostream>
#include <string>
#include "Animal.h"
using namespace std;

class Gato : public Animal {
public:
	// Constructores: //
	Gato(string Nombre);

	// Otros Metodos: //
	void Maullar();
};
