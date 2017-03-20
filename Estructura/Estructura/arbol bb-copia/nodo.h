#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

class nodo
{
	public:
		nodo *hi,*hd;
		int info;
		nodo(){hi=hd=NULL;}
};

#endif
