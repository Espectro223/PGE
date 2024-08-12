// Circulo.h //

#include <iostream>
#include <string>
#include "FiguraGeometrica.h"
using namespace std;

class Circulo : public FiguraGeometrica {
	private:
		float Diametro;

	public:
		// Constructores: //
		Circulo();

		Circulo(float Diametro);

		// Setters de las Variables: //
		void setDiametro(float Diametro);

		// Getters de las Variables: //
		float getDiametro();

		// Otros Metodos: // 
		float sacarArea();
		float sacarPerimetro();
};
