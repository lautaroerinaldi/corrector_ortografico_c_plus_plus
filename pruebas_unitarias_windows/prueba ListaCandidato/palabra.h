#ifndef PALABRA_H_INCLUDED
#define PALABRA_H_INCLUDED
#include "otros.h"
#include <string>

using namespace std;

class palabra
{

private:

    const string pal;
    unsigned int pond;

public:

    /*
    pre:
        enunciado es un string no vac�o.
    post:
        Crea una instancia de la clase palabra, inicializ�ndola con el string
        enunciado y ponderaci�n igual a cero si tipo vale candidato, e igual a
        uno si tipo vale diccionario.
    */
    palabra (const string & enunciado, const tipopalabra & tipo);

    /*
    pre:
        Ninguna.
    post:
        Libera los recursos asignados por la instancia de la clase palabra.
    */
    ~palabra();

    /*
    pre:
        Ninguna.
    post:
        Devuelve el enunciado de la instancia de la clase palabra.
    */
    string geten() const;

    /*
    pre:
        Ninguna.
    post:
        Devuelve la ponderaci�n de la instancia de la clase palabra.
    */
    unsigned int getpond() const;

    /*
    pre:
        ponderaci�n es un entero mayor o igual a cero.
    post:
        Modifica la ponderaci�n de la instancia de la clase palabra.
    */
    void setpond(const unsigned int & ponderacion);
};
#endif
