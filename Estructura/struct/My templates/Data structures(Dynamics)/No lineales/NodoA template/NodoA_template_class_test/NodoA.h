/**
 *	@Autor: Dilan Useche
 *	@Date: 9/4/2016
 *	@Release: 9/4/2016
 *	@Version: 1.0
 */

#ifndef NODOA_H
#define NODOA_H


/**
 *	@brief representacion de un Nodo de informaci�n 
 *	para una estructura de datos de tipo arbol,
 *	con capacidad de doble enlace. La interpretaci�n de los
 *	enlaces solo es una convenci�n de La plantilla NodoA;
 * 	ya que pueden interpretarse de la manera que m�s convenga 
 */
template<class T>
class NodoA
{
	private: 
		// enlace a otro NodoA, interpretado como el NodoA
		NodoA<T>* link_hd; // hijo derecho del NodoA actual
		// enlace a otro Nodo, interpretado como el NodoA
		NodoA<T>* link_hi; // hijo izquierdo del NodoA actual
		T* info; // campo de informacon asociada al NodoA
		int nivel; // nivel del NodoA en su Arbol
		int altura_der; // altura del subArbol derecho del NodoA
		int altura_izq; // altura del subArbol izquierdo del NodoA
		int altura; // altura del subArbol m�s grande del NodoA
		int factorE; // factor de equilibrio del NodoA
	public:
		/**
		 *	@brief inicializa el NodoA
		 *	@since 1.0
		 *	@param T* campo de informacion del NodoA
		 */
		explicit NodoA( T* inf ) : info( inf ) 
		{ 
			this->link_hd = this->link_hi = NULL;
			this->altura = this->altura_der = this->altura_izq = 0;
			this->nivel = this->factorE = 0; 
		} // fin del NodoA
		NodoA<T>* getLink_hd() const; // retorna enlace predecesor
		NodoA<T>* getLink_hi() const; // retorna enlance sucesor
		T getInfo() const; // retorna campo de informacion del Nodo
		T* getInfo( bool ) const; // retorna apuntador a campo de informaci�n del Nodo
		int getNivel() const; // retorn nivel del NodoA en su Arbol
		int getAltura_der() const; // retorna altura del subArbol derecho del NodoA
		int getAltura_izq() const; // retorna altura del subArbol izquierdo del NodoA
		int getAltura() const; // retorna altura del subArbol m�s grande del NodoA
		int getFactorE() const; // retorna el factor de equilibrio del NodoA
		void setLink_hd( NodoA<T>* const ); // establece predecesor
		void setLink_hi( NodoA<T>* const ); // establece sucesor
		void setInfo( T* const ); // establece campo info 
		void setNivel( int ); // establece el nivel del NodoA en su Arbol
		void setAltura_der( int ); // establece altura del subArbol derecho del NodoA
		void setAltura_izq( int ); // establece altura del subArbol izquierdo del NodoA
		void setAltura( int ); // establece altura del subArbol m�s grande del NodoA
		void setFactorE( int ); // establece factor de equilibrio del NodoA
};


/**
 *	@brief devuelve apuntador al NodoA interpretdo como hijo derecho
 *	@since 1.0
 *	@return NodoA<T>* apuntador al Nodo del hijo derecho
 */
 template<class T> NodoA<T>* NodoA<T>::getLink_hd() const
 {
	return this->link_hd; // retorna apuntador
 } // fin de getLink_hd
 
 
/**
 *	@brief devuelve referencia al Nodo interpretdo como hijo izquierdo
 *	@since 1.0
 *	@return NodoA<T>* referencia al Nodo hijo izquierdo
 */
template<class T> NodoA<T>* NodoA<T>::getLink_hi() const
{
	return this->link_hi; // retorna referencia
} // fin de getLink_hi


/**
 *	@brief devuelve copia del campo de informacion del nodo
 *	@since 1.0
 *	@return T copia del campo de informacion del Nodo
 */
template<class T> T NodoA<T>::getInfo() const 
{
	return *(this->info); // retorna campo info
} // fin de getInfo


