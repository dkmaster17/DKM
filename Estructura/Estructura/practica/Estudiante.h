#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

class Estudiante
{
	public:
		int getCedula(){return cedula;}
		char* getNombre(){return nombre;}
		char* getCorreo(){return correo;}
		void setCedula(int);
		void setNombre(char*);
		void setCorreo(char*);
		void mostrar();
		Estudiante(char* ,char* , int );
		Estudiante();
		~Estudiante();
		
		
	private:
		int cedula;
		char nombre[20];
		char correo[50];
};

#endif
