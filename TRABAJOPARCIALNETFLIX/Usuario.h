#pragma once
#include "Tools.h"
#include "menus.h"

class Usuario
{
protected:
	string nombre;
	string apellido;
	string fechaNacimiento;
	string pais;

	
	//cuenta
	string correo;
	string contrasena;
	
	//informacion
	string direccion;
	
	string celular;
	string sexo;
	
	
public:
	Usuario(string nombre, string apellido, string fechaNacimiento, string pais, string correo, 
		string contrasena, string direccion, string telefono, string celular, string sexo) :
		nombre(nombre), apellido(apellido), fechaNacimiento(fechaNacimiento), pais(pais), 
		correo(correo), contrasena(contrasena), direccion(direccion), celular(celular), sexo(sexo) {}
	
	~Usuario() = default;

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
		cout << "--------------------------------" << endl;
		menuReseatPantalla();
	}
	void cambiarNombre() {
		string nuevoNombre;
		cout << "Ingrese el nuevo nombre: ";
		cin.ignore();
		getline(cin, nuevoNombre);
		nombre = nuevoNombre;
		string nuevoApellido;
		cout << "Ingrese el nuevo apellido: ";
		cin.ignore();
		getline(cin, nuevoApellido);
		cout << "Nombre cambiado correctamente." << endl;
		menuReseatPantalla();
	}
	void cambiarCorreo() {
		string nuevoCorreo;
		cout << "Ingrese el nuevo correo: ";
		cin.ignore();
		getline(cin, nuevoCorreo);
		correo = nuevoCorreo;
		cout << "Correo cambiado correctamente." << endl;
		menuReseatPantalla();
	}
	void cambiarDireccion() {
		string nuevaDireccion;
		cout << "Ingrese la nueva direccion: ";
		cin.ignore();
		getline(cin, nuevaDireccion);
		direccion = nuevaDireccion;
		cout << "Direccion cambiada correctamente." << endl;
		menuReseatPantalla();
	}
	void cambiarCelular() {
		string nuevoCelular;
		cout << "Ingrese el nuevo celular: ";
		cin.ignore();
		getline(cin, nuevoCelular);
		celular = nuevoCelular;
		cout << "Celular cambiado correctamente." << endl;
		menuReseatPantalla();
	}
	void cambiarContrasena() {
		string nuevaContrasena;
		cout << "Ingrese la nueva contrasena: ";
		cin.ignore();
		getline(cin, nuevaContrasena);
		contrasena = nuevaContrasena;
		cout << "Contrasena cambiada correctamente." << endl;
		menuReseatPantalla();
	}

};
