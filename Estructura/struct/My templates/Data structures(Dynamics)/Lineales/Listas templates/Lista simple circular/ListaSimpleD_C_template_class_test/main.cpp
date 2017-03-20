#include <iostream>
#include <cstdlib>
#include "ListaSimpleD_C.h"
#include "Datos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	ListaSimpleD_C<int>* lista1 = new ListaSimpleD_C<int>();
	
	int numeros[7] = { 2, 1, 7, 15, 4, 28, 0 };
	
	
	for( int x = 0; x < 7; x++ )
	{
		lista1->agregar( &numeros[x] );
		lista1->imprimir();
	}
	
	
	cout << endl << endl;

	lista1->imprimir();
	
	int num = 100;
	cout << lista1->eliminar( &num ) << endl;
	cout << endl << endl;
	
	
	cout << lista1->eliminar ( &numeros[3] ) << endl;
	lista1->imprimir();
	cout << lista1->eliminar ( &numeros[0] ) << endl;
	lista1->imprimir();
	cout << lista1->eliminar ( &numeros[5] ) << endl;
	lista1->imprimir();
	cout << lista1->eliminar ( &numeros[6] ) << endl;
	lista1->imprimir();
	cout << lista1->eliminar ( &numeros[2] ) << endl;
	lista1->imprimir();
	cout << lista1->eliminar ( &numeros[1] ) << endl;
	lista1->imprimir();
	cout << lista1->eliminar ( &numeros[4] ) << endl;
	lista1->imprimir();
	cout << lista1->eliminar ( &numeros[3] ) << endl;
	lista1->imprimir();
	
	delete lista1;
	
	cout << "---------------------------------" << endl << endl;
	
	//---------------------------------------------------
	Datos* datos1 = new Datos( "Dilan", 20, 'M', 7.99 );
	Datos* datos2 = new Datos( "Antonio", 20, 'M', 7.99 );
	Datos* datos3 = new Datos( "Gabriel", 20, 'M', 7.99 );
	Datos* datos4 = new Datos( "Eduardo", 20, 'M', 7.99 );
	
	
	ListaSimpleD_C<Datos>* lista2 = new ListaSimpleD_C<Datos>();
	
	lista2->agregar( datos1 );
	lista2->imprimir();
	lista2->agregar( datos2 );
	lista2->imprimir();
	lista2->agregar( datos3 );
	lista2->imprimir();
	lista2->agregar( datos4 );
	lista2->imprimir();
	cout << endl << endl;
	
	Datos* datos5 = new Datos( "fgdfgdf", 20, 'M', 7.99 );
	
	cout << lista2->eliminar( datos5 ) << endl;;
	lista2->imprimir();
	cout << lista2->eliminar( datos4 ) << endl;;
	lista2->imprimir();
	cout << lista2->eliminar( datos3 ) << endl;;
	lista2->imprimir();
	cout << lista2->eliminar( datos2 ) << endl;;
	lista2->imprimir();
	cout << lista2->eliminar( datos1 ) << endl;;
	lista2->imprimir();
	
	
	return 0;
}
