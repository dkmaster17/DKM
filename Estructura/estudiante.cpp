// Class automatically generated by Dev-C++ New Class wizard

#include "estudiante.h" // class's header file

Estudiante::Estudiante()
{
	
}
Estudiante::~Estudiante()
{

}
 void Estudiante::setNombre(char *nom)
 {
 strcpy(Nombre,nom);
 }
void Estudiante::setCorreo(char *cor)
{
strcpy(Correo,cor);
}
void Estudiante::setCedula(int ced)
{
cedula=ced;
}	
int Estudiante::getCedula()
{
return cedula;
}
char* Estudiante::getNombre()
{
return Nombre;
}
char* Estudiante::getCorreo()
{
return Correo;
}
