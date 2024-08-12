#include <iostream>
#include "Carga.h"
using namespace std;

int main()
{
    cout << "Display de Empleados:" << endl;
    Carga* carga = new Carga();
    carga->mostrarEmpleado();
    return 0;
}

