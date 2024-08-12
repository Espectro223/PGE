// Funciones de Animal.h //

#include <iostream>
#include <string>
#include "Animal.h"
using namespace std;

Animal::Animal() {
	Nombre = "default";
}

Animal::Animal(string Nombre) {
	this->Nombre = Nombre;
}

Animal::Animal(string Nombre, bool siCome, bool siDuerme) {
	this->Nombre = Nombre;
	this->siCome = siCome;
	this->siDuerme = siDuerme;
}

void Animal::setNombre(string Nombre) {
	this->Nombre = Nombre;
}

void Animal::setsiCome(bool siCome) {
	this->siCome = siCome;
}

void Animal::setsiDuerme(bool siDuerme) {
	this->siDuerme = siDuerme;
}

string Animal::getNombre() {
	return Nombre;
}

bool Animal::getsiCome() {
	return siCome;
}

bool Animal::getsiDuerme() {
	return siDuerme;
}

void Animal::Comer() {
	if (siCome == 0) {
		cout << Nombre << " no come" << endl;
	}
	else {
		cout << Nombre << " come" << endl;
	}
}

void Animal::Dormir() {
	if (siDuerme == 0) {
		cout << Nombre << " no duerme" << endl;
	}
	else {
		cout << Nombre << " duerme" << endl;
	}
}