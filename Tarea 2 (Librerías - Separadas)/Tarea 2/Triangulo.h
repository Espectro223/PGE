// Triangulo.h //

#include <iostream>
#include <string>
#include "FiguraGeometrica.h"
using namespace std;

class Triangulo : public FiguraGeometrica {
	private:
		float Altura;
		float Base;
		float L1, L2, L3; // Lados del Triangulo

	public:
		// Constructores: //
		Triangulo(float Altura, float Base, float L1, float L2, float L3);

		// Setters de las Variables: //
		void setAltura(float Altura);
		void setBase(float Base);

		// Getters de las Variables: //
		float getAltura();
		float getBase();

		// Otros Metodos: // 
		float sacarArea();
		float sacarPerimetro();
};