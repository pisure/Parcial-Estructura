#include "menus.h"
#include "SolicitudPago.h"
#include "Cola.h"
#include "Cliente.h"
#include "Empleado.h"
#include <fstream>
#include "Pelicula.h"
#include <sstream>
#include "Lista.h"
#include "Serie.h"



void cargarSolicitudesPago(Cola<SolicitudPago*>& cola) {
    ifstream archivo("solicitudesPago.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }
    string line;
    string nombreCliente;
    string idSolicitud;
    string precio;
    string metodoPago;
    string fecha;
    bool estado;
    bool estadoPago;
	while (getline(archivo, line)) {
		nombreCliente = line;
		getline(archivo, line);
		idSolicitud = line;
		getline(archivo, line);
		precio = line;
		getline(archivo, line);
		metodoPago = line;
		getline(archivo, line);
		fecha = line;
		getline(archivo, line);
		estado = (line == "1") ? true : false;
		getline(archivo, line);
		estadoPago = line == "1" ? true : false;
		SolicitudPago* solicitud = new SolicitudPago(nombreCliente, idSolicitud, precio, metodoPago, fecha, estado, estadoPago);
		cola.encolar(solicitud);
    }
    archivo.close();
}



void guardarSolicitudesPago(Cola<SolicitudPago*>& cola) {
    ofstream archivo("solicitudesPago.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo" << endl;
        return;
    }
    while (!cola.esVacia()) {
        SolicitudPago* solicitud = cola.desencolar();
        archivo << solicitud->getNombreCliente() << endl;
        archivo << solicitud->getIdSolicitud() << endl;
        archivo << solicitud->getPrecio() << endl;
        archivo << solicitud->getMetodoPago() << endl;
        archivo << solicitud->getFecha() << endl;
        archivo << solicitud->getEstado() << endl;
        archivo << solicitud->getEstadoPago() << endl;
        delete solicitud;
    }
    archivo.close();
}

// Función para guardar las películas en un archivo de texto llamado peliculas.txt
void guardarPeliculas(const Lista<Pelicula*>* peliculas) {
    ofstream archivo("peliculas.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < peliculas->obtenerTamano(); i++) {
            Pelicula* pelicula = peliculas->obtenerEnPosicion(i);
            if (pelicula != nullptr) {
                archivo << pelicula->getTitulo() << ","
                    << pelicula->getGenero() << ","
                    << pelicula->getDirector() << ","
                    << pelicula->getMinEdad() << ","
                    << pelicula->getId() << ","
                    << pelicula->getDuracion() << endl;
            }
        }
        archivo.close();
        cout << "Películas guardadas exitosamente en peliculas.txt." << endl;
    }
    else {
        cerr << "Error: No se pudo abrir el archivo peliculas.txt para escribir." << endl;
    }
}

// Función para cargar las películas desde el archivo a la lista
void cargarPeliculas(Lista<Pelicula*>* peliculas) {
    ifstream archivo("peliculas.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            if (linea.empty()) continue; // Saltar líneas vacías

            string titulo, genero, director;
            int minEdad, id, duracion;

            // Usar stringstream para procesar la línea
            stringstream ss(linea);
            string token;
            int campo = 0;

            try {
                while (getline(ss, token, ',')) {
                    switch (campo) {
                    case 0:
                        titulo = token;
                        break;
                    case 1:
                        genero = token;
                        break;
                    case 2:
                        director = token;
                        break;
                    case 3:
                        minEdad = stoi(token);
                        break;
                    case 4:
                        id = stoi(token);
                        break;
                    case 5:
                        duracion = stoi(token);
                        break;
                    default:
                        break;
                    }
                    campo++;
                }

                if (campo == 6) { // Verificar que se hayan leído todos los campos
                    Pelicula* pelicula = new Pelicula(titulo, genero, director, minEdad, id, duracion);
                    peliculas->agregar(pelicula);
                }
                else {
                    cerr << "Advertencia: Línea con formato incorrecto en peliculas.txt: " << linea << endl;
                }
            }
            catch (const invalid_argument& e) {
                cerr << "Error: Conversión inválida en línea: " << linea << " - " << e.what() << endl;
            }
            catch (const out_of_range& e) {
                cerr << "Error: Valor fuera de rango en línea: " << linea << " - " << e.what() << endl;
            }
        }
        archivo.close();
        cout << "Películas cargadas exitosamente desde peliculas.txt." << endl;
    }
    else {
        cerr << "Error: No se pudo abrir el archivo peliculas.txt para leer." << endl;
    }
}

//hacemos lo mismo con series

