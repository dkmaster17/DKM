#ifndef LIB_INV_LIST_H
#define LIB_INV_LIST_H


#include <new>



/* --------------- Node ---------------
Nodo de una lista doblemente enlazada. Puede almacenar cualquier valor (variables, punteros,
otras estructuras complejas, etc).
*/

template <class T>
struct inv_Node_List
{
	inv_Node_List* previous;  // puntero al siguiente nodo
	inv_Node_List* next;  // puntero al nodo anterior
	T value;  // valor almacenado por el nodo
};



/* --------------- Iterator ---------------
Objeto capaz de recorrer una lista doblemente enlazada. Quedan invalidados cuando la estructura
de la lista es alterada (por ejemplo, al insertar o eliminar un nodo), en tal caso deben reinicializarse.
Se utilizan para leer y modificar «los valores de los nodos» que ya conforman la lista.
*/

template <class T>
class inv_Iterator
{
	private:
		inv_Node_List<T> *node;
	
	public:
		inv_Iterator(inv_Node_List<T> *_node) : node(_node) {}
		
		bool toNext();  // mueve el iterador al siguiente elemento de la lista
		bool toPrevious();  // mueve el iterador al elemento anterior de la lista
		bool toFirst();  // ir hasta la primera posición
		bool toLast();  // ir hasta la última posición
		
		bool getCurrent(T* _dest);  // obtener el valor del elemento apuntado por el iterador
		bool getNext(T* _dest);  // obtener el valor del elemento que está inmediatamente después del iterador
		bool getPrevious(T* _dest);  // obtener el valor del elemento que está inmediatamente antes del iterador
};
template <class T> inline bool inv_Iterator<T>::toNext()  // mueve el cursor al elemento siguiente de la lista
{
	if(node && node->next)  // si el nodo existe y también existe el sucesor
	{
		node = node->next;  // ir al siguiente y retornar TRUE
		return true;
	}
	return false;  // no se pudo avanzar, retornar FALSE
}
template <class T> inline bool inv_Iterator<T>::toPrevious()  // mueve el cursor al elemento anterior de la lista
{
	if(node && node->previous)  // si el nodo existe y también existe el predecesor
	{
		node = node->previous;  // ir al anterior y retornar TRUE
		return true;
	}
	return false;  // no se pudo retroceder, retornar FALSE
}
template <class T> inline bool inv_Iterator<T>::toFirst()
{
	while(toPrevious());  // ir hasta la primera posición
}
template <class T> inline bool inv_Iterator<T>::toLast()
{
	while(toNext());  // ir hasta la última posición
}
template <class T> inline bool inv_Iterator<T>::getCurrent(T* _dest)
{
	if(node)  // si el nodo existe
	{
		*_dest = node->value;  // devolver el valor del nodo actual
		return true;
	}
	return false;
}
template <class T> inline bool inv_Iterator<T>::getNext(T* _dest)
{
	if(node && node->next)  // si el nodo existe y también existe el sucesor
	{
		*_dest = node->next->value;  // devolver el valor del siguiente nodo
		return true;
	}
	return false;
}
template <class T> inline bool inv_Iterator<T>::getPrevious(T* _dest)
{
	if(node && node->previous)  // si el nodo existe y también existe el predecesor
	{
		*_dest = node->previous->value;  // devolver el valor del nodo anterior
		return true;
	}
	return false;
}



/* --------------- List ---------------
Objeto que controla estructuralmente una lista doblemente enlazada
*/

template <class T>
class inv_List
{
	private:
		inv_Node_List<T> *currentNode;  // elemento apuntado por el cursor
		inv_Node_List<T> *firstNode;  // primer elemento
		inv_Node_List<T> *lastNode;  // último elemento
		int n_items;  // número de elementos de la lista
		int index;  // índice del elemento apuntado por el cursor
		
	public:
		inv_List() : currentNode(nullptr), firstNode(nullptr), lastNode(nullptr), n_items(0), index(0) {}
		~inv_List();
		
