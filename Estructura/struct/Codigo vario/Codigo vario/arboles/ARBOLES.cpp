#include <iostream>
#include <cstdlib>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <class T>
class NodoA
{
	private :
	int Fe;
	T inf;
	NodoA<T> *HI,*HD;    // Hijos por ambos lados.
	int nivel;
	int alturaD,alturaI,altura;// es mas facil manejar y expresar la altura apartir de cada nodo de esta manera;
	bool Hoja; 
	public :
		NodoA(){ HD=HI=NULL; inf=NULL;alturaD=alturaI=altura=0;Hoja=true;nivel=Fe=0;}
		
		NodoA(T elemento){HD=HI=NULL;inf=elemento;}
		
		void set_inf(T elemento){inf=elemento;}
		
		void set_HI(NodoA <T>* a){HI=a;}
		
		void set_HD(NodoA <T>* a ){HD=a;}
		
		void set_leaf(bool a){Hoja=a;}
		
		void set_alturaD(int a ){alturaD=a;}
		
		void set_alturaI(int a ){alturaI=a;}
		
		void set_alturaG(int a ){altura=a;}
		
		void set_Fe(int a){Fe=a;}
		
		void set_Nivel(int a){nivel=a;}
		
		bool get_leaf(){return Hoja;}
		
		int get_Nivel(){return nivel;}
		
		int get_alturaD(){return alturaD;}
		
		int get_alturaI(){return alturaI;}
		
		int get_alturaG(){return altura;}
		
		int get_Fe(){return Fe;}
		
		T get_inf(){return inf;}
		
		NodoA<T>* get_HI(){return HI;}
		
		NodoA<T>* get_HD(){return HD;}
		
		void actualizar();
				
};
template <class T>
void NodoA <T>::actualizar()
{
	if (alturaI<alturaD)
         altura=alturaD;
	else altura=alturaI;
	Fe = alturaD - alturaI ;
}

template <class T>
class ArbolBB
{
	private:
	NodoA<T> *Raiz;
	bool Eq;
	int altura;
	NodoA<T> * DES;
	NodoA<T> * DEP;	
	public:
		ArbolBB(bool Eq=false){Raiz=NULL;DES=DEP=NULL;altura=0;}
        void actual(int nivel = 0 ,NodoA<T>*p=NULL);
		void equilibrar();
		void preorden(NodoA<T> *p,int);
		bool isEq(){return Eq;}
		bool isEmpty(){return !this->get_Raiz();}
		int  get_Altura(){return altura;}
		void Agregar(T elemento);
		void Mostrar(NodoA<T>*);
		NodoA<T>* Buscar(T,NodoA<T>** antes=NULL);
		NodoA<T>* get_Raiz(){return Raiz;}
		NodoA<T>* menor(NodoA<T> *p,NodoA<T> **padre);
		NodoA<T>* mayor(NodoA<T> *p,NodoA<T> **padre);	
        NodoA<T>* RD(NodoA<T>*);
        NodoA<T>* RI(NodoA<T>*);
        NodoA<T>* CRD(NodoA<T>*,NodoA<T>*);
        NodoA<T>* CRI(NodoA<T>*,NodoA<T>*);
        
        
};
template <class T>
void ArbolBB<T> :: actual(int nivel, NodoA<T>*recorrido)
{
	
	if(recorrido->get_HI())
	{
		actual(nivel++,recorrido->get_HI());
	}
	
	if(recorrido->get_HD())
	{
		actual(nivel++,recorrido->get_HD());
	}
	if(recorrido->get_HD()) 
     recorrido->set_alturaD(recorrido->get_HD()->get_alturaG()+1);
    else recorrido->set_alturaD(0);  
    if(recorrido->get_HD()) 
     recorrido->set_alturaI(recorrido->get_HI()->get_alturaG()+1);
    else recorrido->set_alturaI(0);
    
    recorrido->actualizar();
    recorrido->set_Nivel(nivel);
    if(DES  && (recorrido->get_Fe()==2||recorrido->get_Fe==-2)&&Eq)DES=recorrido;
	if(DES && (recorrido->get_HI()==DES)||recorrido->get_HD==DES)DEP=recorrido;

}
template <class T>
void ArbolBB<T>::preorden(NodoA<T> * p ,int nivel)
{
	for(int i=0;i<nivel;i++)
	{
		cout<<"\t";
	}
		cout<<nivel<<" :"<<p->get_inf()<<endl;
		if(p->get_HD()){preorden(p->get_HD(),nivel++);}
	
		if(p->get_HI()){preorden(p->get_HI(),nivel++);}
}
template <class T>
NodoA<T>* ArbolBB<T>::mayor(NodoA<T> *p,NodoA<T> **padre){
	NodoA<T> *q=p;
	
	while(q->get_HD()){
		*padre=q;
		q=q->get_HD();
	}
	return q;
}
template <class T>
NodoA<T>* ArbolBB<T>::menor(NodoA<T> *p,NodoA<T> **padre){
	NodoA<T> *q=p;
	
	while(q->get_HI()){
		q=q->get_HI();
	}
	return q;
}

