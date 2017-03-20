#include "Estudiante.h"
#include <string.h>
#include <iostream>

using namespace std;

Estudiante::Estudiante(){
	
}

Estudiante::Estudiante(char* Nombre,char* Correo, int cedula)
{
	strcpy(this->correo,Correo);
	strcpy(this->nombre,Nombre);
	this->cedula=cedula;
}

 Estudiante::~Estudiante(){
}
void Estudiante::setCorreo(char* corre){
	strcpy(this->correo,corre);
}
void Estudiante::setNombre(char* nom){
	strcpy(this->nombre,nom);
}
void Estudiante::setCedula(int ced){
	this->cedula=ced;
}
void Estudiante::mostrar()
 {
 	
 cout<<" "<< this->nombre <<" "<< this->correo<<" "<<this->cedula<<endl;	

 }
