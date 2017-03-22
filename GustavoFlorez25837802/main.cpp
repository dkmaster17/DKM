#include <iostream>
#include <string.h>
#include <fstream>
#include <math.h> 
/*Gustavo Florez 25837802*/

using namespace std;

int Transformacion(int n, int base) 
{
   int Valor=0, coeficiente=1;
   while (n!=0) 
   {
      Valor+=coeficiente*(n%base);
      coeficiente*=10;
      n/=base;
   }
   return Valor;
}


void Problema01_Digito_de_la_Suerte()//Me falto cabeza .
{

	ifstream Entrada;
	ofstream Salida;
	int N=0,S=0,auxpow=0,auxSalida=0;
	int aux=0,maxpow=0,i=0;
	int contador_numerosSortarios=0,Cont=0,Unidad=0,mayor=0;
	Entrada.open("digito.txt",ios::in);
	Salida.open("Salida.txt",ios::out);
	
	if ( Entrada.fail() && Salida.fail() )
	{
	
	cout<<"error al abrir el archivo"<<endl;
	
	}
	else
	{
		
	while ( !Entrada.eof() )
	{
		
	maxpow=0;
	
	if(Entrada.eof())
	{
		
	break;
	
	}
	
	Entrada >> N;// Numero de prueba para sortario
	
	if( N ==-1 )
	{
		
	break;
	
	}
	
	Entrada >> S;//	Numero dque considera sortario
	
	
	Cont=N;
	mayor=0;	
	for(int j = 2 ; j < 11 ; j++ )//DOnde J es la Base .
	{
	contador_numerosSortarios=0;
	i=0;
	Cont=Transformacion(N,j);
	cout<<Cont<<" En Base:"<<j<<endl;
	cin.get();
	aux=Cont;
	while(aux!=0)
	{
		
	Unidad=aux%10;	//para ir digito a digito (Se que me falta algo)
	aux=aux/10;		//dividiendo para la unidad la unidad.;
	if(Unidad == S)	//Mientras se desfragmenta el numero empieza a sumar su numeros Sortarios
	{
		
	auxpow=j;	
	contador_numerosSortarios++;
	
	if (contador_numerosSortarios>mayor)
	{
		
	mayor=contador_numerosSortarios;	
	auxSalida=Cont;
	cout<<"llevo el:"<<Cont<<endl;	
	
	}
	
		
	}
	if (contador_numerosSortarios==mayor)
	{
			
	auxSalida=Cont;	
		
	}
	
	}
	
	}
	
	Salida << auxSalida <<endl;
	
	}
	
	}
	
	Entrada.close();
	Salida.close();

}

void Problema02_Soldados()//Me falto cabeza .
{
	ifstream Entrada;
	ofstream Salida;
	int ContMatrices=0,MatrizN=0,n;
	bool band=false,MuestraMatrizN=false,Final=false;
	Entrada.open("Soldados.txt",ios::in);
	Salida.open("Salida2.txt");
	int Columnas,filas;
	
	if ( Entrada.fail() && Salida.fail() )
	{
	
	cout<<"error al abrir el archivo"<<endl;
	
	}
	else
	{
	Entrada>>ContMatrices;
	while ( ContMatrices>0 )
	{
	MatrizN++;
	MuestraMatrizN=false;
	if(Entrada.eof())
	{
		
	break;
	
	}
	Entrada>>filas;
	Entrada>>Columnas;

	int MatrizdeMuestra [filas][Columnas];
		
	
	
	
	for(int i=0;i<filas;i++)
	{
	for(int j=0;j<Columnas;j++)
	{
		Entrada >>n;
		MatrizdeMuestra[i][j]=n;
	}
	}
	
	for(int i=0;i<filas;i++)
	{
		band=false;
		for(int j=0;j<Columnas;j++)
		{
			if(MatrizdeMuestra[i][j]==1)
			{
					if(i+1<filas&&MatrizdeMuestra[i+1][j]==1)
					{
						
					band=true;//Acompañado
						
					}
					if(i-1>=0&&MatrizdeMuestra[i-1][j]==1)
					{
						
					band=true;//Acompañado
						
					}
					if(j+1<Columnas&&MatrizdeMuestra[i][j+1]==1)
					{
						
					band=true;//Acompañado
						
					}
					if(j-1>=0&&MatrizdeMuestra[i][j-1]==1)
					{
						
					band=true;//Acompañado
						
					}
					if((j-1>=0&&i-1>=0)&&MatrizdeMuestra[i-1][j-1]==1)
					{
						
					band=true;//Acompañado
						
					}
					
					if((j+1<Columnas&&i+1<filas)&&MatrizdeMuestra[i+1][j+1]==1)
					{
						
					band=true;//Acompañado
						
					}
					if((j+1<Columnas&&i-1>=0)&&MatrizdeMuestra[i-1][j+1]==1)
					{
						
					band=true;//Acompañado
						
					}
					if((j-1>=0 && i+1<filas)&&MatrizdeMuestra[i+1][j-1]==1)
					{
						
					band=true;//Acompañado
						
					}
					
					if(!band)//Solo si se perdio
					{
						if (!MuestraMatrizN)
						{
							
						Salida <<"Matriz "<<MatrizN<<endl;
						MuestraMatrizN=true;	
						
						}
						Salida<<i<<" "<<j<<endl;
						band=false;
					}
					
			
			}

		}
	}
	
	if(!MuestraMatrizN)
	{
		
	Salida <<"Matriz "<<MatrizN<<endl;	
	Salida<<"Ninguno"<<endl;
	
	}
	
	ContMatrices--;	
	
	}
	
	Salida.close();
	Entrada.close();
	
	
	}

}

	
int main(int argc, char** argv) {
	Problema01_Digito_de_la_Suerte();//AHora si funcionan¡¡¡¡
	Problema02_Soldados();
	return 0;
}








