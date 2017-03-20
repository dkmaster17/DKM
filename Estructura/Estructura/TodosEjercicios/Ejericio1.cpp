#include <iostream>
#include "string.h"
#include <fstream>
#include "Usuario.h"
#include <math.h> 
//GUSTAVO ANDRES FLOREZ BALLESTEROS SECCION 2  //TODOS LOS EJERCICIOS 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
int  cargar(Usuario *Users,int n)
{
	ifstream Data;
	string Nombre;
	long SaldoD;
	long long Targeta;
	int i=0;
	
	Data.open("InformacionClientesMorosos.txt",ios::in);
	if(Data.fail())
	{
	cout <<"No se encuentra el archivo que busca"<<endl;
	}
	else
	{
	while (!Data.eof())
	{
	Data>> Nombre;
	Data>> Targeta;
	Data>> SaldoD;
	Users[i].setTitular(Nombre);
	Users[i].setSaldoD(SaldoD);
	Users[i].setTargeta(Targeta);
	i++;
	}
	
	}
	Data.close();
	
	return i;
	
}

void Mostrar(Usuario *Users,int n)
{
	for (int i = 0; i<n;i++)
	{
	Users[i].mostrar();
	}
}
void Metodo_Shell_Sort(Usuario *Users,int n)
{
     int incremento=n/2;
	 Usuario UserAux;
     while(incremento>0)
     {
     for(int i=0 ;i+incremento<n;i++)
     {
     if(Users[i].getSaldoD()>Users[i+incremento].getSaldoD())
     {
                                 UserAux=Users[i];
                                 Users[i]=Users[i+incremento];
                                 Users[i+incremento]=UserAux;
                                 while(i >= 0 && Users[i].getSaldoD()<Users[i-incremento].getSaldoD())
                                 {
                                 UserAux=Users[i];
                                 Users[i]=Users[i-incremento];
                                 Users[i-incremento]=UserAux;
                                 i-=incremento;
                                 }
     }
     
     }
     incremento/=2;
     
     }
	 
}
void Metodo_Shaker_Sort(Usuario *Users ,int n)
{
  int Izq=0,Der=n;
  Usuario UserAux;
  
    do{
	for(int i =Izq;i<Der;i++)
	{
		if(Users[i].getTargeta()<Users[i+1].getTargeta())
		{
			UserAux=Users[i];
			Users[i]=Users[i+1];
			Users[i+1]=UserAux;
		}
	}
	
	
	for(int i =Der;i>Izq;i--)
	{
		if(Users[i].getTargeta() > Users[i-1].getTargeta())
		{
			UserAux=Users[i];
			Users[i]=Users[i-1];
			Users[i-1]=UserAux;
		}
	}
	
	Izq++;
	Der--;
	
}while(Izq<=Der);

}
void Metodo_Seleccion(Usuario *Users,int n)
{
     int Base; Usuario UserAux;

       for(int i=n-1;i>0;i--)
	{
        
		Base=0;
		for(int j=1;j<=i;j++)
		{
			if(Users[j].getTitular()>Users[Base].getTitular())
			   Base=j;
				if(Base != i)
				{
	            UserAux=Users[Base];
	            Users[Base]=Users[i];
	            Users[i]=UserAux;
	            }
		}

	}



}

int Hash(long long clave)
{
long long x;
double aux=0;
int tam=16;
int resp;
int j =tam-1;
int vec[tam];
for(int i =0;i<tam;i++)
{  
x = pow(10,j);
j--;    
vec[i] = (clave/x)%10;

}

j=5;
for(int i=0;i<6;i++)
{
aux  = (vec[(tam-1)-vec[i]]*pow(10,j))+aux ;
j--;
}

aux=sqrt(aux)*100;
resp=int(aux)%100;
return resp;
}
void mostrarHashingRaiz(Usuario *Users,int n)
{
int pos;
	for (int i = 0; i<n;i++)
	{
	pos=Hash(Users[i].getTargeta());
	cout <<"\t"<<pos<<endl;
	}
}
//----------------------------------------------------------------
void Metodo_Insercion_Variacion(int vec[])
{
    int mayor=0, count=0 ,pos=0;
    int aux;
    int j=0; 
    int k=0;  
	for(int i=0;i<8;i++)
    {
     if(vec[i]<vec[i+1]&&i+1<8)
        {count++;}
        else{count=0;}
       if(count>mayor)
       {
       mayor=count;               
       pos=i-mayor+1;
       }
    }
for(k=pos-1;k>0;k--)
{
	
aux=vec[k];
j=k+1;
while(j<=8&&vec[j]<aux)
{
vec[j-1]=vec[j];
j++;
}
vec[j-1]=aux;
}

    
    for(k=pos+1;k<8;k++)
{
	
aux=vec[k];
j=k-1;
while(j>=0&&vec[j]>aux)
{
vec[j+1]=vec[j];
j--;
}
vec[j+1]=aux;
}
for(int i=0;i<8;i++)
{cout<< vec[i]<<" ";}
} 
//----------------------------------------------------------------
int main(int argc, char** argv) {
    int vec[8]={6,24,12,16,20,17,10,19};
	int n=50;
	int aux=0;
	int r;
	Usuario *Users= new Usuario[n];
    aux =cargar(Users,n);
    
    do{
    cout << "Ingrese la opcion que desea:"<<endl;
    cout <<"1.Alfebeticamente"<<endl;
    cout <<"2.Asendente"<<endl;
    cout <<"3.Decendente"<<endl;
    cout <<"4.Hash"<<endl;
    cout <<"5.InsercionVariacion"<<endl;
    cout <<"6.Salida"<<endl;
	cin >> r ;
	
	switch(r)
	{
	case 1: 
	system("cls");
	Metodo_Seleccion(Users,aux);
	Mostrar(Users,aux);
    system("PAUSE");
	break;	
	case 2: 
	system("cls");
	Metodo_Shaker_Sort(Users,aux);
	Mostrar(Users,aux);
	system("PAUSE");
	break;
	case 3: 
	system("cls");
	Metodo_Shell_Sort(Users,aux);
	Mostrar(Users,aux);
    system("PAUSE");
	break;
	case 4: 
    system("cls");
    mostrarHashingRaiz(Users,aux); 
    system("PAUSE");
    break;
    
	case 5:
    system("cls");
    Metodo_Insercion_Variacion(vec);
    system("PAUSE");
	break;
	case 6:
	break;
	}
system("cls");
}while (r!=6);
	system("PAUSE");
return 0;
}

