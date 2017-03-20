#ifndef REGISTRADO_H
#define REGISTRADO_H
#include "fstream"
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class Registrado
{
	public:
		
		int posicion;
		int cedula;
		string Procedencia;
		string Nombre;
		string Estado;
		int getPosicion(){ return posicion;}
	string getEstado(){ return Estado;}
    int getCed(){ return cedula;}
    string getNom(){ return Nombre;}
    string getprocedencia(){return Procedencia;}
    void setCed(int c){cedula=c;}
    void setPosicion(int c){posicion=c;}
    void setProcedencia (string n){Procedencia=n;}
    void setNom (string n){Nombre=n;}
    void setEstado(string n){Estado=n;}
    void imprimirOriginal(){cout<<posicion<<" "<<Procedencia<<"-"<<cedula<<" "<<Nombre<<" "<<Estado<<endl;}
   
};

#endif
