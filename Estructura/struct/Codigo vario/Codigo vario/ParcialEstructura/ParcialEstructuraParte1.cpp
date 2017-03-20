#include <iostream>
#include <time.h>
#include <fstream>
#include "string"
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <cstddef>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Gustavo Florez Parte 1 25837802 // DO NOT EXECUTE pega el equipo y toca reiniciar...
template <class T>//Nodos Genericos
class Nodo
 {
 private:
 	Nodo *Ant,*Sig;
 	T Inf;
 	int prioridad;
 public:
 	
 	Nodo(){Ant=NULL; Sig=NULL; Inf=NULL;prioridad=0;}
 	Nodo(T elemento){Ant=NULL; Sig=NULL; Inf=elemento;prioridad =0;}
    Nodo(T elemento,int prio){Ant=NULL; Sig=NULL; Inf=elemento;prioridad =prio;}	
	  	
 	Nodo* get_Ant(){return Ant;}
  	
 	Nodo* get_Sig(){return Sig;}
 	
 	T get_Inf(){return Inf;}
 
    void set_Sig(Nodo<T>* a){Sig=a;}
    
    void set_Ant(Nodo<T>* a){Ant=a;}
    
    void set_Inf(T a){Inf=a;}
 };

 
template <class T>
class ColaDin  //Primero al entrar Primero al salir .Para La cola de los objetos del Jugador
{
	private:
	Nodo <T> *Cab ,*Fin;
	public:
	ColaDin(){Cab=Fin=NULL;}	
	bool Vacia(){return Cab==NULL;}

int Agregar(T elemento)
{
	
	Nodo<T> *Agregado;
	Agregado= new Nodo<T>(elemento);
	if (Cab==NULL)
	{	
		Cab=Agregado;
		Fin= Agregado;
	}else
	{
	Fin->set_Sig(Agregado);
	Fin=Agregado;
	}
	
	return 0;
}
T get_ELemento()//Para ubicar el elemento en el arreglo de la lista
{
    return Fin->get_Inf();
}

void Eliminar()
{
	Nodo<T> *aux;
	aux= Cab->get_Sig();
	if(Vacia())
	{
		cout <<"lista vacia"<<endl;
	
	}else
	delete Cab;
	Cab=aux;
}

int Buscar(T elemento)
{
	Nodo <T> *Aux;
	Aux=Cab;
	int enc=0;
	if(Vacia())
	{
		cout <<"lista vacia"<<endl;
	return 0;
	}else
	{
	while(Aux!=NULL)
	{
		if(Aux->get_Inf()==elemento)
		{
			enc=1;
			return 1;
		}
		
	    Aux=Aux->get_Sig();	
		
	}
		return 0;
	}
	
}

void Mostrar()
{
Nodo<T> *Recorrido;
Recorrido=Cab;
if(Recorrido==NULL){cout<<"Sin Objetos"<<endl;}else

{
cout <<"Objetos: "<<endl;
while(Recorrido!=NULL)
{
	cout <<Recorrido->get_Inf().get_Objeto()<<endl;
	Recorrido=Recorrido->get_Sig();
}
}



}
void Vaciar()
{
	int eliminado=0;

	while(Cab!=NULL)
{
eliminado=Eliminar();
}
if(eliminado==1)
{
	cout <<"Lista vaciada"<<endl;
}

}
};
class Objeto//Objetos para los arreglos dinamicos
{
private: 
int Objeto;
public:
int get_Objeto(){return Objeto;}
void set_Objeto(int a){Objeto=a;}
};
template <class T>
class Jugador
{
	private:
		bool Turno;
	    char *Nombre;
	    ColaDin <T> Obj;
	    int puntaje;
	    int pos;
	public:
		 Jugador(){Turno=false;puntaje=0;pos=0;}
		 Jugador(char* Nom){Nombre=Nom;Turno=true;puntaje=0;pos=0;}
		 bool get_Tur(){return Turno;}
		 char* get_Nom(){return Nombre;}
		 void set_Tur(bool A){Turno=A;}
		 void set_Nom(char* a){Nombre=a;}
		 int  get_puntaje(){return puntaje;}
		 int  get_pos(){return pos;}
		 void set_pos(int a){pos=a;}
		 void set_puntaje(int a){puntaje=a;}
		 void Add(T Leido){Obj.Agregar(Leido);}
		 T get_Obj(){return Obj.get_ELemento();}
		 void Elimina(){Obj.Eliminar();}
		 void imprimir(){cout<<"Jugando: "<<Nombre<<" Puntaje: "<<puntaje<<" Posion: "<<pos<<endl;
		                 this->MostrarObjetos();}
		 void MostrarObjetos(){Obj.Mostrar();}
};


 template <class T>//Lista para el tablero;
 class ListaSimple
 {
 	private:
    Nodo<T> *Cab;
	public:
    ListaSimple(){Cab=NULL;}
 	void Agregar(T elemento)
	{
	Nodo<T>* Agregado = new Nodo<T>(elemento); 
	Nodo<T>* Recorrido = Cab; 
	Nodo<T>* Antes = NULL; 
	
	
	if( Agregado ) 
	{
		if( Recorrido == Cab )
		{
			Agregado->set_Sig( Cab ); 
			Cab = Agregado; 
		} 
		else 
		{
			Antes->set_Sig( Agregado ); 
			Agregado->set_Sig( Recorrido ); 
		} 
	}

		
	
    } 
	T get_elemento(int pos)//Para ubicar el elemento en el arreglo de la lista
    {
	Nodo<T> *Recorrido;
	Recorrido =Cab;
	for(int i=0;i<pos;i++){
	Recorrido=Recorrido->get_Sig();
	}
    return Recorrido->get_Inf();
    }
	
 	void ImprimirTablero()
	 {
	 	Nodo<T> *Recorrido;
	 	Recorrido= Cab;
	 	if(!Cab){
		 cout<<"Sin Tablero";
		 }
		 else
		 {
		 	while (Recorrido!=NULL)
		 	{
		 		cout << Recorrido->get_Inf().get_Objeto() <<"--->";
		 		Recorrido=Recorrido->get_Sig();
		    }
		    if(Recorrido==NULL)
				 {
				  cout<<"Over";	
				 }
		 }
	 }
		    
 };

 template <class T>//Pila para la papelera de los objetos dejados .
