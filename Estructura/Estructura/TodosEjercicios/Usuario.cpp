#include "Usuario.h"





Usuario::Usuario()
{
	
}
Usuario::~Usuario()
{

}
void Usuario::setTitular(string titular){
Titular=titular;
}
void Usuario::setSaldoD(long Saldo)
{
	
	SaldoD=Saldo;
}
void Usuario::setTargeta(long long targe)
{
	Targeta=targe;
}

string Usuario::getTitular()
{
return Titular;
}
long long Usuario::getTargeta(){
return Targeta;
}
long  Usuario::getSaldoD()
{
return SaldoD;	
}
void Usuario::mostrar(){
	
	cout<< Titular <<" "<<Targeta<<" "<< SaldoD <<endl;
}
