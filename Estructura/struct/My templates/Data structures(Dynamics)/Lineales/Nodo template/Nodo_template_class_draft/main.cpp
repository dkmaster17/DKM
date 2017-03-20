#include <iostream>
#include "Nodo.h"
#include "Datos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	Datos* datos1 = new Datos( "dilan", 20, 'M', 7.99 );
	cout << "Datos: " << endl;
	cout << datos1->nombre << ", " << datos1->edad << ", " <<
	datos1->sexo << ", " << datos1->promedio << endl << endl;
	
	Nodo<Datos> nodo1( datos1 );
	cout << "Nodo1: " << endl;
	cout << nodo1.info->nombre << ", " << nodo1.info->edad << ", " <<
	nodo1.info->sexo << ", " << nodo1.info->promedio << endl << endl;
	
	Nodo<Datos>* nodo2 = new Nodo<Datos>( datos1 );
	cout << "Nodo2: " << endl;
	cout << nodo2->info->nombre << ", " << nodo2->info->edad << ", " <<
	nodo2->info->sexo << ", " << nodo2->info->promedio << endl << endl;
	
	Nodo<Datos> nodo3( new Datos( "gabriel", 12, 'M', 15.5 ) );
	cout << "Nodo3: " << endl;
	cout << nodo3.info->nombre << ", " << nodo3.info->edad << ", " <<
	nodo3.info->sexo << ", " << nodo3.info->promedio << endl << endl;
	
	Nodo<Datos>* nodo4 = new Nodo<Datos>( new Datos( "Yey", 20, 'F', 6.22 ) );
	cout << "Nodo4: " << endl;
	cout << nodo4->info->nombre << ", " << nodo4->info->edad << ", " <<
	nodo4->info->sexo << ", " << nodo4->info->promedio << endl << endl;
	return 0;
}
