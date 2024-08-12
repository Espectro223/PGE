// Funciones de Alquiler.h //

#include <iostream>
#include <string>
#include "Alquiler.h"
using namespace std;

Alquiler::Alquiler(Pelicula pelicula, int DuracionAlquiler) {
	this->pelicula = pelicula;
	this->DuracionAlquiler = DuracionAlquiler;
}

void Alquiler::setPelicula(Pelicula pelicula) {
	this->pelicula = pelicula;
}

void Alquiler::setDuracionAlquiler(int DuracionAlquiler) {
	this->DuracionAlquiler = DuracionAlquiler;
}

Pelicula Alquiler::getPelicula() {
	return pelicula;
}

int Alquiler::getDuracionAlquiler() {
	return DuracionAlquiler;
}

float Alquiler::calcularCostoAlquiler() {
	float CostoTotal = 100;
	
	if (getDuracionAlquiler() > 7) {
		CostoTotal = CostoTotal * getDuracionAlquiler();
	}

	if (pelicula.getYear() < 2000) {
		CostoTotal = CostoTotal / 2;
	}

	return CostoTotal;
}