#pragma once
#include "Pelicula.h"
#include "Serie.h"

class Descargas
{
private:
	vector<Pelicula*>* peliculas;
	vector<Serie*>* series;
public:
	Descargas() {
		peliculas = new vector<Pelicula*>();
		series = new vector<Serie*>();
	}
	~Descargas() = default;

	void agregarDescarga(Pelicula* pelicula) {
		peliculas->push_back(pelicula);
	}

	void mostrarDescargas() {
		for (auto& pelicula : *peliculas) {
			cout << pelicula->getTitulo() << endl;
		}
	}

	void agregarDescargaSeries(Serie* serie) {
		series->push_back(serie);
	}

	void mostrarDescargasSeries() {
		for (auto& serie : *series) {
			cout << serie->getTitulo() << endl;
		}
	}

	vector<Pelicula*>* getPeliculas() { return peliculas; }

	void setPeliculas(vector<Pelicula*>* peliculas) { this->peliculas = peliculas; }

	vector<Serie*>* getSeries() { return series; }

	void setSeries(vector<Serie*>* series) { this->series = series; }
};