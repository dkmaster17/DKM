#include <iostream>
#include "BicolaD.h"
#include "Nodo.h"
#include "Datos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	BicolaD<int>* bicola1 = new BicolaD<int>( 1 );
	int numero[5] = { 1, 2, 3, 4, 5 };
	
	
	for( int x = 0; x < 5; x++ )
	{
		cout <<	bicola1->agregar( &numero[x], false ) << endl;
		bicola1->imprimir( 1 );
		bicola1->imprimir( 2 );
		bicola1->imprimir();
		cout << endl;
	}
	
	bicola1->eliminar();
	bicola1->imprimir( 3 );
	bicola1->eliminar( 1 );
	bicola1->imprimir();
	bicola1->eliminar( 0 );
	bicola1->imprimir();
	cout <<	bicola1->eliminar() << endl;
	bicola1->eliminar();
	bicola1->imprimir();
	cout << bicola1->eliminar() << endl;
	cout << endl << endl << endl;
	
	delete bicola1;
	
	//-------------------------------------
	
	BicolaD<Datos>* bicola2 = new BicolaD<Datos>( 0 );
	
	bicola2->agregar( new Datos( "Dilan", 20, 'M', 7.91 ) );
	bicola2->imprimir();
	bicola2->agregar( new Datos( "Gabriel", 12, 'M', 15.91 ) );
	bicola2->imprimir();
	bicola2->agregar( new Datos( "Daniela", 19, 'F', 16.91 ), 0 );
	bicola2->imprimir();
	bicola2->agregar( new Datos( "Maria", 18, 'F', 5.91 ), 1 );
	bicola2->imprimir();
	
	bicola2->eliminar();
	bicola2->imprimir();
	bicola2->eliminar( 1 );
	bicola2->imprimir();
	bicola2->eliminar( 0 );
	bicola2->imprimir();
	bicola2->eliminar();
	bicola2->imprimir( 1 );
	bicola2->imprimir( 2 );
	
	
	
	return 0;
}