		bool addFirst(T _value);  // añadir un elemento al inicio de la lista
		bool addLast(T _value);  // añadir un elemento al final de la lista
		bool insertFront(T _value);  // insertar un elemento enfrente (antes) del elemento actual
		bool insertBack(T _value);  // insertar un elemento detrás (después) del elemento actual
		// devuelven TRUE si se reservó memoria correctamente y si la posición indicada es válida, FALSE en caso contrario
		
		bool remove();  // eliminar el elemento actual
		bool removeFirst();  // eliminar el primer elemento de la lista
		bool removeLast();  // eliminar el último elemento de la lista
		// devuelven FALSE si la lista está vacía, TRUE en caso contrario
		
		bool toNext();  // mueve el cursor al siguiente elemento de la lista
		bool toPrevious();  // mueve el cursor al elemento anterior de la lista
		bool toIndex(int _index);  // mueve el cursor al elemento en la posición indicada
		bool toFirst();  // saltar al primer elemento de la lista
		bool toLast();  // saltar al último elemento de la lista
		// devuelven TRUE sólo si el cursor puede moverse hacia la posición indicada, FALSE en caso contrario
		
		bool getCurrent(T* _dest);  // obtener el valor del elemento apuntado por el cursor
		bool getNext(T* _dest);  // obtener el valor del elemento que está inmediatamente después del cursor
		bool getPrevious(T* _dest);  // obtener el valor del elemento que está inmediatamente antes del cursor
		bool getOnIndex(T* _dest, int _index);  // obtener el valor del elemento en la posición indicada
		bool getFirst(T* _dest);  // obtener el valor del primer elemento de la lista
		bool getLast(T* _dest);  // obtener el valor del último elemento de la lista
		// devuelven TRUE sólo si existe la posición indicada, FALSE en caso contrario; getOnIndex() mueve el cursor
		
		bool setCurrent(T _value);  // asignar un valor al elemento apuntado por el cursor
		bool setNext(T _value);  // asignar un valor al elemento  que está inmediatamente después del cursor
		bool setPrevious(T _value);  // asignar un valor al elemento que está inmediatamente antes del cursor
		bool setOnIndex(T _value, int _index);  // asignar un valor al elemento en la posición indicada
		bool setFirst(T _value);  // asignar un valor al primer elemento de la lista
		bool setLast(T _value);  // asignar un valor al último elemento de la lista
		// devuelven TRUE sólo si existe la posición indicada, FALSE en caso contrario; setOnIndex() mueve el cursor
		
		bool swapData(int _index1, int _index2);  // intercambiar valores en las posiciones dadas (ineficiente, seguro)
		bool swapData(inv_Node_List<T> *_node1, inv_Node_List<T> *_node2);  // intercambiar valores de los nodos (eficiente, menos seguro)
		
		int getN_items();  // obtener el número de elementos en la lista
		int getIndex();  // obtener la posición actual del cursor en la lista
		void clear();  // vaciar la lista
		
		inv_Iterator<T> getIterator();  // obtener un interador para la posición actual
		inv_Iterator<T> getIterator(int _index);  // obtener un iterador para la posición indicada; mueve el cursor
		inv_Iterator<T> getIteratorOnFirst();  // obtener un iterador para el primer elemento
		inv_Iterator<T> getIteratorOnLast();  // obtener un iterador para el último elemento
};
// class

template <class T> inv_List<T>::~inv_List()
{
	toFirst();
	while(toNext())
	{
		delete currentNode->previous;
	}
	delete currentNode;
}
// destructor

