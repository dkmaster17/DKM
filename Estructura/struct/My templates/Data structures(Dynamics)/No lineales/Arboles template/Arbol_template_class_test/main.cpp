#include <iostream>
#include <cstdlib>
#include <cstdio>
#include "Arbol.h"
#include "NodoA.h"
#include <windows.h>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void pruebaEnteros()
{
	Arbol<int>* arbol = new Arbol<int>( true );
	
	cout << arbol->isAVL() << endl<< endl;
	
	
	int numeros[20] = { 5, 20, 4, 13, 1, 8, 10, 12, 50, 15, 23, 9, 99, 43, 2, 30, 7, 68, 55, 100 };
	
	
	for( int i = 0; i < 20; i++ )
		cout << "agrego("  << numeros[i] << ")" << ": " << arbol->agregar( &numeros[i] ) << endl;
		
	
	cout << endl;
	arbol->imprimir( arbol->getRaiz() );
	cout << "Altura: " << arbol->getAltura() << endl;
	cout << endl << endl;
	
	
	
	NodoA<int>* hoja = arbol->buscar( &numeros[4] );
	
	cout << "Nodo: " << *hoja->getInfo() << endl; 
	cout << "Es hoja?: " << hoja->isHoja() << endl;
	
	hoja = arbol->buscar( &numeros[0] );
	cout << endl << "Nodo: " << *hoja->getInfo() << endl;
	cout << "Es hoja?: " << hoja->isHoja() << endl;
	
	
	int eliminar[20] = { 12, 5, 8, 13, 1, 4, 10, 20, 50, 15, 23, 9, 99, 43, 2, 30, 7, 68, 55, 100 };
	
	for( int i = 0; i < 20; i++ )
	{
		cout << "elimino(" << eliminar[i] << ")" << ": " << arbol->eliminar( &eliminar[i] ) << endl;
		cout << endl;
		arbol->imprimir( arbol->getRaiz() );
	}
	
	cout << endl << endl;
	cout << "elimino(" << eliminar[0] << ")" << ": " << arbol->eliminar( &eliminar[0] ) << endl;
	arbol->imprimir( arbol->getRaiz() );
	
	
	system( "PAUSE" );
	system( "cls" );
	
	int numeros2[20] = { 5, 20, 4, 13, 1, 8, 10, 12, 50, 15, 23, 9, 99, 43, 2, 30, 7, 68, 55, 100 };
	
	cout << arbol->getRaiz() << endl;
	cout << arbol->getAltura() << endl;
	
	
	for( int i = 0; i < 20; i++ )
		cout << "agrego("  << numeros2[i] << ")" << ": " << arbol->agregar( &numeros2[i] ) << endl;
		
		
	cout << endl;
	arbol->imprimir( arbol->getRaiz() ); 
	
	
	cout << "Elimino arbol completo" << endl;
	arbol->eliminarArbol( arbol->getRaiz() );
	cout << endl;
	arbol->imprimir( arbol->getRaiz() );
}


void pruebaChar()
{
	Arbol<char>* arbol2 = new Arbol<char>( true );
	
	cout << arbol2->isAVL() << endl<< endl;
	
	
	char letras[20] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't' };
	
	
	for( int i = 0; i < 20; i++ )
		cout << "agrego("  << letras[i] << ")" << ": " << arbol2->agregar( &letras[i] ) << endl;
		
	
	cout << endl;
	arbol2->imprimir( arbol2->getRaiz() );
	
	cout << endl << endl;
	
	
	
	NodoA<char>* hoja2 = arbol2->buscar( &letras[4] );
	
	cout << "Nodo: " << *hoja2->getInfo() << endl; 
	cout << "Es hoja?: " << hoja2->isHoja() << endl;
	
	hoja2 = arbol2->buscar( &letras[0] );
	cout << endl << "Nodo: " << *hoja2->getInfo() << endl;
	cout << "Es hoja?: " << hoja2->isHoja() << endl;
	
	
	char eliminar2[20] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't' };
	
	for( int i = 0; i < 20; i++ )
	{
		cout << "elimino(" << eliminar2[i] << ")" << ": " << arbol2->eliminar( &eliminar2[i] ) << endl;
		cout << endl;
		arbol2->imprimir( arbol2->getRaiz() );
	}
	
	cout << endl << endl;
	cout << "elimino(" << eliminar2[0] << ")" << ": " << arbol2->eliminar( &eliminar2[0] ) << endl;
	arbol2->imprimir( arbol2->getRaiz() );
}


int main(int argc, char** argv) 
{
	pruebaEnteros();
	//pruebaChar();
	return 0;
}
