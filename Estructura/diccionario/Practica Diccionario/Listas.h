#include <iostream>
#include <string.h>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_RESET   "\x1b[0m"

class cadena
{
	public:
		char cad[100];
		char* ced;
		
    
		bool operator =(cadena & n)
		{
			strcpy(this->cad,n.cad);
			
		}
		
		bool operator ==(cadena n)
		{
			if(strcmp(this->cad,n.cad)==0)
			{
				return true;
		 	}
			else
			{
			return false;
			}
		}
		
		bool operator<(cadena n)
		{
			if(strcmp(this->cad,n.cad)<0)
			{
				return true;
			}
			else
			return false;
		}
		bool operator>(cadena n)
		{
			if(strcmp(this->cad,n.cad)>0)
			{
				return true;
			}
			else
			return false;
		}
		
		friend ostream& operator<<(ostream &o, cadena n)
		{
			o<<n.cad;
			return o;
		}
		friend istream& operator>>(istream &o, cadena n)
		{
			o>>n.cad;
			return o;
		}
};

template <class T>
class Nodo
{
public:
	Nodo *Sig;
	T inf;
	Nodo(){Sig=NULL;}
};

template <class T>
class ListaDown{
	public:
	Nodo <T>*cab;
	void agregar(T Add);
	void Eliminar(T Eliminar);
	void Vaciar();
	void Buscar(T bus);
	void Mostrar();
	void Cargar();
	ListaDown(){cab=NULL;}
};
template <class T>
void ListaDown <T>::Mostrar()
{
	Nodo <T> *aux=cab;
	if(aux==NULL)
		{
			cout<<"lista vacia"<<endl;
		}
	while(aux)
	{
		
		
		
		cout<<aux->inf<<"\t";
		aux=aux->Sig;
		
	}
	cout<<endl;
	
}

template <class T>
void ListaDown <T>::Eliminar( T elim)
{
	 Nodo <T> *aux =cab, *rec=NULL;
	 while(aux)
	 {
	 	if(aux->inf==elim)
		 {
		 	break;
		 }
		 rec=aux;
		 aux=aux->Sig;
	 }
	 if(aux==NULL)
	 {
	 	cout<<"no lo encontro"<<endl;
	 	getch();
	 	return ;
	 }
	 if(rec==NULL)
	 {
	  cab=cab->Sig;
	  delete aux;
	  return;	
	 }
	 rec->Sig= aux->Sig;
	 delete aux;
}

template <class T>
void ListaDown <T>::Buscar(T bus)
{
	Nodo <T> *aux=cab;
	while(aux)
	{
	if(aux->inf==bus)
	{
		break;
	}	
	aux=aux->Sig;
	}
	if(aux==NULL)
	{
		/*cout<<"ERROR"<<endl;
		cout<<"Revise si la palabra esta bien escrita o existe"<<endl;
		cout<<"La palabra: ";
		cout<<ANSI_COLOR_RED<<bus<<ANSI_COLOR_RESET<<endl;
		//printf(ANSI_COLOR_RED "%T",bus);
		getch();
		return;
	}
	cout<<"Se encontro la palabra: "<<aux->inf<<endl;
	getch();*/
		
		cout<<ANSI_COLOR_RED<<bus<<ANSI_COLOR_RESET<<" ";
		return;
	}
	cout<<aux->inf<<" ";
}

template <class T>
void ListaDown <T>::agregar (T nue)
{
	Nodo <T>*nu;
	nu= new Nodo<T>();
	if(!nu)
	{
		cout<<"no hay memoria"<<endl;
		return ;
	}
	nu->inf= nue;
	if (cab==NULL)
	{
	cab=nu;
	return ;	
	}
	Nodo<T> *aux=cab,*rec=NULL;
	while(aux)
	{
		if(aux->inf<nue)
		{
			break;
		}
		rec=aux;
		aux=aux->Sig;
	}
	if(rec==NULL){
		nu->Sig=cab;
		cab=nu;
	    return;
	}
	rec->Sig=nu;
	nu->Sig=aux;
}
template <class T>
void ListaDown<T>::Vaciar()
{
	 Nodo <T> *aux =cab , *rec=NULL;
	 while(aux)
	 {
		rec=aux;
		aux=aux->Sig;
	 	delete rec;
	}
}

template <class T>
void ListaDown<T>::Cargar()
{
	
	return;
}

template <class T>
class ListaUp{
	public:
	Nodo <T>*cab;
	void agregar(T Add);
	void Eliminar(T Eliminar);
	void Vaciar();
	void Buscar(T bus);
	void Mostrar();
	ListaUp(){cab=NULL;}
};
template <class T>
void ListaUp <T>::Mostrar()
{
	Nodo <T> *aux=cab;
	if(aux==NULL)
		{
			cout<<"lista vacia"<<endl;
		}
	while(aux)
	{
		
		
		
		cout<<aux->inf<<"\t";
		aux=aux->Sig;
		
	}
	cout<<endl;
	
}

template <class T>
void ListaUp <T>::Eliminar( T elim)
{
	 Nodo <T> *aux =cab, *rec=NULL;
	 while(aux)
	 {
	 	if(aux->inf==elim)
		 {
		 	break;
		 }
		 rec=aux;
		 aux=aux->Sig;
	 }
	 if(aux==NULL)
	 {
	 	cout<<"no lo encontro"<<endl;
	 	getch();
	 	return ;
	 }
	 if(rec==NULL)
	 {
	  cab=cab->Sig;
	  delete aux;
	  return;	
	 }
	 rec->Sig= aux->Sig;
	 delete aux;
}
template <class T>
void ListaUp<T>::Vaciar()
{
	 Nodo <T> *aux =cab , *rec=NULL;
	 while(aux)
	 {
		rec=aux;
		aux=aux->Sig;
	 	delete rec;
	}
	cab=NULL;
}

template <class T>
void ListaUp <T>::Buscar(T bus)
{
	Nodo <T> *aux=cab;
	while(aux)
	{
	if(aux->inf==bus)
	{
		break;
	}	
	aux=aux->Sig;
	}
	if(aux==NULL)
	{
		cout<<"no se encontro"<<endl;
	}
	cout<<"Se encontro el la palabra: "<<aux;
}

template <class T>
void ListaUp <T>::agregar (T nue)
{
	Nodo <T>*nu;
	nu= new Nodo<T>();
	if(!nu)
	{
		cout<<"no hay memoria"<<endl;
		return ;
	}
	nu->inf= nue;
	if (cab==NULL)
	{
	cab=nu;
	return ;	
	}
	Nodo<T> *aux=cab,*rec=NULL;
	while(aux)
	{
		if(aux->inf>nue)
		{
			break;
		}
		rec=aux;
		aux=aux->Sig;
	}
	if(rec==NULL){
		nu->Sig=cab;
		cab=nu;
	    return;
	}
	rec->Sig=nu;
	nu->Sig=aux;
}


class Data
{
	public: 
	int i;
	char nom[50];
	float a;
	Data(int d,char*s,float p)
	{
		i=d;
		a=p;
		strcpy(this->nom,s);
	}
	
	bool operator>>(Data n){
		if(this->i==n.i)
		{
			if (strcmp(this->nom,n.nom)==0)
	    {
		return this->a>n.a;
	    }
	    return  strcmp(this->nom,n.nom)>0;
		}
		return this->i>n.i;

	
	    }
};