class PilasDin
{
private :
Nodo <T> *Fin;
public:
	bool Vacio(){return Fin==NULL;}
	int Agregar(T elemento)
{
	
	Nodo<T> *Agregado;
	Agregado= new Nodo<T>(elemento);
	if(Vacio()){
		Fin=Agregado;
	}else
	{
		Agregado->set_Sig(Fin);
		Fin=Agregado;
	}
	
	return 0;
}
T get_ELemento(int pos)//Para ubicar el elemento en el arreglo de la lista
{
	Nodo<T> *Recorrido;
	Recorrido =Fin;
	for(int i=0;i<pos;i++){
	Recorrido=Recorrido->get_Sig();
	}
    return Recorrido->get_Inf();
}

int Buscar(T elemento)
{
	Nodo <T> *Aux;
	Aux=Fin;
	int enc=0;
	if(Vacio())
	{
	cout <<"lista vacia"<<endl;
	return 0;
	}else
	{
	while(Aux!=NULL)
	{
		if(Aux->get_Inf()==elemento)
		{
			enc=1;
			return 1;
		}
		
	    Aux=Aux->get_Sig();	
		
	}
		return 0;
	}
	
}

void Mostrar()
{
Nodo<T> *Recorrido;
Recorrido=Fin;
if(Recorrido==NULL){cout<<"Sin Objetos en papelera"<<endl;}
else{
	cout<<"Objetos Papelera: "<<endl;
	while(Recorrido != NULL)
{
	cout<<Recorrido->get_Inf()<<endl;
	Recorrido=Recorrido->get_Sig();
}
}


}
int Eliminar()
{
	Nodo<T> *aux;
	aux= Fin->get_Sig();
	if(Vacio())
	{
		cout <<"lista vacia"<<endl;
	return 0;
	}else
	Fin->set_Inf(0);
	delete Fin;
	Fin=aux;
	return 1;
}
void Vaciar()
{
int eliminado=0;

	while(Fin!=NULL)
{
eliminado=Eliminar();
eliminado=1;
}
if(eliminado==1)
{
	cout <<"Lista vaciada"<<endl;
}

}	

};
int main(int argc, char** argv) 
{
    int rollDado=0;
    int aux;
    int size;
    Objeto Obj;
    PilasDin <Objeto> Papelera;
    bool win=false;
    Jugador<Objeto> *J1,*J2;
	char AuxNom[30],Numero[15],AuxNom2[30];
	 
	
	ListaSimple <Objeto> LO;
	srand(time(NULL));
	
	
	//Empezamos pidiendo los nombres
	
	cout<<"Nombre primer Jugador: ";
	cin>>AuxNom;
	J1=new Jugador<Objeto>(AuxNom);
	system("cls");
	cout<<"Nombre segundo Jugador: ";
	cin>>AuxNom2;
	J2=new Jugador<Objeto>(AuxNom2);

    system("cls");
    
    
	//Armando Tablero
	ifstream Tablero;
	Tablero.open("Tablero.txt");
	if(!Tablero.fail())
	{
	while(!Tablero.eof())
	{
	Tablero.getline(Numero,15,',');
	aux= atoi(Numero);
	Obj.set_Objeto(aux);
	LO.Agregar(Obj);
	size++;
	}
	Tablero.close();
	}else
	{cout<<"error al cargar el tablero"<<endl;}	
	//Tablero Cargado...
	//Empezando a jugar.
	/////////////////////////////////////////////////////////////////////////////

	J2->set_Tur(true);
	
	J1->set_Tur(true);
	while(!win)
	{
	
	 if(J1->get_Tur()==true&&J1->get_pos()<size)
	 {
 	 system("cls");//limpiamos
 	 
 	 J1->imprimir();//Datos del Jugador 1;
 	 
 	 LO.ImprimirTablero();//tablero para el jugador 1
 	 cout<<endl;
 	 
	 cout <<"\t Press any key to Roll:";//Cualquier tecla para jugar
	 cin.get();
	 cout<<endl;
	 rollDado=(rand() % 6+1);
	 cout <<"your roll:"<<rollDado;
	 cin.get();
 	 J1->set_pos(J1->get_pos()+rollDado);//Llevando la posision del jugador
    
     
     if(J1->get_pos()<size){
     	J1->set_puntaje(J1->get_puntaje()+(LO.get_elemento(J1->get_pos()).get_Objeto()));
     	J1->Add(LO.get_elemento(J1->get_pos()));//Agregando el objeto encontrado en la casilla a la cola en el jugador
		 LO.get_elemento(J2->get_pos()).set_Objeto(0);//pasando por aqui;
		}
	 while(J1->get_puntaje()>400)
	 {
	 	 Papelera.Agregar(LO.get_elemento(J1->get_pos()));
 	     J1->set_puntaje(J1->get_puntaje()-LO.get_elemento(J1->get_pos()).get_Objeto());
		 J1->Elimina();
	 }
	 
     LO.ImprimirTablero();
	 if(J1->get_pos()>=size)
	 {
	 	J1->set_Tur(false);
	 }
	 }
	 
	 ///////////////////////////////////////////
 	if(J2->get_Tur()==true&&J2->get_pos()<size)
	 {
 	 system("cls");//limpiamos
 	 J2->imprimir();//Datos del Jugador 2;
 	 
 	 LO.ImprimirTablero();//tablero para el jugador 2
 	 cout<<endl;
	 cout <<"\t Press any key to Roll:";//Cualquier tecla para jugar
	 cin.get();
	 cout<<endl;
	 rollDado=(rand() % 6+1);
	 cout <<"your roll:"<<rollDado;//haz jugado;
	 cin.get();
 	 J2->set_pos(J2->get_pos()+rollDado);//Llevando la posision del jugador
    
     
     if(J2->get_pos()<size){
     	J2->set_puntaje(J2->get_puntaje()+(LO.get_elemento(J2->get_pos()).get_Objeto()));
     	 J2->Add(LO.get_elemento(J2->get_pos()));//Agregando el objeto encontrado en la casilla a la cola en el jugador
	 LO.get_elemento(J2->get_pos()).set_Objeto(0);//pasando por aqui;
		}
	 while(J2->get_puntaje()>400)
	 {
	 	 Papelera.Agregar(LO.get_elemento(J2->get_pos()));
 	     J2->set_puntaje(J2->get_puntaje()-LO.get_elemento(J2->get_pos()).get_Objeto());
		 J2->Elimina();
	 }
	 
     LO.ImprimirTablero();
	if(J2->get_pos()>=size)
	 {
	 	J2->set_Tur(false);
	 }
	 
	 
	 
	 
	 }
	 if(!J1->get_Tur()&&!J2->get_Tur())
	 {
	win=true; 	
	 }
	 //Acabando el juego
	}
	if (win==true&&J1->get_puntaje()>J2->get_puntaje())
	{
		cout<<"Ganador JUGADOR1: "<<J1->get_Nom()<<" Puntaje: "<<J1->get_puntaje()<<endl;
	}
	else if (win==true&&J2->get_puntaje()>J1->get_puntaje())
	{
		cout<<"Ganador JUGADOR2: "<<J1->get_Nom()<<" Puntaje: "<<J1->get_puntaje()<<endl;
	}else cout<<"Empate¡¡¡ O_O "<<endl;	 //////////////////////////////////////////
	//definiendo al ganador
	
	
	return 0;
}
