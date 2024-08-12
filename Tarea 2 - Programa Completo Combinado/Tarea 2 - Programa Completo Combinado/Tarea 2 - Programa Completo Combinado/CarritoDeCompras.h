// CarritoDeCompras.h //

#include <iostream>
#include <string>
#include "Producto.h"
using namespace std;

class CarritoDeCompras {
	private:
		// Variables: //
		int Size = 0;
		Producto* carro = new Producto[Size];

	public:
		// Constructores: //
		CarritoDeCompras(int Size);

		// Setters de las Variables: //
		void setSize(int Size);

		// Getters de las Variables: //
		int getSize();
		Producto* getCarro();

		// Otros Metodos: //
		bool pushProducto(Producto producto);
};
