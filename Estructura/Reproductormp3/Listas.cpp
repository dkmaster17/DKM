#include <iostream>
#include <string.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <class T>
class Nodo//TOOODO SALE DE AQUI-
{
	private:
	T Inf ;
	Nodo *Sig,*Ant;//direciones de memoria ;
	public:
        Nodo()
		{
		Sig=NULL;
		Ant=NULL;
		Inf=NULL;
		}
		
		Nodo(T Informacion)
		{
		Sig=NULL;
		Ant=NULL;	
		Inf=Informacion;
		}
		Nodo<T> get_Sig()
		{return Sig;}
		void set_Ant(Nodo<T> *a){Ant=a;}
		
		void set_Sig(Nodo<T> *a){Sig=a;}
		
		*Nodo <T> get_Ant(){return Ant;}
		
		
		
		T get_Inf()
		{return Inf;}
		
	    T set_Inf(T Informacion)
		 {Inf=Informacion;}
};
///////------------ListasMetodos--------------//////
template <class T>
class ListasDob
{
	private:
	Nodo <T> *Cab;
	Nodo <T> *Final;
	
	public:
	ListasDob(){Cab=NULL;}
    bool  Vacia(){return Cab==NULL;}//uno a uno; Puede estar vacia ya 0 vacia 1 almenos 1 elemento
//////----------------------Incercion cabezera------////

void InserciondeCabezera(T elemento)
{
Nodo<T> *Agregado;
Agregado= new Nodo<T>(elemento);
Agregado->set_Sig(Cab);
if(Cab!=NULL)
{
Cab->set_Ant(Agregado);
Cab=Agregado;
}
}
/////---------------------IncercionInterna------////

void InsercionInterna(Nodo<T> *anterior,T elemento)
{
	Nodo <T> *Agregado;
	Agregado= new Nodo<T>(elemento);
	Agregado->set_Sig(anterior->get_Sig());
	if(anterior->get_Sig()!=NULL)
	{
		anterior->get_Sig()->set_Ant(Agregado);
		anterior->set_Sig(Agregado);
		Agregado->set_Ant(anterior);
	}
}

int Buscar(T elemento)
{
	Nodo* buscarLista(T destino)
{
Nodo* indice;
for (indice = primero; indice!= NULL; indice = indice->enlaceNodo())
if (destino == indice -> datoNodo())
return indice;
return NULL;
}
Nodo* buscarPosicion(int posicion)
{
Nodo* indice;
int i;
if (0 >= posicion) // posición ha de ser mayor que 0
return NULL;
indice = primero;
for (i = 1;(i < posicion) && (indice != NULL); i++)
indice = indice -> enlaceNodo();
return indice;
}
	
	
}


int Eliminar(T entrada)
{
Nodo<T>* actual;
bool encontrado = false;
actual = Cab;
// Bucle de búsqueda
while ((actual != NULL) && (!encontrado))
{
encontrado = (actual -> get_Inf() == entrada);
if (!encontrado)
actual = actual -> get_Sig();
}
// Enlace de nodo anterior con el siguiente
if (actual != NULL)
{
//distingue entre nodo cabecera o resto de la lista
if (actual == cabeza)
{
cabeza = actual -> get_Sig();
if (actual ->get_SIg() != NULL)
actual -> get_Sig() -> set_Ant(NULL);
}
else if (actual -> get_Sig() != NULL) // No es el último
{
actual->get_Ant()->set_Sig(actual->get_Sig());
actual->get_Sig()->set_Ant(actual->get_Ant());
}
else // último nodo
actual->get_Ant()->set_Sig(NULL);
}
}

int Agregar(T elemento)
{		
if(elemento<Cab->get_Inf())
{
	InserciondeCabezera(elemento);
}
if(elemento>Cab->getInfo())
{
     InsercionInterna(T elemento);
}	
}

void Visualizar()
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
};
///////------------FinMetodosListas--------------//////
int main(int argc, char** argv) {
	int x;
	ListasDob <int> PrLista;
while (x!=0)
{
cout <<"Desea agregar otro dato a la lista"<<endl;
cin << x;
	PrLista.Agregar(x);
	PrLista.Visualizar();
}

	return 0;
}


