#ifndef PALABRA_H_INCLUDED
#define PALABRA_H_INCLUDED

#include <string>

#include "otros.h"

using namespace std;

class palabra
{

		const string pal;
		unsigned int pond;

	public:

		/*
		pre:
		    enunciado es un string no vacío.
		post:
		    Inicializa la instancia con el enunciado y ponderación
		    igual a cero si tipo vale cand, e igual a uno si tipo
		    vale dic.
		*/
		palabra(const string & enunciado, const tipopalabra & tipo);

		/*
		pre:
		    Ninguna.
		post:
		    Libera los recursos asignados a la instancia.
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
		    Devuelve la ponderación de la instancia de la clase palabra.
		*/
		unsigned int getpond() const;

		/*
		pre:
		    ponderación es un entero mayor o igual a cero.
		post:
		    Modifica la ponderación de la instancia de la clase palabra.
		*/
		void setpond(const unsigned int & ponderacion);

};

#endif