// Función para guardar las series en un archivo de texto llamado series.txt
void guardarSeries(const Lista<Serie*>* series) {
    ofstream archivo("series.txt");
    if (archivo.is_open()) {
        for (int i = 0; i < series->obtenerTamano(); i++) {
            Serie* serie = series->obtenerEnPosicion(i);
            if (serie != nullptr) {
                archivo << serie->getTitulo() << ","
                    << serie->getGenero() << ","
                    << serie->getDirector() << ","
                    << serie->getMinEdad() << ","
                    << serie->getId() << ","
                    << serie->getDuracion() << ","
                    << serie->getNumeroTemporadas() << ","
                    << serie->getNumeroEpisodios() << endl;
            }
        }
        archivo.close();
        cout << "Series guardadas exitosamente en series.txt." << endl;
    }
    else {
        cerr << "Error: No se pudo abrir el archivo series.txt para escribir." << endl;
    }
}

// Función para cargar las series desde el archivo a la lista
void cargarSeries(Lista<Serie*>* series) {
    ifstream archivo("series.txt");
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            if (linea.empty()) continue; // Saltar líneas vacías

            string titulo, genero, director;
            int minEdad, id, duracion, numeroTemporadas, numeroEpisodios;

            // Usar stringstream para procesar la línea
            stringstream ss(linea);
            string token;
            int campo = 0;

            try {
                while (getline(ss, token, ',')) {
                    switch (campo) {
                    case 0:
                        titulo = token;
                        break;
                    case 1:
                        genero = token;
                        break;
                    case 2:
                        director = token;
                        break;
                    case 3:
                        minEdad = stoi(token);
                        break;
                    case 4:
                        id = stoi(token);
                        break;
                    case 5:
                        duracion = stoi(token);
                        break;
                    case 6:
                        numeroTemporadas = stoi(token);
                        break;
                    case 7:
                        numeroEpisodios = stoi(token);
                        break;
                    default:
                        break;
                    }
                    campo++;
                }

                if (campo == 8) { // Verificar que se hayan leído todos los campos
                    Serie* serie = new Serie(titulo, genero, director, minEdad, id, duracion, numeroTemporadas, numeroEpisodios);
                    series->agregar(serie);
                }
                else {
                    cerr << "Advertencia: Línea con formato incorrecto en series.txt: " << linea << endl;
                }
            }
            catch (const invalid_argument& e) {
                cerr << "Error: Conversión inválida en línea: " << linea << " - " << e.what() << endl;
            }
            catch (const out_of_range& e) {
                cerr << "Error: Valor fuera de rango en línea: " << linea << " - " << e.what() << endl;
            }
        }
        archivo.close();
        cout << "Series cargadas exitosamente desde series.txt." << endl;
    }
    else {
        cerr << "Error: No se pudo abrir el archivo series.txt para leer." << endl;
    }
}


int main()
{
    srand(time(0));
    vector <Subscripcion> planes;
    planes.push_back(Subscripcion(1, "Basico", "S/ 15.00", false));
    planes.push_back(Subscripcion(2, "Estandar", "S/ 25.00", false));
    planes.push_back(Subscripcion(3, "Premium", "S/ 35.00", false));



    Cola<SolicitudPago*> solicitudesPagos;
    Cliente cliente("Carlos", "Gomez", "02/02/1990", "México", "carlos.gomez@example.com", "password456", "Avenida Siempre Viva 456", "234567890", "876543210", "M");
    Cliente cliente2("Laura", "González", "15/07/1995", "Argentina", "laura.gonzalez@example.com", "password789", "Calle Principal 789", "345678901", "987654321", "F");
    Empleado empleado("Juan", "Perez", "01/01/1980", "España", "juan.perez@example.com", "password123", "Calle Falsa 123", "123456789", "987654321", "M", "E001");
    cargarSolicitudesPago(solicitudesPagos);

    // Crear una lista para almacenar las películas
    Lista<Pelicula*>* peliculas = new Lista<Pelicula*>();
    Lista<Serie*>* series = new Lista<Serie*>();

    // Cargar las películas desde el archivo
    cargarPeliculas(peliculas);
    cargarSeries(series);
    int opcion;
    do {

        opcion = IniciarSesion();
        switch (opcion)
        {
	    case 1:
			system("cls");
		    empleado.menuEmpleado(solicitudesPagos);
			menuReseatPantalla();
		    break;
	    case 2:
			system("cls");
		    cliente.menuCliente(peliculas,series,solicitudesPagos,planes);
			menuReseatPantalla();
		    break;
        case 3:
			system("cls");
		    cout << "Saliendo del programa" << endl;
			menuReseatPantalla();
		    break;
        default:
            break;
        }

	} while (opcion != 3);
   
    
    system("pause");
    system("cls");
	guardarPeliculas(peliculas);
	guardarSeries(series);
    guardarSolicitudesPago(solicitudesPagos);

    return 0; // Add this line
}
