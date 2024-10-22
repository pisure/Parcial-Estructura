#pragma once
#include "Tools.h"

int IniciarSesion() {
		int opcionIniciosSesion;

		cout << "Bienvenido a Netflix" << endl;
		cout << "Seleccione una opcion para iniciar sesion" << endl;
		cout << "1. Empleado" << endl;
		cout << "2. Cliente" << endl;
		cout << "3. Salir" << endl;

		do {
			cout << "Ingrese una opcion: ";
			cin >> opcionIniciosSesion;
			if (opcionIniciosSesion < 1 || opcionIniciosSesion > 3) {
				cout << "Opcion invalida. Intente de nuevo." << endl;
			}
		} while (opcionIniciosSesion < 1 || opcionIniciosSesion > 3);

		return opcionIniciosSesion;
	
}
void menuReseatPantalla() {

	system("pause");
	system("cls");
}
