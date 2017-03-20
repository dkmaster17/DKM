#ifndef ARCHIVO_H
#define ARCHIVO_H
#include <fstream>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
template <class X>
class Archivo
{
	
	X buffer,AuxTipo,AuxTipo2,AuxTipo3;;
	fstream Arch;
	char Nombre_Archivo[40];
	int longitud,CantidadRegistros;
	public:
	Archivo(){}
	Archivo(char* n){strcpy(Nombre_Archivo,n);}
	void Abrir(const std::_Ios_Openmode &b){Arch.open(Nombre_Archivo,b);}
	void Cerrar(){Arch.close();}
	void limpiar(){Arch.clear();}
	void leer(fstream file,X &bufffer){file.read((char*)&buffer,sizeof(X));}
	void Escribir(fstream file,X &buffer){file.write((char*)&buffer,sizeof(X));}
	bool Acabo(){return Arch.eof();}
	bool Fallo(){return Arch.fail();}
	void Posicion(int p){Arch.seekg(p*sizeof(X),ios::beg);}
	void Tamano(){Arch.seekp(0,ios::beg);Arch.clear();CantidadRegistros=Arch.tellg()/sizeof(X);}
	void Imprimir();
	void Ordenar ();
	bool Buscar_Sec     ( X &bus, int pos=0, int Max=99999999 );
	void Particion_Inicial(fstream s,fstream d,fstream z);
	void Particion_fusion(fstream s,fstream d,fstream z,fstream b);
		
};
template <class X>
void Archivo<X>::Imprimir()
{
	limpiar();
	Posicion(0);
	while(!Acabo())
	{
	 Leer(buffer);
	 if(!Acabo()){break;}
	 buffer.imprimir();
	}
	cout<<endl;
}
template <class X>
void Archivo<X>::Ordenar(fstream Original,fstream Aux1,fstream Aux2)
{
 Particion_Inicial(Original,Aux1,Aux2);
 Particion_Fusion (Original,Aux1,Aux2,aux3);	
}
template <class X>
void Archivo<X>::Particion_Inicial(fstream Original,fstream Aux1,fstream Aux2)
{
	
	bool band=true;
	Original.open(Nombre_Archivo,ios::in|ios::binary);
	Aux1.open("Auxiliar_Temporal_1",ios::out|ios::binary);
	Aux2.open("Auxiliar_Temporal_2",ios::out|ios::binary);
	if(Original.fail()||Aux1.fail()||Aux2.fail())
	{
		cout<<"error al abrir el archivo"<<endl;
	}else
	  {
		leer(Original,buffer);
		Escribir(Aux2,buffer);
        AuxTipo=buffer;
	   while(!Original.eof())
     {
	    	
	    leer(Original,buffer);
		if(buffer.get_clave()>=AuxTipo.get_clave())
		{
		AuxTipo=buffer;
		if(band==true)
		{
		Escribir(Aux2,buffer);	
		band=false;	
		}
		else
		{
        Escribir(Aux1,buffer);
        band=true;
		}
	    }
	    
      }
      
	}
	Original.close();
	Aux1.close();
	Aux2.close();
}
template <class X>
void Archivo<X>::Particion_fusion(fstream Original,fstream Aux1,fstream Aux2)
{
	bool band=true,band1,band2;
	
	
	Original.open(Nombre_Archivo,ios::in|ios::binary);
	Aux1.open("Auxiliar_Temporal_1",ios::out|ios::binary);
	Aux2.open("Auxiliar_Temporal_2",ios::out|ios::binary);
    
if(Original.fail()||Aux1.fail()||Aux2.fail())
	{
		cout<<"error al abrir el archivo"<<endl;
	}
	else
    { 
      leer(Aux1,AuxTipo2);
      leer(Aux2,AuxTipo3);
	while((!Aux1.eof()||band1!=true)&&(!Aux2.eof()||band2!=true))
	{
    if ( AuxTipo2<=AuxTipo3)
	{
	Escribir(Original,AuxTipo2);
	leer(Aux2,AuxTipo3);
	}
	else
	{
	Escribir(Original,AuxTipo3);
	leer(Aux1,AuxTipo2);	
	}
	}   
}

}


template <class X>
bool Archivo<X>::Buscar_Sec( X &bus, int pos, int Max )
{
     int i;
     bool enc=false;
     limpiar();
     Posicion(pos);
     while ( i<=Max && !enc )
     { 
       leer(buffer);  
       if ( Acabo() ) break;    
       if ( bus.get_clave()==buffer.get_clave() )
       {
           enc=true;
           bus= buffer;
       }
	   else i++;
     } 
     return enc;        
}
#endif
