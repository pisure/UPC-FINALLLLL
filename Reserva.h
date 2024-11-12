#pragma once
#ifndef RESERVA_H
#define RESERVA_H

#include <iostream>
#include <string>
using namespace std;

class Reserva {
public:
    string codigoReserva;

    Reserva(string codigo) : codigoReserva(codigo) {}

    void mostrar() {
        cout << "Reserva: " << codigoReserva << endl;
    }
};

class NodoReserva {
public:
    Reserva* reserva;
    NodoReserva* siguiente;

    NodoReserva(Reserva* reserva) : reserva(reserva), siguiente(nullptr) {}
};

class ColaReservas {
private:
    NodoReserva* frente;
    NodoReserva* final;

public:
    ColaReservas() : frente(nullptr), final(nullptr) {}

    void enque(Reserva* reserva) {
        NodoReserva* nuevo = new NodoReserva(reserva);
        if (final) {
            final->siguiente = nuevo;
        }
        final = nuevo;
        if (!frente) {
            frente = nuevo;
        }
    }

    Reserva* deque() {
        if (!frente) return nullptr;
        Reserva* reserva = frente->reserva;
        NodoReserva* temp = frente;
        frente = frente->siguiente;
        if (!frente) final = nullptr;
        delete temp;
        return reserva;
    }

    void mostrarReservas() {
        NodoReserva* actual = frente;
        while (actual) {
            actual->reserva->mostrar();
            actual = actual->siguiente;
        }
    }
};

#endif
