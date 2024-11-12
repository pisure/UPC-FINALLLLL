#pragma once
#ifndef PASAJERO_H
#define PASAJERO_H

#include <iostream>
#include <string>
using namespace std;

class Pasajero {
private:
    string nombre;
    int edad;
    string dni;
public:
    Pasajero(string nombre, int edad, string dni) : nombre(nombre), edad(edad), dni(dni) {}

    void mostrar() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << ", DNI: " << dni << endl;
    }
};

#endif
