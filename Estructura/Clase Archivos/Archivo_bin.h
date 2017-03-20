#ifndef ARCHIVO_BIN_H
#define ARCHIVO_BIN_H
#include "Alumno.h"
#include "Manejo.h"
#include <fstream>
#include <iostream>
using namespace std;

class Archivo_bin
{	
	private:
		char nom[40];
		fstream arc;
		Alumno buffer;
		int n, lon;
	public:
		Archivo_bin(char *c){strcpy(nom, c);}
		void abrir(ios_base::openmode modo){arc.open(nom,modo);}
		void cerrar(){arc.close();}
		bool es_fin(){return arc.eof();}
		bool falla(){return arc.fail();}
		void longitud(){lon = sizeof(Alumno);}
		void posicionar(int p){arc.seekg(p*lon, ios::beg);}
		
		void tamanio(){
			arc.seekg(0,ios::end);
			longitud();
			n = arc.tellg()/lon;
		}
		
		
		void leer(Alumno &a){
			arc.read((char *)&a, lon);
		}
		
		void escribir(Alumno &a){
			arc.write((char *)&a, lon);
		}
		
		void imprimir();
		bool buscar_sec(Alumno &clave);
		void ordenar();
	protected:
};

#endif
