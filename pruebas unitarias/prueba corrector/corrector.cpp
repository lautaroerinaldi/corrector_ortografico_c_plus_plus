#include <string>
#include <iostream>

#include "corrector.h"
#include "palabrasinespacio.h"

#include "archivo\archivoTexto.h"

/***************************************************************************************/
corrector::corrector(): filt("cambios.rol")
{
	list = NULL;
	pdic = NULL;
};

/***************************************************************************************/
corrector::~corrector()
{
	if (list)
		delete list;

	if (pdic)
		delete pdic;

	list = NULL;

	pdic = NULL;
};

/***************************************************************************************/
std::string corrector::filtrar(std::string palAfiltrar)
{
	return this->filt.filtrar(palAfiltrar);
};

/***************************************************************************************/
bool corrector::agregarlibro(std::string ruta)
{
	ArchivoTexto miarchivo(ruta);
	std::string linea;
	palabrasinespacio pal;
	std::string aux;

	while (miarchivo.leerLinea(linea))
	{
		pal.setrenglon(linea);

		while (!pal.esfin())
		{

			aux = pal.devuelvepalabra();
			aux = this->filtrar(aux);

			if (aux != "")
				if (!pdic)
					pdic = new diccionario(aux);
				else
					pdic->agregar(aux);
		}
	}

	if (!pdic)
		return false;

	return true;
};

/***************************************************************************************/
void corrector::limpiarlistaydarpond()
{
	Lista<palabra*> *ListaCandidatos = this->list->getlista();

	IteradorLista<palabra*> miiterador = ListaCandidatos->iterador();

	palabra* ppal;
	palabra* ppal2;

	while (miiterador.tieneSiguiente())
	{
		ppal = miiterador.get();

		ppal2 = pdic->estapalabra(ppal->geten());

		if (ppal2)
		{
			ppal->setpond(ppal2->getpond());
			miiterador.siguiente();
		}
		else
			delete miiterador.remover();
	}
};

/***************************************************************************************/
bool corrector::corregirtexto(string texto)
{
	if (list)
		delete list;

	this->list = new ListaCandidato(texto);

	this->limpiarlistaydarpond();

	list->ordenarporponddesc();

	if (list)
		return true;

	return false;
};

/***************************************************************************************/
void corrector::obtenersugerencias()
{
	if (list)
		list->listar();
};

/***************************************************************************************/
bool corrector::haydic()
{
	return pdic;
};
