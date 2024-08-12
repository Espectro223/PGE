// Animal.h //

#pragma once
#include <iostream>
#include <string>
using namespace std;

class Animal {
	private:
		string Nombre;
		bool siCome = 1; // 1 = si lo hace, 2 = no lo hace
		bool siDuerme = 1;

	public:
		// Constructores: //
		Animal();
		Animal(string Nombre);
		Animal(string Nombre, bool siCome, bool siDuerme);

		// Setters de las Variables: //
		void setNombre(string Nombre);
		void setsiCome(bool siCome);
		void setsiDuerme(bool siDuerme);

		// Getters de las Variables: //
		string getNombre();
		bool getsiCome();
		bool getsiDuerme();

		// Otros Metodos: //
		void Comer();
		void Dormir();
};
