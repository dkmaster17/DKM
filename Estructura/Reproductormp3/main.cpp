#include <iostream>
#include<string.h>
#include <windows.h>
#include <conio.h>
#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


//Gustavo Florez Jesus Olmedo Seccion 2 25837802 24781434
class Cancion
{
public:
int pos;
int seg;
char Titulo_Cancion[50];
Cancion(){seg=0;strcpy(Titulo_Cancion,"");}
Cancion(int a,int b,char* Nombres)
{
pos=a; seg=b; strcpy(Titulo_Cancion,Nombres);	
}
void Mostrar(){cout<<" \t °-"<<pos<<" "<<Titulo_Cancion<<" "<<seg<<endl;}
int getSeg() {return seg;}
char* getTitulo(){return Titulo_Cancion;}
};

template <class T>
class ColaCircular
{
	public:
int TamanoCircular;
T *Track;
T Buffer;
int Inicio,Final;

	ColaCircular(int Tam)
	{
	TamanoCircular=Tam;
	Track=new T[TamanoCircular];
	Inicio=-1;Final=-1;
	}
int Agregar(T Buffer);
int Eliminar();
void Mostrar();

};
template <class T>
int ColaCircular<T>::Agregar(T buffer)
{
	if(!Track)
{
	return-1;
}
	 if(Final==TamanoCircular-1)
	 {
	 	Final=-1;
	 }
if(Inicio==-1)
    {Inicio=0;}

	Final++;
	Track[Final]=buffer;
	return 1;
} 


template <class T>
int ColaCircular<T>::Eliminar()
{
	if(!Track)
{
	return-1;
}
if(Inicio==-1 && Final==-1)
{
 return 0;
}
if(Inicio==Final){Inicio=0;}

     
		for(int i=Inicio;i<Final;i++){
		Track[i]=Track[i+1];
	     }
	
	Inicio++;
return 1;
}




template <class T>
void ColaCircular<T>::Mostrar(){

	for(int i=Inicio;i<=Final;i++)
	{
	Track[i].Mostrar();
	}
	
	
}
int main(int argc, char** argv)  {
	
	
	
	
	
	
	
	

	ColaCircular <Cancion> CirSong(7);
	
	
		fstream Canciones;
	    char Nombre[50];
		int seg;
		int pos;
		
		Canciones.open("Canciones.txt");
		if(!Canciones.fail())
        {
			for(int i =0 ;i<7;i++)
			{
			Canciones.getline(Nombre,50,' ');
			Canciones >> seg;
			pos=i;
			Cancion Aux(pos,seg,Nombre);
			CirSong.Agregar(Aux);
			}
			
		}
		else 
		{
			cout<<"No se pudo cargar el archivo"<<endl;
		}
		
	int result;
	bool state=false;
	int Time=0;
    char resp=' ';
    int i=0;
    Time=CirSong.Track[i].getSeg();
	while(resp!='X')
	   {
    	  
         
            
		    if(kbhit())
		     {
		    resp=getch();
            if(resp=='R'||resp=='r')
			{
		      state=true;
			}
	        if(resp=='C'||resp=='c')
			{
				if(CirSong.Final<7)
				{
				Canciones.getline(Nombre,50,' ');
			    Canciones >> seg;
			    pos=i;
			    Cancion Aux(pos,seg,Nombre);
			    CirSong.Agregar(Aux);	
				} 
				else{cout<<"No room for you"<<endl;} 
			}
	        if(!CirSong.Track)
			{
				cout<<"Esperando instrucciones"<<endl;
			}
			if(resp=='N'||resp=='n')
			{
			   CirSong.Eliminar();
			   i++;
			   system("cls");
               Time=CirSong.Track[i].getSeg();
			}
			
			if(resp=='p'||resp=='P'){state=false;
			cout << "Se esta Reproduciendo: "<<CirSong.Track[i].getTitulo()<<"La cancion "<<CirSong.Track[i].pos+1 <<" "<<Time<<endl;
			cout <<"esperando accion"<<endl;
			resp=getch();}
			
			
			if(resp=='S'||resp=='s'){state=false;Time=CirSong.Track[i].getSeg();
			cout << "Se esta Reproduciendo: "<<CirSong.Track[i].getTitulo()<<"La cancion "<<CirSong.Track[i].pos+1 <<" "<<Time<<endl;
			cout <<"esperando accion"<<endl;
			resp=getch();
			}
			
            }
	        
	       if(state)
		   {
	       	  if(Time==0)
			   {
              CirSong.Eliminar();
              i++;
			  Time=CirSong.Track[i].getSeg();
			   }
		    
			cout << "Se esta Reproduciendo: "<<CirSong.Track[i].getTitulo()<<"La cancion "<<CirSong.Track[i].pos+1 <<" "<<Time<<endl;
			Time--;
			Sleep(100);
		   
		   }

           
		 	system("cls");   
	    }
   Canciones.close();
	return 0;			
	 } 
		
	    

	




