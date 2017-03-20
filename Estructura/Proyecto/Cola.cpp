#include "Cola.h"

Cola::Cola()
{
	tam=-1;
	ingre=0;
	ini=0;
	vector=NULL;
}

Cola::Cola(int t){

	tam=t;	
	vector= new Cancion[tam];
	ingre=0;
	ini=0;
	if(!vector){
		cout<<"no se le asignó memoria a la cola"<<endl;
	}
	
}
		
void Cola::set_size(int t){
	if(!vector){
		tam=t;
	
		vector= new Cancion[tam];
		ingre=0;
		ini=0;
	}else{
		cout<<"ya le fue asignado tamaño a la cola"<<endl;
	}
}

int Cola::agregar(Cancion elemento){
	
	if(!vector || ingre>=tam){
		
		return -1;
	}
	
		vector[ingre]=elemento;
		ingre++;

	
	return 1;
	
}

int Cola::eliminar(){
	

	
	
		if(!vector || ingre==0){
		
		return -1;
		}
		
		else
	
		for(int i=0;i<ingre-1;i++){
		vector[i]=vector[i+1];
	}
	
		ingre--;
    
	
	
	return 1;
	
}


void Cola::imprimir(){

	int cont=0;
	do{
		
		cout<<vector[ini].titulo<< "\t" << vector[ini].duracion <<endl;
	
		ini=(ini+1)%tam;
		cont++;
		
	}while(cont<ingre);
	
	ini=0;

	
	
}
