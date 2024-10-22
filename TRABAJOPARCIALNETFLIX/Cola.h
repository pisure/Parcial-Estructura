
#pragma once
#include "Nodo.h"
template <class T>

class Cola
{
public:
	Cola() {
		this->inicio = NULL;
		this->fin = NULL;
	}

	void encolar(T v);
	T desencolar();
	bool esVacia();

private:
	Nodo<T>* inicio;
	Nodo<T>* fin;
};

template <class T>
void Cola<T>::encolar(T v)
{
	Nodo<T>* nuevo = new Nodo<T>(v);
	if (esVacia()) {
		inicio = nuevo;
	}
	else {
		fin->siguiente = nuevo;
	}
	fin = nuevo;
}

template <class T>
T Cola<T>::desencolar()
{
	if (esVacia()) {
		cout << "Cola vacia" << endl;
		return NULL;
	}
	T v = inicio->dato;
	Nodo<T>* aux = inicio;
	inicio = inicio->siguiente;
	delete aux;
	return v;
}

template <class T>
bool Cola<T>::esVacia()
{
	return inicio == NULL;
}