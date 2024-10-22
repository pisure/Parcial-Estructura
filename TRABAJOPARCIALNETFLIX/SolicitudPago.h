#pragma once
#include "tools.h"
class SolicitudPago
{
private:
	string nombreCliente;
	string idSolicitud;
	string precio;
	string metodoPago;
	string fecha;
	bool estado;
	bool estadoPago;

public:
	SolicitudPago(string nombreCliente, string idSolicitud, string precio, string metodoPago, string fecha, bool estado, bool estadoPago) :
		nombreCliente(nombreCliente),idSolicitud(idSolicitud), precio(precio), metodoPago(metodoPago), fecha(fecha), estado(estado) ,estadoPago(estadoPago){}
	~SolicitudPago() = default;

	string getNombreCliente() { return nombreCliente;}
	string getIdSolicitud() { return idSolicitud; }
	string getPrecio() { return precio; }
	string getMetodoPago() { return metodoPago; }
	string getFecha() { return fecha; }
	bool getEstado() { return estado; }
	bool getEstadoPago() { return estadoPago; }

	void setNombreCliente(string nombreCliente) { this->nombreCliente = nombreCliente; }
	void setIdSolicitud(string idSolicitud) { this->idSolicitud = idSolicitud; }
	void setPrecio(string precio) { this->precio = precio; }
	void setMetodoPago(string metodoPago) { this->metodoPago = metodoPago; }
	void setFecha(string fecha) { this->fecha = fecha; }
	void setEstado(bool estado) { this->estado = estado; }
	void setEstadoPago(bool estadoPago) { this->estadoPago = estadoPago; }
	string toString() {
		return "Nombre Cliente: " + nombreCliente + "\nId Solicitud: " + idSolicitud + "\nPrecio: " + precio + "\nMetodo de Pago: " + metodoPago + "\nFecha: " + fecha + "\nEstado: " + to_string(estado) + "\nEstado de Pago: " + to_string(estadoPago);
	}

};
