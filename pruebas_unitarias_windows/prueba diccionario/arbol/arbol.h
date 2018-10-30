#ifndef _ARBOLBBINARIA_H_INCLUDED
#define _ARBOLBBINARIA_H_INCLUDED

#include <iostream>

#include "..\Comparador.h"
#include "nodo.h"

enum enumerado
{
	DER = 0,
	IZQ = 1,
	VACIO = 2
};

template<class T>
class arbolBbinaria
{

	public:

		/*
		pre:
			Ninguna.
		post:
			Devuelve un puntero al nodo raíz del árbol.
		*/
		nodo<T>* getraiz()
		{
			return this->raiz;
		}

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Cambia el nodo raíz del árbol por nuevaraiz.
		*/
		void setraiz(nodo<T>* nuevaraiz)
		{
			this->raiz = nuevaraiz;
		}

/****************************************************************************/
		/*
		pre:
			Ninguna.
		post:
			Se instancia un árbol vacío (con raíz nula) y con
			comparador, que debe corresponderse con el tipo
			de nodo que se esté utilizando.
		*/
		arbolBbinaria(Comparador<T> * comparador)
		{
			this->raiz = NULL;
			this->comparador = comparador;
		};

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Libera los recursos asociados a la instancia,
			eliminando todos los nodos que contiene el árbol
			(los objetos contenidos por los nodos NO).
		*/
		~arbolBbinaria()
		{
			vaciarArbol(this->getraiz());

			if (this->comparador)
				delete comparador;
		}

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Si el dato ya estaba en el árbol, se retorna un puntero al
			dato almacenado en el mismo, sino se agrega el dato en un
			nuevo nodo y se retorna NULL.
		*/
		T* insertar(T *  dato)
		{
			nodo<T> *anterior = NULL;
			enumerado a = VACIO;

			if (this->raiz)
				return insertardato(this->raiz , dato, anterior, a);
			else
				this->raiz = new nodo <T> (dato);

			return NULL;
		}

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Si datoabuscar se encuentra en el árbol, se devuelve un
			puntero al dato almacenado en el mismo, sino devuelve NULL.
		*/
		T * buscar(T * datoAbuscar) const
		{
			return buscardato(this->raiz , datoAbuscar);
		};

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Recorre los elementos del árbol en INFIX y llama a la función
			visitar con cada uno de los datos almacenados.
			(los datos se van pasando ordenados según el comparador que se
			utilizó para insertarlos).
		*/
		void inorden(void (*visitar)(T *& actual))
		{
			this->inord(this->getraiz(), visitar);
		};

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Recorre los elementos del árbol en PREFIX y llama a la función
			visitar con cada uno de los datos almacenados.
		*/
		void preorden(void (*visitar)(T* & actual))
		{
			this->preord(this->getraiz(), visitar);
		};

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Recorre los elementos del árbol en POSTFIX y llama a la función
			visitar con cada uno de los datos almacenados.
		*/
		void postorden(void (*visitar)(T* & actual))
		{
			this->postord(this->getraiz(), visitar);
		};

/****************************************************************************/

		/*
		pre:
			El dato se encuentra en el árbol.
		post:
			Elimina el dato del árbol, sin perder los datos almacenados
			en sus subárboles.
		*/
		bool eliminarDato(T* dato, nodo<T>* nodoActual)
		{
			enumerado en = VACIO;
			nodo<T>* nodoAnterior = nodoActual;
			bool esta = false;

			do
				if (this->comparador->comparar(*nodoActual->getinfo(), *dato) == IGUAL)
				{
					esta = true;

					if (!nodoActual->getizquierda() && !nodoActual->getderecha())
						eliminarHoja(nodoActual, nodoAnterior, en);
					else
						if (!nodoActual->getizquierda() || !nodoActual->getderecha())
							eliminarHijo(nodoActual, nodoAnterior, en);
						else
							eliminar2Hijo(nodoActual, nodoAnterior, en);
				}
				else
				{
					if (this->comparador->comparar(*nodoActual->getinfo(), *dato) == MAYOR)
					{
						nodoAnterior = nodoActual;
						nodoActual = nodoActual->getizquierda();
						en = IZQ;
					}
					else
					{
						nodoAnterior = nodoActual;
						nodoActual = nodoActual->getderecha();
						en = DER;
					}
				}

			while (!esta);

			return esta;
		}

/****************************************************************************/

	private:

