#pragma once
#include <iostream>
#include <string>
#include "CuentaCorriente.h"
#include "CuentaAhorro.h"
using namespace std;

class Carga {
public:
	Carga();
	void Linea();

private:
	CuentaCorriente* corriente = new CuentaCorriente(6000,"admin");
	CuentaAhorro* ahorro = new CuentaAhorro(5000,"1234");
};