#ifndef ALUMNO_H
#define ALUMNO_H
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class Alumno
{
	int cedula;
	char nombre[30]; //nombre fisico
	public:
		Alumno()
		{ 
			cedula=0;
		}
		Alumno(int c,char *n)
		{
			cedula=c;strcpy(nombre,n);
		}
		~Alumno();
		int getCedula(){return cedula;}
		char *getNombre(){return nombre;}
		void setCedula(int c){cedula=c;}
		void setNombre(char *n){ strcpy(nombre,n);}
		void setCedu(char *ce){cedula=atoi(ce);}
		void imprimir(){
			cout<<cedula<<"   "<<nombre<<endl;
		}
	protected:
};

#endif
