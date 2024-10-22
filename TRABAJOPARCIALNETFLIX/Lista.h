#pragma once
#include<iostream>
using namespace std;

template <typename T>
class Lista {
private:
    struct Nodo {
        T dato;
        Nodo* siguiente;
    };
    Nodo* cabeza;
    int tam;

public:
    // Constructor
    Lista() : cabeza(nullptr), tam(0) {}

    // Destructor
    ~Lista() {
        limpiar();
    }

    // M�todo para agregar al final
    void agregar(const T& valor) {
        Nodo* nuevo = new Nodo{ valor, nullptr };
        if (!cabeza) {
            cabeza = nuevo;
        }
        else {
            Nodo* temp = cabeza;
            while (temp->siguiente != nullptr) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevo;
        }
        tam++;
    }

    // M�todo para agregar en posici�n
    void agregarEnPosicion(const T& valor, int posicion) {
        if (posicion < 0 || posicion > tam) {
            cout << "Posici�n inv�lida" << endl;
            return;
        }
        Nodo* nuevo = new Nodo{ valor, nullptr };
        if (posicion == 0) {
            nuevo->siguiente = cabeza;
            cabeza = nuevo;
        }
        else {
            Nodo* temp = cabeza;
            for (int i = 0; i < posicion - 1; i++) {
                temp = temp->siguiente;
            }
            nuevo->siguiente = temp->siguiente;
            temp->siguiente = nuevo;
        }
        tam++;
    }

    // M�todo para eliminar un valor
    void eliminar(const T& valor) {
        Nodo* temp = cabeza;
        Nodo* anterior = nullptr;

        while (temp != nullptr && temp->dato != valor) {
            anterior = temp;
            temp = temp->siguiente;
        }

        if (temp == nullptr) {
            cout << "Valor no encontrado" << endl;
            return;
        }

        if (anterior == nullptr) { // Eliminar cabeza
            cabeza = cabeza->siguiente;
        }
        else {
            anterior->siguiente = temp->siguiente;
        }

        delete temp;
        tam--;
    }

    // M�todo para eliminar en una posici�n
    void eliminarEnPosicion(int posicion) {
        if (posicion < 0 || posicion >= tam) {
            cout << "Posici�n inv�lida" << endl;
            return;
        }

        Nodo* temp = cabeza;
        if (posicion == 0) {
            cabeza = cabeza->siguiente;
        }
        else {
            Nodo* anterior = nullptr;
            for (int i = 0; i < posicion; i++) {
                anterior = temp;
                temp = temp->siguiente;
            }
            anterior->siguiente = temp->siguiente;
        }

        delete temp;
        tam--;
    }

    // M�todo para obtener un valor en una posici�n
    T obtenerEnPosicion(int posicion) const {
        if (posicion < 0 || posicion >= tam) {
            throw out_of_range("Posici�n inv�lida");
        }
        Nodo* temp = cabeza;
        for (int i = 0; i < posicion; i++) {
            temp = temp->siguiente;
        }
        return temp->dato;
    }

    // M�todo para obtener el valor de la cabeza
    T obtener() const {
        if (!cabeza) {
            throw out_of_range("La lista est� vac�a");
        }
        return cabeza->dato;
    }

    // M�todo para modificar un valor en una posici�n
    void modificarEnPosicion(const T& valor, int posicion) {
        if (posicion < 0 || posicion >= tam) {
            cout << "Posici�n inv�lida" << endl;
            return;
        }
        Nodo* temp = cabeza;
        for (int i = 0; i < posicion; i++) {
            temp = temp->siguiente;
        }
        temp->dato = valor;
    }

    // M�todo para modificar la cabeza
    void modificar(const T& valor) {
        if (!cabeza) {
            cout << "La lista est� vac�a" << endl;
            return;
        }
        cabeza->dato = valor;
    }

    // M�todo para obtener el tama�o de la lista
    int obtenerTamano() const {
        return tam;
    }

    // M�todo para limpiar la lista
    void limpiar() {
        while (cabeza != nullptr) {
            Nodo* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
        tam = 0;
    }
};