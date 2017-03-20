#include <iostream>
#include "ListaD.h"
#include "Datos.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void probarListaSimple()
{
	// probando con listas simples de enteros
	cout << "*) Lista simple de enteros..." << endl;
	
	ListaD<int>* lista1 = new ListaD<int>(); // constructor predeterminado ( no es circular ni doble)
	ListaD<int>* lista2 = new ListaD<int>( false, false ); // constructor con dos argumentos
	int numeros[7] = { 4, 1, 7, 10, 25, 0, 9 };
	
	// lista con constructor de dos argumentos
	cout << ".-Lista2(constructor con dos argumentos):" << endl;
	cout << "-Tipo de Lista..." << endl;
	cout << ".Circular: " << lista2->isCircu() << endl;
	cout << ".Doble: " << lista2->isDoble() << endl << endl << endl;
	
	// Lista con constructor predeterminado
	cout << ".-Lista1(constructor sin argumentos):" << endl;
	cout << "-Tipo de Lista..." << endl;
	cout << ".Circular: " << lista1->isCircu() << endl;
	cout << ".Doble: " << lista1->isDoble() << endl << endl;
	/* constructores probados ----------------------------------------------------------------------------*/
	
	// Pruebas solo con lista1
	// Lista vacia, antes de agregar
	cout << ".-Antes de agregar a la lista..." << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	
	
	// agregando a la lista, llamando a agregar con un solo argumento( creciente con repeticion permitida)
	cout << ".-Agregando a la lista(creciente)..." << endl;
	for( int x = 0; x < 7; x++ )
		cout << "agrego( " << lista1->agregar( &numeros[x] ) << " ): " << numeros[x] << " | ";
	// muestro la lista	
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion permitida)
	cout << "-Agregando repetidos a la lista(permitiendolo)(cre, cre, cre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[0] ) << " ): " << numeros[0] << " | "; // agrego elemento repetido 
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_CRE ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_CRE, true ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_INICIO ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // en el inicio de la Lista si especificar la repetición
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_FIN, true ) << // agrego elemento repetido
		" ): " << numeros[5] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion no permitida)
	cout << "-Agregando repetidos a la lista(Sin permitirlo)(cre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_CRE, false ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_INICIO, false ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // en el inicio de la Lista especificando la repetición
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_FIN, false ) << // agrego elemento repetido
		" ): " << numeros[5] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	
	// elimino la lista complte 
	cout << ".-Elimino la lista completa..." << endl;
	lista1->eliminarLista();
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	/* funcion miembro eliminarLista() probado ----------------------------------------------------------------*/
	
	
	// agregando a la lista, llamando a agregar con dos argumentos( creciente con repeticion permitida)
	cout << ".-Agregando a la lista(decreciente)..." << endl;
	for( int x = 0; x < 7; x++ )
		cout << "agrego( " << lista1->agregar( &numeros[x], ListaD<int>::AGRE_DECRE ) << " ): " << numeros[x] << " | ";
	// muestro la lista	
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion permitida)
	cout << "-Agregando repetidos a la lista(permitiendolo)(decre, decre, inicio, fin)...." << endl; 
	cout << "agrego( " << lista1->agregar( &numeros[0], ListaD<int>::AGRE_DECRE ) << // agrego elemento repetido
		" ): " << numeros[0] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[6], ListaD<int>::AGRE_DECRE, true ) << // agrego elemento repetido
		" ): " << numeros[6] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_INICIO, true ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // en el inicio de la Lista especificando la repetición
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_FIN ) << // agrego elemento repetido
		" ): " << numeros[4] << endl; // al final de la lista sin especificar la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion no permitida)
	cout << "-Agregando repetidos a la lista(Sin permitirlo)(decre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[0], ListaD<int>::AGRE_DECRE, false ) << // agrego elemento repetido
		" ): " << numeros[0] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_INICIO, false ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // en el inicio de la Lista si especificar la repetición
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_FIN, false ) << // agrego elemento repetido
		" ): " << numeros[4] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	/* funcion miembro agregar() probadá-----------------------------------------------------------------------------*/
	
	int num = 1250;
	cout << "-Buscando en la lista( real, no existe en la lista)..." << endl;
	cout << "Busco( " << lista1->buscar( &numeros[5] ) << 
		" ): " << numeros[5] << " | "; 
	cout << "Busco( " << lista1->buscar( &num ) << 
		" ): " << num << " | " << endl << endl;
	/* funcion miembro buscar() probadá ----------------------------------------------------------------------------------*/
	
	// elimimando de la lista
	cout << "-Eliminando de la lista( elementos especificos )..." << endl;
	int eliminando[7] = { 0, 9, 25, 1, 10, 7, 4 };
	
	// eliminando de la lista elementos especificos 
	for( int x = 0; x < 7; x++ )
		cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_ELEMENTO), &eliminando[x] ) << " ): " << eliminando[x] << " | ";
	// muestro la lista
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	// eliminando de la lista especificando posicion y elemento( combinacion invalida de argumentos)
	cout << endl << ".-eliminando de la lista( combinacion de argumentos invalida)..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_INICIO, &eliminando[3] ) << " ): " << eliminando[3] << " | ";
	cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_FINAL), &eliminando[4] ) << " ): " << eliminando[4] << " | ";
	cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_ELEMENTO) ) << " ): " << "NULL" << " | ";
	// muestro la lista		
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	// eliminando de la lista al inicio y al final
	cout << endl << ".-Eliminando de la lista( inicio y fin )..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_INICIO ) << " ): " << "Incio"<< " | ";
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_FINAL ) << " ): " << "Final" << " | ";
	// muestro la lista		
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	
	cout << endl << ".-Elimimnando de la lista(elemento que no existe)..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_ELEMENTO, &eliminando[2] ) << " ): " << eliminando[2] << " | ";
			
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	cout << endl;
	cout << "Elimino( " << 
			lista1->eliminar() << " ): " << "Fin" << " | ";
	
			
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	
	cout << endl << "Elimino( " << 
			lista1->eliminar() << " ): " << "Ultimo" << endl;
			
	cout << ".-Antes de agregar a la lista..." << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	/* funcion miembro eliminar probadá-------------------------------------------------------------------------*/
	
	cout << endl << "Elimino( " << 
			lista1->eliminar() << " ): " << "Lista vacia" << endl;
} // fin de probarListaSimple


