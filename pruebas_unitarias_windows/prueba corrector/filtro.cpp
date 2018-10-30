#include <string>

#include "filtro.h"

#include "archivo\archivoTexto.h"

using namespace std;
/***************************************************************************************/
filtro::filtro(string ruta)
{
	string mal;
	string bien;

	unsigned short int posactual = 0;
	ArchivoTexto letras(ruta);

	letras.leerLinea(mal);
	letras.leerLinea(bien);

	for (int i = 0; i < 256; i++)
		if (((i >= 65) && (i <= 90)) || ((i >= 97) && (i <= 122)))
			letrasbien[i] = tolower(i);
		else
			letrasbien[i] = 0;

	while (posactual < mal.size())
	{
		letrasbien[mal[posactual] + 256] = bien[posactual];
		posactual++;
	}
};

/***************************************************************************************/
filtro::~filtro(){};

/***************************************************************************************/
string filtro::filtrar(string palAfiltrar)
{
	string caracter;
	string palabravalida = "";
	int ultimo = 0;

	for (unsigned int i = 0; i < palAfiltrar.size(); i++)
	{
		ultimo = palAfiltrar[i];

		if (ultimo < 0)
			ultimo += 256;

		caracter = letrasbien[ultimo];

		if (caracter[0] != (char)0)
			palabravalida.append(caracter);
	}

	return palabravalida;
};
