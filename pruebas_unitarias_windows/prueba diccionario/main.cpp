#include <iostream>
#include "diccionario.h"
using namespace std;

void visito( palabra * & info)
{
 cout<<info->geten()<<" ";
};

int main()
{

    string cadena;
    diccionario miDiccionario("hola");
    int i;
    for ( i= 0;i<5;i++)
    {
        cout<<"ingrese una palabra al diccionario: "<<endl;
        cin>>cadena;
        miDiccionario.agregar(cadena);
    };
    cout<<"se agregaron "<< i <<" palabras (y hola ya estaba)"<<endl;
    miDiccionario.recorrer(&visito);

    return 0;
}