void probarListaSimpleCircular()
{
	// probando con listas simple circular de enteros
	cout << "*) Lista simple circular de enteros..." << endl;
	
	ListaD<int>* lista1 = new ListaD<int>( false, true); // constructor con dos argumentos ( es circular pero no doble)
	int numeros[7] = { 4, 1, 7, 10, 25, 0, 9 };
	
	// Lista con constructor predeterminado
	cout << ".-Lista1(constructor con dos argumentos):" << endl;
	cout << "-Tipo de Lista..." << endl;
	cout << ".Circular: " << lista1->isCircu() << endl;
	cout << ".Doble: " << lista1->isDoble() << endl << endl;
	/* constructores probados ----------------------------------------------------------------------------*/
	
	// Pruebas solo con lista1
	// Lista vacia, antes de agregar
	cout << ".-Antes de agregar a la lista..." << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	
	
	// agregando a la lista, llamando a agregar con un solo argumento( creciente con repeticion permitida)
	cout << ".-Agregando a la lista(creciente)..." << endl;
	for( int x = 0; x < 7; x++ )
		cout << "agrego( " << lista1->agregar( &numeros[x] ) << " ): " << numeros[x] << " | ";
	// muestro la lista	
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion permitida)
	cout << "-Agregando repetidos a la lista(permitiendolo)(cre, cre, cre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[0] ) << " ): " << numeros[0] << " | "; // agrego elemento repetido 
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_CRE ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_CRE, true ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_INICIO ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // en el inicio de la Lista si especificar la repetición
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_FIN, true ) << // agrego elemento repetido
		" ): " << numeros[5] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion no permitida)
	cout << "-Agregando repetidos a la lista(Sin permitirlo)(cre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_CRE, false ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_INICIO, false ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // en el inicio de la Lista especificando la repetición
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_FIN, false ) << // agrego elemento repetido
		" ): " << numeros[5] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	
	// elimino la lista complte 
	cout << ".-Elimino la lista completa..." << endl;
	lista1->eliminarLista();
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	/* funcion miembro eliminarLista() probado ----------------------------------------------------------------*/
	
	
	// agregando a la lista, llamando a agregar con dos argumentos( creciente con repeticion permitida)
	cout << ".-Agregando a la lista(decreciente)..." << endl;
	for( int x = 0; x < 7; x++ )
		cout << "agrego( " << lista1->agregar( &numeros[x], ListaD<int>::AGRE_DECRE ) << " ): " << numeros[x] << " | ";
	// muestro la lista	
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion permitida)
	cout << "-Agregando repetidos a la lista(permitiendolo)(decre, decre, inicio, fin)...." << endl; 
	cout << "agrego( " << lista1->agregar( &numeros[0], ListaD<int>::AGRE_DECRE ) << // agrego elemento repetido
		" ): " << numeros[0] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[6], ListaD<int>::AGRE_DECRE, true ) << // agrego elemento repetido
		" ): " << numeros[6] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_INICIO, true ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // en el inicio de la Lista especificando la repetición
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_FIN ) << // agrego elemento repetido
		" ): " << numeros[4] << endl; // al final de la lista sin especificar la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion no permitida)
	cout << "-Agregando repetidos a la lista(Sin permitirlo)(decre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[0], ListaD<int>::AGRE_DECRE, false ) << // agrego elemento repetido
		" ): " << numeros[0] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_INICIO, false ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // en el inicio de la Lista si especificar la repetición
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_FIN, false ) << // agrego elemento repetido
		" ): " << numeros[4] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	/* funcion miembro agregar() probadá-----------------------------------------------------------------------------*/
	
	int num = 1250;
	cout << "-Buscando en la lista( real, no existe en la lista)..." << endl;
	cout << "Busco( " << lista1->buscar( &numeros[5] ) << 
		" ): " << numeros[5] << " | "; 
	cout << "Busco( " << lista1->buscar( &num ) << 
		" ): " << num << " | " << endl << endl;
	/* funcion miembro buscar() probadá ----------------------------------------------------------------------------------*/
	
	// elimimando de la lista
	cout << "-Eliminando de la lista( elementos especificos )..." << endl;
	int eliminando[7] = { 0, 9, 25, 1, 10, 7, 4 };
	
	// eliminando de la lista elementos especificos 
	for( int x = 0; x < 7; x++ )
		cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_ELEMENTO), &eliminando[x] ) << " ): " << eliminando[x] << " | ";
	// muestro la lista
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	// eliminando de la lista especificando posicion y elemento( combinacion invalida de argumentos)
	cout << endl << ".-eliminando de la lista( combinacion de argumentos invalida)..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_INICIO, &eliminando[3] ) << " ): " << eliminando[3] << " | ";
	cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_FINAL), &eliminando[4] ) << " ): " << eliminando[4] << " | ";
	cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_ELEMENTO) ) << " ): " << "NULL" << " | ";
	// muestro la lista		
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	// eliminando de la lista al inicio y al final
	cout << endl << ".-Eliminando de la lista( inicio y fin )..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_INICIO ) << " ): " << "Incio"<< " | ";
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_FINAL ) << " ): " << "Final" << " | ";
	// muestro la lista		
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	
	cout << endl << ".-Elimimnando de la lista(elemento que no existe)..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_ELEMENTO, &eliminando[2] ) << " ): " << eliminando[2] << " | ";
			
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	cout << endl;
	cout << "Elimino( " << 
			lista1->eliminar() << " ): " << "Fin" << " | ";
	
			
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	
	cout << endl << "Elimino( " << 
			lista1->eliminar() << " ): " << "Ultimo" << endl;
			
	cout << ".-Antes de agregar a la lista..." << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;  
	/* funcion miembro eliminar probadá-------------------------------------------------------------------------*/
	
	
	cout << endl << "Elimino( " << 
			lista1->eliminar() << " ): " << "Lista vacia" << endl;
} // fin de probarListaSimpleCircular


