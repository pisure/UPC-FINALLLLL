#ifndef GESTIONPASAJES_H
#define GESTIONPASAJES_H

#include <iostream>
#include <string>

// Clase Pasajero
class Pasajero {
public:
    std::string nombre;
    std::string documentoIdentidad;

    Pasajero(const std::string& nombre, const std::string& documentoIdentidad);
    void mostrar();
};

// Clase Ruta
class Ruta {
public:
    std::string nombreRuta;

    Ruta(const std::string& nombreRuta);
    void mostrar();
};

// Clase Reserva
class Reserva {
public:
    std::string codigoReserva;

    Reserva(const std::string& codigoReserva);
    void mostrar();
};

// Clase Transaccion
class Transaccion {
public:
    std::string detalle;

    Transaccion(const std::string& detalle);
    void mostrar();
};

// Clase NodoRuta para lista de rutas
class NodoRuta {
public:
    Ruta* ruta;
    NodoRuta* siguiente;

    NodoRuta(Ruta* ruta);
};

// Clase ListaRutas
class ListaRutas {
public:
    NodoRuta* cabeza;

    ListaRutas();
    void insertar(Ruta* ruta);
    void mostrarRutas();
};

// Clase NodoReserva para cola de reservas
class NodoReserva {
public:
    Reserva* reserva;
    NodoReserva* siguiente;

    NodoReserva(Reserva* reserva);
};

// Clase ColaReservas
class ColaReservas {
public:
    NodoReserva* frente;
    NodoReserva* atras;

    ColaReservas();
    void enque(Reserva* reserva);
    Reserva* deque();
    void mostrarReservas();
};

// Clase NodoHistorial para pila de transacciones
class NodoHistorial {
public:
    Transaccion* transaccion;
    NodoHistorial* siguiente;

    NodoHistorial(Transaccion* transaccion);
};

// Clase PilaHistorial
class PilaHistorial {
public:
    NodoHistorial* cima;

    PilaHistorial();
    void push(Transaccion* transaccion);
    Transaccion* pop();
    void mostrarHistorial();
};

// Funciones del menú
void mostrarMenuPrincipal();
void mostrarMenuPasajero();
void mostrarMenuConductor();
void mostrarMenuSecretario();
void agregarRuta();
void mostrarRutas();
void comprarPasaje();
void editarPasaje();
void cancelarPasaje();
void verReservas();
void verHistorial();

#endif // GESTIONPASAJES_H
