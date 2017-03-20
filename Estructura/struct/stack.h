#ifndef STACK_H
#define STACK_H

#include <new>
#include <stdio.h>


/* --------------- Stack ---------------
Pila simple en arreglo
*/


template <typename T>
class Stack
{
	private:
		T* array;
		int total_items;
		int current_item;

	public:
		Stack(int _totalItems) : total_items(_totalItems), current_item(0)
		{
			array = new (std::nothrow) T[_totalItems];
		}
		~Stack() {delete array;}

		bool push(const T& _source);  // agregar elementos
		bool pop(T* _dest);  // quitar elementos

		int getCurrentItem();

		void print(void (*f)(T& _item), bool _ascending);  // imprimir contenido
};

template <typename T> bool Stack<T>::push(const T& _source)
{
	if(array && current_item < total_items)
	{
		array[current_item] = _source;
		current_item++;
		return true;
	}
	return false;
}
template <typename T> bool Stack<T>::pop(T* _dest)
{
	if(array && current_item > 0)
	{
		current_item--;
		*_dest = array[current_item];
		return true;
	}
	return false;
}

template <typename T> void Stack<T>::print(void (*f)(T& _item), bool _ascending)
{
	printf("\n Stack: %d\n", current_item);
	if(_ascending)
	{
		for(int i=0; i<current_item; i++)
		{
			printf("#%d ", i);
			f(array[i]);
			printf("\n");
		}
	}
	else
	{
		for(int i=current_item-1; i>=0; i--)
		{
			printf("#%d ", i);
			f(array[i]);
			printf("\n");
		}
	}
	printf("\n");
}


#endif
