#ifndef LIB_INV_STACK_H
#define LIB_INV_STACK_H


#include <new>


template <class T>
struct inv_Item_Stack  // elemento de una pila
{
	inv_Item_Stack* previus;
	T value;
};


template <class T>
class inv_Stack
{
	private:
		inv_Item_Stack<T> *item;  // puntero al elemento Actual
		int n_items;  // número de elementos de la pila
		
	public:
		inv_Stack() : item(nullptr), n_items(0) {}  // crear una pila vacía
		~inv_Stack();  // eliminar la pila
		
		bool push(T _value);  // introduce un elemento en la pila
		bool pop(T* _dest);  // extrae el último elemento en la pila
		bool peek(T* _dest);  // visualiza el último elemento de la pila sin extraerlo
		void clear();  // borra todos los elementos de la pila
		
		int getN_items();  // cantidad de elementos en la pila
		T* getArray();  // obtener un vector con la información de la pila
		bool loadArray(T* _array, int _size);  // introduce los datos de un array en la pila
};

template <class T>
inv_Stack<T>::~inv_Stack()
{
	if(item)
	{
		while(item->previus)
		{
			inv_Item_Stack<T> *auxItem = item;
			item = item->previus;
			delete auxItem;
		}
		delete item;
	}
}

template <class T>
inline bool inv_Stack<T>::push(T _value)
{
	inv_Item_Stack<T> *auxItem = new (std::nothrow) inv_Item_Stack<T>();
	if(auxItem)
	{
		auxItem->value = _value;
		auxItem->previus = item;
		item = auxItem;
		n_items++;
		return true;
	}
	return false;
}

template <class T>
inline bool inv_Stack<T>::pop(T* _dest)
{
	if(item)
	{
		*_dest = item->value;
		
		inv_Item_Stack<T> *auxItem = item;
		item = item->previus;
		delete auxItem;
		n_items--;
		return true;
	}
	return false;
}

template <class T>
inline bool inv_Stack<T>::peek(T* _dest)
{
	if(item)
	{
		*_dest = item->value;
		return true;
	}
	return false;
}

template <class T>
inline void inv_Stack<T>::clear()
{
	inv_Item_Stack<T> *auxItem;
	while(item)
	{
		auxItem = item;
		item = item->previus;
		delete auxItem;
	}
	n_items = 0;
}

template <class T>
inline int inv_Stack<T>::getN_items()
{
	return n_items;
}

template <class T>
inline T* inv_Stack<T>::getArray()
{
	T* array = new (std::nothrow) T[n_items];
	if(array)
	{
		inv_Item_Stack<T> *buffItem = item;
		for(int i=n_items-1; i>=0; i--)
		{
			array[i] = buffItem->value;
			buffItem = buffItem->previus;
		}
	}
	return array;
}

template <class T>
inline bool inv_Stack<T>::loadArray(T* _array, int _size)
{
	for(int i=0; i<_size; i++)
	{
		if(!push(_array[i]))
		{
			return false;
		}
	}
	return true;
}


#endif
