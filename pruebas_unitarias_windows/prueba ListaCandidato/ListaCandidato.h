#ifndef LISTACANDIDATO_H_INCLUDED
#define LISTACANDIDATO_H_INCLUDED
#include "lista\Lista.h"
#include<string>


class ListaCandidato
{

private:

    Lista<palabra*> *listaCandidatos;
    string enunciado;

    /*
    pre:
        Ninguna.
    post:
        Anexa a la lista todos los candidatos posibles a sugerir que se obtienen
        por el borrado de una letra.
    */
    void borrado();

    /*
    pre:
        Ninguna.
    post:
        Anexa a la lista todos los candidatos posibles a sugerir que se obtienen
        por la inserción de una letra.
    */
    void insercion();
    /*
    pre:
        Ninguna.
    post:
        Anexa a la lista todos los candidatos posibles a sugerir que se obtienen
        por la alteración de una letra.
    */
    void alteracion();

    /*
    pre:
        candidato es un string no vacío.
    post:
        Anexa un nuevo elemento a la lista, con ponderacion 0.
    */
    void agregar(string candidato);

    /*
    pre: lista no vacia

    post:
        remueve los elementos repetidos de la lista
    */
    void  eliminarrepetidos();

public:

    /*
    pre:
        El string palabra no debe estar vacío.
    post:
        Llama a los métodos encargados de generar todos los posibles candidatos,
        por borrado, inserción y alteración de una letra.
    */
    ListaCandidato(string  enuncia);

    /*
    pre:
        Ninguna.
    post:
        Libera los recursos asignados por la instancia de la clase ListaCandidato.
    */
    ~ListaCandidato();

    /*
    pre:
        Lista no vacía.
    post:
        Se emite por pantalla una lista secuencial de todos los candidatos
    */
    void listar();

    /*
     pre:
         Lista no vacía.
     post:
         devuelve la lista de candidatos
     */

    Lista<palabra*> * getlista();

    /*
        pre:
            Lista no vacía.
        post:
            Se encarga de ordenar la lista por ponderación descendente de los mismos.
        */
    void ordenarporponddesc();

};
#endif // LISTACANDIDATO_H_INCLUDED
