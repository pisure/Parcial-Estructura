#pragma once
//contenido se encargara de ser el padre de serie y pelicula
//se encargara de tener los atributos que comparten ambas clases
#include <iostream>
#include <string>

using namespace std;

class Contenido
{
public:
	Contenido(string ptitulo = "", string pgenero = "", string pdirector = "", int pminEdad = 0, int pId = 0) {

		titulo = ptitulo;
		genero = pgenero;
		director = pdirector;
		minEdad = pminEdad;
		id = pId;

	}
	~Contenido() = default;

	//metodos setters y getters
	void setTitulo(string ptitulo) {
		this->titulo = ptitulo;
	}
	void setGenero(string pgenero) {
		this->genero = pgenero;
	}
	void setDirector(string pdirector) {
		this->director = pdirector;
	}
	void setMinEdad(int pminEdad) {
		this->minEdad = pminEdad;
	}
	void setId(int pid) {
		this->id = pid;
	}

	string getTitulo() {
		return titulo;
	}
	string getGenero() {
		return genero;
	}
	string getDirector() {
		return director;
	}
	int getMinEdad() {
		return minEdad;
	}
	int getId() {
		return id;
	}

protected:
	string titulo;
	string genero;
	string director;

	int minEdad;
	int id;

};

