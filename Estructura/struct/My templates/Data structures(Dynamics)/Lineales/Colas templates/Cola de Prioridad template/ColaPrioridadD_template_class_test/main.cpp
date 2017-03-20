#include <iostream>
#include <cstdlib>
#include "ColaPrioridadD.h"
#include "Nodo.h"
#include "Datos.h"
#include "Sexo.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	ColaPrioridadD<int>* colaP1 = new ColaPrioridadD<int>();
	int num1 = 5;
	int num2 = 6;
	int num3 = 5;
	int num4 = 6;
	int num5 = 7;
	
	cout << colaP1->agregar( &num1, 2 ) << endl;
	cout <<	colaP1->agregar( &num1, 3 ) << endl;
	cout << colaP1->agregar( &num2, 2 ) << endl;
	cout << colaP1->agregar( &num3, 2 ) << endl;
	cout << colaP1->agregar( &num2, 1 ) << endl;
	cout << colaP1->agregar( &num4, 2 ) << endl;
	cout << colaP1->agregar( &num5, 1 ) << endl;	
	colaP1->imprimir();
	cout << endl;

	
	cout << colaP1->eliminar() << endl;
	colaP1->imprimir();
	cout << endl;
	
	cout << colaP1->eliminar() << endl;
	colaP1->imprimir();
	cout << endl;
	
	cout << colaP1->eliminar() << endl;
	colaP1->imprimir();
	cout << endl;
	
	cout << colaP1->eliminar() << endl;
	colaP1->imprimir();
	cout << endl;
	
	cout << colaP1->eliminar() << endl;
	colaP1->imprimir();
	cout << endl;
	
	delete colaP1;
	
	cout << "--------------------------------" << endl;
	
	//--------------------------------------------------
	
	Datos* datos1 = new Datos( "Dilan", 20, 'M', 7.99 );
	Datos* datos2 = new Datos( "Gabriel", 12, 'M', 15.66 );
	Datos* datos3 = new Datos( "Danriela", 19, 'F', 16.66 );
	
	cout << ( *datos1 == *datos2 ) << endl;
	cout << ( *datos1 == *datos3 ) << endl;
	
	delete datos1, datos2, datos3;
	
	cout << "-------------------------------------" << endl;
	
	//--------------------------------------------------------
	
	ColaPrioridadD<Datos>* colaP2 = new ColaPrioridadD<Datos>();
	
	colaP2->agregar( new Datos( "Dilan", 20, 'M', 7.99 ), 3 );
	colaP2->imprimir();
	cout << endl;
	colaP2->agregar( new Datos( "Daniela", 19, 'F', 16.99 ), 1 );
	colaP2->imprimir();
	cout << endl;
	colaP2->agregar( new Datos( "dfhksdf", 435, 'I', 54.45 ), 1 );
	colaP2->imprimir();
	cout << endl;
	colaP2->agregar( new Datos( "Gabriel", 12, 'M', 13.45 ), 2 );
	colaP2->imprimir();
	cout << endl;
	colaP2->agregar( new Datos( "Juan", 12, 'M', 13.45 ), 2 );
	colaP2->imprimir();
	cout << endl;
	colaP2->agregar( new Datos( "Diana", 12, 'F', 13.45 ), 2 );
	colaP2->imprimir();
	cout << endl << endl;
	
	colaP2->eliminar();
	colaP2->imprimir();
	cout << endl;
	colaP2->eliminar();
	colaP2->imprimir();
	cout << endl;
	colaP2->eliminar();
	colaP2->imprimir();
	cout << endl;
	colaP2->eliminar();
	colaP2->imprimir();
	cout << endl;
	colaP2->eliminar();
	colaP2->imprimir();
	cout << endl;
	colaP2->eliminar();
	colaP2->imprimir();
	cout << endl;
	
	delete colaP2;
	
	cout << "----------------------------------" << endl;
	
	// -------------------------------------------------
	
	Sexo* s1 = new Sexo( 'F' );
	Sexo* s2 = new Sexo( 'M' );
	Datos* datos4 = new Datos( "Dilan", 20, 'M', 7.99 );
	cout << ( *s1 == *datos4 ) << endl;
	cout << ( *s2 == *datos4 ) << endl;
	
	delete s1, s2, datos4;
	
	cout << "----------------------------------" << endl;
	
	//------------------------------------------------------

	return 0;
}
