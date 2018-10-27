#include "ListaCandidato.h"
#include <iostream>
#include <string>
using namespace std;

int main(){

string cosa;
cout<<"ingrese palabra"<<endl;
cin>>cosa;

ListaCandidato milistacandidatos(cosa);

Lista<palabra*> *milista = milistacandidatos.getlista();

IteradorLista<palabra*>  miIterador = milista->iterador();

while (miIterador.tieneSiguiente()){

    palabra* mipalabra = miIterador.siguiente();
    cout<< mipalabra->geten() <<endl;

    }
system("pause");
return 0;
}
