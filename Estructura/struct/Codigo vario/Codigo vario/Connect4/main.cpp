#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <gl\gl.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
class Jugador {
	private:
		char *nombre;
		int juego;
	public :
		Jugador() {
			nombre=NULL;
			juego=1;
		}
		void set_Nombre(char* a) {
			nombre=a;
		}
		void set_jugando(int a) {
			juego=a;
		}
		int get_jugando() {
			return juego;
		}
		char* get_Nombre() {
			return nombre;
		}
		void Imprimir() {
			cout<<"Jugador :"<<nombre<<endl;
		}
};
class Ficha {
	private:
		int valor;
	public:
		Ficha() {
			valor=0;
		}
		int get_Valor() {
			return valor;   //Ayudan al manejo de las fichas su
		}
		void set_Valor(int a) {
			valor=a;
		}
		void Imprimir() {
			if(valor!=0)
				cout<<"| "<<valor<<" |";
			else cout<<"|"<<"   "<<"|";
		}
};
void Imprimir (Ficha** MapadeFichas,Ficha *Dondejuego) {
	system("cls");
	HANDLE hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	cout<<endl;
	cout<<endl;

	for(int j=0; j<7; j++) {

		SetConsoleTextAttribute(hConsole,7);
		cout<<"\t";
		if(Dondejuego[j].get_Valor()==1) {
			SetConsoleTextAttribute(hConsole,12);
		}
		if(Dondejuego[j].get_Valor()==2) {
			SetConsoleTextAttribute(hConsole,25);
		}
		if(Dondejuego[j].get_Valor()==0) {
			SetConsoleTextAttribute(hConsole,42);
		}
		Dondejuego[j].Imprimir();

	}
	SetConsoleTextAttribute(hConsole,7);
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<endl;

	for(int i=0; i<6; i++) {
		for(int j=0; j<7; j++) {
			SetConsoleTextAttribute(hConsole,7);
			cout<<"\t";
			if(MapadeFichas[i][j].get_Valor()==1) {
				SetConsoleTextAttribute(hConsole,12);
			}
			if(MapadeFichas[i][j].get_Valor()==2) {
				SetConsoleTextAttribute(hConsole,25);
			}
			if(MapadeFichas[i][j].get_Valor()==0) {
				SetConsoleTextAttribute(hConsole,42);
			}
			MapadeFichas[i][j].Imprimir();

		}
		SetConsoleTextAttribute(hConsole,7);
		cout<<endl;
		cout<<endl;

	}
}
int Intercambio(int a,Ficha* Dondejuego,int quien,int direccion) {

	if(direccion==1) {
		Dondejuego[a].set_Valor(0);
		Dondejuego[a+1].set_Valor(quien);
		return 1;
	}

	if(direccion==2) {
		Dondejuego[a].set_Valor(0);
		Dondejuego[a-1].set_Valor(quien);
		return -1;
	}

}
int play(Ficha **MapadeFichas,int pos,int quienjuega) {
	int count=0;
	for(int i=0; i<7; i++) {
		if(i+1<6) {
			if (MapadeFichas[i+1][pos].get_Valor()==0) {
				count++;
			} else break;

		}
	}
	if(MapadeFichas[count][pos].get_Valor()==0) {
		MapadeFichas[count][pos].set_Valor(quienjuega);
	}
	return count;
}
bool validacionVictoria(Ficha** MapadeFichas,int i,int j,int quienjuega) {
	int n=i,m=j,r=j,p=i;
	int ConVer,ConHor,ConDigDer,ConDigIzq;

	cout<< i<<" " << j <<endl;// 4, 3
	if(MapadeFichas[n][m].get_Valor()==quienjuega) 
	{
		ConVer=ConHor=ConDigIzq=ConDigDer=1;
		for(int k=0; k<3; k++)
		 {
			if(n+1<6&&MapadeFichas[n+1][j].get_Valor()==quienjuega) {
				ConVer++;
			}
			if(m+1<7&&MapadeFichas[i][m+1].get_Valor()==quienjuega) {
				ConHor++;
			}
			if(r-1>=0&&MapadeFichas[i][r-1].get_Valor()==quienjuega) {
				ConHor++;
			}
			if((n+1<6&&m+1<7)  &&MapadeFichas[n+1][m+1].get_Valor()==quienjuega) {
				ConDigDer++;
			}
			if((n+1<6&&r-1>=0) &&MapadeFichas[n+1][r-1].get_Valor()==quienjuega) {
				ConDigIzq++;
			}
			if((p-1>=0&&m+1<7) &&MapadeFichas[p-1][m+1].get_Valor()==quienjuega) {
				ConDigIzq++;
			}
			if((p-1>=0&&r-1>=0)&&MapadeFichas[p-1][r-1].get_Valor()==quienjuega) {
				ConDigDer++;
			}
			n++;
			m++;
			r--;
			p--;
		}
	}
	if(ConVer==4||ConHor==4||ConDigDer==4||ConDigIzq==4)return true;

	return false;
}
void reinicio(Ficha**MapadeFichas,Ficha* Dondejuego,int quienjuega){

	for(int i=0; i<6; i++) {
			Dondejuego[i].set_Valor(0);
		for(int j=0; j<7; j++) {

		MapadeFichas[i][j].set_Valor(0);

		}
	}
		Dondejuego[0].set_Valor(quienjuega);
}
void Movimientos(Ficha** MapadeFichas,Ficha *Dondejuego) {
	char Move='a';
	bool win=false;
	int i=0,j=0,pos;
	int cant;
	Jugador quienjuega;
	Dondejuego[i].set_Valor(quienjuega.get_jugando());
	Imprimir(MapadeFichas,Dondejuego);

	while(win!=true) {

		if(quienjuega.get_jugando()==1)
		{
			Move=getche();
			system("cls");

			 if(Move==82||Move==114)
		   {
		   	reinicio(MapadeFichas,Dondejuego,quienjuega.get_jugando());
		    win=false;
		    i=0;
		   	j=0;
		   }
            if(Move==83||Move==115)
		   {
		   	break;
		   }
			if(Move==77&&i<6) {
					if(i<6)
					{
					i=i+Intercambio(i,Dondejuego,quienjuega.get_jugando(),1);
					}
			}
			if(Move==75&&i>=0) {
				if(i-1>=0) {
					i=i+Intercambio(i,Dondejuego,quienjuega.get_jugando(),2);
				}
			}
			if(Move==' ') {
				    j=play(MapadeFichas,i, quienjuega.get_jugando());
					if(j!=0) {
					cant++;
					if(cant>3) win=validacionVictoria(MapadeFichas,j,i,quienjuega.get_jugando());
					quienjuega.set_jugando(2);
					Dondejuego[i].set_Valor(quienjuega.get_jugando());
				}
			}

		Imprimir(MapadeFichas,Dondejuego);

		} else {

			Move=getche();
			system("cls");

			 if(Move==82||Move==114)
		   {
		   	reinicio(MapadeFichas,Dondejuego,quienjuega.get_jugando());
		   	i=0;
		   	j=0;
		    win=false;
		   }
            if(Move==83||Move==115)
		   {
		   	break;
		   }
			if(Move==77&&i<7) {
				if(i<7) {
					i=i+Intercambio(i,Dondejuego,quienjuega.get_jugando(),1);
				}
			}
			if(Move==75&&i>=0) {
				if(i-1>=0) {
					i=i+Intercambio(i,Dondejuego,quienjuega.get_jugando(),2);
				}
			}

			if(Move==' ') {
				j=play(MapadeFichas,i, quienjuega.get_jugando());
				cant++;
				if(cant>3) win=validacionVictoria(MapadeFichas,j,i,quienjuega.get_jugando());
				quienjuega.set_jugando(1);
				Dondejuego[i].set_Valor(quienjuega.get_jugando());
			}
		Imprimir(MapadeFichas,Dondejuego);
		}

	}

}
	void JugadorVrsPc()
	{

	}
