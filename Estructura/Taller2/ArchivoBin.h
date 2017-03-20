#ifndef ARCHIVOBIN_H
#define ARCHIVOBIN_H
#include  <fstream>
#include "Registrado.h"
#include <iostream>
#include <time.h>
using namespace std;
class ArchivoBin
{

    fstream arctxt,arcbin,arctxt2; // stream para manipular data  (i/o)
    Registrado buffer; // guarda un solo Registrado (por ejemplo para tener al ultimo consultado, etc)
    int numBytes= sizeof(Registrado); // LON
    string ListaEstados[24]={"AMAZONAS","ANZOATEGUI","APURE","ARAGUA","BARINAS","BOLIVAR"
	                        ,"CARABOBO","COJEDES","DELTA AMACURO","FALCON","DISTRITO CAPITAL"
				     		 ,"GUARICO","LARA","MERIDA","MIRANDA","MONAGAS","NUEVA ESPARTA"
					 			,"PORTUGUESA","SUCRE","TACHIRA","TRUJILLO","VARGAS","YARACUY","ZULIA"};
    int aux;
    string arx;
public:
    
    void Bin();    
    ArchivoBin();
    
};
#endif
