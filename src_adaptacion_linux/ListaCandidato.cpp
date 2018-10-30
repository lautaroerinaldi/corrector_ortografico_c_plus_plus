#include <iostream>

#include "ListaCandidato.h"
#include "palabra.h"

/***************************************************************************************/
void ListaCandidato::agregar(string candidato)
{
	this->listaCandidatos->agregar(new palabra(candidato, cand));
}

/***************************************************************************************/
void ListaCandidato::borrado()
{
	string auxiliar = this->enunciado;

	if (auxiliar.length() > 1)
	{
		for (unsigned int contador = 0;contador < auxiliar.length();contador++)
		{
			auxiliar.erase(contador, 1);
			this->agregar(auxiliar);
			auxiliar = this->enunciado;
		}
	}
}

/***************************************************************************************/
void ListaCandidato::alteracion()
{
	string auxiliar = this->enunciado;

	for (unsigned int contador = 0;contador < auxiliar.length();contador++)
	{
		for (char letra = 'a';(int)letra < 123;(int)letra++)
		{
			string aux;
			aux = letra;
			auxiliar.replace(contador, 1, aux);
			this->agregar(auxiliar);
			auxiliar = this->enunciado;
		}
	}
}

/***************************************************************************************/
void ListaCandidato::insercion()
{
	string auxiliar = this->enunciado;

	for (unsigned int contador = 0; contador <= auxiliar.length();contador++)
	{
		for (char letra = 'a';(int)letra < 123;letra++)
		{
			string aux;
			aux = letra;
			auxiliar.insert(contador, aux);
			this->agregar(auxiliar);
			auxiliar = this->enunciado;
		}
	}
}


/***************************************************************************************/
void ListaCandidato::listar()
{
	int a = 0;

	if (listaCandidatos)

	{
		IteradorLista <palabra*> miiterador = this->listaCandidatos->iterador();

		while (miiterador.tieneSiguiente() && (a < 5))

		{

			std::cout << miiterador.get()->geten() << std::endl;

			miiterador.siguiente();
			a++;

		}

	}
	else
		std::cout << "No hay sugerencias para la palabra." << std::endl;
}

/***************************************************************************************/
ListaCandidato::ListaCandidato(string enuncia)
{
	this->listaCandidatos = new Lista<palabra*>;
	this->enunciado = enuncia;
	this->borrado();
	this->alteracion();
	this->insercion();
}

/***************************************************************************************/
ListaCandidato::~ListaCandidato()
{
	if (listaCandidatos)
	{
		IteradorLista<palabra*> miterador = listaCandidatos->iterador();

		while (miterador.tieneSiguiente()){
			delete miterador.siguiente();
		}

		delete listaCandidatos;

		listaCandidatos = NULL;
	}
}

/***************************************************************************************/
void  ListaCandidato::eliminarrepetidos()
{
	if (listaCandidatos)

	{
		IteradorLista <palabra*> miiterador = listaCandidatos->iterador();

		palabra *mipalabra;

		while (miiterador.tieneSiguiente())
		{
			mipalabra = miiterador.siguiente();

			if (miiterador.tieneSiguiente())
				if (mipalabra->geten() == miiterador.get()->geten())
				{
					delete miiterador.remover();
					miiterador.anterior();
				}
		}
	}
}

/***************************************************************************************/
void ListaCandidato::ordenarporponddesc()
{
	Lista<palabra*> *minuevalista;
	minuevalista = new Lista<palabra*>(new ComparadorPorPondDescendente);
	IteradorLista <palabra*> miiterador = this->listaCandidatos->iterador();

	while (miiterador.tieneSiguiente())
		minuevalista->agregar(miiterador.siguiente());

	delete listaCandidatos;

	listaCandidatos = (minuevalista->tamanio() != 0) ? minuevalista : NULL;

	if (minuevalista->tamanio() == 0)
		delete minuevalista;

	this->eliminarrepetidos();
}

/***************************************************************************************/
Lista<palabra*>* ListaCandidato::getlista()
{
	return listaCandidatos;
}
