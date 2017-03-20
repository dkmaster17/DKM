#ifndef DATOS_H
#define DATOS_H

#include <string>

class Datos
{
	public:
		std::string nombre;
		int edad;
		char sexo;
		double promedio;
		Datos( std::string, int, char, double );
};

#endif
