#ifndef FILTRO_H_INCLUDED
#define FILTRO_H_INCLUDED

#include <string>
using namespace std;

class filtro
{
char letrasbien[256];

public:

     /*pre:
     post:  asigna los caracteres que van a ser modificados
    */
    filtro(string ruta);

    /*pre: ninguna
    post:  libera los recursos asociados a la instancia
    */
    ~filtro();

    /*
    pre:
        palAfiltrar debe ser un string que no contenga espacios
    post:
        devuelve un string que solo contiene letras
    */
    string filtrar(string palAfiltrar);
};

#endif

