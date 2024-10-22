#pragma once
#include "Pelicula.h"
#include "Serie.h"

class Visualizaciones
{
private:
	vector<Pelicula*>* peliculas;
	vector<Serie*>* series;
public:
	Visualizaciones() {
		peliculas = new vector<Pelicula*>();
		series = new vector<Serie*>();
	}
	~Visualizaciones() = default;

	void agregarPelicula(Pelicula* pelicula) {
		peliculas->push_back(pelicula);
	}

	void mostrarPeliculas() {
		for (auto& pelicula : *peliculas) {
			cout << pelicula->getTitulo() << endl;
		}
	}

	void agregarSerie(Serie* serie) {
		series->push_back(serie);
	}

	void mostrarSeries() {
		for (auto& serie : *series) {
			cout << serie->getTitulo() << endl;
		}
	}

	vector<Serie*>* getSeries() { return series; }
	void setSeries(vector<Serie*>* series) { this->series = series; }

	



	vector<Pelicula*>* getPeliculas() { return peliculas; }

	void setPeliculas(vector<Pelicula*>* peliculas) { this->peliculas = peliculas; }


};

