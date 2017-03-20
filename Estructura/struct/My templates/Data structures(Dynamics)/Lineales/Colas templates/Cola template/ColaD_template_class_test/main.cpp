#include <iostream>
#include <cstdlib>
#include "ColaD.h"
#include "Datos.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	ColaD<int>* cola1 = new ColaD<int>();
	int numero[5] = { 1, 2, 3, 4, 5 };
	
	
	for( int n = 0; n < 5; n++ )
	{
		cola1->imprimir();
		cola1->agregar( &numero[n] );
	} // fin del for

	for( int n = 0; n < 5; n++ )
	{
		cola1->imprimir();
		cola1->eliminar();
	} // fin del for
	
	cola1->imprimir();
	cout << cola1->eliminar() << endl;
	
	delete cola1;
	
	cola1 = NULL;
	cout << cola1 << endl;
	cout << endl << endl;
	
	//-----------------------------------------------------
	
	ColaD<Datos>* cola2 = new ColaD<Datos>();
	
	cola2->imprimir();
	cola2->agregar( new Datos( "Dilan", 20, 'M', 7.9 ) );
	cola2->imprimir();
	cola2->agregar( new Datos( "Jesus", 18, 'M', 8.1 ) );
	cola2->imprimir();
	cola2->agregar( new Datos( "Candelo", 19, 'M', 7.7 ) );

	for( int n = 0; n < 4; n++ )
	{
		cola2->imprimir();
		cola2->eliminar();
	} // fin del for
	
	
	delete cola2;
	cout << endl << endl;
	
	//----------------------------------------------------
	
	ColaD<Datos>* cola4 = new ColaD<Datos>();
	
	cola4->imprimir();
	cola4->agregar( new Datos( "Dilan", 20, 'M', 7.9 ) );
	cola4->imprimir();
	cola4->agregar( new Datos( "Jesus", 18, 'M', 8.1 ) );
	cola4->imprimir();
	cola4->agregar( new Datos( "Candelo", 19, 'M', 7.7 ) );
	cola4->imprimir();

	cout << "Eliminando ColaD: " << cola4->eliminarCola() << endl;
	cola4->imprimir();
	
	delete cola4;
	cout << endl << endl;
	//-----------------------------------------------------
	
	ColaD<int>* cola3 = new ColaD<int>();
	int n = 250;
	cout << cola3->agregar( &n ) << endl;
	cout << cola3->eliminar() << endl;
	cout << cola3->eliminar() << endl;
	
	
	return 0;
}
