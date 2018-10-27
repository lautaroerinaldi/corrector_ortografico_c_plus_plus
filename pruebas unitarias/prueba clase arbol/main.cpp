#include <iostream>
#include "Comparador.h"
#include "arbol.h"

using namespace std;

void visito( int & info)
{
 cout<<info<<" ";
}

int main()
{

/// prueba con enteros

int a=45,b=30,c(50),d(25),e(32),f(70),g(20),h(28),i(31),j=33,k=10,l=15,m=27;
    int * pp1= &a;
    int * pp2= &b;
    int * pp3= &c;
    int * pp4= &d;
    int * pp5= &e;
    int * pp6= &f;
    int * pp7= &g;
    int * pp8= &h;
    int * pp9= &i;
    int * pp10= &j;
    int * pp11= &k;
    int * pp12= &l;
    int * pp13= &m;
    Comparador<int> * micomparador = new Comparadorpunterosint<int>;
    arbolBbinaria <int> miarbol(micomparador);

    miarbol.insertar(pp1); miarbol.insertar(pp2); miarbol.insertar(pp3); miarbol.insertar(pp4);
    miarbol.insertar(pp5); miarbol.insertar(pp6); miarbol.insertar(pp7); miarbol.insertar(pp8);
    miarbol.insertar(pp9);miarbol.insertar(pp10);miarbol.insertar(pp11);miarbol.insertar(pp12);
    miarbol.insertar(pp13);
cout<< "En inorden:"<< endl;
 miarbol.inorden(&visito);
 cout<< endl <<endl<< "En preorden:"<< endl;
 miarbol.preorden(&visito);
 cout<< endl <<endl<< "En postorden:"<< endl;
 miarbol.postorden(&visito);
 cout << endl<<endl;

cout << endl << "elimino 45, 30 y 50" << endl << endl;
miarbol.eliminarDato(pp1,miarbol.getraiz());
miarbol.eliminarDato(pp2,miarbol.getraiz());
miarbol.eliminarDato(pp3,miarbol.getraiz());

 cout<< "En inorden:"<< endl;
 miarbol.inorden(&visito);
 cout<< endl <<endl<< "En preorden:"<< endl;
 miarbol.preorden(&visito);
 cout<< endl <<endl<< "En postorden:"<< endl;
 miarbol.postorden(&visito);
 cout << endl;

 return 0;
}
