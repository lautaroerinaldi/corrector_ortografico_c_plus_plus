#include "diccionario.h"
#include <iostream>

/***************************************************************************************/

void eliminardato(palabra * &palabraAeliminar )
{
    delete palabraAeliminar;
};
/***************************************************************************************/
 void  diccionario::recorrer(void (*visitar)(palabra* & actual))
{
    for(int i=0;i<26;i++)
    { if(abc[i])
        abc[i]->inorden(visitar);
    };
};
/***************************************************************************************/
char diccionario::primeraletra(const string & texto)
{
	return this->fil.filtrar(texto)[0];
};

/***************************************************************************************/
palabra* diccionario::estapalabra(const string & texto)
{
	unsigned int pos = primeraletra(texto) - 97;

	if (abc[pos])
	{
	    palabra * aux = new palabra(texto, dic);
	    palabra * resbusqueda= abc[pos]->buscar(aux);
	    delete aux;
		return resbusqueda;
	}
	else
		return NULL;
};

/***************************************************************************************/
void diccionario::agregar(const string & texto)
{
	unsigned int pos = primeraletra(texto) - 97;
	if (!(abc[pos]))
		abc[pos] = new arbolBbinaria <palabra>(new ComparadorArbolAsc<palabra>);

palabra * aux, *ainsertar=new palabra(texto, dic);
aux = abc[pos]->insertar(ainsertar);
if (aux)
{
    delete ainsertar;
    aux->setpond(aux->getpond() + 1);
}
}
/***************************************************************************************/

diccionario::diccionario(const string & primerapalabra):fil("cambios2.rol")
{
	for (int x = 0; x < 26; x++)
		abc[x] = NULL;

	this->agregar(primerapalabra);
};

/***************************************************************************************/

diccionario::~diccionario()
{
	for (int x = 0; x < 26; x++)

		if (abc[x])
		{
			abc[x]->postorden(&eliminardato);
			delete abc[x];
			abc[x] = NULL;
		}

   }
/***************************************************************************************/
