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
		    de candidatos no est� vac�a.
		post:
		    Se encarga de dejar en la lista de candidatos solamente
		    los que est�n en el diccionario, eliminando el resto.
		    A los que est�n, les copia la ponderaci�n.
		*/
		void limpiarlistaydarpond();

	public:

		/*
		pre:
		    Ninguna.
		post:
		    Inicializa la instancia sin ning�n diccionario asociado
		    y sin ning�n texto a corregir.
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
		    ruta no debe estar vac�o, y debe corresponderse con
		    el archivo de TEXTO que va a utilizarse para crearse
		    el diccionario.
		post:
		    Devuelve TRUE si pudo cargar el archivo de texto de la
		    ruta especificada, generando un diccionario ponderado,
		    o si al menos, ya hab�a un diccionario cargado.
		*/
		bool agregarlibro(string ruta);

		/*
		pre:
		    texto no debe estar vac�o, no contiene espacios y est�
		    filtrado.
		post:
		    Genera una lista de sugerencias posibles ordenada por
		    ponderaci�n descendente para una determinada palabra
		    ingresada por el usuario, devolviendo TRUE si la lista
		    generada contiene al menos una sugerencia v�lida (en
		    otras palabras, si no est� vac�a).
		*/
		bool corregirtexto(string texto);

		/*
		pre:
		    La lista de candidatos no est� vac�a, que se sabe cuando se
		    llama a corregirtexto.
		post:
		    Muestra por pantalla las sugerencias para la �ltima palabra
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
		    Devuelve un string que s�lo contiene letras
		    en min�sculas.
		*/
		std::string  filtrar(std::string palAfiltrar);

};

#endif
