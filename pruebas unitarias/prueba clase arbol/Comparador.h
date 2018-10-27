/**
 * Comparadores.
 **/

#ifndef __COMPARADOR_H__
#define __COMPARADOR_H__

#include <iostream>
enum ResultadoComparacion
{
    MENOR,
    IGUAL,
    MAYOR,
};

/**
 * Clase abstracta que encapsula la lógica de comparación utilizada para
 * ordenar las estructuras de datos.
 *
 */
template<class T> class Comparador
{

public:
    /**
     * post: devuelve  MAYOR, MENOR o IGUAL de acuerdo a la relación
     *       existente entre elemento1 y elemento2.
     *
     * Método abstracto que deberá ser implementado por los descendientes
     * de Comparador especificando un comportamiento particular.
     */
    virtual ResultadoComparacion comparar(T  elemento1, T  elemento2) = 0;
};

/**
 * Implementación del Comparador que utiliza los operadores "==", "<" y ">"
 * estableciendo un orden ascendente.
 *
 */
template<class T> class ComparadorSimpleAscendente : public Comparador<T>
{

public:
    virtual ResultadoComparacion comparar(T  elemento1, T  elemento2)
    {


        ResultadoComparacion resultado;

        if (elemento1 == elemento2)
        {

            resultado = IGUAL;

        }
        else if (elemento1 > elemento2)
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
template<class T> class Comparadorpunterosint : public Comparador<T>
{

public:
    virtual ResultadoComparacion comparar(T  elemento1, T   elemento2)
    {


        ResultadoComparacion resultado;

        if (elemento1 == elemento2)
        {

            resultado = IGUAL;

        }
        else if (elemento1 > elemento2)
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
template<class T> class ComparadorPalabraAscendente : public Comparador<T>
{

public:
    virtual ResultadoComparacion comparar(T  elemento1, T  elemento2)
    {


        ResultadoComparacion resultado;

        if (elemento1.geten() == elemento2.geten())
        {

            resultado = IGUAL;

        }
        else if (elemento1.geten() > elemento2.geten())
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
