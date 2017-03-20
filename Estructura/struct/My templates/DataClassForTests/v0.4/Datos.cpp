#include "Datos.h"

using namespace std;

/**
 *	@brief inicializa el objeto Datos
 *	@since 0.1
 *	@param string nombre
 *	@param int edad
 *	@param char sexo
 *	@param double promedio
 */
Datos::Datos( std::string n, int e, char s, double p )
{
	this->nombre = n;
	this->edad = e;
	this->sexo = s;
	this->promedio = p;
} // fin del constructor 


/**
 *	@brief sobrecarga el operador de extracci�n de flujo 
 *	un objeto de tipo Datos, y lo representa como una cadena
 *	con todos sus atributos separados por una coma 
 *	@since 0.1
 *	@param ostream& objeto de flujo de salida
 *	@param Datos& objeto de la clase
 *	@return ostream& objeto del flujo de salida 
 */
ostream& operator<<( ostream& salida, const Datos& datos )
{
	char delim = ','; // separador 
	
	// imprime atribtos separados por delim
	salida << datos.nombre << delim << datos.edad << delim << 
	datos.sexo << delim << datos.promedio;
		
	return salida; // retorna el objeto del flujo de salida
} // fin de operator<<


/**
 *	@brief sobrecarga el operador de igualdad, comparando 
 *	un objeto Sexo con un objeto Datos
 *	@since 0.4
 *	@param Sexo& sexo a comparar 
 *	@param Datos& datos a comparar
 *	@return bool true si el sexo de ambos es igual, de 
 *	lo contrario false
 */
bool operator==( const Sexo& s, const Datos& datos )
{
	return ( s.sexo == datos.sexo );
} // fin de operator== 
 

/**
 *	@brief sobrecarga el operador de igualdad, comparando 
 *	dos objetos Datos por su sexo
 *	@since 0.4
 *	@param Datos& datos a comparar 
 *	@param Datos& datos a comparar
 *	@return bool true si el sexo de ambos Datos es igual, de 
 *	lo contrario false
 */
bool Datos::operator==( const Datos& datos )
{
	return (this->sexo == datos.sexo); // retorna desici�n  
} // fin de operator==
 
 