template <class T> inline bool inv_List<T>::addFirst(T _value)
{
	inv_Node_List<T> *auxNode = new inv_Node_List<T>;
	if(auxNode)
	{
		auxNode->value = _value;
		auxNode->previous = nullptr;
		auxNode->next = firstNode;
		if(firstNode)
		{
			firstNode->previous = auxNode;
			firstNode = auxNode;
			index++;
		}
		else
		{
			lastNode = firstNode = currentNode = auxNode;
		}
		n_items++;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::addLast(T _value)
{
	inv_Node_List<T> *auxNode = new inv_Node_List<T>;
	if(auxNode)
	{
		auxNode->value = _value;
		auxNode->next = nullptr;
		auxNode->previous = lastNode;
		if(lastNode)
		{
			lastNode->next = auxNode;
			lastNode = auxNode;
		}
		else
		{
			lastNode = firstNode = currentNode = auxNode;
		}
		n_items++;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::insertFront(T _value)
{
	inv_Node_List<T> *auxNode = new inv_Node_List<T>;
	if(auxNode)
	{
		auxNode->value = _value;
		if(currentNode)
		{
			auxNode->next = currentNode;
			auxNode->previous = currentNode->previous;
			if(currentNode->previous)
			{
				currentNode->previous->next = auxNode;
			}
			else
			{
				firstNode = auxNode;
			}
			currentNode->previous = auxNode;
			index++;
		}
		else
		{
			auxNode->next = auxNode->previous = nullptr;
			lastNode = firstNode = currentNode = auxNode;
		}
		n_items++;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::insertBack(T _value)
{
	inv_Node_List<T> *auxNode = new inv_Node_List<T>;
	if(auxNode)
	{
		auxNode->value = _value;
		if(currentNode)
		{
			auxNode->previous = currentNode;
			auxNode->next = currentNode->next;
			if(currentNode->next)
			{
				currentNode->next->previous = auxNode;
			}
			else
			{
				lastNode = auxNode;
			}
			currentNode = currentNode->next = auxNode;
			index++;
		}
		else
		{
			auxNode->previous = auxNode->next = nullptr;
			lastNode = firstNode = currentNode = auxNode;
		}
		n_items++;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::remove()
{
	inv_Node_List<T> *auxNode = currentNode;
	if(currentNode)
	{
		if(currentNode->previous && currentNode->next)
		{
			currentNode->next->previous = currentNode->previous;
			currentNode->previous->next = currentNode->next;
			currentNode = currentNode->previous;
			index--;
		}
		else
		{
			if(!currentNode->previous)
			{
				if(currentNode->next)
				{
					firstNode = currentNode = currentNode->next;
					currentNode->previous = nullptr;
				}
				else
				{
					lastNode = firstNode = currentNode = nullptr;
				}
			}
			else
			if(!currentNode->next)
			{
				if(currentNode->previous)
				{
					lastNode = currentNode = currentNode->previous;
					currentNode->next = nullptr;
					index--;
				}
				else
				{
					lastNode = firstNode = currentNode = nullptr;
				}
			}
		}
		delete auxNode;
		n_items--;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::removeFirst()
{
	if(firstNode)
	{
		if(firstNode->next)
		{
			if(index > 0) index--; else currentNode = currentNode->next;
			
			firstNode = firstNode->next;
			delete firstNode->previous;
			firstNode->previous = nullptr;
		}
		else
		{
			delete firstNode;
			firstNode = lastNode = currentNode = nullptr;
		}
		n_items--;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::removeLast()
{
	if(lastNode)
	{
		if(lastNode->previous)
		{
			if(currentNode == lastNode)
			{
				currentNode = currentNode->previous;
				index--;
			}
			lastNode = lastNode->previous;
			delete lastNode->next;
			lastNode->next = nullptr;
		}
		else
		{
			delete lastNode;
			firstNode = lastNode = currentNode = nullptr;
		}
		n_items--;
		return true;
	}
	return false;
}
// insert and remove nodes

template <class T> inline bool inv_List<T>::toNext()
{
	if(currentNode && currentNode->next)
	{
		currentNode = currentNode->next;
		index++;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::toPrevious()
{
	if(currentNode && currentNode->previous)
	{
		currentNode = currentNode->previous;
		index--;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::toFirst()
{
	index = 0; 
	return currentNode = firstNode;  // retorna FALSE si firstNode == NULL (lista vacía), en caso contrario retorna TRUE
}
template <class T> inline bool inv_List<T>::toLast()
{
	if(currentNode = lastNode)  // retorna FALSE si lastNode == NULL (lista vacía), en caso contrario retorna TRUE
	{
		index = n_items-1;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::toIndex(int _index)
{
	if(_index > 0 && _index < n_items-1) // si _index está dentro de los límites pero no es el primer ni el último elemento
	{
		while(index < _index) toNext();  // ir al siguiente elemento hasta ubicarse en índice correcto
		while(index > _index) toPrevious();  // ir al elemento anterior hasta ubicarse en el índice correcto
		return true;
	}
	if(_index == 0) return toFirst();  // si _index apunta al primer elemento, ir al primer elemento
	if(_index == n_items-1) return toLast();  // si _index apunta al último elemento, ir al último elemento
	return false;  // retorne FALSE si _index está fuera de los límites de la lista (posición inválida)
}
// move cursor

template <class T> inline bool inv_List<T>::getCurrent(T* _dest)
{
	if(currentNode)
	{
		*_dest = currentNode->value;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::getNext(T* _dest)
{
	if(currentNode && currentNode->next)
	{
		*_dest = currentNode->next->value;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::getPrevious(T* _dest)
{
	if(currentNode && currentNode->previous)
	{
		*_dest = currentNode->previous->value;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::getOnIndex(T* _dest, int _index)
{
	toIndex(_index);
	return getCurrent(_dest);
}
template <class T> inline bool inv_List<T>::getFirst(T* _dest)
{
	if(firstNode)
	{
		*_dest = firstNode->value;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::getLast(T* _dest)
{
	if(lastNode)
	{
		*_dest = lastNode->value;
		return true;
	}
	return false;
}
// get value

template <class T> inline bool inv_List<T>::setCurrent(T _value)
{
	if(currentNode)
	{
		currentNode->value = _value;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::setNext(T _value)
{
	if(currentNode && currentNode->next)
	{
		currentNode->next->value = _value;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::setPrevious(T _value)
{
	if(currentNode && currentNode->previous)
	{
		currentNode->previous->value = _value;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::setOnIndex(T _value, int _index)
{
	if(toIndex(_index))
	{
		currentNode->value = _value;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::setFirst(T _value)
{
	if(firstNode)
	{
		firstNode->value = _value;
		return true;
	}
	return false;
}
template <class T> inline bool inv_List<T>::setLast(T _value)
{
	if(lastNode)
	{
		lastNode->value = _value;
		return true;
	}
	return false;
}
// set value

template <class T> inline bool inv_List<T>::swapData(int _index1, int _index2)
{
	if(toIndex(_index1))
	{
		T auxValue = currentNode->value;
		T* buffer = &currentNode->value;
		if(toIndex(_index2))
		{
			*buffer = currentNode->value;
			currentNode->value = auxValue;
			return true;
		}
	}
	return false;
}
template <class T> inline bool inv_List<T>::swapData(inv_Node_List<T> *_node1, inv_Node_List<T> *_node2)
{
	if(_node1 && _node2)
	{
		T auxValue = _node1->value;
		_node1->value = _node2->value;
		_node2->value = auxValue;
		return true;
	}
	return false;
}
// swap values

template <class T> inline int inv_List<T>::getN_items()
{
	return n_items;
}
template <class T> inline int inv_List<T>::getIndex()
{
	return index;
}
template <class T> inline void inv_List<T>::clear()
{
	while(removeLast());
}
// n_items, index and clear

template <class T> inline inv_Iterator<T> inv_List<T>::getIterator()
{
	return inv_Iterator<T>(currentNode);
}
template <class T> inline inv_Iterator<T> inv_List<T>::getIterator(int _index)
{
	toIndex(_index);
	return getIterator();
}
template <class T> inline inv_Iterator<T> inv_List<T>::getIteratorOnFirst()
{
	return inv_Iterator<T>(firstNode);
}
template <class T> inline inv_Iterator<T> inv_List<T>::getIteratorOnLast()
{
	return inv_Iterator<T>(lastNode);
}
// iterator


#endif
