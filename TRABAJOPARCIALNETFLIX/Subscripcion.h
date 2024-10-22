#pragma once

class Subscripcion
{
private:
	int id;
	string nombre;
	string precio;
	bool estadoActivo;

public:
	Subscripcion(int pid = 0, string pnombre = "", string pprecio = "", bool pestadoActivo = false) {
		id = pid;
		nombre = pnombre;
		precio = pprecio;
		estadoActivo = pestadoActivo;
	}
	~Subscripcion() = default;
	//metodos setters y getters
	void setActivo(bool pestadoActivo) {
		this->estadoActivo = pestadoActivo;
	}
	int getId() {
		return id;
	}
	string getNombre() {
		return nombre;
	}
	string getPrecio() {
		return precio;
	}
	bool getActivo() {
		return estadoActivo;
	}
	SolicitudPago* crearSubscripcion(vector <Subscripcion>& planes, string nombreCliente) {	
		cout << "Ingrese el nombre del plan: ";
		cin.ignore();
		getline(cin, nombre);
		string fecha;
		cout << "Ingrese la fecha de hoy: ";
		cin.ignore();
		getline(cin, fecha);

		for (auto& plan : planes) {
			if (plan.getNombre() == nombre) {
				this->id = plan.getId();
				this->nombre = plan.getNombre();
				this->precio = plan.getPrecio();
				this->estadoActivo = plan.getActivo();
				
			}
		}
		cout << "Solicitud de plan creada" << endl;
		SolicitudPago* solicitud =new SolicitudPago (nombreCliente,to_string(rand() % 1000), precio, "Tarjeta",fecha, true, false);
		return solicitud;
	}
	void mostrarSubscripcion() {
		cout << "Id: " << id << endl;
		cout << "Nombre: " << nombre << endl;
		cout << "Precio: " << precio << endl;
		cout << "Estado: " << estadoActivo << endl;
	}



};