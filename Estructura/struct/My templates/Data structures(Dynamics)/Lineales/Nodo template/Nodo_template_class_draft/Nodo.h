#ifndef NODO_H
#define NODO_H
#include <cstdlib>

template <class T >
class Nodo
{
	public:
		Nodo<T>* enlace;
		T* info;
		Nodo( T* informacion ){ enlace = NULL; info = informacion; }
		~Nodo();
};

template<class T> Nodo<T>::~Nodo(){}

#endif
