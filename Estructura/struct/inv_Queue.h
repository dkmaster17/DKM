#ifndef LIB_INV_QUEUE_H
#define LIB_INV_QUEUE_H


#include <new>


template <class T>
struct inv_Item_Queue  // elemento de una cola
{
	inv_Item_Queue* next;
	T value;
};


template <class T>
class inv_Queue
{
	private:
		inv_Item_Queue<T> *lastItem;  // puntero al último elemento de la cola
		inv_Item_Queue<T> *firstItem;  // puntero al primer elemento de la cola
		int n_items;
		
	public:
		inv_Queue() : lastItem(nullptr), firstItem(nullptr), n_items(0) {}  //crear una cola vacía
		~inv_Queue();  // eliminar la cola
		
		bool push(T _value);  // introduce un elemento en el final de la cola
		bool pop(T* _dest);  // extrae el primer elemento en la cola
		bool peekFirst(T* _dest);  // visualiza el primer elemento de la cola sin extraerlo
		bool peekLast(T* _dest);  // visualiza el último elemento de la cola sin extraerlo
		void clear();  // borra todos los elementos de la cola
		
		int getN_items();  // cantidad de elementos en la cola
		T* getArray();  // obtener un vector con la información de la cola
		bool loadArray(T* _array, int _size);  // introduce los datos de un array en la cola
};

template <class T>
inv_Queue<T>::~inv_Queue()
{
	if(firstItem)
	{
		while(firstItem->next)
		{
			inv_Item_Queue<T> *auxItem = firstItem;
			firstItem = firstItem->next;
			delete auxItem;
		}
		delete firstItem;
	}
}

template <class T>
inline bool inv_Queue<T>::push(T _value)
{
	inv_Item_Queue<T> *auxItem = new (std::nothrow) inv_Item_Queue<T>();
	if(auxItem)
	{
		auxItem->value = _value;
		auxItem->next = nullptr;
		
		lastItem? (lastItem = lastItem->next = auxItem) : (firstItem = lastItem = auxItem);
		n_items++;
		return true;
	}
	return false;
}

template <class T>
inline bool inv_Queue<T>::pop(T* _dest)
{
	if(firstItem)
	{
		*_dest = firstItem->value;
		
		inv_Item_Queue<T> *auxItem = firstItem;
		firstItem = firstItem->next;
		delete auxItem;
		n_items--;
		if(!n_items) lastItem = nullptr;
		return true;
	}
	return false;
}

template <class T>
inline bool inv_Queue<T>::peekFirst(T* _dest)
{
	if(firstItem)
	{
		*_dest = firstItem->value;
		return true;
	}
	return false;
}

template <class T>
inline bool inv_Queue<T>::peekLast(T* _dest)
{
	if(lastItem)
	{
		*_dest = lastItem->value;
		return true;
	}
	return false;
}

template <class T>
inline void inv_Queue<T>::clear()
{
	inv_Item_Queue<T> *auxItem;
	while(firstItem)
	{
		auxItem = firstItem;
		firstItem = firstItem->next;
		delete auxItem;
	}
	lastItem = nullptr;
	n_items = 0;
}

template <class T>
inline int inv_Queue<T>::getN_items()
{
	return n_items;
}

template <class T>
inline T* inv_Queue<T>::getArray()
{
	T* array = new (std::nothrow) T[n_items];
	if(array)
	{
		inv_Item_Queue<T> *buffItem = firstItem;
		for(int i=0; i<n_items; i++)
		{
			array[i] = buffItem->value;
			buffItem = buffItem->next;
		}
	}
	return array;
}

template <class T>
inline bool inv_Queue<T>::loadArray(T* _array, int _size)
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
