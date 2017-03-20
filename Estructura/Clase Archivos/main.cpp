#include <iostream>
#include "Alumno.h"
#include "Archivo_bin.h"
#include "Manejo.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	Alumno v[]={Alumno(20,"Gustavito"),Alumno(23,"Cubito"),Alumno(28,"Olmedito"),Alumno(25,"Luisito")};
	Archivo_bin obj("Datos.dat");
	obj.abrir(ios::out | ios::binary);
	obj.longitud();
	for(int i=0; i<4; i++)
		obj.escribir(v[i]);
	obj.cerrar();
	obj.abrir(ios::in | ios::binary);
	obj.imprimir();
	obj.cerrar();
	system("PAUSE");
	
	// Búsqueda
	system("cls");
	char resp;		
	cout << "Desea buscar algun alumno? S/N";
	cin >> resp;
	while(resp == 's' || resp == 'S'){
		system("cls");
		int cedu;
		cout << "Dar una cedula mmgvo  ";
		cin >> cedu;
		Alumno objalu(cedu, "");
		Archivo_bin obj("Datos.dat");
		obj.abrir(ios::in | ios::binary);
		
		if(obj.falla()){
			cout << "Error mmgvo" << endl;
			exit(0);
		}
		
		obj.longitud();
		
		if(obj.buscar_sec(objalu)){
			cout << "\n\nFue localizado en el archvo mmgvo" << endl;
			objalu.imprimir(); 
		}else
			cout << "\n\nNo info pa'" << endl;
		
		cout << "\n\n\nBuscar otro mmgvo? S/N" << endl;
		cin >> resp;
		
	}
	
	return 0;
}

