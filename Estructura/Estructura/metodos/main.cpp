#include <cstdlib>
#include <iostream>
#include "time.h"
using namespace std;



void Metodo_Burbuja(int vec[10]);
void Metodo_Burbuja_Optimizada(int vec[10]);
void Metodo_Seleccion(int vec[10]);
void Metodo_Shell_Sort(int vect [10]);
void Metodo_Insercion(int vec[10]);
void Metodo_Shaker_Sort(int vec [10]);
void Restauracion_del_Vector(int vec2[],int vec[]);
int  metodoPibote(int vec[10],int tam);
void QuickSort(int vec[10],int Tam);
void Tiempo_Por_Metodo();
void Imprimir(int vec[10]);
void menu();

int main(int argc, char *argv[])
{
menu();

system("PAUSE");

return 0;
}
void Imprimir(int vec[])
{
for(int i=0;i<10;i++)
     {
     cout<<vec[i]<<" ";
     }
cout<<endl;
}


void menu()
{
    
int x=0;
int vec[10]={19,17,8,45,18,282,192,1942,172,194};
int vec2[10]={19,17,8,45,18,282,192,1942,172,194};
//Metodo_Burbuja(vec);
//Metodo_Burbuja_Optimizada(vec);
//Metodo_Seleccion(vec);
//Metodo_Shell_Sort(vec);
//Metodo_Insercion(vec);
//Metodo_Shaker_Sort(vec);
QuickSort(vec,10);
Imprimir(vec);
}

void Metodo_Burbuja(int vec[])
{
     int aux=0;
    
    for(int k=9;k>0;k--){
     for(int i=0;i<9;i++)
     {
             if(vec[i]>vec[i+1])
             {
             aux=vec[i];
             vec[i]=vec[i+1];
             vec[i+1]=aux;
             }
            
     }
     }
     
}
void Metodo_Burbuja_Optimizada(int vec[])
{
int aux=0 , band=0;
for(int k=9;k>0&&band==0;k--){
     band=1;
     for(int i=0;i<9;i++)
     {
            
             if(vec[i]>vec[i+1])
             {
             band=0;
             aux=vec[i];
             vec[i]=vec[i+1];
             vec[i+1]=aux;
             }
     }
     
     }                        
}
void Metodo_Seleccion(int vec[])
{
     int mayor=0, aux;

       for(int i=9;i>0;i--)
	{
        
		mayor=0;
		for(int j=0;j<=i;j++)
		{
			if(vec[j]>vec[mayor])
			mayor=j;
				if(mayor != i)
				{
	         aux=vec[mayor];
	         vec[mayor]=vec[i];
	         vec[i]=aux;
	            }
		}

	}


}
void Tiempo_Por_Metodo()
{
int inicio, fin ,t;
inicio=clock();
fin=clock();
t=fin-inicio;
cout<<endl;
cout<<t;
cout<<endl;     
}
void Restauracion_del_Vector(int vec2[],int vec[])
{
    for(int i=0;i<10;i++)
     {
     vec[i]=vec2[i];
     } 
}
void Metodo_Shell_Sort(int vec[])
{
     int incremento=10/2,aux=0;
     while(incremento>0)
     {
     for(int i=0 ;i+incremento<10;i++)
     {
     if(vec[i]>vec[i+incremento])
     {
                                 aux=vec[i];
                                 vec[i]=vec[i+incremento];
                                 vec[i+incremento]=aux;
                                 while(i >= 0 && vec[i]<vec[i-incremento])
                                 {
                                 aux=vec[i];
                                 vec[i]=vec[i-incremento];
                                 vec[i-incremento]=aux;
                                 i-=incremento;
                                 }
     }
     
     }
     incremento/=2;
     
     }
     
}

void Metodo_Insercion(int vec[])
{
	
int i,aux=0,j=0,inicio=0;


}
void Metodo_Shaker_Sort(int vec [])
{
  int aux =0,Izq=0,Der=10;
  
do{
	for(int i =Izq;i<Der;i++)
	{
		if(vec[i]>vec[i+1])
		{
			aux=vec[i];
			vec[i]=vec[i+1];
			vec[i+1]=aux;
		}
	}
	
	
	for(int i =Der;i>Izq;i--)
	{
		if(vec[i]<vec[i-1])
		{
			aux=vec[i];
			vec[i]=vec[i-1];
			vec[i-1]=aux;
		}
	}
	Izq++;
	Der--;
	
}while(Izq<=Der);
  
  
  
     
}
void QuickSort(int vec[],int Tam)
{
	int pospib;
	int SufPeq=3;
	if(Tam<=SufPeq)
	{
	Metodo_Insercion(vec);	
	}
	else
	{
	pospib=metodoPibote(vec,Tam);
	QuickSort(&vec[0],pospib);
	QuickSort(&vec[pospib],Tam-pospib-1);	
	}
}

///////////////////////////////////////////////----------------------------------/////////////////////////////////////////////////////////////////////

int metodoPibote(int vec[],int Tam)
{
//Metodo para dividir el array;	

int Aux;
int i = 1;
int j = Tam-1;

while(i<j)
{
int pibo=vec[0];
  while(vec[i]<pibo&&i<Tam)
 {					 
 i++;	
 }
  while(vec[j]>pibo&&j>=0)
 {
 j--;
 }	
 
 if(i<j)
 {
  Aux=vec[i];
  vec[i]=vec[j];	
  vec[j]=Aux;
 }
}
return j;
}







