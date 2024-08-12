// Funciones de Veterinario.h //

#include <iostream>
#include <string>
#include "Veterinario.h"
using namespace std;

Veterinario::Veterinario() 
{
}

void Veterinario::examinarAnimal(Animal animal) {
	if (animal.getsiCome() == false || animal.getsiDuerme() == false) {
		cout << "Esta enfermo el animal " << animal.getNombre() << endl;
	}
	else {
		cout << "No esta enfermo el animal " << animal.getNombre() << endl;
	}
}