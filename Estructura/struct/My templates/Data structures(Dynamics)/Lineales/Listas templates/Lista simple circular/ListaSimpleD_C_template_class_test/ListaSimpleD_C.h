/**
 *	@Autor: Dilan Useche
 *	@Date: 2/29/2016
 *	@Release: 2/29/2016
 *	@Version: 0.1
 */

#ifndef LISTASIMPLED_C_H
#define LISTASIMPLED_C_H

#include <cstdlib>
#include <iostream>
#include "Nodo.h"

/**
 *	@brief representacion de una estructura de datos lineal
 *	dinamica tipo lista simple dinamica circular,
 *	compatible con cualquier tipo de dato
 */
template<class T>
class ListaSimpleD_C
{
	public:
		Nodo<T>* fin; //  referencia al fin de la lista 
	public:
		/**
		 *	@brief inicializa la ListaSimpleD_C, asiganando a NULL
		 * 	la cabezera de la misma
		 *	@since 0.1
		 */
		ListaSimpleD_C(){ this->fin = NULL; }
		bool isVacia() const; // determina si la lista esta vacia
		bool agregar( T*, int pos = 3 ); // agrega un nuevo Nodo a la lista
		bool eliminar( T* ); // elimina un elemento de la lista
		void imprimir() const; // imprime la lista en el flujo std de salida	
}; // fin de ListaSimpleD_C


/**
 *	@brief determina si la lista esta vacia
 *	@since: 0.1
 *	@return bool true lista vacia, de lo contrario false
 */
template<class T> bool ListaSimpleD_C<T>::isVacia() const
{
	return !this->fin; // retorna desicion 
} // fin de isVacia


/**
 *	@brief agrega un nuevo elementos de datos o informacion 
 *	a la lista, creando un nuevo Nodo y asignanando a su 
 *	campo info el elemento de informacion especificado
 *	nota: en esta version de la función solo esta implementado
 * 	el caso 3( insertar en orden creciente )
 *	@since: 0.1
 *	@param T* campo de informacion del nuevo Nodo
 *	@param int posición u orden en el que se va insertar el 
 *	nuevo elemento; 1 inseta al inicio; 2 inserta al final;
 *	3 inserta en oreden creciente; 4 inserta en orden decresiente
 *	@return bool true exito al agregar, de lo contrario false,
 *	debido a falta de memoria
 */
template<class T> bool ListaSimpleD_C<T>::agregar( T* info, int pos )
{
	Nodo<T>* nuevo = new Nodo<T>( info ); // crea nuevo Nodo
	// recorrido empezara en la cabezera de la lista
	Nodo<T>* recor = ( this->fin ? this->fin->getLink_suc() : NULL ); 
	Nodo<T>* antes = this->fin; // antes sera el fin de la lista
	bool enc = false; // determina si se encuentra posicion en la lista
	
	
	if( nuevo ) // si la asignacion de memoria tuvo exito
	{
		// mientras la lista no este vacia
		while( recor && !enc )
		{
			// si nuevo es menor a recor 
			if( nuevo->getInfo() < recor->getInfo() )
				enc = true;
			else
			{
				antes = recor; // antes sera recor 
				recor = recor->getLink_suc(); // recor sera su sucesor 
			
				// si se rrecorrio toda la lista 
				if( recor == this->fin->getLink_suc() )
					break; // dejo de buscar
			} // fin del if...else
		} // fin del while
		
		// si la lista esta vacia 
		if( !recor )
			antes = recor = nuevo; // antes y recor serán nuevo
			
		nuevo->setLink_suc( recor ); // suc de nuevo sera recor
		antes->setLink_suc( nuevo ); // suc de antes será nuevo
		
		// si no se encontro posición en la lista
		if( !enc )
			this->fin = nuevo; // fin ahora sera nuevo
	}
	else // de lo contrario, no habia memoria suficiente
		return false; // fallo al agregar por falta de memoria
		
	return true; // exito al agregar
} // fin de agregar


/**
 *	@brief elimina el Nodo con el campo info especificado  
 *	@since: 0.1
 *	@return bool true exito al eliminar, false si la lista
 *	esta vacia, o si no se encuentra el elemento a eliminar
 */
template<class T> bool ListaSimpleD_C<T>::eliminar( T* info )
{
	// Nodo a eliminar de la lista empezar siendo la cabezera
	Nodo<T>* recor = ( this->fin ? this->fin->getLink_suc() : NULL ); 
	Nodo<T>* antes = this->fin; // Nodo anterior a eliminar 
	bool enc = false; // determina si se encontro elemento a eliminar
	
	
	if( !this->isVacia() ) // si la lista no esta vacia
	{	
		// mientras eliminar no se haya encontrado
		while( !enc )
		{
			// si se encuentra el elemento a eliminar
			if( recor->getInfo() == *info )
				enc = true;
			else
			{
				// antes sera recor y recor sera su sucesor
				antes = recor;
				recor = recor->getLink_suc();
				
				// si se rrecorrio toda la lista 
				if( recor == this->fin->getLink_suc() )
					break; // dejo de buscar
			} // fin del if...else
		} // fin del while
		
		// si se encontro el elemento a eliminar
		if( enc )
		{
			antes->setLink_suc( recor->getLink_suc() ); // antes sera suc de recor
			
			// si recor y antes son el mismo (solo hay un elemento)
			if( recor == antes ) // this->fin == this->fin->getLink_suc() && recor == this->fin
				this->fin = NULL; // fin sera NULL
				
			// si recor es igual a fin( ultimo elemento a eliminar)
			if( recor == this->fin )
				this->fin = antes;
	
			delete recor; // elimino Nodo liberando memoria
		}
		else
			return false; // no se encontro el elemento
	}
	else // de lo contrario, esta vacia la lista
		return false; // lista vacia
		
	return true; // exito al eliminar
} // fin de eliminar


/**
 *	@brief imprime la lista en el flujo std de salida,
 *	si la lista esta vacia, se imprime "NULL"
 *	@since: 0.1
 */
template<class T> void ListaSimpleD_C<T>::imprimir() const
{
	// El recorrido empezara en la cabezera de la lista
	Nodo<T>* recor = ( this->fin ? this->fin->getLink_suc() : NULL );
	bool empezado = false; // determina si ya se empezo el recorrido 
	
	// se la lista no esta vacia
	if( recor )
	{
		while( recor != this->fin->getLink_suc() || !empezado ) // mientras no se salga de la lista
		{
			// si no se ha empezado la impresion
			if( !empezado )
				empezado = true; // empezado es verdadero 
			
			if( recor == this->fin )
				std::cout << recor->getInfo() << "|-->" << recor->getLink_suc()->getInfo(); // imprime Nodo
			else
				std::cout << recor->getInfo() << "-->"; // imprime Nodo
				
			recor = recor->getLink_suc(); // recor pasa a su sucesor
		} // end while
	}
	else
		std::cout << "NULL" << std::endl; // lista vacia
		
	std::cout << std::endl; // linea en blanco
} // fin de imprimir


#endif
