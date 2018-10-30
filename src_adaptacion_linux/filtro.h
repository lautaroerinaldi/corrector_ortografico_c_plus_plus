#ifndef FILTRO_H_INCLUDED
#define FILTRO_H_INCLUDED

using namespace std;

#include <string>

class filtro
{

		char letrasbien[256];

	public:

		/*
		pre:
			Ruta vale 'cambios.rol' si se desean cambiar los
			caracteres en may�sculas tildados por los que les
			corresponden en min�sculas (tambi�n tildados).
		post:
			Asigna los caracteres que van a ser modificados.
		*/
		filtro(string ruta);

		/*
		pre:
			Ninguna.
		post:
			Libera los recursos asociados a la instancia.
		*/
		~filtro();

		/*
		pre:
		    palAfiltrar no debe contener espacios.
		post:
		    Devuelve un string que s�lo contiene letras,
		    eliminando los dem�s caracteres de palAfiltrar.
		    Cambia todas las may�scular por min�sculas.
		*/
		string filtrar(string palAfiltrar);

};

#endif

