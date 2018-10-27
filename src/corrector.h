#ifndef CORRECTOR_H_INCLUDED
#define CORRECTOR_H_INCLUDED

#include "diccionario.h"
#include "filtro.h"
#include "ListaCandidato.h"

class corrector
{

		diccionario * pdic;
		ListaCandidato * list;
		filtro filt;

		/*
		pre:
		    Que el diccionario se encuentre cargado y que la lista
		    de candidatos no esté vacía.
		post:
		    Se encarga de dejar en la lista de candidatos solamente
		    los que están en el diccionario, eliminando el resto.
		    A los que están, les copia la ponderación.
		*/
		void limpiarlistaydarpond();

	public:

		/*
		pre:
		    Ninguna.
		post:
		    Inicializa la instancia sin ningún diccionario asociado
		    y sin ningún texto a corregir.
		*/
		corrector();

		/*
		pre:
		    Ninguna.
		post:
		    Libera los recursos asociados a la instancia.
		*/
		~corrector();

		/*
		pre:
		    ruta no debe estar vacío, y debe corresponderse con
		    el archivo de TEXTO que va a utilizarse para crearse
		    el diccionario.
		post:
		    Devuelve TRUE si pudo cargar el archivo de texto de la
		    ruta especificada, generando un diccionario ponderado,
		    o si al menos, ya había un diccionario cargado.
		*/
		bool agregarlibro(string ruta);

		/*
		pre:
		    texto no debe estar vacío, no contiene espacios y está
		    filtrado.
		post:
		    Genera una lista de sugerencias posibles ordenada por
		    ponderación descendente para una determinada palabra
		    ingresada por el usuario, devolviendo TRUE si la lista
		    generada contiene al menos una sugerencia válida (en
		    otras palabras, si no está vacía).
		*/
		bool corregirtexto(string texto);

		/*
		pre:
		    La lista de candidatos no esté vacía, que se sabe cuando se
		    llama a corregirtexto.
		post:
		    Muestra por pantalla las sugerencias para la última palabra
		    corregida, una debajo de la otra.
		*/
		void obtenersugerencias();

		/*
		pre:
		    Ninguna.
		post:
		    Devuelve TRUE si se encuentra un diccionario cargado con,
		    al menos, una palabra.
		*/
		bool haydic();

		/*
		pre:
		    palAfiltrar no contiene espacios.
		post:
		    Devuelve un string que sólo contiene letras
		    en minúsculas.
		*/
		std::string  filtrar(std::string palAfiltrar);

};

#endif
