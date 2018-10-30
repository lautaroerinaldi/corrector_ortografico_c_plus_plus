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
        por la inserci�n de una letra.
    */
    void insercion();
    /*
    pre:
        Ninguna.
    post:
        Anexa a la lista todos los candidatos posibles a sugerir que se obtienen
        por la alteraci�n de una letra.
    */
    void alteracion();

    /*
    pre:
        candidato es un string no vac�o.
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
        El string palabra no debe estar vac�o.
    post:
        Llama a los m�todos encargados de generar todos los posibles candidatos,
        por borrado, inserci�n y alteraci�n de una letra.
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
        Lista no vac�a.
    post:
        Se emite por pantalla una lista secuencial de todos los candidatos
    */
    void listar();

    /*
     pre:
         Lista no vac�a.
     post:
         devuelve la lista de candidatos
     */

    Lista<palabra*> * getlista();

    /*
        pre:
            Lista no vac�a.
        post:
            Se encarga de ordenar la lista por ponderaci�n descendente de los mismos.
        */
    void ordenarporponddesc();

};
#endif // LISTACANDIDATO_H_INCLUDED
