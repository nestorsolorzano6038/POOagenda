#include <iostream>
#include <vector>

#include "persona.h"


using namespace std;

int main(){
    /*vector <Persona> Agenda;

    //Persona nuevaPersona("Pancho","123456789",PONN670945JPG",7,9,2002);

    Agenda.emplace_back("Pancho","123456789","MOLL730608HDF",8,6,1973);

    Agenda.emplace_back();

    //nuevaPersona.setNombre("Paco");

    for(auto const &p : Agenda){
        cout<<p.getNombre()<<endl;
    }
    cin.get();
    */

    vector <Persona> Agenda;

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

    std::cout << "Agregar otra persona? (s/n): ";
    std::cin >> respuesta;
    std::cin.ignore();   // Importante, ver abajo

} while (respuesta == 's' || respuesta == 'S');

std::cout << "Total: " << Agenda.size() << " personas\n";
/*
    vector <Persona> Agenda;

    Persona nuevaPersona()
    cout << nuevaPersona.setNombre()<< endl;

    cout<<"Actualizar telefono";

    for(const auto &t : Agenda){
        cout<<t.getTel()<<endl;
    }
*/
    return 0;
}
