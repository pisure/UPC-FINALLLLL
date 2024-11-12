#include "GestionPasajes.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


using namespace std;

// Variables globales para almacenar las rutas, reservas y transacciones
ListaRutas listaRutas;
ColaReservas colaReservas;
PilaHistorial pilaHistorial;

//Vectores para almacenar los datos cargados de archivos

vector<string> origenes;
vector<string> destinos;
vector<string> horas;

void cargarDatosDesdeArchivos() {
    // Cargar orígenes
    ifstream origenFile("origen.txt");
    if (origenFile.is_open()) {
        string linea;
        while (getline(origenFile, linea)) {
            origenes.push_back(linea);
        }
        origenFile.close();
    }
    else {
        cout << "No se pudo abrir origen.txt" << endl;
    }

    // Cargar destinos
    ifstream destinoFile("destino.txt");
    if (destinoFile.is_open()) {
        string linea;
        while (getline(destinoFile, linea)) {
            destinos.push_back(linea);
        }
        destinoFile.close();
    }
    else {
        cout << "No se pudo abrir destino.txt" << endl;
    }

    // Cargar horas
    ifstream horaFile("hora.txt");
    if (horaFile.is_open()) {
        string linea;
        while (getline(horaFile, linea)) {
            horas.push_back(linea);
        }
        horaFile.close();
    }
    else {
        cout << "No se pudo abrir hora.txt" << endl;
    }
}

void mostrarDatosCargados() {
    cout << "\nDatos cargados desde archivos:" << endl;

    cout << "\nOrígenes disponibles:" << endl;
    for (const auto& origen : origenes) {
        cout << "- " << origen << endl;
    }

    cout << "\nDestinos disponibles:" << endl;
    for (const auto& destino : destinos) {
        cout << "- " << destino << endl;
    }

    cout << "\nHoras disponibles:" << endl;
    for (const auto& hora : horas) {
        cout << "- " << hora << endl;
    }
}

int main() {
    cargarDatosDesdeArchivos();

    int rol;
    do {
        mostrarMenuPrincipal();
        cout << "Selecciona tu rol (0 para salir): ";
        cin >> rol;
        cin.ignore();

        switch (rol) {
        case 1: 
            mostrarMenuPasajero();
            break;
        case 2:
            mostrarMenuConductor();
            break;
        case 3:
            mostrarMenuSecretario();
            break;
        case 0:
            cout << "Saliendo del sistema..." << endl;
            break;
        default:
            cout << "Opcion no valida." << endl;
        }
    } while (rol != 0);

    return 0;
}

void mostrarMenuPrincipal() {
    cout << "\n------ Sistema de Gestion de Pasajes ------\n";
    cout << "1. Pasajero\n";
    cout << "2. Conductor\n";
    cout << "3. Secretario\n";
    cout << "0. Salir\n";
}

void mostrarMenuPasajero() {
    int opcion;
    do {
        cout << "\n------ Menu Pasajero ------\n";
        cout << "1. Comprar pasaje\n";
        cout << "2. Cancelar pasaje\n";
        cout << "3. Ver reservas\n";
        cout << "4. Volver al menu principal\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: comprarPasaje(); break;
        case 2: cancelarPasaje(); break;
        case 3: verReservas(); break;
        case 4: cout << "Volviendo al menu principal..." << endl; break;
        default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 4);
}

void mostrarMenuConductor() {
    int opcion;
    do {
        cout << "\n------ Menu Conductor ------\n";
        cout << "1. Mostrar rutas\n";
        cout << "2. Volver al menu principal\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: mostrarRutas(); break;
        case 2: cout << "Volviendo al menu principal..." << endl; break;
        default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 2);
}

void mostrarMenuSecretario() {
    int opcion;
    do {
        cout << "\n------ Menu Secretario ------\n";
        cout << "1. Editar pasaje\n";
        cout << "2. Ver historial de transacciones\n";
        cout << "3. Volver al menu principal\n";
        cout << "Selecciona una opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
        case 1: editarPasaje(); break;
        case 2: verHistorial(); break;
        case 3: cout << "Volviendo al menu principal..." << endl; break;
        default: cout << "Opcion no valida." << endl;
        }
    } while (opcion != 3);
}

void agregarRuta() {
    string nombreRuta;
    cout << "Ingrese el nombre de la ruta (Ej. Lima - Cusco): ";
    getline(cin, nombreRuta);
    listaRutas.insertar(new Ruta(nombreRuta));
    cout << "Ruta agregada correctamente." << endl;
}

void mostrarRutas() {
    cout << "\nRutas disponibles:\n";
    listaRutas.mostrarRutas();
}

void comprarPasaje() {
    string codigoReserva;
    cout << "Ingrese el codigo de la reserva (Ej. R001): ";
    getline(cin, codigoReserva);
    colaReservas.enque(new Reserva(codigoReserva));
    pilaHistorial.push(new Transaccion("Compra de pasaje " + codigoReserva));
    cout << "Pasaje comprado y agregado al historial de transacciones." << endl;
}

