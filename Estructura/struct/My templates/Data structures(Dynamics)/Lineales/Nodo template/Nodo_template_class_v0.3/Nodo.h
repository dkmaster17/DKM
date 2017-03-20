/**
 *	@Autor: Dilan Useche
 *	@Date: 2/27/2016
 *	@Release: 2/28/2016
 *	@Version: 0.3
 */

#ifndef NODO_H
#define NODO_H
#include <cstdlib>


/**
 *	@brief representacion de un Nodo de informaci�n 
 *	para cualquier estructura de datos, con capacidad
 *	de simple o doble enlace. La interpretaci�n de los
 *	enlaces solo es una convenci�n de La plantilla Nodo;
 * 	ya que pueden interpretarse de la manera que m�s convenga 
 */
template<class T> 
class Nodo
{
	private: 
		// enlace a otro Nodo, interpretado como el Nodo
		Nodo<T>* link_pre; // predecesor del Nodo actual
		// enlace a otro Nodo, interpretado como el Nodo
		Nodo<T>* link_suc; // sucesor del Nodo actual
		// enlace a otro Nodo, interpretado como un Nodo
		Nodo<T>* link_ext; // externo a otra estructura
		T* info; // campo de informacon asociada al Nodo
	public:
		/**
		 *	@brief inicializa el Nodo
		 *	@since 0.1
		 *	@param T* campo de informacion del Nodo
		 */
		explicit Nodo( T* inf ) : info( inf ) 
		{ this->link_pre = this->link_suc = this->link_ext = NULL; } 
		~Nodo(); // libera recursos asociados al Nodo
		Nodo<T>* getLink_pre() const; // retorna enlace predecesor
		Nodo<T>* getLink_suc() const; // retorna enlance sucesor
		Nodo<T>* getLink_ext() const; // retorna enlace externo
		T getInfo() const; // retorna campo de informacion del Nodo
		void setLink_pre( Nodo<T>* const ); // establece predecesor
		void setLink_suc( Nodo<T>* const ); // establece sucesor
		void setLink_ext( Nodo<T>* const ); // estabablece enlace externo 
		void setInfo( T* const ); // establece campo info 
}; // fin de la template class Nodo


/**
 *	@brief liberas recursos asocaidos al Nodo
 *	@since 0.1
 */
template<class T> Nodo<T>::~Nodo(){} // fin del destructor


/**
 *	@brief devuelve referencia al Nodo interpretdo como predecesor
 *	@since 0.1
 *	@return Nodo<T>* referencia al Nodo predecesor
 */
 template<class T> Nodo<T>* Nodo<T>::getLink_pre() const
 {
	return this->link_pre; // retorna referencia
 } // fin de getLink_pre
 
 
/**
 *	@brief devuelve referencia al Nodo interpretdo como sucesor
 *	@since 0.1
 *	@return Nodo<T>* referencia al Nodo sucesor
 */
template<class T> Nodo<T>* Nodo<T>::getLink_suc() const
{
	return this->link_suc; // retorna referencia
} // fin de getLink_suc
 
 
 /**
 *	@brief devuelve referencia al Nodo interpretdo como externo
 *	@since 0.3
 *	@return Nodo<T>* referencia al Nodo externo
 */
template<class T> Nodo<T>* Nodo<T>::getLink_ext() const
{
	return this->link_ext; // retorna referencia
} // fin de getLink_ext


/**
 *	@brief devuelve copia del campo de informacion del nodo
 *	@since 0.1
 *	@return T copia del campo de informacion del Nodo
 */
template<class T> T Nodo<T>::getInfo() const 
{
	return *(this->info); // retorna campo info
} // fin de getInfo


 /**
 *	@brief establece el Nodo predecesor del Nodo actual
 *	@since 0.1
 *	@param Nodo<T>* const Nodo predecesor
 */
template<class T> void Nodo<T>::setLink_pre( Nodo<T>* const pre ) 
{
	this->link_pre = pre;
} // fin de de setLink_pre


 /**
 *	@brief establece el Nodo sucesor del Nodo actual
 *	@since 0.1
 *	@param Nodo<T>* const Nodo sucesor
 */
template<class T> void Nodo<T>::setLink_suc( Nodo<T>* const suc ) 
{
	this->link_suc = suc;
} // fin de de setLink_suc


 /**
 *	@brief establece el Nodo externo del Nodo actual
 *	@since 0.3
 *	@param Nodo<T>* const Nodo externo
 */
template<class T> void Nodo<T>::setLink_ext( Nodo<T>* const ext ) 
{
	this->link_ext = ext;
} // fin de de setLink_ext


 /**
 *	@brief establece el campo info del Nodo actual
 *	@since 0.3
 *	@param const T* const campo info 
 */
template<class T> void Nodo<T>::setInfo( T* const inf ) 
{
	delete this->info; // libero campo info actual
	this->info = inf; // referencio al nuevo campo info
} // fin de de setLink_ext

#endif











