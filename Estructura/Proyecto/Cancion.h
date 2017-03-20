#ifndef CANCION_H
#define CANCION_H
#include <string>
#include <iostream>

using namespace std;
class Cancion
{
	

	
	public:
	string titulo;
	int duracion;
		Cancion();
		Cancion(string titu, int dura);
		~Cancion();
	protected:
};

#endif
