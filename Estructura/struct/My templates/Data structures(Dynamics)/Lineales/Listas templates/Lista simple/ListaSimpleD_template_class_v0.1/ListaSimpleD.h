/**
 *	@Autor: Dilan Useche
 *	@Date: 2/29/2016
 *	@Release: 2/29/2016
 *	@Version: 0.1
 */

#ifndef LISTASIMPLED_H
#define LISTASIMPLED_H

#include <cstdlib>
#include "Nodo.h"


/**
 *	@brief representacion de una estructura de datos lineal
 *	dinamica tipo lista simple, compatible con cualquier tipo de dato
 */
template<class T>
class ListaSimpleD
{
	private:
		Nodo<T>* cab; // cabezera al inicio de la lista 
	public:
		/**
		 *	@brief inicializa la ListaSimpleD, asiganando a NULL
		 * 	la cabezera de la misma
		 *	@since 0.1
		 */
		ListaSimpleD(){ this->cab = NULL; }
		bool isVacia() const; // determina si la lista esta vacia
		bool agregar( T*, int pos = 3 ); // agrega un nuevo Nodo a la lista
		bool eliminar( T* ); // elimina un elemento de la lista
		void imprimir() const; // imprime la lista en el flujo std de salida	
}; // fin de ListaSimpleD



/**
 *	@brief determina si la lista esta vacia
 *	@since: 0.1
 *	@return bool true lista vacia, de lo contrario false
 */
template<class T> bool ListaSimpleD<T>::isVacia() const
{
	return !this->cab; // retorna desicion 
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
template<class T> bool ListaSimpleD<T>::agregar( T* info, int pos )
{
	Nodo<T>* nuevo = new Nodo<T>( info ); // crea nuevo Nodo
	Nodo<T>* recor = this->cab; // recorrido empezara en cab
	Nodo<T>* antes = NULL; // antes sera NULL
	
	
	if( nuevo ) // si la asignacion de memoria tuvo exito
	{
		while( recor )
		{
			// si el nuevo Nodo es menor al Nodo recor
			if( nuevo->getInfo() < recor->getInfo() )
				break; // salgo del recorrido
				
			antes = recor; // antes sera ahora recor	
			recor = recor->getLink_suc(); // recor sera su sucesor 
		} // fin del while 
		
		
		// si la inserción es al inicio de la lista 
		if( recor == this->cab )
		{
			nuevo->setLink_suc( this->cab ); // suc de nuevo sera cab 
			this->cab = nuevo; // cab sera nuevo
		} 
		else // si la insercion no es al inicio de la lista
		{
			antes->setLink_suc( nuevo ); // suc de antes sera nuevo
			nuevo->setLink_suc( recor ); // suc de nuevo sera recor 
		} // fin del if...else
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
template<class T> bool ListaSimpleD<T>::eliminar( T* info )
{
	Nodo<T>* eliminar = this->cab; // Nodo a eliminar de la lista
	Nodo<T>* antes; // Nodo anterior a eliminar 
	
	if( !this->isVacia() ) // si la lista no esta vacia
	{	
		while( eliminar ) // mientras recor no sea NULL
		{
			// si recor es igual a los buscado
			if( eliminar->getInfo() == *info )
				break; // salgo del ciclo
		
			antes = eliminar;	
			eliminar = eliminar->getLink_suc(); // recor sera su sucesor 
		} // fin del while 
		
		
		// si no se encuentra el elemento a eliminar
		if( !eliminar ) 
			return false; // fallo al eliminar
		
		// si se va a eliminar la cabezera de la lista 
		if( eliminar == this->cab )
			this->cab = this->cab->getLink_suc(); // cab sera su sucesor 
		else
			antes->setLink_suc( eliminar->getLink_suc() );
					
		delete eliminar; // elimina Nodo	
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
template<class T> void ListaSimpleD<T>::imprimir() const
{
	// El recorrido empezara en la cabezera de la lista
	Nodo<T>* recor = this->cab; 
	
	
	while( recor ) // mientras no se salga de la lista
	{
		std::cout << recor->getInfo() << "-->"; // imprime Nodo
		recor = recor->getLink_suc(); // recor pasa a su sucesor
	} // end while
	
	
	std::cout << "NULL" << std::endl; // imprime enlace del ultimo Nodo
} // fin de imprimir

#endif
