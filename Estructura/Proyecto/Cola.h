#ifndef COLA_H
#define COLA_H
#include <iostream>
#include <string>
#include "Cancion.h"
using namespace std;

class Cola
{
	public:
	Cancion *vector;
	int tam;
	int ingre;
	int ini;
	public:
		Cola();
		Cola(int t);
		
		void set_size(int t);
		int agregar(Cancion elemento);
		int eliminar();
		void imprimir();
};

#endif
