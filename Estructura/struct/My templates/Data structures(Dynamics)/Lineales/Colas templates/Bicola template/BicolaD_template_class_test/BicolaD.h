/**
 *	@Autor: Dilan Useche
 *	@Date: 2/28/2016
 *	@Release: 10/3/2016
 *	@Version: 1.0
 */


#ifndef BICOLAD_H
#define BICOLAD_H

#include <cstdlib>
#include "Nodo.h"


/**
 *	@brief representacion de una estructura de datos lineal
 *	dinamica tipo bicola, compatible con cualquier tipo de dato
 */
 template<class T>
class BicolaD
{
	private:
		Nodo<T>* frente; // frente de la BicolaD
		Nodo<T>* fin; // fin de la BicolaD
		bool tipo; // tipo de BicolaD 
	public:
		/**
		 *	@brief inicializa la BicolaD, asiganando a NULL
		 * 	el frente y el fin de la misma, y establece su tipo
		 *	@param bool true entrada registringida, false salida restringida 
		 *	@since 0.1
		 */
		BicolaD( bool t )  : tipo( t )
		{ this->frente = this->fin = NULL; }
		Nodo<T>* getFrente() const; // retorna frente de la BicolaD
		Nodo<T>* getFin() const; // retorna el fin de la BicolaD
		bool getTipo() const; // retorna tipo de la BicolaD
		bool isVacia() const; // determina si la BicolaD esta vacia
		bool agregar( T*, bool tipoE = true ); // agrega un nuevo Nodo a la BicolaD
		bool eliminar( bool tipoS = false ); // elimina el Nodo en el frente de la BicolaD
		void imprimir( int dir = 3 ) const; // imprime la BicolaD en el flujo std de salida
	protected:
}; // fin de la BicolaD


/**
 *	@brief retorna apuntador al Nodo en el frente de la BicolaD
 *	@since: 1.0
 *	@return Nodo<T>* apuntador al frente de la ColaD
 */
 template<class T> Nodo<T>* BicolaD<T>::getFrente() const
 {
	return this->frente; 
 } // fin de getFrente
 
 
/**
 *	@brief retorna apuntador al Nodo en el fin de la BicolaD
 *	@since: 1.0
 *	@return Nodo<T>* apuntador al fin de la ColaD
 */
 template<class T> Nodo<T>* BicolaD<T>::getFin() const
 {
	return this->fin; 
 } // fin de getFin
 
 
 /**
 *	@brief retorna tipo de la BicolaD
 *	@since: 1.0
 *	@return bool true entrada restringida, false salida restringida
 */
 template<class T> bool BicolaD<T>::getTipo() const
 {
	return this->tipo;
 } // fin de getTipo
 
 
/**
 *	@brief determina si la BicolaD esta vacia
 *	@since: 0.1
 *	@return bool true BicolaD vacia, de lo contrario false
 */
template<class T> bool BicolaD<T>::isVacia() const
{
	return !this->frente; // retorna desicion 
} // fin de isVacia


/**
 *	@brief agrega un nuevo elementos de datos o informacion 
 *	a la BicolaD, creando un nuevo Nodo y asignanando a su 
 *	campo info el elemento de informacion especificado
 *	@since: 0.1
 *	@param T* campo de informacion del nuevo Nodo
 *	@param bool tipo de entrada, false entrada por el frente,
 *	de lo contrario entrada por el fin. Si es una BicolaD de entrada
 *	restringida debe omitirse el segundo parámetro, si no se hace,
 *	este igualmente no se tomara en cuenta. Si se omite el parámetro
 *	en una BicolaD de salida restringida, la entrada se hará por 
 *	defecto por el fin de la cola  
 *	@return bool true exito al agregar, de lo contrario false,
 *	debido a falta de memoria
 */