void probarListaDoble()
{
	// probando con lista doble de enteros
	cout << "*) Lista Doble de enteros..." << endl;
	
	ListaD<int>* lista1 = new ListaD<int>( true, false ); // constructor con dos argumentos ( es doble pero no circular)
	int numeros[7] = { 4, 1, 7, 10, 25, 0, 9 };
	
	// Lista con constructor predeterminado
	cout << ".-Lista1(constructor con dos argumentos):" << endl;
	cout << "-Tipo de Lista..." << endl;
	cout << ".Circular: " << lista1->isCircu() << endl;
	cout << ".Doble: " << lista1->isDoble() << endl << endl;
	/* constructores probados ----------------------------------------------------------------------------*/
	
	// Pruebas solo con lista1
	// Lista vacia, antes de agregar
	cout << ".-Antes de agregar a la lista..." << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	
	
	// agregando a la lista, llamando a agregar con un solo argumento( creciente con repeticion permitida)
	cout << ".-Agregando a la lista(creciente)..." << endl;
	for( int x = 0; x < 7; x++ )
		cout << "agrego( " << lista1->agregar( &numeros[x] ) << " ): " << numeros[x] << " | ";
	// muestro la lista	
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion permitida)
	cout << "-Agregando repetidos a la lista(permitiendolo)(cre, cre, cre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[0] ) << " ): " << numeros[0] << " | "; // agrego elemento repetido 
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_CRE ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_CRE, true ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_INICIO ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // en el inicio de la Lista si especificar la repetición
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_FIN, true ) << // agrego elemento repetido
		" ): " << numeros[5] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion no permitida)
	cout << "-Agregando repetidos a la lista(Sin permitirlo)(cre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_CRE, false ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_INICIO, false ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // en el inicio de la Lista especificando la repetición
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_FIN, false ) << // agrego elemento repetido
		" ): " << numeros[5] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	
	// elimino la lista complte 
	cout << ".-Elimino la lista completa..." << endl;
	lista1->eliminarLista();
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	/* funcion miembro eliminarLista() probado ----------------------------------------------------------------*/
	
	
	// agregando a la lista, llamando a agregar con dos argumentos( creciente con repeticion permitida)
	cout << ".-Agregando a la lista(decreciente)..." << endl;
	for( int x = 0; x < 7; x++ )
		cout << "agrego( " << lista1->agregar( &numeros[x], ListaD<int>::AGRE_DECRE ) << " ): " << numeros[x] << " | ";
	// muestro la lista	
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion permitida)
	cout << "-Agregando repetidos a la lista(permitiendolo)(decre, decre, inicio, fin)...." << endl; 
	cout << "agrego( " << lista1->agregar( &numeros[0], ListaD<int>::AGRE_DECRE ) << // agrego elemento repetido
		" ): " << numeros[0] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[6], ListaD<int>::AGRE_DECRE, true ) << // agrego elemento repetido
		" ): " << numeros[6] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_INICIO, true ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // en el inicio de la Lista especificando la repetición
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_FIN ) << // agrego elemento repetido
		" ): " << numeros[4] << endl; // al final de la lista sin especificar la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion no permitida)
	cout << "-Agregando repetidos a la lista(Sin permitirlo)(decre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[0], ListaD<int>::AGRE_DECRE, false ) << // agrego elemento repetido
		" ): " << numeros[0] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_INICIO, false ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // en el inicio de la Lista si especificar la repetición
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_FIN, false ) << // agrego elemento repetido
		" ): " << numeros[4] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	/* funcion miembro agregar() probadá-----------------------------------------------------------------------------*/
	
	int num = 1250;
	cout << "-Buscando en la lista( real, no existe en la lista)..." << endl;
	cout << "Busco( " << lista1->buscar( &numeros[5] ) << 
		" ): " << numeros[5] << " | "; 
	cout << "Busco( " << lista1->buscar( &num ) << 
		" ): " << num << " | " << endl << endl;
	/* funcion miembro buscar() probadá ----------------------------------------------------------------------------------*/
	
	// elimimando de la lista
	cout << "-Eliminando de la lista( elementos especificos )..." << endl;
	int eliminando[7] = { 0, 9, 25, 1, 10, 7, 4 };
	
	// eliminando de la lista elementos especificos 
	for( int x = 0; x < 7; x++ )
		cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_ELEMENTO), &eliminando[x] ) << " ): " << eliminando[x] << " | ";
	// muestro la lista
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	// eliminando de la lista especificando posicion y elemento( combinacion invalida de argumentos)
	cout << endl << ".-eliminando de la lista( combinacion de argumentos invalida)..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_INICIO, &eliminando[3] ) << " ): " << eliminando[3] << " | ";
	cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_FINAL), &eliminando[4] ) << " ): " << eliminando[4] << " | ";
	cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_ELEMENTO) ) << " ): " << "NULL" << " | ";
	// muestro la lista		
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	// eliminando de la lista al inicio y al final
	cout << endl << ".-Eliminando de la lista( inicio y fin )..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_INICIO ) << " ): " << "Incio"<< " | ";
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_FINAL ) << " ): " << "Final" << " | ";
	// muestro la lista		
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	
	cout << endl << ".-Elimimnando de la lista(elemento que no existe)..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_ELEMENTO, &eliminando[2] ) << " ): " << eliminando[2] << " | ";
			
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	cout << endl;
	cout << "Elimino( " << 
			lista1->eliminar() << " ): " << "Fin" << " | ";
	
			
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	
	cout << endl << "Elimino( " << 
			lista1->eliminar() << " ): " << "Ultimo" << endl;
			
	cout << ".-Antes de agregar a la lista..." << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;  
	/* funcion miembro eliminar probadá-------------------------------------------------------------------------*/
	
	
	cout << endl << "Elimino( " << 
			lista1->eliminar() << " ): " << "Lista vacia" << endl; 
} // fin de probarListaDoble


