#include <iostream>
#include <string>
#include <fstream>
#include "Cola.h"
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

using namespace std;


int main(int argc, char** argv) {
	
	Cola obj(7);
	int x;
	fstream archivo;
	string buffer;
	Cancion *auxcan;
	string auxnom;
	int auxdur;
	int band=1;
	char tecla;
	int j=0;

	cout << "BIENVENIDO!!!" << endl;
	system("PAUSE");
	system("CLS");

	
	archivo.open("mp3.txt");
	if (archivo.fail()){
		cout << "No se pudo leer el archivo" << endl;
	}
	else{
		
		
		
	for (int i=0; i<7; i++){
		
		
	
		getline(archivo, buffer, '\n');
		
		auxnom=buffer.substr(0,buffer.find(','));
		
		buffer=buffer.substr(buffer.find(',')+1);
		
		auxdur=atoi(buffer.substr(0,buffer.find(',')).c_str());
	
		auxcan = new Cancion(auxnom, auxdur);
		
		obj.agregar(*auxcan);
		

	}
	
	}
		int tiempo =obj.vector[j].duracion;
	
	
	
	
	
	while (tecla!='f'){
		


		if (kbhit()){//inicio kbhit
		
		tecla=getch();
		
		if (tecla=='r' || tecla=='R'){
			
			band=0;
			
		}
		
		if (tecla=='n' || tecla=='N'){
			
			obj.eliminar();
			tiempo=obj.vector[j].duracion;
			
		}

	   if(tecla=='p' || tecla=='P'){
	   	
	   	band=1;
	   	
	   }
	   
	   if (tecla=='s' || tecla=='S'){
	   	
	   	band=1;
	   	tiempo=obj.vector[j].duracion;
	   	
	   }
	   
	     if(tecla=='c' || tecla=='C'){
	   	
	   		if(obj.ingre<7){
	   	
	   	getline(archivo, buffer, '\n');
		
		auxnom=buffer.substr(0,buffer.find(','));
		
		buffer=buffer.substr(buffer.find(',')+1);
		
		auxdur=atoi(buffer.substr(0,buffer.find(',')).c_str());
	
		auxcan = new Cancion(auxnom, auxdur);
		
		obj.agregar(*auxcan);
	}
	else{
		cout << "No hay memoria suficiente" << endl;
		system("PAUSE");
	}
	   	
	   }
	   
	   
		}//fin kbhit	
		
		if(band==0){
		obj.imprimir();
		

		if(tiempo==0){
	
		obj.eliminar();
		
		if (obj.vector[j].duracion){
			
		tiempo = obj.vector[j].duracion;
			
		}
		else{
			cout << "Fin de reproduccion. Siguiente instruccion?" << endl;
			cin >> tecla;
		}
		
		
	
	}
		cout <<endl << "Reproduciendo: " << obj.vector[j].titulo << " " << tiempo << endl;
		
		cout<< endl << "R: Reproducir  S:Detener  P:Pausar  N:Siguiente" << endl << "C: Agregar nuevo archivo a la cola  F:Salir"<<endl;
		

		tiempo--;
		
	}
	
		if(band==1){
		obj.imprimir();
		


		cout <<endl << "Reproduciendo: " << obj.vector[j].titulo << " " << tiempo << endl;
		
		cout<< endl << "R: Reproducir  S:Detener  P:Pausar  N:Siguiente" << endl << "C: Agregar nuevo archivo a la cola  F:Salir"<<endl;

		
	}
	
			Sleep(200);
			system("CLS");
	
	
	
	}//while
	
	archivo.close();

	


	return 0;
}
