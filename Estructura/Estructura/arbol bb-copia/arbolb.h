#ifndef ARBOLB_H
#define ARBOLB_H
#include <iostream>
#include "nodo.h"
using namespace std;

class arbolB
{
	public:
		nodo *raiz;
		void add(nodo nuevo);
		void remove(nodo &eli);
		void search(nodo &eli);
		int* print(nodo *root,bool sw,int cantI,int cantD,bool side,int nivel=0);
		nodo* menor(nodo *p,nodo **padre);
		nodo* mayor(nodo *p,nodo **padre);
		int eliminar(nodo *p,nodo *padre);
		void preorden(nodo *p,int nivel);
		arbolB(){raiz=NULL;}
		int altura(nodo *p);
};

int arbolB::altura(nodo *p){
		int altI,altD;
		
		if(p->hi==p->hd)
			return 0;
		
		if(p->hi)
			altI=1+altura(p->hi);
			
		if(p->hd)
			altD=1+altura(p->hd);
		
		if(altI>altD)
			return altI;
		else
			return altD;
	}

nodo* arbolB::menor(nodo *p,nodo **padre){
	
	nodo *q=p;
	while(q->hi)
		q=q->hi;
		
	return q;
	
}

nodo* arbolB::mayor(nodo ,nodo **padre){
	nodo *q=p;
	
	while(q->hd){
		*padre=q;
		q=q->hd;
	}
	
	return q;
}

int arbolB::eliminar(nodo *p,nodo *padre){
	
	nodo *aux,*padaux;
	int r;
	
	if(p->hi==p->hd){
		if(padre!=NULL)
			if(padre->hi==p)
				padre->hi=NULL;
			else
				padre->hd=NULL;
		else
			padre==NULL;
		delete p;
		
		return 1;
	}
	
	if(p->hi && p->hd==NULL){
		padaux=p;
		aux=mayor(p->hd,&padaux);
		p->info=aux->info;
		r=eliminar(aux,padaux);
		
	}else if(p->hd && p->hi==NULL){
		padaux=p;
		aux=menor(p->hd,&padaux);
		p->info=aux->info;
		r=eliminar(aux,padaux);
		
	}else{
		
		padaux=p;
		aux=mayor(p->hd,&padaux);
		p->info=aux->info;
		r=eliminar(aux,padaux);
		
	}
	
}

void arbolB::preorden(nodo *p,int nivel){
	for(int i=0;i<nivel;i++)
				cout<<"\t\t";
				cout<<nivel<<"-"<<p->info<<endl;
			if(p->hd)
				preorden(p->hd,nivel+1);
			if(p->hi)
				preorden(p->hi,nivel+1);
}

void arbolB::add(nodo nuevo){
	nodo *recor,*nue;
	
	nue=new nodo();
	*nue=nuevo;
	
	if(!raiz){
		
		raiz=nue;
		return;
	}
	recor=raiz;
	
	alfa:
	//si nuevo es igual a recor
	if(recor->info==nue->info){
		cout<<"ya esta agregado"<<endl;
		return;
	}
	
	//si nuevo es menor a recor
	if(recor->info>nue->info){
		
		if(recor->hi){
			recor=recor->hi;
			goto alfa;
		}
		
		recor->hi=nue;
		return;
	}
	
	//si nuevo es mayor a recor
	if(recor->info<nue->info){
		
		if(recor->hd){
			recor=recor->hd;
			goto alfa;
		}
		
		recor->hd=nue;
		return;
		
	}
}

void arbolB::search(nodo &eli){
	
	nodo *recor,*nue;
	
	nue=new nodo();
	*nue=eli;
	
	if(!raiz){
		
		cout<<"arbol esta vacio"<<endl;
		return;
	}
	recor=raiz;
	
	alfa:
	//si nuevo es igual a recor
	if(recor->info==nue->info){
		cout<<"econtrado"<<endl;
		eli=*recor;
		return;
	}
	
	//si nuevo es menor a recor
	if(recor->info>nue->info){
		
		if(recor->hi){
			recor=recor->hi;
			goto alfa;
		}
		
		cout<<"no se econtró"<<endl;
		return;
	}
	
	//si nuevo es mayor a recor
	if(recor->info<nue->info){
		
		if(recor->hd){
			recor=recor->hd;
			goto alfa;
		}
		
		cout<<"no se econtró"<<endl;
		return;
		
	}
	
}

int* arbolB::print(nodo *root,bool sw,int cantI,int cantD,bool side,int nivel){

	int *tam=NULL;
	int x[2];
	
	if(sw){
		nodo *recor;
		recor = root;

		for(int i=0;i<nivel;i++)
		cout<<"\t";
		
		cout<<"("<<nivel<<")"<<recor->info<<endl;
		
		if(nivel>0)
			if(side)
				cantD++;
			else
				cantI++;
		
		if(recor->hd){
			
				
			tam=print(recor->hd,sw,cantI,cantD,side,nivel+1);
		}
		
		if(!nivel)
			side=false;
		
		if(recor->hi){

			tam=print(recor->hi,sw,cantI,cantD,side,nivel+1);
	}
			
	}else{
		
		nodo *p=root;
				if(root==NULL)
					return NULL;
				preorden(p,nivel);
	}
	if(tam==NULL){
		
	x[0]=cantD;
	x[1]=cantI;
	
	}else{
	x[0]=tam[0];
	x[1]=tam[1];
	}
	return x;
}


#endif