		nodo<T>* raiz;
		Comparador<T> * comparador;

/****************************************************************************/
		void inord(nodo<T>*n, void (*visitar)(T *& actual))
		{
			if (n)
			{
				inord(n->getizquierda(), visitar);
				visitar(n->getinfo());
				inord(n->getderecha(), visitar);
			}
		};

/****************************************************************************/
		void preord(nodo<T>*n, void (*visitar)(T *& actual))
		{
			if (n)
			{
				visitar(n->getinfo());
				preord(n->getizquierda(), visitar);
				preord(n->getderecha(), visitar);
			}
		};

/****************************************************************************/
		void postord(nodo<T>*n, void (*visitar)(T *& actual))
		{
			if (n)
			{
				postord(n->getizquierda(), visitar);
				postord(n->getderecha(), visitar);
				visitar(n->getinfo());
			}
		}

/****************************************************************************/
		/*
		pre:
            Ninguna.
        post:
            Elimina todos los nodos correspondientes al árbol
            que que tiene como raíz a n.
        */
		void vaciarArbol(nodo<T>*n)
		{
			if (n)
			{
				vaciarArbol(n->getizquierda());
				vaciarArbol(n->getderecha());
				delete n;
			}

			this->setraiz(NULL);
		}

/****************************************************************************/
		T * insertardato(nodo<T> *nodoactual , T *  dato , nodo<T> *nodoanterior, enumerado en)
		{
			if (nodoactual)
			{
				if (this->comparador->comparar(* (nodoactual->getinfo()), *dato) == MAYOR)
					return  insertardato(nodoactual->getizquierda(), dato, nodoactual, IZQ);
				else
					if (this->comparador->comparar(*nodoactual->getinfo(), *dato) == MENOR)
						return  insertardato(nodoactual->getderecha(), dato, nodoactual, DER);
					else
						return nodoactual->getinfo();;
			}
			else
			{
				nodoactual = new nodo<T> (dato);

				if (en == DER)
					nodoanterior->setderecha(nodoactual);
				else
					if (en == IZQ)
						nodoanterior->setizquierda(nodoactual);

				return NULL;
			}
		};

/****************************************************************************/
		T * buscardato(nodo<T> * nodoactual , T * datoAbuscar) const
		{
			if (nodoactual)
			{
				if (this->comparador->comparar(*nodoactual->getinfo(), *datoAbuscar) == MAYOR)
					return  buscardato(nodoactual->getizquierda(), datoAbuscar);
				else
					if (this->comparador->comparar(*nodoactual->getinfo(), *datoAbuscar) == MENOR)
						return  buscardato(nodoactual->getderecha(), datoAbuscar);
					else
						return  nodoactual->getinfo();
			}

			return NULL;
		}

/****************************************************************************/
		void eliminarHoja(nodo<T>* nodoAeliminar, nodo<T>* nodoAnterior, enumerado vinePorAca)
		{
			if (vinePorAca == DER)
				nodoAnterior->setderecha(NULL);
			else
				if (vinePorAca == IZQ)
					nodoAnterior->setizquierda(NULL);
				else
					this->setraiz(NULL);

			delete nodoAeliminar;
		}

/****************************************************************************/
		void eliminarHijo(nodo<T>* nodoAeliminar, nodo<T>* nodoAnterior, enumerado vinePorAca)
		{
			if (vinePorAca == DER)
				if (!nodoAeliminar->getderecha())
					nodoAnterior->setderecha(nodoAeliminar->getizquierda());
				else
					nodoAnterior->setderecha(nodoAeliminar->getderecha());
			else
				if (vinePorAca == IZQ)
					if (!nodoAeliminar->getderecha())
						nodoAnterior->setizquierda(nodoAeliminar->getizquierda());
					else
						nodoAnterior->setizquierda(nodoAeliminar->getderecha());
				else
					if (!nodoAeliminar->getderecha())
						this->setraiz(nodoAeliminar->getizquierda());
					else
						this->setraiz(nodoAeliminar->getderecha());

			delete nodoAeliminar;
		}

/****************************************************************************/
		void eliminar2Hijo(nodo<T>* nodoAeliminar, nodo<T>* nodoAnterior, enumerado vinePorAca)
		{
			nodo<T>* mayorDeMenor, *nodoant;
			MayordeMenor(nodoAeliminar, nodoant, mayorDeMenor);

			if (mayorDeMenor == nodoAeliminar->getizquierda())
			{
				mayorDeMenor->setderecha(nodoAeliminar->getderecha());

				if (vinePorAca == DER)
					nodoAnterior->setderecha(mayorDeMenor);
				else
					if (vinePorAca == IZQ)
						nodoAnterior->setizquierda(mayorDeMenor);
					else
						this->setraiz(mayorDeMenor);
			}
			else
				if (!mayorDeMenor->getderecha() && !mayorDeMenor->getizquierda())
				{
					if (vinePorAca == DER)
						nodoAnterior->setderecha(mayorDeMenor);
					else
						if (vinePorAca == IZQ)
							nodoAnterior->setizquierda(mayorDeMenor);
						else
							this->setraiz(mayorDeMenor);

					if (nodoant->getizquierda() == mayorDeMenor)
						nodoant->setizquierda(NULL);
					else
						nodoant->setderecha(NULL);

					mayorDeMenor->setizquierda(nodoAeliminar->getizquierda());

					mayorDeMenor->setderecha(nodoAeliminar->getderecha());

					delete nodoAeliminar;
				}
				else
				{
					if (mayorDeMenor->getizquierda())
					{
						if (vinePorAca == DER)
							nodoAnterior->setderecha(mayorDeMenor);
						else
							if (vinePorAca == IZQ)
								nodoAnterior->setizquierda(mayorDeMenor);
							else
								this->setraiz(mayorDeMenor);

						mayorDeMenor->setderecha(nodoAeliminar->getderecha());

						nodo<T>* menorDeMenor;

						MenordeMenor(mayorDeMenor, menorDeMenor);

						menorDeMenor->setizquierda(nodoAeliminar->getizquierda());

						nodoant->setderecha(NULL);

						delete nodoAeliminar;
					}
				}
		}

/****************************************************************************/
		void MayordeMenor(nodo<T>* nodoActual, nodo<T>* &nodoAnterior, nodo<T>* &mayorDeMenor)
		{
			mayorDeMenor = nodoActual->getizquierda();
			nodoAnterior = NULL;

			while (mayorDeMenor->getderecha())
			{
				nodoAnterior = mayorDeMenor;
				mayorDeMenor = mayorDeMenor->getderecha();
			}
		}

/****************************************************************************/
		void MenordeMenor(nodo<T>* nodoActual, nodo<T>* &menorDeMenor)
		{
			menorDeMenor = nodoActual;

			while (menorDeMenor->getizquierda())
				menorDeMenor = menorDeMenor->getizquierda();
		}

};

#endif

