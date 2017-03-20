#include "Datos.h"

using namespace std;

Datos::Datos( std::string n, int e, char s, double p )
{
	this->nombre = n;
	this->edad = e;
	this->sexo = s;
	this->promedio = p;
}


ostream& operator<<( ostream& salida, const Datos& datos )
{
	char delim = ',';
	
	salida << datos.nombre << delim << datos.edad << delim << 
	datos.sexo << delim << datos.promedio;
		
	return salida;  
} // fin de operator<<