void editarPasaje() {
    string codigoReservaActual, codigoReservaNuevo;
    cout << "Ingrese el codigo actual de la reserva a editar: ";
    getline(cin, codigoReservaActual);
    cout << "Ingrese el nuevo codigo de la reserva: ";
    getline(cin, codigoReservaNuevo);

    Reserva* reservaActual = colaReservas.deque(); // Solo un ejemplo, agregar funcionalidad de búsqueda.
    if (reservaActual) {
        colaReservas.enque(new Reserva(codigoReservaNuevo));
        pilaHistorial.push(new Transaccion("Edicion de reserva: " + codigoReservaActual + " a " + codigoReservaNuevo));
        cout << "Reserva editada correctamente." << endl;
    }
    else {
        cout << "Reserva no encontrada." << endl;
    }
}

void cancelarPasaje() {
    string codigoReserva;
    cout << "Ingrese el codigo de la reserva a cancelar: ";
    getline(cin, codigoReserva);

    Reserva* reserva = colaReservas.deque(); // Mejorar con búsqueda real.
    if (reserva) {
        pilaHistorial.push(new Transaccion("Cancelacion de reserva: " + codigoReserva));
        cout << "Reserva cancelada correctamente." << endl;
    }
    else {
        cout << "Reserva no encontrada." << endl;
    }
}

void verReservas() {
    cout << "\nReservas actuales en la cola:\n";
    colaReservas.mostrarReservas();
}

void verHistorial() {
    cout << "\nHistorial de transacciones:\n";
    pilaHistorial.mostrarHistorial();
}

// Implementaciones de las clases

Pasajero::Pasajero(const string& nombre, const string& documentoIdentidad)
    : nombre(nombre), documentoIdentidad(documentoIdentidad) {}

void Pasajero::mostrar() {
    cout << "Nombre: " << nombre << ", Documento: " << documentoIdentidad << endl;
}

Ruta::Ruta(const string& nombreRuta) : nombreRuta(nombreRuta) {}

void Ruta::mostrar() {
    cout << "Ruta: " << nombreRuta << endl;
}

Reserva::Reserva(const string& codigoReserva) : codigoReserva(codigoReserva) {}

void Reserva::mostrar() {
    cout << "Reserva: " << codigoReserva << endl;
}

Transaccion::Transaccion(const string& detalle) : detalle(detalle) {}

void Transaccion::mostrar() {
    cout << "Transaccion: " << detalle << endl;
}

NodoRuta::NodoRuta(Ruta* ruta) : ruta(ruta), siguiente(nullptr) {}

ListaRutas::ListaRutas() : cabeza(nullptr) {}

void ListaRutas::insertar(Ruta* ruta) {
    NodoRuta* nuevoNodo = new NodoRuta(ruta);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void ListaRutas::mostrarRutas() {
    NodoRuta* actual = cabeza;
    while (actual) {
        actual->ruta->mostrar();
        actual = actual->siguiente;
    }
}

NodoReserva::NodoReserva(Reserva* reserva) : reserva(reserva), siguiente(nullptr) {}

ColaReservas::ColaReservas() : frente(nullptr), atras(nullptr) {}

void ColaReservas::enque(Reserva* reserva) {
    NodoReserva* nuevoNodo = new NodoReserva(reserva);
    if (!atras) {
        frente = atras = nuevoNodo;
    }
    else {
        atras->siguiente = nuevoNodo;
        atras = nuevoNodo;
    }
}

Reserva* ColaReservas::deque() {
    if (!frente) return nullptr;
    NodoReserva* temp = frente;
    Reserva* reserva = frente->reserva;
    frente = frente->siguiente;
    if (!frente) atras = nullptr; // Cola vacía
    delete temp;
    return reserva;
}

void ColaReservas::mostrarReservas() {
    NodoReserva* actual = frente;
    while (actual) {
        actual->reserva->mostrar();
        actual = actual->siguiente;
    }
}

NodoHistorial::NodoHistorial(Transaccion* transaccion) : transaccion(transaccion), siguiente(nullptr) {}

PilaHistorial::PilaHistorial() : cima(nullptr) {}

void PilaHistorial::push(Transaccion* transaccion) {
    NodoHistorial* nuevoNodo = new NodoHistorial(transaccion);
    nuevoNodo->siguiente = cima;
    cima = nuevoNodo;
}

Transaccion* PilaHistorial::pop() {
    if (!cima) return nullptr;
    NodoHistorial* temp = cima;
    Transaccion* transaccion = cima->transaccion;
    cima = cima->siguiente;
    delete temp;
    return transaccion;
}

void PilaHistorial::mostrarHistorial() {
    NodoHistorial* actual = cima;
    while (actual) {
        actual->transaccion->mostrar();
        actual = actual->siguiente;
    }
}
