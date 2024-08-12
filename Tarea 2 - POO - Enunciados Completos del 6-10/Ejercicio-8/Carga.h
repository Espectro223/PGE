#pragma once
#include <iostream>
#include <string>
#include "Alquiler.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();

private:
	Pelicula* pelicula = new Pelicula("SpiderMan", "Sam Raimi", "Accion-SuperHeroes", 2007);
	Alquiler* alquiler = new Alquiler(*pelicula,500);
};