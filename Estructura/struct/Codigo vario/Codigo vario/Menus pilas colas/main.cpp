#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	return 0;
}
template<class T>
class pila
{
private :
public  :
pila();
void MenuBasePilas();
}

template <class T>
class cola
{
cola();
void MenuBaseColas();	
}

template <class T>
pila <T>::MenuBasePilas()
{
	int r=-1;
while(r!=0)
{
cout<<"Ingrese la accion que desea Efectuar"<<endl;
cout<<"1.Agregar"<<endl;
cout<<"2.Eliminar"<<endl;
cout<<"0.Volver"<<endl;
cin>>r;
switch(r)
 case 1:
 Agregar();
  break;
case 2:
 Eliminar();
 break;
 default;	
}		
}

