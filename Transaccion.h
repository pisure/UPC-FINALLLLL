#pragma once
#ifndef TRANSACCION_H
#define TRANSACCION_H

#include <iostream>
#include <string>
using namespace std;

class Transaccion {
public:
    string codigoTransaccion;

    Transaccion(string codigo) : codigoTransaccion(codigo) {}

    void mostrar() {
        cout << "Transaccion: " << codigoTransaccion << endl;
    }
};

class NodoTransaccion {
public:
    Transaccion* transaccion;
    NodoTransaccion* siguiente;

    NodoTransaccion(Transaccion* transaccion) : transaccion(transaccion), siguiente(nullptr) {}
};

class PilaHistorial {
private:
    NodoTransaccion* tope;

public:
    PilaHistorial() : tope(nullptr) {}

    void push(Transaccion* transaccion) {
        NodoTransaccion* nuevo = new NodoTransaccion(transaccion);
        nuevo->siguiente = tope;
        tope = nuevo;
    }

    Transaccion* pop() {
        if (!tope) return nullptr;
        Transaccion* transaccion = tope->transaccion;
        NodoTransaccion* temp = tope;
        tope = tope->siguiente;
        delete temp;
        return transaccion;
    }

    void mostrarHistorial() {
        NodoTransaccion* actual = tope;
        while (actual) {
            actual->transaccion->mostrar();
            actual = actual->siguiente;
        }
    }
};

#endif
