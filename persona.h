#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

#include <string>

struct Fecha {
    int dia;
    int mes;
    int anio;
};


class Persona {
private:
    std::string nombre;
    Fecha fechaNacimiento; //Atributo el cual con tiene un struct de datos
    std::string tel;
    std::string curp;


    //Metodo auxiliar para validar la logica
    bool esFechaValida(int d, int m, int a)const;
    static Fecha obtenerFechaActual();

    static bool esTelValido(const std::string &tel);


public:
    //Contructor sin parametros y con parametros
    Persona();
    Persona(std::string nom, std::string t, std::string c, int d, int m, int a);


    //Metodos getter y setters
    void setNombre(std::string nom);
    std::string getNombre() const;

    //Actualizar telefono y dar 3 intentos
    bool setTel(std::string t);
    std::string getTel() const;


    // Mutador con validacion de la faha
    bool setFechaNacimiento(int d, int m, int a);
    Fecha getFechaNacimiento() const;


    //Metodo para el calculo de la edad
    int getEdad() const;

};


#endif //PERSONA_H_INCLUDED
