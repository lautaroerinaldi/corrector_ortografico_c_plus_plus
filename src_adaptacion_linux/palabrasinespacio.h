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
			Devuelve true si no hay más palabras para devolver.
		*/
		bool esfin();

		/*
		pre:
			Previamente se estableció un renglón y no es fin.
		post:
			Devuelve una palabra del renglón, y avanza hacia
			la próxima palabra (para no devolver dos veces la
			misma).
		*/
		string devuelvepalabra();

		/*
		pre:
			Ninguna.
		post:
			Asigna un renglón en blanco. Hasta que no se establezca
			un renglón será fin y no se podrán devolver palabras.
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
			Establece un renglón y si este contiene cadenas
			de caracteres que no sean todos espacios, permite
			comenzar a devolver palabras.
		*/
		void setrenglon(string texto);

};

#endif
