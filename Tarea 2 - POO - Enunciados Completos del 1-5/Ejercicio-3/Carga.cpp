#include "Carga.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Carga::Carga() {

	float diametro, l1, l2, l3, altura, base;
	int indicador;
	bool bucle = true;
	do {
		Linea();
		cout << "-> Primero, indique que tipo de figura geometrica va a cargar a continuacion: \n";
		cout << "0 - Circulo\n";
		cout << "1 - Cuadrado\n";
		cout << "2 - Triangulo\n";
		cout << "3 - Salir\n";
		cout << "--> "; cin >> indicador;

		switch (indicador) {

		case 0:
			cout << "Indique el diametro del circulo: "; 
			cin >> diametro;
			while (diametro <= 0) {
				cout << "Indique un diametro valido: "; 
				cin >> diametro;
			}

			cargarCirculo(diametro);
			mostrarCirculo();
			break;

		case 1:
			cout << "\nCargue los lados del cuadrado: ";

			cin.clear();
			cout << "\n* Lado 1: "; cin >> l1;
			while (l1 <= 0) {
				cout << "\n* Lado 1: "; cin >> l1;
			}

			cin.clear();
			cout << "\n* Lado 2: "; cin >> l2;
			while (l2 <= 0) {
				cout << "\n* Lado 2: "; cin >> l2;
			}

			cargarCuadrado(l1, l2);
			mostrarCuadrado();
			break;

		case 2:
			cout << "\nIngrese los datos del triangulo: ";

			cout << "\n* Lado 1: "; cin >> l1;
			while (l1 <= 0) {
				cout << "\n* Lado 1: "; cin >> l1;
			}

			cout << "\n* Lado 2: "; cin >> l2;
			while (l2 <= 0) {
				cout << "\n* Lado 2: "; cin >> l2;
			}

			cout << "\n* Lado 3: "; cin >> l3;
			while (l3 <= 0) {
				cout << "\n* Lado 3: "; cin >> l3;
			}

			cout << "\n* Base: "; cin >> base;
			while (base <= 0) {
				cout << "\n* Base: "; cin >> base;
			}

			cout << "\n* Altura: "; cin >> altura;
			while (altura <= 0) {
				cout << "\n* Altura: "; cin >> altura;
			}

			cargarTriangulo(altura, base, l1, l2, l3);
			mostrarTriangulo();
			break;

		case 3:
			bucle = false;
			cout << "Saliendo del programa...\n";
			break;

		default:
			cout << "La opcion indicada no esta disponible. Eliga una de las validas\n";
			break;
		}

	} while (bucle);
	Linea();
}

void Carga::Linea() {

	for (int x = 0; x != 50; x++) {
		cout << "-";
	}
	cout << "" << endl;
}

void Carga::cargarCuadrado(float L1, float L2){

	cuadrado->setL1(L1);
	cuadrado->setL2(L2);
}

void Carga::cargarCirculo(float diametro){

	circulo->setDiametro(diametro);
}

void Carga::cargarTriangulo(float Altura, float Base, float L1, float L2, float L3){

	triangulo->setL1(L1);
	triangulo->setL2(L2);
	triangulo->setL3(L3);
	triangulo->setAltura(Altura);
	triangulo->setBase(Base);
}

void Carga::mostrarCuadrado(){

	float l1 = cuadrado->getL1(), l2 = cuadrado->getL2();
	float area = cuadrado->sacarArea(), perimetro = cuadrado->sacarPerimetro();
	Linea();
	cout << "\nLos lados del cuadrado fueron : " << l1 << " , " << l2 << endl;
	cout << "El area del cuadrado es " << area << " y su perimetro es " << perimetro << endl;
	Linea();
}

void Carga::mostrarCirculo(){

	float diametro = circulo->getDiametro(), area = circulo->sacarArea(), perimetro = circulo->sacarPerimetro();
	Linea();
	cout << "\nEl diametro del circulo cargado es: " << diametro << " con un area de " << area << " y un perimetro de: " << perimetro << endl;
	Linea();
}

void Carga::mostrarTriangulo(){

	float l1 = triangulo->getL1(), l2 = triangulo->getL2(), l3 = triangulo->getL3();
	float altura = triangulo->getAltura(), base = triangulo->getBase();
	float perimetro = triangulo->sacarPerimetro(), area = triangulo->sacarArea();

	Linea();
	cout << "\nLos lados del triangulo que fueron son: " << l1 << " , " << l2 << " , " << l3 << endl;
	cout << "Su altura es " << altura << " y su base es " << base << endl;
	cout << "Por lo tanto, su perimetro es " << perimetro << " y su area es " << area << endl;
	Linea();
}
