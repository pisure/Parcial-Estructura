#pragma once
#include <string>
using namespace std;

class MiPago
{
private:
    string idPago;
    string descripcion;
    double monto;

public:
    MiPago(string idPago, string descripcion, double monto) :
        idPago(idPago), descripcion(descripcion), monto(monto) {}
    ~MiPago() = default;

    string getIdPago() { return idPago; }
    string getDescripcion() { return descripcion; }
    double getMonto() { return monto; }
	void mostrarDatos() {
		cout << "ID Pago: " << idPago << endl;
		cout << "Descripcion: " << descripcion << endl;
		cout << "Monto: " << monto << endl;
	}
};
