#include "Archivo_bin.h"

void Archivo_bin::imprimir(){
	posicionar(0);
	while(true){
		leer(buffer);
		if(es_fin())break;
		buffer.imprimir();
	}
}

bool Archivo_bin::buscar_sec(Alumno &clave){
	bool enc = false;
	posicionar(0);
	while(!enc){
		leer(buffer);
		if(es_fin())break;
		if(buffer.getCedula()==clave.getCedula()){
			enc = true;
			clave = buffer;
		}
	}
	return enc;
}

