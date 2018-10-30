#ifndef _NODO_H_INCLUDED
#define _NODO_H_INCLUDED

template<class T>
class nodo
{

		T * info;
		nodo<T> * derecha;
		nodo<T> * izquierda;

	public :

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Se guarda el puntero al dato en el nodo, y se lo deja sin
			aubárboles derecho e izquierdo.
		*/
		nodo(T  * dato)
		{
			this->derecha = NULL;
			this->izquierda = NULL;
			this->info = dato;
		};

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Libera los recursos asociados a la instancia.
		*/
		~nodo(){};

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Retorna un puntero al dato almacenado en el nodo.
		*/
		T * & getinfo()
		{
			return this->info;
		};

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Devuelve un puntero al subárbol derecho.
		*/
		nodo<T> * getderecha()
		{
			return this->derecha;
		};

/****************************************************************************/

		/*
		pre:
			Ninguna.
		post:
			Devuelve un puntero al subárbol izquierdo.
		*/
		nodo<T> * getizquierda()
		{
			return this->izquierda;
		};

/****************************************************************************/

		/*
		pre:
			nodo debe contener un dato menor que nodonuevo.
		post:
			Asigna un subárbol izquierdo (nodonuevo) al nodo actual.
		*/
		void setizquierda(nodo<T> * nodonuevo)
		{
			this->izquierda = nodonuevo;
		};

/****************************************************************************/

		/*
		pre:
			nodo debe contener un dato mayor que nodonuevo.
		post:
			Asigna nuevo subárbol derecho (nodonuevo) al nodo actual.
		*/
		void  setderecha(nodo<T> * nodonuevo)
		{
			this->derecha = nodonuevo;
		};

};

#endif // NODO_H_INCLUDED
