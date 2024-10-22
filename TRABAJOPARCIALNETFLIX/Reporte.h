#pragma once
#include <string>
using namespace std;

class Reporte
{
private:
    string descripcion;
    string detalle;

public:
    Reporte(string descripcion,string detalle) : descripcion(descripcion),detalle(detalle) {}
    ~Reporte() = default;

    string getDescripcion() { return descripcion; }
	string getDetalle() { return detalle; }
	void mostrarDatos() {
		cout << "Descripcion: " << descripcion << endl;
		cout << "Detalle: " << detalle << endl;
	}
};
