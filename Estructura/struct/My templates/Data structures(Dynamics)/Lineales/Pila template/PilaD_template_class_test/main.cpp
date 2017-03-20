#include <iostream>
#include <cstdlib>
#include "PilaD.h"
#include "Datos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv)
{
	PilaD<int>* pila1 = new PilaD<int>();
	int numero[5] = { 1, 2, 3, 4, 5 };
	
	
	for( int n = 0; n < 5; n++ )
	{
		pila1->imprimir();
		pila1->agregar( &numero[n] );
	} // fin del for

	for( int n = 0; n < 5; n++ )
	{
		pila1->imprimir();
		pila1->eliminar();
	} // fin del for
	
	pila1->imprimir();
	cout << pila1->eliminar() << endl;
	
	delete pila1;
	
	pila1 = NULL;
	cout << pila1 << endl;
	cout << endl << endl;
	
	//-----------------------------------------------------
	
	PilaD<Datos>* pila2 = new PilaD<Datos>();
	
	pila2->imprimir();
	pila2->agregar( new Datos( "Dilan", 20, 'M', 7.9 ) );
	pila2->imprimir();
	pila2->agregar( new Datos( "Jesus", 18, 'M', 8.1 ) );
	pila2->imprimir();
	pila2->agregar( new Datos( "Candelo", 19, 'M', 7.7 ) );

	for( int n = 0; n < 4; n++ )
	{
		pila2->imprimir();
		pila2->eliminar();
	} // fin del for
	
	delete pila2;
	cout << endl << endl;
	
	//---------------------------------------
	PilaD<Datos>* pila4 = new PilaD<Datos>();
	
	pila4->imprimir();
	pila4->agregar( new Datos( "Dilan", 20, 'M', 7.9 ) );
	pila4->imprimir();
	pila4->agregar( new Datos( "Jesus", 18, 'M', 8.1 ) );
	pila4->imprimir();
	pila4->agregar( new Datos( "Candelo", 19, 'M', 7.7 ) );
	pila4->imprimir();
	
	cout << "Eliminando la PilaD: " << pila4->eliminarPila() << endl;
	pila4->imprimir();

	
	delete pila4;
	cout << endl << endl;
	//---------------------------------------
	
	PilaD<int>* pila3 = new PilaD<int>();
	int num = 1200;
	cout << pila3->agregar( &num ) << endl;
	cout << pila3->eliminar() << endl;
	cout << pila3->eliminar() << endl;
	
	
	

 	
	return 0;
}
