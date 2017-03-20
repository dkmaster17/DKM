/**
 *	@Autor: Dilan Useche
 *	@Date: 2/27/2016
 *	@Release: 2/29/2016
 *	@Version: 0.4
 */

#ifndef DATOS_H
#define DATOS_H

#include <string>
#include <iostream>
#include "Sexo.h"

/**
 *	@brief clase común que representa un conjunto de datos
 */
class Datos
{
	// función para sobrecargar operador de extracción de flujo
	friend std::ostream& operator<<( std::ostream&, const Datos& );
	// duncion sobrecarga el operador de igualdad
	friend bool operator==( const Sexo&, const Datos& ); 
	public:
		// datos en diferentes tipos de datos
		std::string nombre;
		int edad;
		char sexo;
		double promedio;
		
		Datos( std::string, int, char, double );
		bool operator==( const Datos& ); // sobrecarga el operador de igualdad
}; // fin de Datos

#endif
