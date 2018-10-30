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
		    que se obtienen por la inserci�n de una letra.
		*/
		void insercion();

		/*
		pre:
		    Ninguna.
		post:
		    Anexa a la lista todos los candidatos posibles a sugerir
		    que se obtienen por la alteraci�n de una letra.
		*/
		void alteracion();

		/*
		pre:
		    candidato no est� vac�o.
		post:
		    Anexa un nuevo elemento a la lista, con ponderacion 0.
		*/
		void agregar(string candidato);

		/*
		pre:
			listaCandidatos no est� vacia.
		post:
		    Remueve los elementos repetidos de la lista.
		*/
		void  eliminarrepetidos();

	public:

		/*
		pre:
		    enuncia no debe estar vac�o y est� previamente filtrado.
		post:
		    Llama a los m�todos encargados de generar todos los
		    posibles candidatos, por borrado, inserci�n y alteraci�n
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
		    La lista de candidatos no est� vac�a.
		post:
		    Se emite por pantalla una lista secuencial de todos los
		    candidatos uno debajo del otro.
		*/
		void listar();

		/*
		 pre:
		     Lista no vac�a.
		 post:
		     Devuelve la lista de candidatos, eliminando o modificando
		     uno de ella, se modifica en ListaCandidato.
		 */
		Lista<palabra*> * getlista();

		/*
		    pre:
		        Lista no vac�a, y previamente se les asign� ponderaci�n
		        a todos los elementos de ella.
		    post:
		        Se encarga de ordenar la lista por ponderaci�n descendente
		        de los mismos.
		    */
		void ordenarporponddesc();

};

#endif // LISTACANDIDATO_H_INCLUDED
