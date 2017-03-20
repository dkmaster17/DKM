#include <iostream>
#include "Estudiante.h"
#include <fstream>
#include "stdio.h"
#include "string.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cargar(Estudiante *vector,int tamano){
	int i=0,cedula=0;
	char nombre[20],correo[50];
	
	ifstream In;
	
	In.open("EstudiantesData.txt",ios::in);
	if(In.fail())
	{
		cout<< "esto no arranca"<<endl;
    }
    else{
	

	while(!In.eof()&&i<45)
	{
    
   
    In.getline(nombre,20,' ');
	In.getline(correo,50,' ');	
	In >> cedula;
	
	
	vector[i].setNombre(nombre);
	vector[i].setCorreo(correo);
	vector[i].setCedula(cedula);
	i++;
	
	
	}		
    }
	In.close();
	return i;

}

void Metodo_Shell_Sort(Estudiante *vec,int tam)
{
     int incremento=tam/2;
	 Estudiante EstAux;
     while(incremento>0)
     {
     for(int i=0 ;i+incremento<tam;i++)
     {
     
     	
     if(strcmp(vec[i].getNombre(),vec[i+incremento].getNombre())>0)
     {
     	
                                 EstAux=vec[i];
                                 vec[i]=vec[i+incremento];
                                 vec[i+incremento]=EstAux;
                                 
								 while(i >= 0 && strcmp(vec[i].getNombre(),vec[i-incremento].getNombre())<0)
                                 {
                                 EstAux=vec[i];
                                 vec[i]=vec[i-incremento];
                                 vec[i-incremento]=EstAux;
                                 i-=incremento;
                                 }
                                 
     }
     
     }
     incremento/=2;
     
     }

}
void Mostrar(Estudiante *vec,int tam)
{
	for(int i=0;i<tam;i++){
	vec[i].mostrar();
	}
}
 
int main(int argc, char** argv) {
    int tamano=45;
    int aux;
    Estudiante *Est = new Estudiante[45];
    aux = cargar(Est,tamano);
    Metodo_Shell_Sort(Est,aux);
    Mostrar(Est,aux);
	
	
	
	
	
	return 0;
}
