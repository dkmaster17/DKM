#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <class T>
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
 /////Tempalte clase Nodo con metodos/////////////
template <class T>
class ColaDin//Primero al entrar Primero al salir .
{
	private:
	Nodo <T> *Cabecera ,*Fin;
	public:
		
	bool Vacia(){return Cabecera==NULL;}

int Agregar(T elemento)
{
	
	Nodo<T> *Agregado;
	Agregado= new Nodo<T>(elemento);
	if (Cabecera==NULL)
	{	
		Cabecera=Agregado;
		Fin= Agregado;
	}else
	{
	Fin->set_Sig(Agregado);
	Fin=Agregado;
	}
	
	return 0;
}

int Eliminar()
{
	Nodo<T> *aux;
	aux= Cabecera->get_Sig();
	if(Vacia())
	{
		cout <<"lista vacia"<<endl;
	return 0;
	}else
	Cabecera->set_Inf(0);
	delete Cabecera;
	Cabecera=aux;
	return 1;
}

int Buscar(T elemento)
{
	Nodo <T> *Aux;
	Aux=Cabecera;
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
Recorrido=Cabecera;
if(Recorrido==NULL){cout<<"lista vacia"<<endl;}
while(Recorrido!=NULL)
{
	cout<<Recorrido->get_Inf()<<endl;
	Recorrido=Recorrido->get_Sig();
}

}
void Vaciar()
{
	int eliminado=0;

	while(Cabecera!=NULL)
{
eliminado=Eliminar();
}
if(eliminado==1)
{
	cout <<"Lista vaciada"<<endl;
}

}
};

///////////////------------ColasDin Completamente Funcionales
//////////////-------------Inicio PilasDinamicas------------
template <class T>
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
if(Recorrido==NULL){cout<<"lista vacia"<<endl;}
while(Recorrido!=NULL)
{
	cout<<Recorrido->get_Inf()<<endl;
	Recorrido=Recorrido->get_Sig();
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
//////////////-------------Fin Pilas Dinamicas ---------------//////
/////////////--------------Inicio Listas Doblemente enlazadas--------//////////
template <class  T>
class ListasDoblemente{
	
	private:
	Nodo<T>*Actual,*Final;
	
	int Tam;
public :
	static const bool Circular=true;
	static const bool Dob=true;
	static const int att_Ini=1;
	static const int att_End=2;
	static const int att_Cre=3;
	static const int att_Dec=4;
	static const int Elim_Ini=-1;
	static const int Elim_element=0;
	static const int Elim_Final=1;
	
	 
	ListasDoblemente(){Actual=NULL;Final=NULL;}
	bool vacia(){return Actual==NULL;}

Nodo<T>* Buscar(T Elemento,int Tipo=1)
{
	Nodo <T> *Buscando;
	Buscando=Actual;
	bool Comenzo=false;
	while(Buscando &&(Buscando !=Actual ||!Comenzo))
	{
		if(!Comenzo)
		{
			Comenzo=true;
		}
		if(Tipo==1&&(Elemento == Buscando->get_Inf()))
		{
			return Buscando;
		}else return NULL;
		
	}
}
	int Agregar(T elemento,int pos=1)
	{
    Nodo <T>* Agregado,*Recorrido;
    Agregado= new Nodo<T>(elemento);
 	Recorrido= Actual;
 	Nodo<T> *Anterior= NULL;
 	if(Agregado)
	 {
	 	Recorrido=this->Buscar(elemento,1);
	 	if(Recorrido)
	 {
	 	return -1;
	 }
	  Recorrido=Actual;
	  Anterior=NULL;
	 }
	 
	
	 
	
	if( pos == att_Cre || pos == att_Dec ) 
		{ 
			// obtengo las posiciones recor y antes  del nuevo Nodo
			Recorrido = this->Buscar(elemento,1);
		} 
		else if( pos == att_End ) // si no, si se quiere agregar al final 
		{
			Recorrido = NULL; // recor sera NULL
			Anterior = Final; // antes sera el fin
		}
		if (!Anterior && !Recorrido)
		{
			Actual=Final=Agregado;
		}
		if(Recorrido)
		{
			Recorrido->set_Ant(Agregado);
			Agregado->set_Sig(Recorrido);
			Actual = ( Recorrido == Actual ? Agregado : Actual );
		}		
		if(Anterior) // antes tiene dirección
		{	// si la lista es doble, pre de nuevo será antes 
			Agregado->set_Ant(Anterior);
			Anterior->set_Sig(Agregado);
			
			// si agregue de ultimo, fin ahora sera nuevo
			Final = ( Anterior == this->Final ? Agregado : this->Final );
		} // fin del if
		if(Circular)
		{
			Final->set_Sig(Actual);
			if(Dob)
			{
			 Actual->set_Ant(Final);
			}
		}
		Tam++;
		return 1;
    }
	void Mostrar()
	{
		
	Nodo <T> *Recorrido;
	Recorrido = Actual;
	if(!Recorrido)
	 {
	 	cout<<"Sin espacio"<<endl;	
	 }
	 
	 if(Recorrido && Actual== Final)
	 {
	 	for( int i = 0; i < ( Dob ? 2 : 1 ); i++ )
		{
			cout << Recorrido->get_Inf();
		
			// si la ListaD es circular
			if(Circular) // imprimo enlace circular
				cout << "|-->" << Recorrido->get_Sig()->get_Inf() <<endl; 
			else
				cout << "-->NULL" << endl; // enlace utimo Nodo
		}
	  }
	  while(Recorrido && Recorrido != Final)
	  {
	  	cout<<Recorrido->get_Inf()<<endl;
	  	Recorrido= Recorrido->get_Sig();
	  	
		  if(Circular)
		  {
		  	cout<<Recorrido->get_Sig()->get_Inf()<<endl;
		  }else
		  cout<<"vacio"<<endl;
      }	
    	/*
    	Recorrido=Final;
    	while (Recorrido &&Dob && Recorrido!=Actual)
		{
		cout<<Recorrido->get_Inf()<<endl;
		Recorrido=Recorrido->get_Ant();	
		if(Recorrido==Actual)
		{
		cout<<Recorrido->get_Inf()<<endl;
		if(Circular)
		 {
		 	cout<<Recorrido->get_Ant()->get_Inf();
		 }
		 else{cout<<"Vacio"<<endl;}
		}
		
		}
		*/
	}
};
int main(int argc, char** argv) {




/*
	ListasDoblemente<int> Lista;
	Lista.Agregar(12);
    Lista.Agregar(15);
    Lista.Agregar(17);

	
	Lista.Mostrar();
*/	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	/*
	int buscar;
	PilasDin<int> Pilas;
	Pilas.Agregar(12);
	Pilas.Agregar(17);
	Pilas.Agregar(16);
	Pilas.Agregar(27);
	Pilas.Agregar(19);
	Pilas.Mostrar();
	Pilas.Eliminar();
	Pilas.Eliminar();
	buscar= Pilas.Buscar(29);
	if(buscar==1){cout<<"encontrado"<<endl;}
	Pilas.Mostrar();
	*/
	ColaDin<int> Cola;
	int buscar;
	Cola.Mostrar();
	Cola.Agregar(12);
	
	Cola.Agregar(11);
	
	Cola.Agregar(16);
	
	Cola.Agregar(15);

	Cola.Mostrar();
	//buscar = Cola.Buscar(12);
	//if(buscar ==1){ cout <<"encontrado"<<endl;}else{cout<<"no encontrado"<<endl;}
	//Cola.Vaciar();
	//Cola.Mostrar();
	
	return 0;
}
