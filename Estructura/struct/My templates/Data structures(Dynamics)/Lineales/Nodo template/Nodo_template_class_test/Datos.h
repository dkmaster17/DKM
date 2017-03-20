#ifndef DATOS_H
#define DATOS_H

#include <string>
#include <iostream>

class Datos
{
	friend std::ostream& operator<<( std::ostream&, const Datos& );
	private:
	public:
		std::string nombre;
		int edad;
		char sexo;
		double promedio;
		Datos( std::string, int, char, double );
};

#endif
