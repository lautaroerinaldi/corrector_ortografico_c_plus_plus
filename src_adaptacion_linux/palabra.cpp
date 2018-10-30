#include "palabra.h"
/***************************************************************************************/
palabra::palabra(const string & enunciado, const tipopalabra & tipo): pal(enunciado)
{
	pond = tipo;
}

/***************************************************************************************/
palabra::~palabra() {}

/***************************************************************************************/
string palabra::geten() const
{
	return pal;
}

/***************************************************************************************/
unsigned int palabra::getpond() const
{
	return pond;
}

/***************************************************************************************/
void palabra::setpond(const unsigned int & ponderacion)
{
	pond = ponderacion;
}
