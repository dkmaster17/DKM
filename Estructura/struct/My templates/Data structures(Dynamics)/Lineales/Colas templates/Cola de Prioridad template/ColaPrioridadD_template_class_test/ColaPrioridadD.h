/**
 *	@Autor: Dilan Useche
 *	@Date: 2/29/2016
 *	@Release: 2/29/2016
 *	@Version: 0.1
 */

#ifndef COLAPRIORIDADD_H
#define COLAPRIORIDADD_H

#include <cstdlib>
#include "Nodo.h"


/**
 *	@brief representacion de una estructura de datos lineal
 *	dinamica tipo cola de prioridad, compatible con cualquier
 *	tipo de dato
 */
template<class T>
class ColaPrioridadD
{
	private:
		Nodo<T>* frente; // frente de la cola principal
		Nodo<T>* fin; // fin de la cola principal
	public:
		/**
		 *	@brief inicializa la ColaPrioridadD, asignando a NULL el
		 *	frente y fin de su cola principal
		 *	@since 0.1
		 */
		ColaPrioridadD(){ this->frente = this->fin = NULL; }
		bool isVacia() const; // determina si la ColaPrioridadD esta vacía
		Nodo<T>* buscar( T* ); // busca un campo info en la cola principal
		int agregar( T*, int cola = 3 ); // agrega un nuevo Nodo a la ColaPrioridadD
		bool eliminar(); // elimina un Nodo en el frente de la ColaPrioridadD
		void imprimir() const; // imprime la ColaPrioridadD en el flujo std de salida
}; // fin de ColaPrioridadD


/**
 *	@brief determina si la ColaPrioridadD esta vacia
 *	@since: 0.1
 *	@return bool true ColaPrioridadD vacia, de lo contrario false
 */
template<class T> bool ColaPrioridadD<T>::isVacia() const
{
	return !this->frente; // retorna desicion 
} // fin de isVacia



/**
 *	@brief busca un campo info en la cola principal 
 *	@since: 0.1
 *	@return const Nodo<T>* const referencia al Nodo que contiene
 *	el campo info especificado. Si no se encuentra el campo info
 *	especificado en la cola principal, se retornará una referencia
 *	a NULL. La comparación dependera totalmente
 *	de la sobrecarga del operador == en la clase del campo info.
 *	Para efectos donde el campo info de la cola principal sea diferente 
 *	al compo info de la subcola, debe tomarse en cuenta cuando se 
 *	sobrecargue el operador == en cualquiera de las dos clases
 *	que el operando izquierdo sera la clase de la cola principal
 * 	y el operando derecho sera la clase de la subcola 
 */
template<class T> Nodo<T>* ColaPrioridadD<T>::buscar( T* info )
{
	// recorrido empezara en el frente de la cola principal
	Nodo<T>* recor = this->frente;
	
	
	// mientras recor no se vuelva NULL
	while( recor )
	{
		// si se encuentra el campo info
		if( recor->getInfo() == *info ) 
			return recor; // retorno referencia al Nodo 
			
			
		recor = recor->getLink_ext(); // recor sera su pre(ext)
	} // fin del while
	
	
	return recor; // retorna una referencia a NULL
} // fin de buscar


/**
 *	@brief agrega un nuevo elementos de datos o informacion 
 *	a la ColaPrioridadD, creando un nuevo Nodo y asignando 
 *	a su campo info el elemento de informacion especificado.
 *	Para añadir los nuevos Nodos a la ColaPrioridadD se 
 *	comparan sus campos info, esta comparación dependera totalmente
 *	de la sobrecarga del operador == en la clase del campo info.
 *	nota: los enlaces en la plantilla Nodo para los Nodos
 *	en la cola principal se interpretan de la siguiente manera:
 *	link_ext sera el predecesor del Nodo; link_pre sera el 
 *	frente de la subcola; link_suc sera el fin de la subcola  
 *	@since: 0.1
 *	@param T* campo de informacion del nuevo Nodo
 *	@param int 1 agrega a la cola principal; 2 agrega a la subcola
 *	correspondiente en la cola principal; 3 agrega tanto a la cola 
 *	principal como a la subcola
 *	@return -1 no se pudo agregar un Nodo de subcola, debido a que la 
 *	la cola principal esta vacia; -2 no se pudo agregar un Nodo de subcola
 *	debido a que no se encuentra el Nodo relacionado en la cola principal;
 *	0 no se pudo agregar un Nodo debido a falla en la aignación de memoria;
 *	1 se pudo agregar con exito el Nodo
 */
