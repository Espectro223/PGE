#include "Carga.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Carga::Carga() {

	Linea();
	
	int diasAlquiler = alquiler->getDuracionAlquiler(), Year = pelicula->getYear();
	string titulo = pelicula->getTitulo(), director = pelicula->getDirector(), genero = pelicula->getGenero();

	cout << "\t DATOS DEL RECIBO DE LA RENTA DE LA PELICULA \t\n\n";
	cout << "Ficha Tecnica del producto: " << titulo << " | " << director << " | " << genero  << " | " << Year << endl;
	cout << "Dias de alquiler: " << diasAlquiler << "\n\n";

	float costo = alquiler->calcularCostoAlquiler();
	cout << "Costo Final para el alquiler: " << costo << " $ARG" << endl << endl;
	Linea();
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}