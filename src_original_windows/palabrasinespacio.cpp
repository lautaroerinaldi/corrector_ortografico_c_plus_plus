#include "palabrasinespacio.h"

/***************************************************************************************/
palabrasinespacio::palabrasinespacio()
{
	renglon = "";
	posactual = 0;
	unapalabra = "";
};

/***************************************************************************************/
palabrasinespacio::~palabrasinespacio(){};

/***************************************************************************************/
bool palabrasinespacio::esfin()
{
	if (unapalabra == "")
		return true;
	else
		return false;
};

/***************************************************************************************/
string palabrasinespacio::devuelvepalabra()
{
	string vieja = unapalabra;
	string aux = "";
	bool fin = false;

	while ((posactual < renglon.size()) && (!fin))
	{
		if (renglon[posactual] != char(32))
			aux.append(renglon, posactual, 1);
		else
			if (aux != "")
				fin = true;

		posactual++;
	}

	unapalabra = aux;

	return vieja;
};

/***************************************************************************************/
void palabrasinespacio::setrenglon(string texto)
{
	texto.append(" ");
	renglon = texto;
	posactual = 0;
	string aux = "";
	bool fin = !(renglon.size() > 0);

	while ((!fin) && (posactual < renglon.size()))
	{
		if (renglon[posactual] != char(32))
			aux.append(renglon, posactual, 1);
		else
			if (aux != "")
				fin = true;

		posactual++;
	}

	unapalabra = aux;
};
