#include <iostream>
#include <string>
#include "Vertice.h"
#include "Nodo.h"
#include "Camino.h"
#include "Grafo.h"
#include "Camino.h"

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) 
{
	/*
	Vertice* vertice1 = new Vertice( "D", 3.3 );
	cout << vertice1->getIdentificador() << endl;
	cout << vertice1->getLongitudArista() << endl;
//	delete vertice1; 
	cout << endl << endl;
	
	Vertice* vertice2 = new Vertice( "E", 4.2 );
	cout << vertice2->getIdentificador() << endl;
	cout << vertice2->getLongitudArista() << endl;
//	delete vertice2; 
	cout << endl << endl;
	
	/*
	Vertice* vertice3 = new Vertice( "U", 2.5 );
	cout << vertice3->getIdentificador() << endl;
	cout << vertice3->getLongitudArista() << endl;
//	delete vertice3; 
	cout << endl << endl;*/
	
/*
	Camino* camino = new Camino();
	cout << Camino::id_static << endl;
	cout << *camino << endl;
	camino->lista_vertices->imprimir();
	camino->lista_vertices->agregar( vertice1, ListaD<Vertice>::AGRE_FIN );
	camino->lista_vertices->agregar( vertice2, ListaD<Vertice>::AGRE_FIN );
	camino->lista_vertices->agregar( vertice3, ListaD<Vertice>::AGRE_FIN );
	camino->lista_vertices->imprimir();
	camino->actualizar();
	cout << *camino << endl;
	
	cout << endl << endl;
	
	Camino* camino2 = new Camino();
	cout << Camino::id_static << endl;
	cout << *camino2 << endl;
	
	cout << (*camino == *camino2) << endl;
	cout << (*camino > *camino2) << endl;
	cout << (*camino < *camino2) << endl; */
	
	/*
	Grafo* grafo = new Grafo();
	cout << grafo->isDirigido() << endl;
	cout << grafo->isPonderado() << endl;
	cout << grafo->lista_adyacencia->isVacia() << endl;
	cout << grafo->lista_caminos->isVacia() << endl;*/
	
	/*
	Grafo* grafo = new Grafo( false, true );
	cout << grafo->agregar( vertice1, vertice2 ) << endl;
	cout << grafo->isDirigido() << endl;
	cout << grafo->isPonderado() << endl;
	cout << grafo->lista_adyacencia->isVacia() << endl;
	cout << grafo->lista_caminos->isVacia() << endl;
	grafo->imprimirListaAdyacencia(); */
	
	
	Grafo* grafo = new Grafo( "entrada.txt", ' ', true, true );
	cout << grafo->isDirigido() << endl;
	cout << grafo->isPonderado() << endl;
	cout << grafo->lista_adyacencia->isVacia() << endl;
	cout << grafo->lista_caminos->isVacia() << endl;
	grafo->imprimirListaAdyacencia();
	cout << grafo->getNumeroVertices() << endl;
	grafo->BuscarCaminos(); 
	grafo->buscarCaminos_maxVertices();
	grafo->buscarCaminos_MinMaxLongitud_Grafo( false );
	cout << endl;
	grafo->imprimirListaCaminos(); 
	cout << endl;
	
	Vertice* vertice1 = new Vertice( "D", 3.3 );
	cout << vertice1->getIdentificador() << endl;
	cout << vertice1->getLongitudArista() << endl;
	cout << endl;
	
	Vertice* vertice2 = new Vertice( "F", 3.3 );
	cout << vertice2->getIdentificador() << endl;
	cout << vertice2->getLongitudArista() << endl;
	cout << endl;
	
	cout << grafo->buscarCaminos_MinMaxLongitud_Vertices( vertice1, vertice2 ) << endl;
	grafo->imprimirListaCaminos(); 
	cout << endl;
	
	
	/*
	//////////////////////////////////////////////////////
	cout << endl << endl;
	
	Vertice* vertice = new Vertice( "A", 3.3 );
	cout << vertice->getIdentificador() << endl;
	cout << vertice->getLongitudArista() << endl;
	
	cout << endl << endl;
	
	Camino* camino = grafo->lista_caminos->getCab()->getInfo();

	cout << *camino << endl;
	camino->lista_vertices->imprimir();
	
	cout << "Elimino: " << camino->eliminarListaVerticesDesde( vertice ) << endl;
	camino->actualizar();
	cout << *camino << endl;
	camino->lista_vertices->imprimir(); */
	
	/////////////////////////////////////////////
/*	cout << endl << endl;
	
	Vertice* vertice1 = new Vertice( "san cristobal", 3.3 );
	cout << vertice1->getIdentificador() << endl;
	cout << vertice1->getLongitudArista() << endl;
	cout << endl << endl;
	
	Vertice* vertice2 = new Vertice( "tariba", 3.3 );
	cout << vertice2->getIdentificador() << endl;
	cout << vertice2->getLongitudArista() << endl;
	cout << endl << endl;
	
	cout << grafo->conectividad( vertice1, vertice2 ) << endl;
	grafo->imprimirListaCaminos(); */
	
	
/*	/////////////////////////////////////
	cout << endl << endl;
	
	Camino* camino1 = grafo->lista_caminos->getFin()->getInfo();
	Camino* camino2 = grafo->lista_caminos->getCab()->getInfo();
	
	cout << *camino1 << endl;
	cout << *camino2 << endl;
	cout << camino1->iguales( camino2, true ) << endl;
	//cout << *camino2 << endl;  */
	
	
/*	//////////////////////////////////////////////////
		
	Vertice* vertice1 = new Vertice( "D", 3.3 );
	cout << vertice1->getIdentificador() << endl;
	cout << vertice1->getLongitudArista() << endl;
//	delete vertice1; 
	cout << endl << endl;
	
	Vertice* vertice2 = new Vertice( "E", 4.2 );
	cout << vertice2->getIdentificador() << endl;
	cout << vertice2->getLongitudArista() << endl;
//	delete vertice2; 
	cout << endl << endl;
	
	
	Vertice* vertice3 = new Vertice( "U", 2.5 );
	cout << vertice3->getIdentificador() << endl;
	cout << vertice3->getLongitudArista() << endl;
//	delete vertice3; 
	cout << endl << endl;
	
	Camino* camino1 = new Camino();
	Camino* camino2 = new Camino();
	
	camino1->lista_vertices->agregar( vertice1, ListaD<Vertice>::AGRE_FIN );
	camino1->lista_vertices->agregar( vertice2, ListaD<Vertice>::AGRE_FIN );
	camino1->lista_vertices->agregar( vertice3, ListaD<Vertice>::AGRE_FIN );
	camino2->lista_vertices->agregar( vertice3, ListaD<Vertice>::AGRE_FIN );
	camino2->lista_vertices->agregar( vertice2, ListaD<Vertice>::AGRE_FIN );
	camino2->lista_vertices->agregar( vertice1, ListaD<Vertice>::AGRE_FIN );
	
	cout << *camino1 << endl;
	camino1->lista_vertices->imprimir();
	cout << endl << endl;
	cout << *camino2 << endl;
	camino2->lista_vertices->imprimir();
	
	cout << endl;
	cout << camino1->iguales( camino2, true ) << endl; */
	return 0;
}












