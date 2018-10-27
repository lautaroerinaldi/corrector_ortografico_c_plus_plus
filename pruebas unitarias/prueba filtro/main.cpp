#include <string>
#include <iostream>
#include "filtro.h"
using namespace std;

int main()
{
    string palabra;
    filtro mifiltro("cambios.rol");

    for (int i=0;i<5;i++){

     cout<<"ingrese una palabra con caracteres invalidos: "<<endl;
     cin>>palabra;
     palabra=mifiltro.filtrar(palabra);
     cout<<"palabra filtrada: "<<palabra<<endl<<endl;

    }
    return 0;
}