void probarListaDobleCircular()
{
	// probando con lista doble circular de enteros
	cout << "*) Lista Doble circular de enteros..." << endl;
	
	ListaD<int>* lista1 = new ListaD<int>( true, true ); // constructor con dos argumentos ( es doble y circular)
	int numeros[7] = { 4, 1, 7, 10, 25, 0, 9 };
	
	// Lista con constructor predeterminado
	cout << ".-Lista1(constructor con dos argumentos):" << endl;
	cout << "-Tipo de Lista..." << endl;
	cout << ".Circular: " << lista1->isCircu() << endl;
	cout << ".Doble: " << lista1->isDoble() << endl << endl;
	/* constructores probados ----------------------------------------------------------------------------*/
	
	// Pruebas solo con lista1
	// Lista vacia, antes de agregar
	cout << ".-Antes de agregar a la lista..." << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	
	
	// agregando a la lista, llamando a agregar con un solo argumento( creciente con repeticion permitida)
	cout << ".-Agregando a la lista(creciente)..." << endl;
	for( int x = 0; x < 7; x++ )
		cout << "agrego( " << lista1->agregar( &numeros[x] ) << " ): " << numeros[x] << " | ";
	// muestro la lista	
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion permitida)
	cout << "-Agregando repetidos a la lista(permitiendolo)(cre, cre, cre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[0] ) << " ): " << numeros[0] << " | "; // agrego elemento repetido 
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_CRE ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_CRE, true ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_INICIO ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // en el inicio de la Lista si especificar la repetición
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_FIN, true ) << // agrego elemento repetido
		" ): " << numeros[5] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion no permitida)
	cout << "-Agregando repetidos a la lista(Sin permitirlo)(cre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_CRE, false ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_INICIO, false ) << // agrego elemento repetido
		" ): " << numeros[4] << " | "; // en el inicio de la Lista especificando la repetición
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_FIN, false ) << // agrego elemento repetido
		" ): " << numeros[5] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	
	// elimino la lista complte 
	cout << ".-Elimino la lista completa..." << endl;
	lista1->eliminarLista();
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	/* funcion miembro eliminarLista() probado ----------------------------------------------------------------*/
	
	
	// agregando a la lista, llamando a agregar con dos argumentos( creciente con repeticion permitida)
	cout << ".-Agregando a la lista(decreciente)..." << endl;
	for( int x = 0; x < 7; x++ )
		cout << "agrego( " << lista1->agregar( &numeros[x], ListaD<int>::AGRE_DECRE ) << " ): " << numeros[x] << " | ";
	// muestro la lista	
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion permitida)
	cout << "-Agregando repetidos a la lista(permitiendolo)(decre, decre, inicio, fin)...." << endl; 
	cout << "agrego( " << lista1->agregar( &numeros[0], ListaD<int>::AGRE_DECRE ) << // agrego elemento repetido
		" ): " << numeros[0] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[6], ListaD<int>::AGRE_DECRE, true ) << // agrego elemento repetido
		" ): " << numeros[6] << " | "; // especificando la pos y la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_INICIO, true ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // en el inicio de la Lista especificando la repetición
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_FIN ) << // agrego elemento repetido
		" ): " << numeros[4] << endl; // al final de la lista sin especificar la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	
	// agregando a la lista repetidos( con repeticion no permitida)
	cout << "-Agregando repetidos a la lista(Sin permitirlo)(decre, inicio, fin)...." << endl;
	cout << "agrego( " << lista1->agregar( &numeros[0], ListaD<int>::AGRE_DECRE, false ) << // agrego elemento repetido
		" ): " << numeros[0] << " | "; // especificando la pos y no la repeticion
	cout << "agrego( " << lista1->agregar( &numeros[5], ListaD<int>::AGRE_INICIO, false ) << // agrego elemento repetido
		" ): " << numeros[5] << " | "; // en el inicio de la Lista si especificar la repetición
	cout << "agrego( " << lista1->agregar( &numeros[4], ListaD<int>::AGRE_FIN, false ) << // agrego elemento repetido
		" ): " << numeros[4] << endl; // al final de la lista especificando la repeticion
	// muestro la lista
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl << endl;
	/* funcion miembro agregar() probadá-----------------------------------------------------------------------------*/
	
	int num = 1250;
	cout << "-Buscando en la lista( real, no existe en la lista)..." << endl;
	cout << "Busco( " << lista1->buscar( &numeros[5] ) << 
		" ): " << numeros[5] << " | "; 
	cout << "Busco( " << lista1->buscar( &num ) << 
		" ): " << num << " | " << endl << endl;
	/* funcion miembro buscar() probadá ----------------------------------------------------------------------------------*/
	
	// elimimando de la lista
	cout << "-Eliminando de la lista( elementos especificos )..." << endl;
	int eliminando[7] = { 0, 9, 25, 1, 10, 7, 4 };
	
	// eliminando de la lista elementos especificos 
	for( int x = 0; x < 7; x++ )
		cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_ELEMENTO), &eliminando[x] ) << " ): " << eliminando[x] << " | ";
	// muestro la lista
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	// eliminando de la lista especificando posicion y elemento( combinacion invalida de argumentos)
	cout << endl << ".-eliminando de la lista( combinacion de argumentos invalida)..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_INICIO, &eliminando[3] ) << " ): " << eliminando[3] << " | ";
	cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_FINAL), &eliminando[4] ) << " ): " << eliminando[4] << " | ";
	cout << "Elimino( " << 
			lista1->eliminar( (ListaD<int>::ELIM_ELEMENTO) ) << " ): " << "NULL" << " | ";
	// muestro la lista		
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	// eliminando de la lista al inicio y al final
	cout << endl << ".-Eliminando de la lista( inicio y fin )..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_INICIO ) << " ): " << "Incio"<< " | ";
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_FINAL ) << " ): " << "Final" << " | ";
	// muestro la lista		
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	
	cout << endl << ".-Elimimnando de la lista(elemento que no existe)..." << endl;
	cout << "Elimino( " << 
			lista1->eliminar( ListaD<int>::ELIM_ELEMENTO, &eliminando[2] ) << " ): " << eliminando[2] << " | ";
			
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	cout << endl;
	cout << "Elimino( " << 
			lista1->eliminar() << " ): " << "Fin" << " | ";
	
			
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	
	
	cout << endl << "Elimino( " << 
			lista1->eliminar() << " ): " << "Ultimo" << endl;
			
	cout << ".-Antes de agregar a la lista..." << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;  
	/* funcion miembro eliminar probadá-------------------------------------------------------------------------*/
	
	
	cout << endl << "Elimino( " << 
			lista1->eliminar() << " ): " << "Lista vacia" << endl; 
} // fin de probarListaDobleCircular

