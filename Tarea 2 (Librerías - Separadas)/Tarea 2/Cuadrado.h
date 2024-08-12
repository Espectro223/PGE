// Cuadrado.h //

#include <iostream>
#include <string>
#include "FiguraGeometrica.h"
using namespace std;

class Cuadrado : public FiguraGeometrica {
	private:
		float L1, L2; // Lados del Cuadrado

	public:
		// Constructores: //
		Cuadrado(float L1, float L2);

		// Setters de las Variables: //
		void setL1(float L1);
		void setL2(float L2);

		// Getters de las Variables: //
		float getL1();
		float getL2();

		// Otros Metodos: // 
		float sacarArea();
		float sacarPerimetro();
};