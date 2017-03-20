#include <iostream>
#include <string.h>
#include "Listas.h"
#include <fstream>
#include <conio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Hecho por Jesus Olmedo C.I 24.781.434
// 	y Gustavo Florez C.I 25.837.802


int main(int argc, char** argv) {
	
	cadena buff; //Buffer de la cadena
	
	int palindromo = 1; //bandera palindromos
	int contpali=0; //contador de palindromos
	
	int i;
	int j;
	
	ListaDown<cadena> lista;  //Declarando la lista de cadenas
	
	fstream arc;
	arc.open("diccionario.txt",ios::in);  //Apertura archivo en modo de lectura
	if(arc.fail())
	{
		cout<<"Error apertura archivo";
	}
	else
	{
		cout<<"Loading...";
		while(!arc.eof())
		{
			arc.getline(buff.cad,100,'\n');
			lista.agregar(buff);  //Guardando las palabras del documento de texto en la lista alfabeticamente
		}	
	}
	arc.close();
	/////////////MENU////////////////
	system("cls");
	cout<<"Bienvenido"<<endl;
	cout<<"Introduzca la palabra palindromo a buscar: ";
	cin.getline(buff.cad,100);
	
    cadena trozo;  //Variable donde se guardara palabra por palabra

    trozo.ced = strtok( buff.cad," ");  // Seperando por espacios

    while( trozo.ced != NULL ) 
	{
		palindromo=1;
		strcpy(trozo.cad,trozo.ced); 
		
		lista.Buscar(trozo);  //Buscando en la lista si existe la palabra
		
        //Revisando si es palindromo o no
        
        j=strlen(trozo.cad)-1;
    	for(i=0; i<strlen(trozo.cad)/2; i++, j--) {
        if (*(trozo.cad+i)!=*(trozo.cad+j)) {
            palindromo = 0;
        }
    }
    
    if (palindromo==1){contpali++;}
    trozo.ced = strtok(NULL, " ");
	}

    
    
	cout<<endl<<endl<<"Cantidad de palindromos en la frase: "<<contpali;  //imprimiendo palindromo
	
	
	
	getch();
	exit(0);
}