void pruebaPunteros()
{
 	int num1 = 1;
 	int num2 = -1;
 	
	int* p1 = &num1;
	int** p2 = &p1;
	
	cout << "p1Valor: " << *p1 << endl;
	cout << "p1: " << p1 << endl;
	cout << "&p1: " << &p1 << endl;
	cout << "p2: " << p2 << endl;
	cout << "p2Valor: " << *p2 << endl;
	
	*p2 = &num2;
	
	cout << "p1Valor: " << *p1 << endl;
	cout << "p1: " << p1 << endl;
	cout << "p2: " << *p2 << endl;
	
	int **p3 = NULL;
	cout << "p3: " << p3 << endl << endl; 
	
	p1 = NULL;
	int **p4 = &p1;
	cout << "p1: " << p1 << endl;
	cout << "p4: " << p4 << endl;
	cout << "*p4: " << *p4 << endl;
} // fin de pruebaPunteros

void probarListaV1_1()
{
	// probando con listas simples de enteros
	cout << "*) Lista simple de enteros..." << endl;
	
	ListaD<int>* lista1 = new ListaD<int>(); // constructor predeterminado ( no es circular ni doble)
	ListaD<int>* lista2 = new ListaD<int>( false, false ); // constructor con dos argumentos
	int numeros[7] = { 4, 1, 7, 10, 25, 0, 9 };
	
	// lista con constructor de dos argumentos
	cout << ".-Lista2(constructor con dos argumentos):" << endl;
	cout << "-Tipo de Lista..." << endl;
	cout << ".Circular: " << lista2->isCircu() << endl;
	cout << ".Doble: " << lista2->isDoble() << endl;
	cout << "-Tamaño: " << lista2->getSize() << endl << endl << endl;
	
	// Lista con constructor predeterminado
	cout << ".-Lista1(constructor sin argumentos):" << endl;
	cout << "-Tipo de Lista..." << endl;
	cout << ".Circular: " << lista1->isCircu() << endl;
	cout << ".Doble: " << lista1->isDoble() << endl;
	cout << "-Tamaño: " << lista1->getSize() << endl << endl << endl;
	/* constructores probados ----------------------------------------------------------------------------*/
	
	// Pruebas solo con lista1
	// Lista vacia, antes de agregar
	cout << ".-Antes de agregar a la lista..." << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): ";
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << endl;
	cout << ".fin: " << lista1->getFin() << endl << endl;
	
	
	// agregando a la lista, llamando a agregar con un solo argumento( creciente con repeticion permitida)
	cout << ".-Agregando a la lista(creciente)..." << endl;
	for( int x = 0; x < 7; x++ )
		cout << "agrego( " << lista1->agregar( &numeros[x] ) << " ): " << numeros[x] << " | ";
	// muestro la lista	
	cout << endl;
	cout << ".Lista(Enlaces de lista): ";
	lista1->imprimir(); 
	cout << ".Lista(Todos los enlaces): " << endl;
	lista1->imprimir( false );
	cout << ".cab: " << lista1->getCab() << "| " << lista1->getCab()->getInfo() << endl;
	cout << ".fin: " << lista1->getFin() << "| " << lista1->getFin()->getInfo() << endl;
	cout << ".cab->pre: " << lista1->getCab()->getLink_pre() << endl;
	cout << ".fin->suc: " << lista1->getFin()->getLink_suc() << endl;
	cout << "-Tamaño: " << lista1->getSize() << endl << endl << endl;
	
	cout << " Imprimo la lista: " << endl;
	for( int i = 0; i < lista1->getSize(); i++ )
		cout << *lista1->getElemento_info( i ) << endl;
		
	cout << endl << endl << " Imprimo la lista: " << endl;
	for( int i = 0; i < lista1->getSize(); i++ )
		cout << *lista1->getElemento_nodo( i )->getInfo() << endl;
		
		
	cout << endl << endl << " Intento con indices negativos y que desborden el tamaño: " << endl;
	cout << lista1->getElemento_info( -1 ) << endl;
	cout << lista1->getElemento_info( 7 ) << endl;
	
	
	cout << endl << endl << endl << "libero memoria de la lista " << endl;
	delete lista1;
	
	cout << lista1->getElemento_nodo( 0 ) << endl;
}

