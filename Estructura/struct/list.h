#ifndef LIST_H
#define LIST_H

#include <new>
#include <stdio.h>


/* --------------- Lista ---------------
Lista dinámica
*/

template <typename T>
struct Node
{
	T info;
	Node<T> *previous;
	Node<T> *next;
};


template <typename T>
class List
{
	private:
		Node<T> *node;  // puntero al nodo actual
		int n_items;  // número de elementos insertados
		
	public:
		List() : node(nullptr), n_items(0) {}  // la lista comienza "vacía"
		~List() {clear();}
		
		bool insert(const T& _source, bool (*comp)(const T& _source, const T& _info));  // insertar en orden (comp retorna true cuando _source < _info)
		bool insertBack(const T& _source);  // insertar un nuevo elemento en la posición siguiente al actual
		bool insertFront(const T& _source);  // insertar un nuevo elemento en la posición anterior al actual
		bool extract(T* _dest);  // extraer el elemento seleccionado de la lista
		bool peek(T* _dest);  // obtener el valor del nodo actual
		bool setInfo(const T& _source);  // establece un valor para el elemento actual
		
		void toStart();  // desplazarse al inicio de la lista
		void toEnd();  // desplazarse al final de la lista
		bool toNext();  // ir al siguiente nodo
		bool toPrevious();  // ir al elemento nodo
		
		void clear();  // vaciar lista
		
		void print(void (*f)(T& _item));  // imprimir contenido
};

template <typename T> bool List<T>::insert(const T& _source, bool (*comp)(const T& _data1, const T& _data2))
{
	if(node)
	{
		toStart();
		do
		{
			if(comp(_source, node->info))  // si el dato a ingresar es inferior al almacenado en el nodo actual
			{
				return insertFront(_source);
			}
		}
		while(toNext());
	}
	return insertBack(_source);  // si todos los datos de la lista son inferiores al dato a ingresar
}
template <typename T> bool List<T>::insertBack(const T& _source)
{
	Node<T> *buffNode = new (std::nothrow) Node<T>;
	if(buffNode)
	{
		buffNode->info = _source;
		if(node)  // si hay elementos en la lista
		{
			buffNode->previous = node;
			buffNode->next = node->next;
			if(node->next) node->next->previous = buffNode;
			node->next = buffNode;
			node = buffNode;
		}
		else  // si la lista está vacía
		{
			buffNode->previous = buffNode->next = nullptr;
			node = buffNode;
		}
		n_items++;
		return true;
	}
	return false;
}
template <typename T> bool List<T>::insertFront(const T& _source)
{
	Node<T> *buffNode = new (std::nothrow) Node<T>;
	if(buffNode)
	{
		buffNode->info = _source;
		if(node)  // si hay elementos en la lista
		{
			buffNode->previous = node->previous;
			buffNode->next = node;
			if(node->previous) node->previous->next = buffNode;
			node->previous = buffNode;
			node = buffNode;
		}
		else  // si la lista está vacía
		{
			buffNode->previous = buffNode->next = nullptr;
			node = buffNode;
		}
		n_items++;
		return true;
	}
	return false;
}
template <typename T> bool List<T>::extract(T* _dest)
{
	if(node)
	{
		Node<T> *auxNode = node;
		if(node->previous) node->previous->next = node->next;
		if(node->next) node->next->previous = node->previous;
		
		if(node->previous)
		{
			node = node->previous;
		}
		else
		{
			node = node->next;
		}
		
		*_dest = auxNode->info;
		delete auxNode;
		n_items--;
		return true;
	}
	return false;
}
template <typename T> bool List<T>::peek(T* _dest)
{
	if(node)
	{
		*_dest = node->info;
		return true;
	}
	return false;
}
template <typename T> bool List<T>::setInfo(const T& _source)
{
	if(node)
	{
		node->info = _source;
		return true;
	}
	return false;
}

template <typename T> void List<T>::toStart()
{
	while(toPrevious())
	{
		// no ocurre nada mientras se recorre la lista~
	}
}
template <typename T> void List<T>::toEnd()
{
	while(toNext())
	{
		// no ocurre nada mientras se recorre la lista~
	}
}
template <typename T> inline bool List<T>::toNext()
{
	if(node && node->next)
	{
		node = node->next;
		return true;
	}
	return false;
}
template <typename T> inline bool List<T>::toPrevious()
{
	if(node && node->previous)
	{
		node = node->previous;
		return true;
	}
	return false;
}

template <typename T> void List<T>::clear()
{
	toStart();
	Node<T> *auxNode;
	while(node)  // mientras la liste contenga elementos
	{
		auxNode = node;  // guardar dirección del actual
		node = node->next;  // avanzar al siguiente
		delete auxNode;  //eliminar el actual
	}
}

template <typename T> void List<T>::print(void (*f)(T& _item))
{
	printf("\n List: %d\n", n_items);
	if(node)
	{
		toStart();
		int i=0;
		do
		{
			printf("#%d ", i);
			f(node->info);  // se llama a la función que imprime el contenido de un elemento
			printf("\n");
			i++;
		}
		while(toNext());
	}
}


#endif
