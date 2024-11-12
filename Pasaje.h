#pragma once
#ifndef PASAJE_H
#define PASAJE_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Pasaje {
private:
    string codigo;       // Código único del pasaje
    string origen;       // Origen del pasaje
    string destino;      // Destino del pasaje
    string horaCompra;   // Hora establecida para el pasaje

public:
    // Constructor
    Pasaje(string codigo, string origen, string destino, string horaCompra)
        : codigo(codigo), origen(origen), destino(destino), horaCompra(horaCompra) {
    }

    // Métodos getter
    string getCodigo() const {
        return codigo;
    }

    string getOrigen() const {
        return origen;
    }

    string getDestino() const {
        return destino;
    }

    string getHoraCompra() const {
        return horaCompra;
    }

    // Método para mostrar la información del pasaje
    void mostrar() const {
        cout << "Código: " << codigo
            << ", Origen: " << origen
            << ", Destino: " << destino
            << ", Hora: " << horaCompra << endl;
    }

    // Método estático para cargar pasajes desde archivos
    static vector<Pasaje*> cargarDesdeArchivos(const string& archivoOrigen,
        const string& archivoDestino,
        const string& archivoHora) {
        vector<Pasaje*> pasajes;
        ifstream archivoO(archivoOrigen), archivoD(archivoDestino), archivoH(archivoHora);

        if (!archivoO.is_open() || !archivoD.is_open() || !archivoH.is_open()) {
            cerr << "Error al abrir los archivos." << endl;
            return pasajes;
        }

        string origen, destino, hora;
        int contador = 1; // Para generar códigos únicos

        while (getline(archivoO, origen) && getline(archivoD, destino) && getline(archivoH, hora)) {
            string codigo = "P" + to_string(contador++);
            Pasaje* pasaje = new Pasaje(codigo, origen, destino, hora);
            pasajes.push_back(pasaje);
        }

        archivoO.close();
        archivoD.close();
        archivoH.close();

        return pasajes;
    }
};

#endif
