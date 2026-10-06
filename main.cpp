#include <iostream>
#include <vector>

#include "persona.h"

int main(){

    std::vector <Persona> Agenda;

    std::string nombre, tel, curp;
int d, m, a;
char respuesta;

do {
    std::cout << "Nombre: ";
    std::getline(std::cin, nombre);

    std::cout << "Telefono: ";
    std::getline(std::cin, tel);

    std::cout << "CURP: ";
    std::cin >> curp;


    std::cout << "Fecha de nacimiento (dia mes anio): ";
    std::cin >> d >> m >> a;

    Agenda.emplace_back(nombre, tel, curp, d, m, a);

    std::cout<<"Tienes: " edad

    std::cout << "Agregar otra persona? (s/n): ";
    std::cin >> respuesta;
    std::cin.ignore();   // Importante, ver abajo

} while (respuesta == 's' || respuesta == 'S');

std::cout << "Total: " << Agenda.size() << " personas\n";

    return 0;
}
