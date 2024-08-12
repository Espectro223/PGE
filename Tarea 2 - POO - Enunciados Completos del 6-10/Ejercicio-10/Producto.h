// Producto.h //

#include <iostream>
#include <string>
using namespace std;

class Producto {
	private:
		// Variables: //
		string Nombre;
		float Precio;
		int Cantidad;

	public:
		// Constructores: //
		Producto();
		Producto(string Nombre, float Precio, int Cantidad);

		// Setters de las Variables: //
		void setNombre(string Nombre);
		void setPrecio(float Precio);
		void setCantidad(int Cantidad);

		// Getters de las Variables: //
		string getNombre();
		float getPrecio();
		int getCantidad();
};