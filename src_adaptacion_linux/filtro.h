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
			caracteres en mayúsculas tildados por los que les
			corresponden en minúsculas (también tildados).
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
		    Devuelve un string que sólo contiene letras,
		    eliminando los demás caracteres de palAfiltrar.
		    Cambia todas las mayúscular por minúsculas.
		*/
		string filtrar(string palAfiltrar);

};

#endif

