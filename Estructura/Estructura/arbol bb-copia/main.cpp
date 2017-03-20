#include <iostream>
using namespace std;

#include "nodo.h"
#include "arbolb.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	
	arbolB arbol_1,arbol_2;
	nodo nuevo;
	int alt1,alt2,*cant1,*cant2,canI=0,canD=0,x1,x2,y1,y2;
	int cont=1;
	
	
	alfa:
		cin>>nuevo.info;
		arbol_1.add(nuevo);
		
		cin>>nuevo.info;
		arbol_2.add(nuevo);
		
		if(cont==4)
			 goto beta;	
		cont++;
	goto alfa;
	
	beta:
		
		alt1=arbol_1.altura(arbol_1.raiz);
		alt2=arbol_1.altura(arbol_2.raiz);
		
	cant1=arbol_1.print(arbol_1.raiz,true,canI,canD,true);
	x1=cant1[0];
	y1=cant1[1];
	
	cant2=arbol_2.print(arbol_2.raiz,true,canI,canD,true);
	x2=cant2[0];
	y2=cant2[1];
	
	if(alt1==alt2)
		if(x1==x2 && y1==y2)
			cout<<"son equivalentes";
		else
			cout<<"no son equivalentes porque no tienen la misma cantidad de nodos:\narbol_1 nodos derechos:"<<x1<<" nodos izquierdos:"<<y1<<"\narbol_1 nodos derechos:"<<x2<<" nodos izqueirdos:"<<y2;
	else
		cout<<"no son equivalentes porque no tienen la misma altura:\narbol 1: "<<alt1<<"\narbol 2: "<<alt2;
	
	return 0;
}
