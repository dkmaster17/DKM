#include <iostream>
#include <fstream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//Gustavo Florez parte 2 25837802 Sec 2;
template <class T>
class Nodo//Nodos genericos
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
 template <class T>//Lista basica simple
 class Lista
 {
 	private :
 		Nodo<T> *Cab;
	public:
	Lista(){Cab=NULL;} 

	Nodo<T> Buscar(T elemento)
{
	Nodo <T> *Aux;
	Aux=Cab;
	int enc=0;
	if(Cab==NULL)
	{
		cout <<"lista vacia"<<endl;
	
	}else
	{
	while(Aux!=NULL)
	{
		if(Aux->get_Inf()==elemento)
		{
			enc=1;
			return Aux;
		}
		
	    Aux=Aux->get_Sig();	
		
	}
		return NULL;
	}
	
}
    void Agregar(T elemento)
	{
	Nodo<T>* Agregado = new Nodo<T>(elemento); 
	Nodo<T>* Recorrido = Cab; 
	Nodo<T>* Antes = NULL; 
	
	
	if( Agregado ) 
	{
		while( Recorrido )
		{
		
			if( Agregado->get_Inf() < Recorrido->get_Inf() )
				break; 
				
			Antes = Recorrido;	
			Recorrido = Recorrido->get_Sig(); 
		} 
		
		
		
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
    void Eliminar( T elemento )
{
	Nodo<T>* eliminar = Cab; // Nodo a eliminar de la lista
	Nodo<T>* Antes; // Nodo anterior a eliminar 
	
	if( Cab==NULL ) // si la lista no esta vacia
	{	
		while( eliminar ) // mientras recor no sea NULL
		{
			// si recor es igual a los buscado
			if( eliminar->getInfo() == elemento )
				break; // salgo del ciclo
		
			Antes = eliminar;	
			eliminar = eliminar->get_Sig(); // recor sera su sucesor 
		} // fin del while 
		
		
		// si no se encuentra el elemento a eliminar
		if( !eliminar ) 
			return false; // fallo al eliminar
		
		// si se va a eliminar la cabezera de la lista 
		if( eliminar == this->cab )
			Cab = Cab->get_Sig(); // cab sera su sucesor 
		else
			Antes->set_Sig( eliminar->get_Sig());
					
		delete eliminar; // elimina Nodo	
	}

		
	
} 
    
    void Mostrar(int a)
	 {
	 	Nodo<T> *Recorrido;
	 	Recorrido= Cab;
	 	if(!Cab){
		 cout<<"No BOOK";
		 }
		 else
		 {
		 	while (a!=0)
		 	{
 		        Recorrido->get_Inf().imprimir();//imprmirnedo los datos de Recetas
		 		Recorrido=Recorrido->get_Sig();
		 		if(Recorrido==NULL)
				 {
				  cout<<"Over";
				  break;	
				 }
				 a--;
		    }
		 }
	 }
 }; 
 
 template <class T>//Ingredientes con lista de codigos
 class Ingredientes
 {
 	private:
 char Nom[50];
 int  calorias;
 Lista <T> codigos;//ordenada asendentemente :es un int 
 public:
 	Ingredientes(char* Nombre ,int cal){Nom=Nombre;calorias=cal;codigos=NULL;}
 	void imprimir(){cout<< Nom<<" ,"<<calorias<<"-->" ;}
 	
    char* get_Nom(){return Nom;}
 	
 	void set_Nom(char* a){Nom=a;}
			
	void set_calorias(int a){calorias=a;}
	
	int get_calorias(){return calorias;}
	void Codigos(T elemento){codigos.Agregar(elemento);}
			
 };
 
 template <class T>
 class Recetas//Recetas con lista de ingredientes
 {
 	 private :
	 char Nombre[50];
	 int calorias;
	 int codigo;
	 Lista <T> Ingrediente;
	 
        public :
        	Recetas(){}
        	Recetas(char* Nom,int a,int b){Nombre=Nom;calorias=a;codigo=b;Ingrediente=NULL;}
        	void imprimir(){cout<<"Receta: "<<Nombre<<" codigo :"<<codigo<<" Total Calorias: "<<calorias<<endl;
			                Ingrediente.Mostrar();}//Al llamar desde aqui a mostrar deberia usar el mismo metodo 
							                       //imprimir  como lo emplea ingredientes 
												   //para asi imprmirlo todo desde aqui.
			
			void cargarIngredientes()
			{
				char Ingre[50];
				int cal;
			ifstream Ing;
			Ing.open("ingredientes.txt");
			if(!Ing.fail())
			{
			while (!Ing.eof())
			{
				Ing.getline(Ingre,50,'(,)');
				Ing>>cal;
				Ingredientes<T> Aux;
				
				Aux= new Ingredientes<T>(Ingre,cal);
				while(Ing.get()!='\n')
				{
					Ing>>cal;
					Aux.Codigos(cal);//Lista de Codigos
				}
				
				Ingrediente.Agregar(Aux);//Codigos agregados a los ingredientes
			}	
				
			}
			else
			{
				cout<<"no se pudieron cargar los ingredientes"<<endl;
			}
			
			}
			int get_calorias(){return calorias;}
			
			int get_codigo(){return codigo;}
			
			char* get_Nom(){return Nombre;}
			
			void set_calorias(int a){calorias=a;}
			
			void set_codigo(int a){codigo=a;}
			
			void set_Nom(char* a){Nombre=a;}
        	
 };


int main(int argc, char** argv) {
	int code=0;
	char Nombre[50];
	int calorias=0;
	Recetas < Ingredientes<int> > Aux;
	Lista < Recetas <Ingredientes<int> > > Recetario;
	ifstream Libro;
	Libro.open("Libro.txt");
	if(!Libro.fail())
	{
		while(!Libro.eof())
		{
			Libro>>code;
			Libro.getline(Nombre,50,',');
		    Libro>>calorias;
		    Aux.set_calorias(calorias);
		    Aux.set_Nom(Nombre);
		    Aux.set_codigo(code);
	        Recetario.Agregar(Aux);
		}
		
		Libro.close();
	}else 
	{
		cout<<"no se pudo cargar el libro"<<endl;
	}
	Aux.cargarIngredientes();
	cout<<"Alimentos Hipocaloricos"<<endl;
	Recetario.Mostrar(3);//para mostrar las 3 recetas con menos calorias dado que se acomoda de manera ascendente. los menores seran los primeros 
    cout<< endl;
	int cod;
	cout <<"Editando una receta ingrese el codigo de la receta: "<< endl;
	cin >>cod;
	
	Recetario.Buscar();//Funcionaria alterando la busqueda para recetario y bsucando el codigo en si get-Inf falto tiempo .
	if(Aux!=NULL)
	{
		cout<<"se encontro,Ingrese cambio:"<<endl;
		cin>>calorias;
		Aux->get_Inf().set_calorias(calorias);
	}else
	{
		cout <<"No se encontro"<<endl;
	}
    cout <<"Ingrese codigo receta a eliminar:"<<endl;
    cin>>cod;
    
    Recetario.Eliminar(cod);
	if(Aux==NULL)
	{
		cout<<"Se ah borrado"<<endl;
	}else
	{
		cout <<"No se encontro"<<endl;
	}
    
	
	
	return 0;
}




