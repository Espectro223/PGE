// Funciones de Pelicula.h //

#include <iostream>
#include <string>
#include "Pelicula.h"
using namespace std;

Pelicula::Pelicula() {
	this->Titulo = "default";
	this->Director = "default";
	this->Genero = "default";
	this->Year = 0;
}

Pelicula::Pelicula(string Titulo, string Director, string Genero, int Year) {
	this->Titulo = Titulo;
	this->Director = Director;
	this->Genero = Genero;
	this->Year = Year;
}

void Pelicula::setTitulo(string Titulo) {
	this->Titulo = Titulo;
}

void Pelicula::setDirector(string Director) {
	this->Director = Director;
}

void Pelicula::setGenero(string Genero) {
	this->Genero = Genero;
}

void Pelicula::setYear(int Year) {
	this->Year = Year;
}

string Pelicula::getTitulo() {
	return Titulo;
}

string Pelicula::getDirector() {
	return Director;
}

string Pelicula::getGenero() {
	return Genero;
}

int Pelicula::getYear() {
	return Year;
}