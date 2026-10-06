#include "persona.h"
#include <ctime>   // Libreria para obtener el tiempo real del sistema
#include <iostream>
#include <cctype>


// Constructor sin parametros (Valores por defecto seguros)
Persona::Persona() {
    nombre = "Sin Nombre";
    fechaNacimiento = {1, 1, 2000};
    tel="0000000000";
    curp="Sin Curp";
}

// Constructor parametrizado utilizando el setter para garantizar integridad
Persona::Persona(std::string nom, std::string t, std::string c,  int d, int m, int a) {
    nombre = nom;
    tel = t;
    curp = c;
    // Si la fecha es invalida, se fuerza un estado consistente por defecto
    if (!setFechaNacimiento(d, m, a)) {
        fechaNacimiento = {1, 1, 2000};
    }
}

void Persona::setNombre(std::string nom) { nombre = nom; }
std::string Persona::getNombre() const { return nombre; }
Fecha Persona::getFechaNacimiento() const { return fechaNacimiento; }



bool Persona::setTel(std::string t) {
    if (t.empty()) return false;
    tel = t;
    return true;
}
std::string Persona::getTel() const { return tel; }

bool Persona::esTelValido(const std::string &tel) {
    if (tel.size() != 10){
        std::cerr << "Error: Numero telefonico invalido\n";
        return false;
        }

    for (int i=0;i<=9;i++){
        if (!isdigit(tel[i])){
            std::cerr << "Error: Numero telefonico invalido\n";
            return false;
            }
        }
    return true;
    }

    std::cerr << "Error: Fecha numero telefonico invalido\n";
    return false; // Rechazado
}


// Proteccion de informacion mediante filtrado en el Setter
bool Persona::setFechaNacimiento(int d, int m, int a) {
    if (esFechaValida(d, m, a)) {
        fechaNacimiento.dia = d;
        fechaNacimiento.mes = m;
        fechaNacimiento.anio = a;
        return true; // Asignacion exitosa
    }
    std::cerr << "Error: Fecha de nacimiento invalida.\n";
    return false; // Rechazado
}

// Obtiene la fecha actual para validarla despues
Fecha Persona::obtenerFechaActual() {
    std::time_t tiempoActual = std::time(nullptr);
    std::tm* ahora = std::localtime(&tiempoActual);

    Fecha hoy;
    hoy.dia  = ahora->tm_mday;
    hoy.mes  = ahora->tm_mon + 1;      // tm_mon va de 0 a 11
    hoy.anio = ahora->tm_year + 1900;  // tm_year cuenta desde 1900

    return hoy;
}

// Metodo Privado: El usuario no necesita saber COMO se valida, solo que funciona
bool Persona::esFechaValida(int d, int m, int a) const {
    if (a < 1900 || m < 1 || m > 12 || d < 1) return false;


    int diasPorMes[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };


    // Validar año bisiesto para Febrero
    if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0)) {
        diasPorMes[1] = 29;
    }

    if (d > diasPorMes[m - 1]) return false;

    // Valida que no sea mayor a la fecha actual
     Fecha hoy = obtenerFechaActual();

    if (a > hoy.anio) return false;
    if (a == hoy.anio && m > hoy.mes) return false;
    if (a == hoy.anio && m == hoy.mes && d > hoy.dia) return false;

    return true;
}

// Calculo dinamico de la edad usando <ctime>
int Persona::getEdad() const {

    Fecha hoy = obtenerFechaActual();

    int edad = hoy.anio - fechaNacimiento.anio;

    // Ajuste si aun no ha pasado su cumpleaños este año
    if (hoy.mes < fechaNacimiento.mes ||
       (hoy.mes == fechaNacimiento.mes && hoy.dia < fechaNacimiento.dia)) {
        edad--;
    }


    return edad;
}

