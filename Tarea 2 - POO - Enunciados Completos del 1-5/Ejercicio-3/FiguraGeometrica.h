// FiguraGeometrica.h //
#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H
#include <iostream>
#include <string>
using namespace std;

class FiguraGeometrica {
	private:
		float Area;
		float Perimetro;

	public:
		// Constructores: //
		FiguraGeometrica();
		FiguraGeometrica(float Area, float Perimetro);

		// Setters de las Variables: //
		void setArea(float Area);
		void setPerimetro(float Perimetro);

		// Getters de las Variables: //
		float getArea();
		float getPerimetro();
};

#endif // FIGURAGEOMETRICA_H