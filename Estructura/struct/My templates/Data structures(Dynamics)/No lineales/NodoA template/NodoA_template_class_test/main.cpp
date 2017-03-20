#include <iostream>
#include <string>
#include <cstdlib>
#include "Datos.h"
#include "NodoA.h"

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int numero = 5;
	NodoA<int>* nodo0 = new NodoA<int>( &numero );
	cout << nodo0->getInfo() << endl;
	cout << nodo0->getLink_hd() << endl;
	cout << nodo0->getLink_hi() << endl << endl;
	
	
	NodoA<Datos>* nodo1 = new NodoA<Datos>( 
		new Datos( "Dilan", 20, 'M', 7.91 ) );	
	cout << nodo1->getInfo() << endl;
	cout << nodo1->getLink_hd() << endl;
	cout << nodo1->getLink_hi() << endl << endl;
	
	
	NodoA<Datos>* nodo2 = new NodoA<Datos>(
		new Datos( "Gabriel", 12, 'M', 15.66 ) );
	cout << nodo2->getInfo() << endl;
	cout << nodo2->getLink_hd() << endl;
	cout << nodo2->getLink_hi() << endl << endl;
	
	NodoA<Datos>* nodo3 = new NodoA<Datos>( 
		new Datos( "Diego", 12, 'M', 13.12) );
	cout << nodo3->getInfo() << endl;
	cout << nodo3->getLink_hd() << endl;
	cout << nodo3->getLink_hi() << endl;
	

	nodo1->setLink_hd( nodo2 );
	cout << nodo1->getLink_hd()->getInfo() << endl;
	nodo1->setLink_hd( NULL );
	cout << nodo1->getLink_hd() << endl;
	nodo1->setLink_hd( nodo2 );
	cout << nodo1->getLink_hd()->getInfo() << endl << endl;
	
	
	nodo2->setLink_hi( nodo1 );
	cout << nodo2->getLink_hi()->getInfo() << endl;
	nodo2->setLink_hi( NULL );
	cout << nodo2->getLink_hi() << endl;
	nodo2->setLink_hi( nodo1 );
	cout << nodo2->getLink_hi()->getInfo() << endl << endl;

	return 0;
}
