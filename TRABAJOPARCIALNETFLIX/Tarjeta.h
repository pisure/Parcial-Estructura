class Tarjeta {
private:
    string numero;
    string titular;
    string fechaExpiracion;
    string cvv;

public:
    Tarjeta(string numero, string titular, string fechaExpiracion, string cvv) :
        numero(numero), titular(titular), fechaExpiracion(fechaExpiracion), cvv(cvv) {}

    string getNumero() const { return numero; }
    string getTitular() const { return titular; }
    string getFechaExpiracion() const { return fechaExpiracion; }
    string getCvv() const { return cvv; }

    void mostrarDatos() {
        cout << "Numero: " << numero << "\nTitular: " << titular 
             << "\nFecha de Expiracion: " << fechaExpiracion << endl;
    }
};
