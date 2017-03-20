/**
 *	@Autor: Dilan Useche
 *	@Date: 2/27/2016
 *	@Release: 2/28/2016
 *	@Version: 0.1
 */

#ifndef COLAD_H
#define COLAD_H

#include <cstdlib>
#include "Nodo.h"


/**
 *	@brief representacion de una estructura de datos lineal
 *	dinamica tipo cola, compatible con cualquier tipo de dato
 */
template<class T>
class ColaD
{
	private:
		Nodo<T>* frente; // frente de la ColaD
		Nodo<T>* fin; // fin de la ColaD
		bool isVacia() const; // determina si la ColaD esta vacia
		
	public:
		/**
		 *	@brief inicializa la ColaD, asiganando a NULL
		 * 	el frente y el fin de la misma
		 *	@since 0.1
		 */
		ColaD(){ this->frente = this->fin = NULL; };
//		~ColaD(); 
		bool agregar( T* ); // agrega un nuevo Nodo a la ColaD
		bool eliminar(); // elimina el Nodo en el frente de la ColaD
		void imprimir() const; // imprime la ColaD en el flujo std de salida	
		
		
}; // fin de ColaD


/**
 *	@brief determina si la ColaD esta vacia
 *	@since: 0.1
 *	@return bool true ColaD vacia, de lo contrario false
 */
template<class T> bool ColaD<T>::isVacia() const
{
	return !this->frente; // retorna desicion 
} // fin de isVacia


/**
 *	@brief agrega un nuevo elementos de datos o informacion 
 *	a la ColaD, creando un nuevo Nodo y asignanando a su 
 *	campo info el elemento de informacion especificado
 *	@since: 0.1
 *	@param T* campo de informacion del nuevo Nodo
 *	@return bool true exito al agregar, de lo contrario false,
 *	debido a falta de memoria
 */
template<class T> bool ColaD<T>::agregar( T* info )
{
	Nodo<T>* nuevo = new Nodo<T>( info ); // crea nuevo Nodo
	
	
	if( nuevo ) // si la asignacion de memoria tuvo exito
	{
		if( this->isVacia() )
			this->frente = this->fin = nuevo;
		else
		{
			this->fin->setLink_pre( nuevo );
			this->fin = nuevo;
		}
	}
	else // de lo contrario, no habia memoria suficiente
		return false; // fallo al agregar por falta de memoria
} // fin de agregar


/**
 *	@brief elimina el Nodo actual en el frente de ColaD
 *	@since: 0.1
 *	@return bool true exito al eliminar, false si la ColaD
 *	esta vacia
 */
template<class T> bool ColaD<T>::eliminar()
{
	Nodo<T>* eliminar; // Nodo a eliminar de la ColaD
	
	
	if( !this->isVacia() ) // si la colaD no esta vacia
	{
		eliminar = this->frente; // eliminar sera el frente
		
		if( this->frente == this->fin )
			this->frente = this->fin = NULL;
		else
			this->frente = this->frente->getLink_pre(); // frente ahora sera el predecesor del mismo 
			
			
		delete eliminar; // elimina Nodo en el tope, liberando memoria
	}
	else // de lo contrario, esta vacia la ColaD
		return false; // ColaD vacia
} // fin de eliminar


/**
 *	@brief imprime la ColaD en el flujo std de salida,
 *	si la ColaD esta vacia, se imprime "NULL"
 *	@since: 0.1
 */
template<class T> void ColaD<T>::imprimir() const
{
	Nodo<T>* recor = this->frente; // El recorrido empezara en el frente de la ColaD
	
	
	while( recor ) // mientras no se salga de la ColaD
	{
		std::cout << recor->getInfo() << "-->"; // imprime Nodo
		recor = recor->getLink_pre(); // recor pasa a su predecesor
	} // end while
	
	
	std::cout << "NULL" << std::endl; // imprime enlace del ultimo Nodo
} // fin de imprimir

#endif
