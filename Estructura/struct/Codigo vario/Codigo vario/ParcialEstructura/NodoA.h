/**
 *	@Autor: Dilan Useche
 *	@Date: 2/27/2016
 *	@Release: 23/4/2016
 *	@Version: 1.2
 */

#ifndef NodoA_H
#define NodoA_H


/**
 *	@brief representacion de un NodoA de información 
 *	para cualquier estructura de datos, con capacidad
 *	de simple o doble enlace. La interpretación de los
 *	enlaces solo es una convención de La plantilla NodoA;
 * 	ya que pueden interpretarse de la manera que más convenga 
 */
template<class T> 
class NodoA
{
	private: 
		// enlace a otro NodoA, interpretado como el NodoA
		NodoA<T>* link_pre; // predecesor del NodoA actual
		// enlace a otro NodoA, interpretado como el NodoA
		NodoA<T>* link_suc; // sucesor del NodoA actual
		T* info; // campo de informacon asociada al NodoA
	public:
		/**
		 *	@brief inicializa el NodoA
		 *	@since 0.1
		 *	@param T* campo de informacion del NodoA
		 */
		explicit NodoA( T* inf ) : info( inf ) 
		{ this->link_pre = this->link_suc = NULL; } 
		~NodoA(); // destructor de NodoA
		NodoA<T>* getLink_pre() const; // retorna enlace predecesor
		NodoA<T>* getLink_suc() const; // retorna enlance sucesor
		T* getInfo() const; // retorna apuntador a campo de información del NodoA
		void setLink_pre( NodoA<T>* const ); // establece predecesor
		void setLink_suc( NodoA<T>* const ); // establece sucesor
		void setInfo( T* const ); // establece campo info 
}; // fin de la template class NodoA


/**
 *	@brief libera memoria del campo info del NodoA 
 *	y asigna a NULL todos sus apuntadores
 *	nota: si la memeoria del campo info del NodoA
 *	no fue asiganada con el operador new el comportamiento 
 *	del destructor no esta definido y puede traer 
 *	incovenientes inesperados, por lo tanto, se recomienda 
 *	solo enviar al contructor de NodoA objetos instaciados con
 *	el operador new 
 *	@since 1.2
 */
template<class T> NodoA<T>::~NodoA()
{
	delete this->info; // libera memoria campo info
	
	// asigana a NULL apuntadores
	this->link_pre = this->link_suc = NULL;
	this->info = NULL;
} // fin del destructor


/**
 *	@brief devuelve referencia al NodoA interpretdo como predecesor
 *	@since 0.1
 *	@return NodoA<T>* referencia al NodoA predecesor
 */
 template<class T> NodoA<T>* NodoA<T>::getLink_pre() const
 {
	return this->link_pre; // retorna referencia
 } // fin de getLink_pre
 
 
/**
 *	@brief devuelve referencia al NodoA interpretdo como sucesor
 *	@since 0.1
 *	@return NodoA<T>* referencia al NodoA sucesor
 */
template<class T> NodoA<T>* NodoA<T>::getLink_suc() const
{
	return this->link_suc; // retorna referencia
} // fin de getLink_suc


/**
 *	@brief devuelve apuntador al campo de informacion del NodoA
 *	@since 1.1
 *	@param bool solo por cuestiones de sobrecarga
 *	@return T* apuntador campo de informacion del NodoA
 */
template<class T> T* NodoA<T>::getInfo() const 
{
	return this->info; // retorna campo info
} // fin de getInfo


 /**
 *	@brief establece el NodoA predecesor del NodoA actual
 *	@since 0.1
 *	@param NodoA<T>* const NodoA predecesor
 */
template<class T> void NodoA<T>::setLink_pre( NodoA<T>* const pre ) 
{
	this->link_pre = pre;
} // fin de de setLink_pre


 /**
 *	@brief establece el NodoA sucesor del NodoA actual
 *	@since 0.1
 *	@param NodoA<T>* const NodoA sucesor
 */
template<class T> void NodoA<T>::setLink_suc( NodoA<T>* const suc ) 
{
	this->link_suc = suc;
} // fin de de setLink_suc


 /**
 *	@brief establece el campo info del NodoA actual
 *	@since 0.3
 *	@param const T* const campo info 
 */
template<class T> void NodoA<T>::setInfo( T* const inf ) 
{
	delete this->info; // libero campo info actual
	this->info = inf; // referencio al nuevo campo info
} // fin de de setLink_ext

#endif