template<class T> int ColaPrioridadD<T>::agregar( T* info, int cola )
{
	// si se quiere agregar un Nodo a una subcola pero la cola principal 
	if( this->isVacia() && cola == 2 ) // esta vacia 
		return -1; // imposible agregar Nodo a subcola
		

	// crea nuevo Nodo de cola principal y secundaria		
	Nodo<T>* nuevo_cp = new Nodo<T>( info ); // Nodo cola principal 
	Nodo<T>* nuevo_cs = new Nodo<T>( info ); // Nodo cola secundaria
	
	
	if( nuevo_cp && nuevo_cs ) // si la asignacion de memoria tuvo exito
	{
		// si no se añadira a una subcola
		if( cola == 1 )
			delete nuevo_cs; // libero nodo de subcola
			
			
		// si se quiere agregar Nodo a la cola principal
		if( cola == 1 || cola == 3 )
		{
			if( this->isVacia() ) // si la cola principal esta vacia
				this->frente = this->fin = nuevo_cp; // frente y fin a nuevo
			else // si la cola principal no esta vacía
			{
				this->fin->setLink_ext( nuevo_cp ); // pre(ext) de fin a nuevo
				this->fin = nuevo_cp; // fin ahora sera nuevo
			} // fin del if...else	
		} // fin del if
		
		
		// si se quiere agregar a una subcola
		if( cola == 2 || cola == 3 )
		{
			// almacena referencia si se encuentra el campo info 
			Nodo<T>* nodoP; // relacionado en la cola principal 
			nodoP = this->buscar( info ); // busca en al cola principal
			
			
			if( !nodoP ) // si no se encontro en al cola principal
				return -2; // imposible agregar Nodo de subcola
			
				 
			if( !nodoP->getLink_pre() ) // si la subcola esta vacia
			{
				nodoP->setLink_pre( nuevo_cs ); // frente de la subcola a nuevo
				nodoP->setLink_suc( nuevo_cs ); // fin de la subcola a nuevo
			}
			else // si la subcola no esta vacía
			{	
				nodoP->getLink_suc()->setLink_pre( nuevo_cs ); // pre del fin de la subcola a nuevo
				nodoP->setLink_suc( nuevo_cs ); // fin de la subcola ahora sera nuevo
			}  // fin del if..else
		} // fin del if
	}
	else // de lo contrario, no habia memoria suficiente
		return 0; // fallo al agregar por falta de memoria
		
	return 1; // exito al agregar
} // fin de agregar


/**
 *	@brief elimina el Nodo frente actual de la subcola
 *	en el frente de la cola principal. Si solo hay un Nodo
 *	en la subcola, se eliminara el Nodo asociado en la cola
 *	principal.
 *	nota: los enlaces en la plantilla Nodo para los Nodos
 *	en la cola principal se interpretan de la siguiente manera:
 *	link_ext sera el predecesor del Nodo; link_pre sera el 
 *	frente de la subcola; link_suc sera el fin de la subcola 
 *	@since: 0.1
 *	@return bool true exito al eliminar, false si la cola 
 *	principal esta vacia
 *	esta vacia
 */
template<class T> bool ColaPrioridadD<T>::eliminar()
{
	Nodo<T>* eliminar_cp; // Nodo a eliminar de la cola principal
	Nodo<T>* eliminar_cs; // Nodo a eliminar de la subcola
	
	
	if( !this->isVacia() ) // si la cola principal no esta vacia
	{
		eliminar_cp = this->frente; // eliminar de CP sera el frente
		// eliminar de la CS sera el frente de la misma
		eliminar_cs = this->frente->getLink_pre();
		
		// si el frente y fin de la subcola son el mismo Nodo
		if( this->frente->getLink_pre() == this->frente->getLink_suc() )
		{ 
			// si la subcola no esta vacia 
			if( this->frente->getLink_pre() != NULL )
				delete eliminar_cs; // libero Nodo de subcola
				
				
			// si el frente y fin de la cola princial son el mismo
			if( this->frente == this->fin ) // Nodo
				this->frente = this->fin = NULL; // frente y fin a NULL
			else
				this->frente = this->frente->getLink_ext(); // frente sera el pre de si mismo
				
			delete eliminar_cp; // libero Nodo de la SC y de la CP
		}
		else // si no son el mimos Nodo( mas de un Nodo en la cola principal)
		{
			// frente de la subcola sera el predecesor del mismo 
			this->frente->setLink_pre( eliminar_cs->getLink_pre() );
			delete eliminar_cs; // libero Nodo de la subcola
		} // fin del if...else 
	}
	else // de lo contrario, esta vacia la ColaPrioridadD
		return false; // ColaPrioridadD esta vacia
		
	return true; // exito al eliminar
} // fin de eliminar


/**
 *	@brief imprime la ColaPrioridadD en el flujo std de salida,
 *	si la ColaPrioridadD esta vacia, se imprime "NULL"
 *	@since: 0.1
 */
template<class T> void ColaPrioridadD<T>::imprimir() const
{
	// El recorrido de CP empezara en el frente de la cola principal
	Nodo<T>* recor_cp = this->frente; 
	Nodo<T>* recor_cs; // para recorrer cada subcola
	
	
	while( recor_cp ) // mientras no se salga de la cola principal
	{
		// el recorrido de CS empezara en el frente de la misma
		recor_cs = recor_cp->getLink_pre();
		
		// imprime Nodo de la cola principal
		std::cout << "|" << recor_cp->getInfo() << "|" << "--->";
		
		
		while( recor_cs ) // mientras no se salga de la subcola
		{
			// imprime Nodo de la subcola
			std::cout << recor_cs->getInfo() << "-->"; 
			recor_cs = recor_cs->getLink_pre(); // recor CS pasa a su predecesor
		} // fin del while
		
		
		std::cout << "NULL" << std::endl; // imprime enlace del ultimo Nodo
		std::cout << "!" << std::endl;  
		recor_cp = recor_cp->getLink_ext(); // recor CP pasa a su predecesor
	} // fin del while
	
	
	std::cout << "NULL" << std::endl; // imprime enlace del ultimo Nodo
} // fin de imprimir

#endif
