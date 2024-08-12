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
		Triangulo();
		Triangulo(float Altura, float Base, float L1, float L2, float L3);

		// Setters de las Variables: //
		void setAltura(float Altura);
		void setBase(float Base);
		void setL1(float L1);
		void setL2(float L1);
		void setL3(float L1);

		// Getters de las Variables: //
		float getAltura();
		float getBase();
		float getL1();
		float getL2();
		float getL3();


		// Otros Metodos: // 
		float sacarArea();
		float sacarPerimetro();
};