#ifndef DICCIONARIO_H_INCLUDED
#define DICCIONARIO_H_INCLUDED

#include "palabra.h"
#include "filtro.h"
#include "arbol\arbol.h"

void eliminardato(palabra * &palabraAeliminar);

class diccionario
{

		arbolBbinaria<palabra> * abc[26];
		filtro fil;

		/*
		pre:
			texto est� filtrado y no vacio
		post:
			devuelve la primer letra del string para ubicarla
			en el vector de palabras
		*/
		char primeraletra(const string & texto);

	public:

		/*
		pre:
		    texto est� filtrado y no est� vac�o.
		post:
		    Si la palabra ya se encontraba en el diccionario,
		    le suma uno a la ponderacion; En caso contrario,
		    la agrega al mismo, creando una nueva instancia
		    de la clase palabra (ponderaci�n = 1).
		*/
		void agregar(const string & texto);

		/*
			pre:
				texto est� filtrado y no est� vac�o.
			post:
				si esta la palabra devuelve un puntero a la
				instancia de la clase palabra, en caso contrario
				devuelve NULL.
		*/
		palabra* estapalabra(const string & texto);

		/*
		pre:
			primerapalabra esta filtrado y no est� vac�o.
		post:
		    primerapalabra va a agregarse al diccionario como
		    una nueva palabra (que va a ser la primera).
		*/
		diccionario(const string & primerapalabra);

		/*
		pre:
		    Ninguna.
		post:
		    Libera los recursos asignados a la instancia de la
		    clase diccionario.
		*/
		~diccionario();

};

#endif
