#pragma once
#include "Usuario.h"
#include "SolicitudPago.h"
#include "MiPago.h"
#include "Tarjeta.h"
#include "Perfil.h"
#include "Subscripcion.h"


class Cliente : public Usuario
{
private:
    vector<SolicitudPago*> solicitudesPropias;
    vector<MiPago> pagos;
    vector<Tarjeta> tarjetas;
	vector<Perfil> perfiles;
	Subscripcion plan;
	int perfilesCreados = 0;
	int perfilesMaximos=5;
    //Suscripcion plans;


public:
    Cliente(string nombre, string apellido, string fechaNacimiento, string pais, string correo,
        string contrasena, string direccion, string telefono, string celular, string sexo) :
        Usuario(nombre, apellido, fechaNacimiento, pais, correo, contrasena,
            direccion, telefono, celular, sexo) {
		plan = Subscripcion();
		pagos = vector<MiPago>();
		solicitudesPropias = vector<SolicitudPago*>();
		tarjetas = vector<Tarjeta>();
		perfiles = vector<Perfil>();
    }
    ~Cliente() = default;
	//CONTROL TARJETAS
    void agregarTarjeta() {
		string numero;
		string titular;
		string fechaExpiracion;
		string cvv;
		cout << "Ingrese el numero de la tarjeta: ";
		cin.ignore();
		getline(cin, numero);
		cout << "Ingrese el titular de la tarjeta: ";
		cin.ignore();
		getline(cin, titular);
		cout << "Ingrese la fecha de expiracion de la tarjeta: ";
		cin.ignore();
		getline(cin, fechaExpiracion);
		cout << "Ingrese el cvv de la tarjeta: ";
		cin.ignore();
		getline(cin, cvv);
		
		Tarjeta tarjeta(numero, titular, fechaExpiracion, cvv);
        tarjetas.push_back(tarjeta);
		cout << "Tarjeta agregada correctamente." << endl;
		menuReseatPantalla();
    }
	void mostrarTarjetas() {
		int i = 1;
		for (auto& tarjeta : tarjetas) {

			cout << "Tarjeta: " << i << endl;
			cout << "----------------------\n";
			tarjeta.mostrarDatos();
			cout << "----------------------\n" << endl;
			i++;
		}
		menuReseatPantalla();
	}
	void menuTarjeta() {
		int opcionMenuTarjeta;
		do {
			cout << "1.Agregar Tarjeta" << endl;
			cout << "2.Mostrar Tarjetas" << endl;
			cout << "3.Salir" << endl;
			do {
				cout << "Ingrese una opcion: ";
				cin >> opcionMenuTarjeta;
				if (opcionMenuTarjeta < 1 || opcionMenuTarjeta > 3) {
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			} while (opcionMenuTarjeta < 1 || opcionMenuTarjeta > 3);
			switch (opcionMenuTarjeta)
			{
			case 1:
				system("cls");
				agregarTarjeta();
				break;
			case 2:
				system("cls");
				mostrarTarjetas();
				break;
			case 3:
				system("cls");
				cout << "Saliendo del menu de tarjetas" << endl;
				menuReseatPantalla();
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcionMenuTarjeta != 3);
	}
	//CONTROL PAGOS
    void crearSolicitudPago(Cola<SolicitudPago*>& cola, SolicitudPago* solicitud) {
        
        solicitudesPropias.push_back(solicitud);
        cola.encolar(solicitud);
    }

    void verificarSolicitudes() {
        for (auto& solicitud : solicitudesPropias) {
            if (solicitud->getEstado() && solicitud->getEstadoPago()) {
                MiPago pago(solicitud->getIdSolicitud(), solicitud->getFecha(), stod(solicitud->getPrecio()));
                pagos.push_back(pago);
            }
        }
    }
	void mostrarPagos() {
		verificarSolicitudes();
		for (auto& pago : pagos) {
			pago.mostrarDatos();
		}
	}
	void mostrarSolicitudes() {
		for (auto& solicitud : solicitudesPropias) {
			cout << solicitud->toString() << endl;
		}
	}
	//CONTROL PERFILES
	void agregarPerfil() {
		if (perfilesCreados >= perfilesMaximos) {
			cout << "No se pueden crear mas perfiles" << endl;
			menuReseatPantalla();
			
		}
		else {
			string nombrePerfil;
		
			int edad;
			cout << "Ingrese el nombre del perfil: ";
			cin >> nombrePerfil;
			cout << "Ingresar edad: ";
			cin >> edad;
		
			Perfil perfil(nombrePerfil, edad);
			perfiles.push_back(perfil);
			cout << "Perfil agregado correctamente." << endl;
			perfilesCreados++;
			menuReseatPantalla();
		}
	}
	void menuPerfil(Lista <Pelicula*>* peliculas, Lista <Serie*>* series) {
		int opcion;
		do {
			mostrarPerfiles();
			cout << "6. Crear perfil" << endl;
			
			do {
				cout << "Ingrese el numero de perfil al que desea ingresar(7 PARA RETORNAR): ";
				cin >> opcion;
				if (opcion < 1 || opcion > 6) {
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			} while (opcion < 1 || opcion > 7);
			
			switch (opcion)
			{
			case 1:
				system("cls");
				if (perfiles.size() >=opcion) {
					perfiles[opcion - 1].menuPerfil(peliculas,series);
					break;
				}
				else {
					cout << "Perfil no creado" << endl;
				}
				menuReseatPantalla();
				break;
			case 2:

				system("cls");
				if (perfiles.size() > opcion) {
					perfiles[opcion - 1].menuPerfil(peliculas,series);
					break;
				}
				else {
					cout << "Perfil no creado" << endl;
				}
				menuReseatPantalla();
				break;
			case 3:
				system("cls");
				if (perfiles.size() > opcion) {
					perfiles[opcion - 1].menuPerfil(peliculas,series);
					break;
				}
				else {
					cout << "Perfil no creado" << endl;
				}
				menuReseatPantalla();
				break;
			case 4:
				system("cls");
				if (perfiles.size() > opcion) {
					perfiles[opcion - 1].menuPerfil(peliculas,series);
					break;
				}
				else {
					cout << "Perfil no creado" << endl;
				}
				menuReseatPantalla();
				break;
			case 5:
				system("cls");
				if (perfiles.size() > opcion) {
					perfiles[opcion - 1].menuPerfil(peliculas,series);
					break;
				}
				else {
					cout << "Perfil no creado" << endl;
				}
				menuReseatPantalla();
				break;
			case 6:
				system("cls");
				agregarPerfil();
				break;

			case 7:
				system("cls");
				cout << "Retornando al menu principal" << endl;
				cout << "Saliendo del perfil" << endl;
				menuReseatPantalla();
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcion != 7);
	}
	void mostrarPerfiles() {
		// haz el for con un iterador
		for (int j = 0; j < 5; j++) {
			cout << "Perfil: " << j+1 << endl;
			cout << "----------------------\n";
			if (j < perfiles.size())
				cout << perfiles[j].getNombrePerfil() << endl;
			else

				cout << "Perfil no creado" << endl;
			cout << "----------------------\n" << endl;
		}

	}
	//CONTROL DE CUENTAS
	void menuCliente(Lista<Pelicula*>*peliculas, Lista <Serie*>* series, Cola<SolicitudPago*>& cola, vector <Subscripcion>& planes) {
		int opcionMenuCliente;
		do {
			cout << "1.Perfiles" << endl;
			cout << "2.Tarjetas" << endl;
			cout << "3.MisPagos" << endl;
			cout << "4.Subscripcion" << endl;
			cout << "5.Solicitudes de Pago" << endl;
			cout << "6.Privacidad" << endl;
			cout << "7.Salir" << endl;
			do {
				cout << "Ingrese una opcion: ";
				cin >> opcionMenuCliente;
				if (opcionMenuCliente < 1 || opcionMenuCliente > 7) {
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			} while (opcionMenuCliente < 1 || opcionMenuCliente > 7);
			switch (opcionMenuCliente)
			{
			case 1:
				system("cls");
				menuPerfil(peliculas,series);
				break;
			case 2:
				system("cls");

				menuTarjeta();
				break;
			case 3:
				system("cls");
				mostrarPagos();
				menuReseatPantalla();
				break;
			case 4:
				system("cls");
				menuSubscripcion(planes,cola);
				menuReseatPantalla();
				break;
			case 5:
				system("cls");
				mostrarSolicitudes();
				menuReseatPantalla();
				break;
			case 6:
				system("cls");
				menuPrivacidad();
				menuReseatPantalla();
				break;
			case 7:
				system("cls");
				cout << "Saliendo del menu de cliente" << endl;
				menuReseatPantalla();
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			
			}
		
		} while (opcionMenuCliente != 7);

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
	//Control de subscripcion
	void menuSubscripcion(vector <Subscripcion>& planes, Cola<SolicitudPago*>& cola) {
		int opcionMenuSubscripcion;
		do {
			cout << "1.Crear Subscripcion" << endl;
			cout << "2.Mostrar Subscripciones" << endl;
			cout << "3.Salir" << endl;
			do {
				cout << "Ingrese una opcion: ";
				cin >> opcionMenuSubscripcion;
				if (opcionMenuSubscripcion < 1 || opcionMenuSubscripcion > 3) {
					cout << "Opcion invalida. Intente de nuevo." << endl;
				}
			} while (opcionMenuSubscripcion < 1 || opcionMenuSubscripcion > 3);
			switch (opcionMenuSubscripcion)
			{
			case 1:
				system("cls");
				 
				crearSolicitudPago(cola,plan.crearSubscripcion(planes, nombre));
				menuReseatPantalla();
				break;
			case 2:
				system("cls");
				plan.mostrarSubscripcion();
				menuReseatPantalla();
				break;
			case 3:
				system("cls");
				cout << "Saliendo del menu de subscripcion" << endl;
				menuReseatPantalla();
				break;
			default:
				cout << "Opcion invalida" << endl;
				break;
			}
		} while (opcionMenuSubscripcion != 3);
	}
};

