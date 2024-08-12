#include <iostream>
#include <string>
#include "Juego.h"
using namespace std;

Juego::Juego(string NombrePJ) {
	this->NombrePJ = NombrePJ;
	cout << "Se abre la Veterinaria!!!" << endl;
	Separacion();
	while (Vidas != 0) {
		bool tipoAnimal = rand() % 2; // Para elegir entre un Perro o Gato. false = Gato, true = Perro
		bool enfermo = rand() % 2;

		cout << "Vidas: " << Vidas << " | Puntaje: " << Puntaje << " | Animales Curados: " << AnimalesCurados << " | Dinero Obtenido: " << DineroObtenido << endl;
		cout << NombrePJ << " | ";

		if (tipoAnimal == false) {
			Gato* gato = new Gato("Garfield");
			cout << " Gato" << endl;
			if (enfermo == true) {
				ponerEnfermo(gato);
			}
			cout << "Actualmente: " << endl;
			cout << "Duerme: " << gato->getsiDuerme() << " | Come: " << gato->getsiCome() << endl;
			gato->Maullar();
		}
		else {
			Perro* perro = new Perro("Oddy");
			cout << " Perro" << endl;
			if (enfermo == true) {
				ponerEnfermo(perro);
			}
			cout << "Actualmente: " << endl;
			cout << "Duerme: " << perro->getsiDuerme() << " | Come: " << perro->getsiCome() << endl;
			perro->Ladrar();
		}

		bool Seleccion;
		Separacion();
		cout << "Esta enfermo (1 = si o 0 = no)?" << endl;
		Separacion();
		cin >> Seleccion;
		Separacion();
		
		switch (Seleccion) {
			case true:
				if (enfermo == true) {
					cout << "Correcto. Siguiente Paciente!" << endl;
					Puntaje = Puntaje + 100;
					AnimalesCurados += 1;
					DineroObtenido += 100;
					Separacion();
				}
				else {
					cout << "Incorrecto. :(" << endl;
					Vidas = Vidas - 1;
				}
				break;

			case false:
				if (enfermo == false) {
					cout << "Correcto. Siguiente Paciente!" << endl;
					Puntaje = Puntaje + 100;
					AnimalesCurados += 1;
					DineroObtenido += 100;
				}
				else {
					cout << "Incorrecto. :(" << endl;
					Vidas = Vidas - 1;
				}
				break;

			default:
				cout << "Saltando al siguiente Paciente. No me hago responsable de este" << endl;
				break;
		}
		Separacion();
	}
}

void Juego::setVidas(int Vidas) {
	this->Vidas = Vidas;
}

void Juego::setPuntaje(int Puntaje) {
	this->Puntaje = Puntaje;
}

void Juego::setAnimalesCurados(int AnimalesCurados) {
	this->AnimalesCurados = AnimalesCurados;
}

void Juego::setDineroObtenido(float DineroObtenido) {
	this->DineroObtenido = DineroObtenido;
}

void Juego::setNombrePJ(string NombrePJ) {
	this->NombrePJ = NombrePJ;
}

int Juego::getVidas() {
	return Vidas;
}

int Juego::getPuntaje() {
	return Puntaje;
}

int Juego::getAnimalesCurados() {
	return AnimalesCurados;
}

float Juego::getDineroObtenido() {
	return DineroObtenido;
}

string Juego::getNombrePJ() {
	return NombrePJ;
}

void Juego::ponerEnfermo(Perro* perro) {
	int cuantosMalesTiene = rand() % 3;
	if (cuantosMalesTiene == 2) {
		perro->setsiCome(false);
		perro->setsiDuerme(false);
	}
	else if (cuantosMalesTiene == 1) {
		int decidirCualDeLosDos = rand() % 2;
		if (decidirCualDeLosDos == 0) {
			perro->setsiCome(false);
		}
		else {
			perro->setsiDuerme(false);
		}
	}
	return;
}

void Juego::ponerEnfermo(Gato* gato) {
	int cuantosMalesTiene = rand() % 3;
	if (cuantosMalesTiene == 2) {
		gato->setsiCome(false);
		gato->setsiDuerme(false);
	}
	else if (cuantosMalesTiene == 1) {
		int decidirCualDeLosDos = rand() % 2;
		if (decidirCualDeLosDos == 0) {
			gato->setsiCome(false);
		}
		else {
			gato->setsiDuerme(false);
		}
	}
	return;
}