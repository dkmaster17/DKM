#include <iostream>
#include <string>
#include <cstdlib>
#include "Datos.h"
#include "Nodo.h"

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	int* numero = new int;
	*numero = 5;
	Nodo<int>* nodo0 = new Nodo<int>( numero );
	cout << *nodo0->getInfo() << endl;
	cout << *numero << endl;
	cout << nodo0->getLink_suc() << endl;
	cout << nodo0->getLink_pre() << endl;	
	delete nodo0;
	cout << nodo0->getInfo() << endl;
	cout << *numero << endl;
	cout << nodo0->getLink_suc() << endl;
	cout << nodo0->getLink_pre() << endl << endl << endl;
	
	
	Datos* dato = new Datos( "Dilan", 20, 'M', 7.91 );
	Nodo<Datos>* nodo1 = new Nodo<Datos>( dato );	
	cout << *nodo1->getInfo() << endl;
	cout << *dato << endl;
	cout << nodo1->getLink_suc() << endl;
	cout << nodo1->getLink_pre() << endl;
	delete nodo1;
	cout << nodo1->getInfo() << endl;
	cout << dato << endl;
	cout << nodo1->getLink_suc() << endl;
	cout << nodo1->getLink_pre() << endl << endl;
	
	
	
	Nodo<Datos>* nodo2 = new Nodo<Datos>(
		new Datos( "Gabriel", 12, 'M', 15.66 ) );
	cout << *nodo2->getInfo() << endl;
	cout << nodo2->getLink_suc() << endl;
	cout << nodo2->getLink_pre() << endl;
	delete nodo2;
	
	/*
	Nodo<Datos>* nodo3 = new Nodo<Datos>( 
		new Datos( "Diego", 12, 'M', 13.12) );
	cout << *nodo3->getInfo() << endl;
	cout << nodo3->getLink_suc() << endl;
	cout << nodo3->getLink_pre() << endl;
	

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
	cout << nodo2->getLink_hi()->getInfo() << endl << endl; */

	return 0;
}
