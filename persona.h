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
    Fecha fechaNacimiento; // Atributo encapsulado
    std::string tel;
    std::string curp;


    // 4.4 Metodo privado auxiliar para validar la l�gica interna
    bool esFechaValida(int d, int m, int a)const;
    static Fecha obtenerFechaActual();


public:
    // 4.5 Constructores
    Persona();
    Persona(std::string nom, std::string t, std::string c, int d, int m, int a);


    // 4.3 M�todos Getters y Setters
    void setNombre(std::string nom);
    std::string getNombre() const;

    //Actualizar telefono
    bool setNuevoTel(std::string t);
    std::string getNuevoTel() const;


    // Mutador con validacion
    bool setFechaNacimiento(int d, int m, int a);
    Fecha getFechaNacimiento() const;


    // El m�todo estrella: calcula la edad din�micamente
    int getEdad() const;

};


#endif //PERSONA_H_INCLUDED