template <class T>
NodoA<T>* ArbolBB <T>::Buscar(T elemento,NodoA<T> ** anterior)
{
	NodoA<T>* recorrido=Raiz;
	
	while(recorrido)
	{
		if(anterior)
		*anterior=recorrido;
		
		if(elemento==recorrido->get_inf())
		{
			return recorrido;
		}
		else if(elemento<recorrido->get_inf())
		{
			recorrido=recorrido->get_HI();
		}else
		    recorrido=recorrido->get_HD();
	
	if(recorrido&&elemento==recorrido->get_inf())
	return recorrido;
	}
	return NULL;
}

template <class T>
void ArbolBB<T>::Agregar(T elemento)
{
NodoA<T>* Agregado= new NodoA<T>(elemento);
NodoA<T>* recorrido; 
NodoA<T>* antes = NULL;

if(Agregado)
{
	if(this->isEmpty())
	{
		Raiz=Agregado;
	}
	else
	{
	recorrido=Buscar(elemento,&antes);	
	if(recorrido)
	{
		return;
	}else
		 {
		if(elemento<antes->get_inf()){antes->set_HI(Agregado);}
		else antes->set_HD(Agregado); 	
	 	 }
    }
    
    actual(0,Raiz);
    altura= Raiz->get_alturaG();
    
    while(Eq&&DES)
	{
	equilibrar();
	actual(0,Raiz);
	altura=Raiz->get_alturaG();	
	}
	
}else return;

return;
 
}

template <class T>
void ArbolBB<T>::equilibrar()
{
          NodoA<T>* SubRaiz;
		  if(DES->get_Fe()==2)
		  {
	      
	       if(DES->get_HD()->get_Fe()>0)
		   {
		   	SubRaiz=RI(DES->get_HD());
		  	}
	      	else
		  	{
		  	SubRaiz=CRI(DES->get_HD(),DES->get_HD()->get_HI());
		  	}
		  }else
		  	   {
		  	   if(DES->get_HI()->get_Fe()<0)
				 {
				 	SubRaiz=RD(DES->get_HI());
				 }else
				 {
				 	SubRaiz=CRD(DES->get_HI(),DES->get_HI()->get_HD());
				 }
			   }
		   if(DEP)
		   {
		   	if(DEP->get_HD()==DES)
			   {
			   	DEP->set_HD(SubRaiz);
			   }else
			    DEP->set_HI(SubRaiz);
		   }
		   if(DES==Raiz)
		   {
		   	Raiz=SubRaiz;
		   }
		   DES=DEP=NULL;
}
template <class T>
NodoA<T>* ArbolBB<T>::RI(NodoA<T>*p)
{
	DES->set_HD(p->get_HI());
	p->set_HI(DES);
	return p;
}
template <class T>
NodoA<T>* ArbolBB<T>::RD(NodoA<T>*p)
{
	DES->set_HI(p->get_HD());
	p->set_HD(DES);
	return p;
}
template <class T>
NodoA<T>* ArbolBB<T>::CRD(NodoA<T>*p,NodoA<T>*paux)
{
	DES->set_HD(paux->get_HI());
	paux->set_HI(DES);
	p->set_HI(paux->get_HD());
	paux->set_HD(p);
	return paux;
}
template <class T>
NodoA<T>* ArbolBB<T>::CRI(NodoA<T>*p,NodoA<T>*paux)
{
	DES->set_HI(paux->get_HD());
	paux->set_HD(DES);
	p->set_HD(paux->get_HI());
	paux->set_HI(p);
	return paux;
}

template <class T>
void ArbolBB<T>::Mostrar(NodoA<T>* recorrido)
{
	if(!recorrido)
	{
		cout<<"Arbol vacio"<<endl;
		return;
	}
	if(recorrido->get_HI())
	{
		Mostrar(recorrido->get_HI());
	}
	for(int i=0;i<recorrido->get_Nivel();i++)
	{
		cout<<"\t\t";
	}
	cout<<recorrido->get_inf()<<endl;
	if(recorrido->get_HD())
	{
		Mostrar(recorrido->get_HD());
	}
	
}

int main(int argc, char** argv) {
	ArbolBB <int> B= new ArbolBB<int>(true);
    B.Agregar(12);
    B.Agregar(62);
    B.Agregar(22);
    B.Agregar(5);
    B.Agregar(10);
    B.Agregar(9);
    B.Mostrar(B.get_Raiz());
	return 0;
}
