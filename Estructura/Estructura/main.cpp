#include <iostream>
#include <string.h>
#include <stdlib.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;
class Alumno
{
unsigned int ced ;
char Nom[30];
public:
	Alumno(){ced=0;}
	Alumno(char* n,int c){ced=c;strcpy(Nom,n);}
    int get_Cedula(){return ced;}
    char*get_Nombre(){return Nom;}
    void set_cedula(char* n){ced=atoi(n);}
    void set_Nombre(char* n){strcpy(Nom,n);}
    void imprimir(){cout <<Nom<<" "<<ced<< endl;}
};
class Materia
{
	unsigned int cod ;
	char titulo[80],uc;
	
	public:
	Materia(){cod=0;}
	Materia(int c,char* t, char u){cod=c;strcpy(titulo,t);uc=u;}
    int get_Codigo(){return cod;}
    char*get_titulo(){return titulo;}
    char get_Uc(){return uc;}
    void set_Codigo(char* n){cod=atoi(n);}
    void set_Nombre(char* n){strcpy(titulo,n);}
    void set_Uc(char n){uc=n;}
    void imprimir(){cout<<cod<<" "<<titulo<<" "<<uc<<endl;}
};
class Inscritos
{
	unsigned int Codigo;
	unsigned int Cedula;
	public:
	Inscritos(){Codigo=0;Cedula=0;}
	Inscritos(int Cod, int Ced){Codigo=Cod;Cedula=Ced;}
	int get_Clave(int tipo=0){if(tipo!=0){return Codigo;} else {return Cedula;}}
	void set_Codigo(int n){Codigo=n;}
	void set_Cedula(int n){Cedula=n;}
	void imprimir(){cout<<Codigo<<" "<<Cedula<<endl;}
};
int main(int argc, char** argv) {
	
	
	
	return 0;
}
