#pragma once
//serie va a heredar de contenido

#include "Contenido.h"

using namespace std;

class Serie : public Contenido
{
public:
	Serie(string titulo = "", string genero = "", string director = "", int minEdad = 0, int id = 0, int duracion = 0, int numeroTemporadas = 0, int numeroEpisodios = 0) : Contenido(titulo, genero, director, minEdad, id) {
		this->duracion = duracion;
		this->numeroTemporadas = numeroTemporadas;
		this->numeroEpisodios = numeroEpisodios;

	}
	~Serie() = default;

	//metodos setters y getters
	void setDuracion(int pduracion) {
		this->duracion = pduracion;
	}
	void setNumeroTemporadas(int pnumeroTemporadas) {
		this->numeroTemporadas = pnumeroTemporadas;
	}
	void setNumeroEpisodios(int pnumeroEpisodios) {
		this->numeroEpisodios = pnumeroEpisodios;
	}

	int getDuracion() {
		return duracion;
	}
	int getNumeroTemporadas() {
		return numeroTemporadas;
	}
	int getNumeroEpisodios() {
		return numeroEpisodios;
	}

private:
	int duracion;
	int numeroTemporadas;
	int numeroEpisodios;

};
