/**
 * Comparadores.
 **/

#ifndef __COMPARADOR_H__
#define __COMPARADOR_H__
#include "..\palabra.h"
enum ResultadoComparacion
{
	MENOR,
	IGUAL,
	MAYOR,
};

/**
 * Clase abstracta que encapsula la l�gica de comparaci�n utilizada para
 * ordenar las estructuras de datos.
 *
 */

template<class T> class Comparador
{

	public:
		/**
		 * post: devuelve  MAYOR, MENOR o IGUAL de acuerdo a la relaci�n
		 *       existente entre elemento1 y elemento2.
		 *
		 * M�todo abstracto que deber� ser implementado por los descendientes
		 * de Comparador especificando un comportamiento particular.
		 */
		virtual ResultadoComparacion comparar(T elemento1, T elemento2) = 0;
};

/**
 * Implementaci�n del Comparador que utiliza los operadores "==", "<" y ">"
 * estableciendo un orden ascendente.
 *
 */

template<class T> class ComparadorSimpleAscendente : public Comparador<T>
{

	public:
		virtual ResultadoComparacion comparar(T elemento1, T elemento2)
		{

			ResultadoComparacion resultado;

			if (elemento1 == elemento2)
			{

				resultado = IGUAL;

			}
			else
				if (elemento1 > elemento2)
				{

					resultado = MAYOR;

				}
				else
				{

					resultado = MENOR;
				}

			return resultado;
		}
};


/**
 * Implementaci�n del Comparador que utiliza los operadores "==", "<" y ">"
 * estableciendo un orden descendente.
 *
 */

template<class T> class ComparadorSimpleDescendente : public Comparador<T>
{

	public:
		virtual ResultadoComparacion comparar(T elemento1, T elemento2)
		{

			ResultadoComparacion resultado;

			if (elemento1 == elemento2)
			{

				resultado = IGUAL;

			}
			else
				if (elemento1 < elemento2)
				{

					resultado = MAYOR;

				}
				else
				{

					resultado = MENOR;
				}

			return resultado;
		}
};

/**
 * Implementaci�n del Comparador cuyo comportamiento es nulo, al comparar
 * dos elementos cualesquiera devuelve IGUAL.
 *
 */

template<class T> class ComparadorConstante : public Comparador<T>
{

	public:
		virtual ResultadoComparacion comparar(T elemento1, T elemento2)
		{

			return IGUAL;
		}

};

/**
 * Implementaci�n del Comparador que utiliza los operadores "==", "<" y ">"
 * estableciendo un orden ascendente.
 *
 */

class ComparadorPorPalabrasAscendente: public Comparador<palabra*>
{

	public:
		virtual ResultadoComparacion comparar(palabra * elemento1, palabra * elemento2)
		{

			ResultadoComparacion resultado;

			if (elemento1->geten() == elemento2->geten())
			{

				resultado = IGUAL;

			}
			else
				if (elemento1->geten() > elemento2->geten())
				{

					resultado = MAYOR;

				}
				else
				{

					resultado = MENOR;
				}

			return resultado;
		}
};

class ComparadorPorPondDescendente: public Comparador<palabra*>
{

	public:
		virtual ResultadoComparacion comparar(palabra * elemento1, palabra * elemento2)
		{

			ResultadoComparacion resultado;

			if (elemento1->getpond() == elemento2->getpond())
			{

				resultado = IGUAL;

			}
			else
				if (elemento1->getpond() > elemento2->getpond())
				{

					resultado = MENOR;

				}
				else
				{

					resultado = MAYOR;
				}

			return resultado;
		}
};

template<class T> class ComparadorArbolAsc : public Comparador<T>
{

	public:
		virtual ResultadoComparacion comparar(T  elemento1, T  elemento2)
		{


			ResultadoComparacion resultado;

			if (elemento1.geten() == elemento2.geten())
			{

				resultado = IGUAL;

			}
			else
				if (elemento1.geten() > elemento2.geten())
				{

					resultado = MAYOR;

				}
				else
				{

					resultado = MENOR;
				}

			return resultado;
		}

};

#endif
