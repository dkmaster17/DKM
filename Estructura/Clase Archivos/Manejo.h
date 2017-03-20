#ifndef MANEJO_H
#define MANEJO_H
#include "Alumno.h"
#include <fstream>
#include <iostream>
#include <string.h>




//ARCHIVO
//TEXTO: .TXT
//BINARIO: .DAT ...
using namespace std;
class Manejo
{
	fstream arc; //stream para manipular el archivo
	char nombre[30];
	char line[120];
	Alumno buffer;
	public:
		Manejo(char *n){ strcpy(nombre,n);}
		void abrir(ios_base::openmode modo) //Para entrada o salida
		{ 
			arc.open(nombre,modo);
		}
		void cerrar()
		{
			arc.close();
		}
		bool falla()
		{
		 return arc.fail();
		}
		bool Es_fin()
		{
			return arc.eof();
		}
		void escribir(Alumno &A)
		{
			arc<<A.getCedula()<<","<<A.getNombre()<<endl;
		}
		void leer(Alumno &A)
		{
			arc.getline(line,120,',');
			A.setCedu(line);
			arc.getline(line,120,'\n');
			A.setNombre(line);
		}
		
	protected:
};

#endif