template<class T> bool BicolaD<T>::agregar( T* info, bool tipoE )
{
	Nodo<T>* nuevo = new Nodo<T>( info ); // crea nuevo Nodo
	
	
	if( nuevo ) // si la asignacion de memoria tuvo exito
	{
		if( this->isVacia() ) // si esta vacia
		{   
			// frente y fin ahora sera el nuevo Nodo
			this->frente = this->fin = nuevo; 
			return true; // exito al agregar
		} // fin del if
			
			
		// si es de entrada restringida, o si no lo es, pero
		if( this->tipo || tipoE ) // se quiere insertar por el fin
		{   
			// inserto por el fin de la Bicola    
			this->fin->setLink_pre( nuevo ); // nuevo será pre de fin
			nuevo->setLink_suc( this->fin ); // fin será suc de nuevo
			this->fin = nuevo; // fin sera ahora el nuevo Nodo
		}
		else // si no, se quiere insertar por el frente de la BicolaD
		{
			// inserto por el frente de la BicolaD
			this->frente->setLink_suc( nuevo ); // nuevo será suc de frente
			nuevo->setLink_pre( this->frente ); // frente será pre de nuevo
			this->frente = nuevo; // frente sera ahora el nuevo Nodo
		} // fin del if...else
	}
	else // de lo contrario, no habia memoria suficiente
		return false; // fallo al agregar por falta de memoria
		
	return true; // exito al agregar
} // fin de agregar



/**
 *	@brief elimina el Nodo actual en el frente o fin de
 *	la BicolaD dependiendo del tipo de la misma 
 *	@since: 0.1
 *	@param bool tipo de eliminación, false eliminación por el frente,
 *	de lo contrario eliminación por el fin. Si es una BicolaD de salida
 *	restringida debe omitirse el parámetro, si no se hace,
 *	este igualmente no se tomara en cuenta. Si se omite el 
 *	parámetro en una Bicola de entrada restringida, la eliminación
 *	se hará por defecto por el frente de la cola
 *	@return bool true exito al eliminar, false si la BicolaD
 *	esta vacia
 */
template<class T> bool BicolaD<T>::eliminar( bool tipoS )
{
	Nodo<T>* eliminar; // Nodo a eliminar de la BicolaD
	
	
	if( !this->isVacia() ) // si la BicolaD no esta vacia
	{
		if( this->frente == this->fin ) // si solo hay un Nodo
		{
			this->frente = this->fin = NULL; // lista vacia 
			return true; // exito al eliminar
		} // fin del if
		
		
		// si es entrada restringida, o si no lo es, pero
		if( !this->tipo || !tipoS) // se quiere eliminar por el frente
		{
			eliminar = this->frente; // eliminar sera el frente

			// frente ahora sera el predecesor del mismo 
			this->frente = this->frente->getLink_pre(); 
			this->frente->setLink_suc( NULL );
		}
		else // si no, se quiere eliminar ppr el fin de la BicolaD
		{
			eliminar = this->fin;
			
			// fin ahora sera el sucesor del mismo
			this->fin = this->fin->getLink_suc();
			this->fin->setLink_pre( NULL );	
		} // fin del if...else
			
			
		delete eliminar; // elimina Nodo, liberando memoria
	}
	else // de lo contrario, esta vacia la BicolaD
		return false; // BicolaD vacia
		
		
	return true; // exito al eliminar
} // fin de eliminar


/**
 *	@brief imprime la BicolaD en el flujo std de salida,
 *	si la BicolaD esta vacia, se imprime "NULL"
 *	@param int direccion de la impresión, 1: de frente a fin;
 *	2: de fin a frente; 3: ambas direcciones. Si se omite el
 *	parámetro la BicolaD será impresa en ambas direcciones
 *	@since: 0.1
 */
template<class T> void BicolaD<T>::imprimir( int dir ) const
{
	// El recorrido empezara en el frente de la BicolaD
	Nodo<T>* recor = this->frente; 
	
	
	if( dir == 1 || dir == 3 ) // si se quiere imprimir de frente a fin
	{
		while( recor ) // mientras no se salga de la bicolaD
		{
			std::cout << recor->getInfo() << "-->"; // imprime Nodo
			recor = recor->getLink_pre(); // recor pasa a su predecesor
		} // end while
		
		std::cout << "NULL" << std::endl; // imprime enlace del ultimo Nodo
	} // fin del if
	
	
	// El recorrido empezara en el fin de la BicolaD
	recor = this->fin;
	
	if( dir == 2 || dir == 3 ) // si se quiere impirmir de fin a frente 
	{
		while( recor ) // mientras no se salga de la bicolaD
		{
			std::cout << recor->getInfo() << "-->"; // imprime Nodo
			recor = recor->getLink_suc(); // recor pasa a su predecesor
		} // end while
		
		std::cout << "NULL" << std::endl; // imprime enlace del ultimo Nodo
	} // din del if
} // fin de imprimir

#endif
