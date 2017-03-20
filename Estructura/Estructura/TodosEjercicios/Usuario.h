#ifndef USUARIO_H
#define USUARIO_H
#include "string.h"
#include <iostream>
using namespace std;

class Usuario
{
	private:
		long long  Targeta;
	    string Titular;
		long SaldoD;
		
		
	public:
		long long  getTargeta();
		long getSaldoD();
		string getTitular();
		void setTargeta(long long);
		void setSaldoD(long);
		void setTitular(string);
		void mostrar();
		Usuario();
		~Usuario();

};

#endif