/**
 *	@brief devuelve apuntador al campo de informacion del nodo
 *	@since 1.0
 *	@param bool solo por cuestiones de sobrecarga
 *	@return T* apuntador campo de informacion del Nodo
 */
template<class T> T* NodoA<T>::getInfo( bool sobrecarga ) const 
{
	return this->info; // retorna apuntador a campo info
} // fin de getInfo


/**
 *	@brief retorna nivel del NodoA en su Arbol
 *	@since 1.0
 *	@return int nivel del NodoA en su Arbol
 */
template<class T> int NodoA<T>::getNivel() const
{
	return this->nivel;
} // fin de getNivel

/**
 *	@brief retorna altura del subArbol derecho del NodoA
 *	@since 1.0
 *	@return int altura del subArbol derecho del NodoA
 */
template<class T> int NodoA<T>::getAltura_der() const
{
	return this->altura_der;
} // fin de getAltura_der


/**
 *	@brief retorna altura del subArbol izquierdo del NodoA
 *	@since 1.0
 *	@return int altura del subArbol izquierdo del NodoA
 */
template<class T> int NodoA<T>::getAltura_izq() const
{
	return this->altura_izq;
} // fin de getAltura_izq


/**
 *	@brief retorna altura del subArbol m�s grande del NodoA
 *	@since 1.0
 *	@return int altura del subArbol m�s grande del NodoA
 */
template<class T> int NodoA<T>::getAltura() const
{
	return this->altura;
} // fin de getAltura


/**
 *	@brief retorna el factor de equilibrio del NodoA
 *	@since 1.0
 *	@return int factor de equilibrio del NodoA
 */
template<class T> int NodoA<T>::getFactorE() const
{
	return this->factorE;
} // fin de getFactorE


 /**
 *	@brief establece el Nodo hijo derecho del Nodo actual
 *	@since 1.0
 *	@param NodoA<T>* const Nodo hijo derecho
 */
template<class T> void NodoA<T>::setLink_hd( NodoA<T>* const hd ) 
{
	this->link_hd = hd;
} // fin de de setLink_hd


 /**
 *	@brief establece el Nodo hijo izquierdo del Nodo actual
 *	@since 1.0
 *	@param NodoA<T>* const Nodo hijo izquierdo
 */
template<class T> void NodoA<T>::setLink_hi( NodoA<T>* const hi ) 
{
	this->link_hi = hi;
} // fin de de setLink_hi


 /**
 *	@brief establece el campo info del Nodo actual
 *	@since 1.0
 *	@param const T* const campo info 
 */
template<class T> void NodoA<T>::setInfo( T* const inf ) 
{
	delete this->info; // libero campo info actual
	this->info = inf; // referencio al nuevo campo info
} // fin de de setLink_ext


 /**
 *	@brief establece el nivel del NodoA en su Arbol
 *	@since 1.0
 *	@param int nivel del NodoA en su Arbol
 */
template<class T> void NodoA<T>::setNivel( int nivel )
{
	this->nivel = nivel;
} // fin de de setNivel


 /**
 *	@brief establece altura del subArbol derecho del NodoA
 *	@since 1.0
 *	@param int altura del subArbol derecho del NodoA
 */
template<class T> void NodoA<T>::setAltura_der( int altura_der )
{
	this->altura_der = altura_der;
} // fin de de setAltura_der


 /**
 *	@brief establece altura del subArbol izquierdo del NodoA
 *	@since 1.0
 *	@param int altura del subArbol izquierdo del NodoA
 */
template<class T> void NodoA<T>::setAltura_izq( int altura_izq )
{
	this->altura_izq = altura_izq;
} // fin de de setAltura_izq


 /**
 *	@brief establece altura del subArbol m�s grande del NodoA
 *	@since 1.0
 *	@param int altura del subArbol m�s grande del NodoA
 */
template<class T> void NodoA<T>::setAltura( int altura )
{
	this->altura = altura;
} // fin de de setAltura


 /**
 *	@brief establece factor de equilibrio del NodoA
 *	@since 1.0
 *	@param int factor de equilibrio del NodoA
 */
template<class T> void NodoA<T>::setFactorE( int factorE )
{
	this->factorE = factorE;
} // fin de de setFactorE


#endif
