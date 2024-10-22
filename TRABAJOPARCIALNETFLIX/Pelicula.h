#pragma once
//va a heredar de contenido
#include "Contenido.h"

using namespace std;

class Pelicula : public Contenido
{
public:
	Pelicula(string titulo = "", string genero = "", string director = "", int minEdad = 0, int id = 0, int duracion = 0) : Contenido(titulo, genero, director, minEdad, id) {
		this->duracion = duracion;
	}
	~Pelicula() = default;

	//metodos setters y getters
	void setDuracion(int pduracion) {
		this->duracion = pduracion;
	}
	int getDuracion() {
		return duracion;
	}



private:
	int duracion;

};
