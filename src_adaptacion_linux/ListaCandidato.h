#ifndef LISTACANDIDATO_H_INCLUDED
#define LISTACANDIDATO_H_INCLUDED

#include <string>

#include "Lista.h"

class ListaCandidato
{

		Lista<palabra*> * listaCandidatos;
		string enunciado;

		/*
		pre:
		    Ninguna.
		post:
		    Anexa a la lista todos los candidatos posibles a sugerir
		    que se obtienen por el borrado de una letra.
		*/
		void borrado();

		/*
		pre:
		    Ninguna.
		post:
		    Anexa a la lista todos los candidatos posibles a sugerir
		    que se obtienen por la inserción de una letra.
		*/
		void insercion();

		/*
		pre:
		    Ninguna.
		post:
		    Anexa a la lista todos los candidatos posibles a sugerir
		    que se obtienen por la alteración de una letra.
		*/
		void alteracion();

		/*
		pre:
		    candidato no está vacío.
		post:
		    Anexa un nuevo elemento a la lista, con ponderacion 0.
		*/
		void agregar(string candidato);

		/*
		pre:
			listaCandidatos no está vacia.
		post:
		    Remueve los elementos repetidos de la lista.
		*/
		void  eliminarrepetidos();

	public:

		/*
		pre:
		    enuncia no debe estar vacío y está previamente filtrado.
		post:
		    Llama a los métodos encargados de generar todos los
		    posibles candidatos, por borrado, inserción y alteración
		    de una letra.
		*/
		ListaCandidato(string enuncia);

		/*
		pre:
		    Ninguna.
		post:
		    Libera los recursos asignados por la instancia de la
		    clase ListaCandidato.
		*/
		~ListaCandidato();

		/*
		pre:
		    La lista de candidatos no está vacía.
		post:
		    Se emite por pantalla una lista secuencial de todos los
		    candidatos uno debajo del otro.
		*/
		void listar();

		/*
		 pre:
		     Lista no vacía.
		 post:
		     Devuelve la lista de candidatos, eliminando o modificando
		     uno de ella, se modifica en ListaCandidato.
		 */
		Lista<palabra*> * getlista();

		/*
		    pre:
		        Lista no vacía, y previamente se les asignó ponderación
		        a todos los elementos de ella.
		    post:
		        Se encarga de ordenar la lista por ponderación descendente
		        de los mismos.
		    */
		void ordenarporponddesc();

};

#endif // LISTACANDIDATO_H_INCLUDED
