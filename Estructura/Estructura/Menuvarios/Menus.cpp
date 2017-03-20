#include <iostream>
#include <time.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

template <class X>
class pila{
protected:
	X buffer;
	X *V;
	int Tam;
	int Top;
	public:
		pila(int tam){Tam=tam;Top=-1;}
		int Tamano(){ V= new X [Tam];}
		int Agregar(X);
		int Eliminar(X);
		void Menu();
		void Imprimir();
		
};
template <class X>
int pila <X>::Agregar(X buffer)
{
     if(!V)
     {
     	return -1;
	 }
	 if(Top==Tam-1)
	 {
	 	return 0;
	 }
	 V[Top]=buffer;
	 Top++;
	 return 1;
}
template <class X>
int pila <X>::Eliminar(X buffer)
{
	if(!V)
     {
     	return -1;
	 }
	  if(Top==-1)
	 {
	 	return 0;
	 }
	 buffer=V[Top];
	 Top--;
	 return 1;
}
template <class X>
void pila<X>::Menu()
{
	int r=999;
	
while (r!=0){

cout<<"Ingrese opcion:"<<endl;
cout<<"1.Agregar elemento."<<endl;
cout<<"2.Eliminar elemento"<<endl;
cin>>r;

switch(r)
{
case 1:
this.Agregar(buffer); break;
case 2: 
this.Eliminar(buffer); break;
default: break;
}

}
}

template <class X>
void pila <X>::Imprimir(){
int i=0;
for(i=0;i<Top;i++)
{
	cout<<V[i]<<endl;
}	
}






int main(int argc, char** argv) {
	
	int Tam,Valor,result;
	cout<<"ingrese el tamaño del elemento:"<<endl;
	cin>>Tam;
	pila <int> V(Tam+1);
	
	srand(time(NULL));
	V.Tamano();
	for(int i=0;i<Tam+1;i++)
	{
	   	Valor=rand()%40+1;
	   result = V.Agregar(Valor);
	   if(result==-1)
	   {
	   	cout<<"Vacio"<<endl;
	   }
	   if(result==0)
	   {
	   	cout<<"no espacio en la pila"<<endl;
	   }
	   if(result==1)
	   {
	   	cout<<"Agregado correctamente"<<endl;
	   }
	   
	}
	V.Imprimir();
	return 0;
}





