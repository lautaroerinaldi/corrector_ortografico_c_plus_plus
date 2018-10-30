#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED
#include "palabra.h"
#include "filtro.h"
#include "arbol\arbol.h"

void eliminardato(palabra * &palabraAeliminar );

class diccionario
{

	private:
		arbolBbinaria<palabra> * abc[26];
		filtro fil;
    public:

		/*
		pre:
		    palabra es un string no vacío.
		post:
		    Si la palabra ya se encontraba en el diccionario, le suma uno a la ponderacion;
		    En caso contrario, la agrega al mismo, creando una nueva instancia
		    de la clase palabra (ponderación = 1).
		*/

		void agregar(const string & texto);

		/*pre:
		post:si esta la palabra devuelve un puntero a la instancia de la clase palabra,
		    en caso contrario devuelve NULL
		*/
		palabra* estapalabra(const string & texto);

		/*
		pre:
		    Que primera palabra sea un string no vacío.
		post:
		    Dicho string va a agregarse al diccionario como una nueva palabra
		    (que va a ser la primera).
		*/
		diccionario(const string & primerapalabra);

		/*
		pre:
		    Ninguna.
		post:
		    Libera los recursos asignados a la instancia de la clase diccionario.
		*/
		~diccionario();

		/*
		pre: recibe string no vacio
		post: devuelve la primer letra del string para ubicarla en el vector de palabras
		*/
		char primeraletra(const string & texto);

		/*
		pre: recibe un metodo para visualizar el dato almacenado
		post: muestra por pantalla los datos almacenados en modo inorden
        */
		void recorrer(void (*visitar)(palabra* & actual));
};

#endif
