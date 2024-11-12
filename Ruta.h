#pragma once
#ifndef RUTA_H
#define RUTA_H

#include <iostream>
#include <string>
#include <vector>
#include "Pasaje.h" // Asegúrate de incluir la clase Pasaje correctamente

using namespace std;

class Ruta {
private:
    string nombre;
    vector<Pasaje*> pasajes; // Lista de punteros a objetos de la clase Pasaje

public:
    Ruta(string nombre) : nombre(nombre) {}

    void agregarPasaje(Pasaje* pasaje) {
        pasajes.push_back(pasaje);
    }

    void mostrar() {
        cout << "Ruta: " << nombre << endl;
        if (!pasajes.empty()) {
            cout << "Pasajes:" << endl;
            for (auto& pasaje : pasajes) {
                cout << "  Origen: " << pasaje->getOrigen()
                    << ", Destino: " << pasaje->getDestino()
                    << ", Hora: " << pasaje->getHoraCompra() << endl;
            }
        }
        else {
            cout << "  No hay pasajes asignados." << endl;
        }
    }

    string getNombre() const {
        return nombre;
    }

    vector<Pasaje*> getPasajes() const {
        return pasajes;
    }
};

class NodoRuta {
public:
    Ruta* ruta;
    NodoRuta* siguiente;

    NodoRuta(Ruta* ruta) : ruta(ruta), siguiente(nullptr) {}
};

class ListaRutas {
private:
    NodoRuta* cabeza;

public:
    ListaRutas() : cabeza(nullptr) {}

    void insertar(Ruta* ruta) {
        NodoRuta* nuevo = new NodoRuta(ruta);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    Ruta* buscar(string nombreRuta) {
        NodoRuta* actual = cabeza;
        while (actual) {
            if (actual->ruta->getNombre() == nombreRuta) {
                return actual->ruta;
            }
            actual = actual->siguiente;
        }
        return nullptr;
    }

    bool eliminar(string nombreRuta) {
        NodoRuta* actual = cabeza;
        NodoRuta* previo = nullptr;
        while (actual) {
            if (actual->ruta->getNombre() == nombreRuta) {
                if (previo) {
                    previo->siguiente = actual->siguiente;
                }
                else {
                    cabeza = actual->siguiente;
                }
                delete actual->ruta; // Liberar memoria de la ruta
                delete actual;       // Liberar memoria del nodo
                return true;
            }
            previo = actual;
            actual = actual->siguiente;
        }
        return false;
    }
};

#endif
