#pragma once
#include "Usuario.h"
#include "SolicitudPago.h"
#include "Reporte.h"

class Empleado : public Usuario
{
private:
	string idEmpleado;
	vector<Reporte> reportes;

public:
	Empleado(string nombre, string apellido, string fechaNacimiento, string pais, string correo,
		string contrasena, string direccion, string telefono, string celular, string sexo, string idEmpleado) :
		Usuario(nombre, apellido, fechaNacimiento, pais, correo, contrasena,
			direccion, telefono, celular, sexo), idEmpleado(idEmpleado) {}
	Empleado() = default;
	//CONTROL DE SOLICITUDES
	void atenderSolicitud(Cola<SolicitudPago*>& cola) {
		if (!cola.esVacia()) {
			SolicitudPago* solicitud = cola.desencolar();
			cout << "Solicitud de: " << solicitud->getNombreCliente() << endl;
			cout << "ID Solicitud: " << solicitud->getIdSolicitud() << endl;
			cout << "Precio: " << solicitud->getPrecio() << endl;
			cout << "Metodo de pago: " << solicitud->getMetodoPago() << endl;
			cout << "Fecha: " << solicitud->getFecha() << endl;
			cout << "Estado: " << (solicitud->getEstado() ? "Aceptado" : "Denegado") << endl;

			revisarSolicitudPago(solicitud);
		}
	}
	void crearReporte(const string& descripcion, string detalle) {
		Reporte reporte(descripcion, detalle);
		reportes.push_back(reporte);
	}

	void revisarSolicitudPago(SolicitudPago* solicitud) {
		int opcionRevision;

		cout << "1. Aceptar solicitud" << endl;
		cout << "2. Denegar solicitud" << endl;
		cout << "3. Salir" << endl;
		cout << "Ingrese una opcion: ";
		cin >> opcionRevision;
		string detalle;
		switch (opcionRevision) {
		case 1:
			solicitud->setEstado(true);
			cout << "Solicitud aceptada" << endl;
			cout << "--------------------------------" << endl;
			cout << "Agregar detalle: ";
			cin.ignore();
			getline(cin, detalle);
			crearReporte("Solicitud aceptada", detalle);
			menuReseatPantalla();
			break;
		case 2:
			solicitud->setEstado(false);
			cout << "Agregar detalle: ";
			cin.ignore();
			getline(cin, detalle);
			menuReseatPantalla();
			crearReporte("Solicitud denegada", detalle);
			break;
		case 3:
			cout << "Saliendo de la revision de solicitud" << endl;
			menuReseatPantalla();
			break;
		default:
			cout << "Opcion invalida" << endl;
			break;
		}




	}

	void mostrarReportes() {
		for (auto& reporte : reportes) {
			reporte.mostrarDatos();
		}
	}
	//CONTROL DE CATALOGO


	void menuEmpleado(Cola<SolicitudPago*>& cola) {
		int opcion;
		do {
			cout << "1. Atender solicitud" << endl;
			cout << "2. Mostrar reportes" << endl;

			cout << "3. Privacidad" << endl;


			cout << "4. Salir" << endl;
			cout << "Ingrese una opcion: ";
			cin >> opcion;
			switch (opcion) {
			case 1:
				atenderSolicitud(cola);
				break;
			case 2:
				mostrarReportes();
				break;
			case 3:
				menuPrivacidad();
				break;
			case 5:
				cout << "Saliendo del menu de empleado" << endl;
				menuReseatPantalla();
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcion != 4);
	}
	void mostrarDatos() {
		cout << "--------------------------------" << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Apellido: " << apellido << endl;
		cout << "Fecha de nacimiento: " << fechaNacimiento << endl;
		cout << "Pais: " << pais << endl;
		cout << "Correo: " << correo << endl;
		cout << "Direccion: " << direccion << endl;
		cout << "Celular: " << celular << endl;
		cout << "Sexo: " << sexo << endl;
		cout << "ID Empleado: " << idEmpleado << endl;
		cout << "--------------------------------" << endl;
		menuReseatPantalla();
	}
	//CONTROL DE PRIVACIDAD
	void menuPrivacidad() {
		int opcionMenuPrivacidad;
		do {
			cout << "1.Mostrar informacion" << endl;
			cout << "2.Cambiar contrasena" << endl;
			cout << "3.Cambiar correo" << endl;
			cout << "4.Cambiar direccion" << endl;
			cout << "5.Cambiar celular" << endl;
			cout << "6.Salir" << endl;
			do {
				cout << "Ingrese una opcion: ";
				cin >> opcionMenuPrivacidad;
				if (opcionMenuPrivacidad < 1 || opcionMenuPrivacidad > 6) {
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			} while (opcionMenuPrivacidad < 1 || opcionMenuPrivacidad > 6);
			switch (opcionMenuPrivacidad)
			{
			case 1:
				system("cls");
				mostrarDatos();
				break;
			case 2:
				system("cls");
				cambiarContrasena();
				break;
			case 3:
				system("cls");
				cambiarCorreo();
				break;
			case 4:
				system("cls");
				cambiarDireccion();
				break;
			case 5:
				system("cls");
				cambiarCelular();
				break;
			case 6:
				system("cls");
				cout << "Saliendo del menu de privacidad" << endl;
				menuReseatPantalla();
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcionMenuPrivacidad != 6);
	}
};



