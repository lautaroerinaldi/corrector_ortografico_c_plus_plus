#include "otros.h"
#include "filtro.h"

char primeraletra(const string & texto)
{

    filtro fil("cambios2.rol");

    return fil.filtrar(texto)[0];

};
