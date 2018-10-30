#include <iostream>
#include <string>

#include "corrector.h"
#include "filtro.h"
#include "palabrasinespacio.h"

#include "cronometro.h"

void correccion(corrector & micorrector, palabrasinespacio & palsinesp, Cronometro & micronometro, filtro & mifiltro)
{
	string aux, aux2;

	if (micorrector.haydic())
	{
		cout << "Ingrese palabras:" << endl<<endl;

		getline(cin , aux);
		micronometro.continuar();
		palsinesp.setrenglon(aux);
		cout << endl;
		while (!palsinesp.esfin())
		{
			aux2 = palsinesp.devuelvepalabra();

			std::cout << std::endl;
			std::cout << "Opciones sugeridas para: " << aux2 << std::endl;
			aux2 = mifiltro.filtrar(aux2);

			if (aux2 != "")
			{
				micorrector.corregirtexto(aux2);
				micorrector.obtenersugerencias();
			}
			else
				std::cout << "No hay sugerencias para la palabra." << std::endl;
		}
		micronometro.pausar();
	}
	else
		cout << "No fue agregado ningun diccionario." << endl;
};

int main()
{
	Cronometro micronometro;
	micronometro.iniciar();
	micronometro.pausar();

	corrector micorrector;
	palabrasinespacio palsinesp;
	filtro mifiltro("cambios.rol");

	string ruta;
	char opcion = '0';

	while (opcion != '3')
	{
		cout << endl;
		cout << "Ingrese opcion:" << endl<<endl;
		cout << " 1 : Agregar libro" << endl;
		cout << " 2 : Corregir texto" << endl;
		cout << " 3 : Salir" << endl;

		cin >> opcion;
		cin.get();

		switch (opcion)
		{

			case '1':
				//system("cls");
				cout << "Ingrese el nombre del archivo de texto sin extension." << endl << "	(tiene que estar en esta misma carpeta)" << endl<<endl;
				cin >> ruta;
				cout << endl;

				ruta = mifiltro.filtrar(ruta);
				ruta.append(".txt");
				cout << "Agregando Libro ....." << endl<<endl;
				micronometro.continuar();

				if (micorrector.agregarlibro(ruta))
					cout << "El libro se agrego correctamente." << endl;
				else
					cout << "El libro NO se pudo cargar." << endl;

				micronometro.pausar();

				break;

			case '2':
				//system("cls");

				correccion(micorrector, palsinesp, micronometro, mifiltro);

				break;

			case '3':
				//system("cls");

				cout << micronometro.toString() << endl;

				//system("pause");

				return 0;

			default :
				//system("cls");

				cout << "ERROR de ingreso." << endl;
		}
	}

	return 0;
}

