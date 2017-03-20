#ifndef QUEUE_H
#define QUEUE_H

#include <new>
#include <stdio.h>


/* --------------- Queue ---------------
Cola en arreglo circular
*/


template <typename T>
class Queue
{
	private:
		T* array;  // vector de punteros a T
		int total_items;  // total de elementos que se pueden almacenar a la vez
		int front;  // el frente lógico de la lista
		int end;  // el final lógico de la lista
		
	public:
		Queue(int _totalItems) : total_items(_totalItems), front(0), end(0)  // la cola comienza "vacía"
		{
			array = new (std::nothrow) T[_totalItems];  // reservar memoria
		}
		~Queue() {delete array;}  // liberar memoria

		bool push(const T& _source);  // agregar elementos
		bool pop(T* _dest);  // quitar elementos

		int getFront();
		int getEnd();
		int getTotalItems();

		void print(void (*f)(T& _item), bool _ascending);  // imprimir contenido
};

template <typename T> bool Queue<T>::push(const T& _source)
{
	if(array && end - front < total_items)  // el frente nunca debe adelantarse demasiado, porque desbordaría la cola
	{
		array[end % total_items] = _source;  // el '%' asegura que el final siempre esté en el rango del vector
		end++;
		if(end > total_items * 2)  // evitar que las variables «front» y «end» crezcan excesivamente
		{
			end -= total_items;
			front -= total_items;
		}
		return true;
	}
	return false;
}

template <typename T> bool Queue<T>::pop(T* _dest)
{
	if(array && front < end)
	{
		*_dest = array[front % total_items];  // se extrae el elemento del frente (posición lógica)
		front++;
		return true;
	}
	return false;
}

template <typename T> void Queue<T>::print(void (*f)(T& _item), bool _ascending)
{
	printf("\n Queue: %d\n", end - front);
	if(_ascending)
	{
		for(int i=0; i<end-front; i++)  // i recorre toda la lista desde el frente hasta el final
		{
			printf("#%d ", i);
			f(array[(i + front) % total_items]);  // se llama a la función que imprime el contenido de un elemento
			printf("\n");
		}
	}
	else
	{
		for(int i=end-front-1; i>=0; i--)
		{
			printf("#%d ", i);
			f(array[(i + front) % total_items]);
			printf("\n");
		}
	}
	printf("\n");
}


#endif
