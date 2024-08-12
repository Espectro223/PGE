#pragma once
#include <iostream>
#include <string>
#include "Animal.h"
#include "Veterinario.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();

private:
	Animal* animal = new Animal("Firulais",1,1);
	Veterinario* veterinario = new Veterinario();
};