void probarLista1_2()
{
	ListaD<Datos>* lista = new ListaD<Datos>();
	Datos* dato = new Datos( "Dilan", 20, 'M', 7.8 );
	
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	
	lista->imprimir();
	cout << lista->getSize() << endl;
	lista->eliminar( ListaD<Datos>::ELIM_INICIO );
	lista->imprimir();
	cout << lista->getSize() << endl;
	lista->eliminar( ListaD<Datos>::ELIM_FINAL );
	lista->imprimir();
	cout << lista->getSize() << endl;
	lista->eliminar( ListaD<Datos>::ELIM_ELEMENTO, dato );
	lista->imprimir();
	cout << lista->getSize() << endl;
	lista->eliminarLista();
	lista->imprimir();
	cout << lista->getSize() << endl << endl << endl;
	
	
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	lista->agregar( new Datos( "Dilan", 20, 'M', 7.8 ) );
	
	lista->imprimir();
	lista->imprimir(true);
	cout << lista->getSize() << endl << endl << endl;
	delete lista;
	//lista->imprimir();
	cout << lista->getSize() << endl << endl << endl;
}

int main(int argc, char** argv)
{

 	//probarListaSimple();
 	//probarListaSimpleCircular();
 	//probarListaDoble();
 	//probarListaDobleCircular();
 	//probarListaV1_1();
 	probarLista1_2();
 	//pruebaPunteros();
	return 0;
}