void JugadorVrsJugador()
{
	Ficha **MapadeFichas= new Ficha*[6];
	Ficha *Dondejuego= new Ficha[7];

	for(int i=0; i<7; i++) {
		MapadeFichas[i]=new Ficha[7];
	}
	Movimientos(MapadeFichas,Dondejuego);

	cout<<endl;
	cout<<endl;
	cout<<endl;
}
void Creditos()
{

}
void Menu()
{
	char resp;
	while(resp!='4')
	{
		cout<<endl;
		cout<<endl;
		cout<<endl;
		cout<<endl;

		cout<<"\t\t\t 1-->Jugador Vrs Pc."<<endl;
		cout<<"jooodaseee"<<endl;

		cout<<endl;
		cout<<endl;
		cout<<"\t\t   2-->Jugador Vrs Jugador."<<endl;

		cout<<endl;
		cout<<endl;
		cout<<"\t\t\t 3-->Creditos."<<endl;

		cout<<endl;
		cout<<endl;
		cout<<"\t\t\t 4-->Salir."<<endl;

		cout<<endl;
		cout<<endl;
		cin>> resp;
		cout<<endl;
		cout<<endl;

		switch (resp)
		{
			case '1':
			JugadorVrsPc();
			break;

			case '2':
			JugadorVrsJugador();
			break;

			case '3':
			Creditos();
			break;

			case '4':
			break;
		}
	}
}

int main(int argc, char** argv) {

	Menu();
	return 0;

}
