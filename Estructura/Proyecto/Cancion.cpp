#include "Cancion.h"

Cancion::Cancion()
{
	titulo=' ';
	duracion=0;
}

Cancion::Cancion(string titu, int dura)
{
	
	titulo=titu;
	duracion=dura;
}

Cancion::~Cancion()
{
}
