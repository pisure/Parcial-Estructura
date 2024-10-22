#pragma once
#include "Visualizaciones.h"
#include "Descargas.h"
#include "MiLista.h"
#include "Lista.h"
#include "Pelicula.h"
#include "Serie.h"




class Perfil
{
private:
	string nombrePerfil;
	int edad;

	Visualizaciones visualizacionesActual;
	Descargas descargasActual;
	MiLista miListaActual;

public:
	Perfil(string nombrePerfil, int edad) : nombrePerfil(nombrePerfil), edad(edad) {
		visualizacionesActual = Visualizaciones();
		descargasActual = Descargas();
		miListaActual = MiLista();
	}
	~Perfil() = default;
	void mostrarPerfil() {
		cout << "Nombre del perfil: " << nombrePerfil << endl;
		cout << "Edad: " << edad << endl;
	}
	void menuPerfil(Lista<Pelicula*>* peliculas,Lista<Serie*>* series) {
		int opcion;
		do {
			cout << "1. Mostrar peliculas visualizadas" << endl;
			cout << "2. Agregar pelicula a descargas" << endl;
			cout << "3. Mostrar peliculas descargadas" << endl;
			cout << "4. Agregar pelicula a mi lista" << endl;
			cout << "5. Mostrar peliculas de mi lista" << endl;
			cout << "6. Cambiar nombre perfil" << endl;
			cout << "7. Mostrar informacion del perfil" << endl;
			cout << "8. Buscar pelicula por ID" << endl;
			cout << "9. Buscar pelicula por nombre" << endl;
			cout << "10. Buscar pelicula por director" << endl;
			cout << "11. Mostrar series visualizadas" << endl;
			cout << "12. Agregar serie a descargas" << endl;
			cout << "13. Mostrar series descargadas" << endl;
			cout << "14. Agregar serie a mi lista" << endl;
			cout << "15. Mostrar series de mi lista" << endl;
			cout << "16. Buscar serie por ID" << endl;
			cout << "17. Buscar serie por nombre" << endl;
			cout << "18. Buscar serie por director" << endl;
			cout << "19. Salir" << endl;
			cout << "--------------------------------" << endl;
			do {
				cout << "Opcion: ";
				cin >> opcion;
				if (opcion < 1 || opcion > 19) {
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			} while (opcion < 1 || opcion > 19);

			system("cls");

			switch (opcion)
			{

			case 1:
				visualizacionesActual.mostrarPeliculas();
				menuReseatPantalla();
				break;
			case 2:
				descargasActual.agregarDescarga(buscarPeliculaPorNombre(peliculas));
				menuReseatPantalla();
				break;
			case 3:
				descargasActual.mostrarDescargas();
				menuReseatPantalla();
				break;
			case 4:
				miListaActual.agregarPelicula(buscarPeliculaPorNombre(peliculas));
				menuReseatPantalla();
				break;
			case 5:
				miListaActual.mostrarPeliculas();
				menuReseatPantalla();
				break;
			case 6:
				cambiarPerfil();
				menuReseatPantalla();

				break;
			case 7:
				mostrarPerfil();
				menuReseatPantalla();
				break;
			case 8:
				visualizacionesActual.agregarPelicula(buscarPelicula(peliculas));
				menuReseatPantalla();
				break;
			case 9:
				visualizacionesActual.agregarPelicula(buscarPeliculaPorNombre(peliculas));
				menuReseatPantalla();
				break;
			case 10:
				visualizacionesActual.agregarPelicula(buscarPeliculaPorDirector(peliculas));
				menuReseatPantalla();
				break;
			case 11:
				visualizacionesActual.mostrarSeries();
				menuReseatPantalla();
				break;
			case 12:
				descargasActual.agregarDescargaSeries(buscarSeriePorNombre(series));
				break;
			case 13:
				descargasActual.mostrarDescargasSeries();
				break;
			case 14:
				miListaActual.agregarSerie(buscarSeriePorNombre(series));
				break;
			case 15:
				miListaActual.mostrarSeries();
				break;
			case 16:
				visualizacionesActual.agregarSerie(buscarSerie(series));
				break;
			case 17:
				visualizacionesActual.agregarSerie(buscarSeriePorNombre(series));
				break;
			case 18:
				visualizacionesActual.agregarSerie(buscarSeriePorDirector(series));
				break;
			case 19:
				cout << "Saliendo del perfil" << endl;
				break;

			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcion != 19);


	}

	void cambiarPerfil() {
		cout << "-------Cambiando de perfil------" << endl;
		cout << "Nombre del perfil: ";
		cin >> nombrePerfil;

		cout << "\n Perfil cambiado exitosamente" << endl;
	}
	string getNombrePerfil() { return this->nombrePerfil; }
	int getEdad() { return edad; }

	// Métodos de búsqueda
	Pelicula* buscarPelicula(Lista<Pelicula*>* peliculas) {
		int id;
		cout << "Ingrese el ID de la pelicula: ";
		cin >> id;

		for (int i = 0; i < peliculas->obtenerTamano(); i++) {
			Pelicula* pelicula = peliculas->obtenerEnPosicion(i);
			if (pelicula->getId() == id) {
				cout << "Pelicula encontrada: " << pelicula->getTitulo() << endl;
				return pelicula;
			}
		}

		cout << "Pelicula no encontrada" << endl;
		return nullptr;
	}

	Pelicula* buscarPeliculaPorNombre(Lista<Pelicula*>* peliculas) {
		string nombre;
		cout << "Ingrese el nombre de la pelicula: ";
		cin.ignore();
		getline(cin, nombre);

		for (int i = 0; i < peliculas->obtenerTamano(); i++) {
			Pelicula* pelicula = peliculas->obtenerEnPosicion(i);
			if (pelicula->getTitulo() == nombre) {
				cout << "Pelicula encontrada: " << pelicula->getTitulo() << endl;
				return pelicula;
			}
		}

		cout << "Pelicula no encontrada" << endl;
		return nullptr;
	}

	Pelicula* buscarPeliculaPorDirector(Lista<Pelicula*>* peliculas) {
		string director;
		cout << "Ingrese el director de la pelicula: ";
		cin.ignore();
		getline(cin, director);
		Lista<Pelicula*> peliculasEncontradas;
		for (int i = 0; i < peliculas->obtenerTamano(); i++) {
			Pelicula* pelicula = peliculas->obtenerEnPosicion(i);
			if (pelicula->getDirector() == director) {
				peliculasEncontradas.agregar(pelicula);
			}
		}
		if (peliculasEncontradas.obtenerTamano() > 0) {
			cout << "Peliculas encontradas: " << endl;
			for (int i = 0; i < peliculasEncontradas.obtenerTamano(); i++) {
				Pelicula* pelicula = peliculasEncontradas.obtenerEnPosicion(i);
				cout << i + 1 << ". " << pelicula->getTitulo() << endl;
			}
			int opcion;
			cout << "Seleccione una pelicula: ";
			cin >> opcion;
			if (opcion >= 1 && opcion <= peliculasEncontradas.obtenerTamano()) {
				return peliculasEncontradas.obtenerEnPosicion(opcion - 1);
			}
			else {
				cout << "Opcion invalida." << endl;
			}
		}
		else {
			cout << "Pelicula no encontrada" << endl;
		}
		return nullptr;
	}

	//lo mismo para series
	Serie* buscarSerie(Lista<Serie*>* series) {
		int id;
		cout << "Ingrese el ID de la serie: ";
		cin >> id;

		for (int i = 0; i < series->obtenerTamano(); i++) {
			Serie* serie = series->obtenerEnPosicion(i);
			if (serie->getId() == id) {
				cout << "Serie encontrada: " << serie->getTitulo() << endl;
				return serie;
			}
		}

		cout << "Serie no encontrada" << endl;
		return nullptr;
	}

	Serie* buscarSeriePorNombre(Lista<Serie*>* series) {
		string nombre;
		cout << "Ingrese el nombre de la serie: ";
		cin.ignore();
		getline(cin, nombre);

		for (int i = 0; i < series->obtenerTamano(); i++) {
			Serie* serie = series->obtenerEnPosicion(i);
			if (serie->getTitulo() == nombre) {
				cout << "Serie encontrada: " << serie->getTitulo() << endl;
				return serie;
			}
		}

		cout << "Serie no encontrada" << endl;
		return nullptr;
	}

	Serie* buscarSeriePorDirector(Lista<Serie*>* series) {
		string director;
		cout << "Ingrese el director de la serie: ";
		cin.ignore();
		getline(cin, director);
		Lista<Serie*> seriesEncontradas;
		for (int i = 0; i < series->obtenerTamano(); i++) {
			Serie* serie = series->obtenerEnPosicion(i);
			if (serie->getDirector() == director) {
				seriesEncontradas.agregar(serie);
			}
		}
		if (seriesEncontradas.obtenerTamano() > 0) {
			cout << "Series encontradas: " << endl;
			for (int i = 0; i < seriesEncontradas.obtenerTamano(); i++) {
				Serie* serie = seriesEncontradas.obtenerEnPosicion(i);
				cout << i + 1 << ". " << serie->getTitulo() << endl;
			}
			int opcion;
			cout << "Seleccione una serie: ";
			cin >> opcion;
			if (opcion >= 1 && opcion <= seriesEncontradas.obtenerTamano()) {
				return seriesEncontradas.obtenerEnPosicion(opcion - 1);
			}
			else {
				cout << "Opcion invalida." << endl;
			}
		}
		else {
			cout << "Serie no encontrada" << endl;
		}
		return nullptr;
	}

};
