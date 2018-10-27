#ifndef PALABRASINESPACIO_H_INCLUDED
#define PALABRASINESPACIO_H_INCLUDED

#include <string>

using namespace std;

class palabrasinespacio
{

		string renglon;
		unsigned int posactual;
		string unapalabra;

	public:

		/*
		pre:
			Ninguna.
		post:
			Devuelve true si no hay m�s palabras para devolver.
		*/
		bool esfin();

		/*
		pre:
			Previamente se estableci� un rengl�n y no es fin.
		post:
			Devuelve una palabra del rengl�n, y avanza hacia
			la pr�xima palabra (para no devolver dos veces la
			misma).
		*/
		string devuelvepalabra();

		/*
		pre:
			Ninguna.
		post:
			Asigna un rengl�n en blanco. Hasta que no se establezca
			un rengl�n ser� fin y no se podr�n devolver palabras.
		*/
		palabrasinespacio();

		/*
		pre:
			Ninguna.
		post:
			Libera los recursos asociados a la instancia.
		*/
		~palabrasinespacio();

		/*
		pre:
			Ninguna.
		post:
			Establece un rengl�n y si este contiene cadenas
			de caracteres que no sean todos espacios, permite
			comenzar a devolver palabras.
		*/
		void setrenglon(string texto);

};

#endif
