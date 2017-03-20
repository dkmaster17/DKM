#include <iostream>
#include "ArchivoBin.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void OrdenamientoCedula();
void OrdenamientoEstado();

int main(int argc, char** argv) {
	int resp=99;
	ArchivoBin Obj;
	
	Obj.Bin();
	
	cout<<"Bienvendo a la super duper mega maxi hiper deca deci ultra maxima aplicacion de ordenamiento del puto mundo"<<endl;
	while(resp!=0)
	{
  cout<<"1. Ordenar Cedula descendente."<<endl;
  cout<<"2. Ordenar nombre alfabeticamente."<<endl;
  cout<<"3. Ordenar Estado alfameticamente."<<endl;
  cout<<"0. Salir."<<endl;
  cin>>resp;
  
  switch(resp)
  {
  	  case 1:
  	  OrdenamientoCedula();	
	  break;
	  case 2: 
	  OrdenamientoEstado();
	  break;
	  case 3:
	break; 
  }
	}
	return 0;


}
void OrdenamientoCedula()
{
	int band=0;
	Registrado buffer, buffer2, buffer3;
	int numBytes=sizeof(Registrado);
	fstream arcbin,arcbin2,arcbin3,arcbin4;
	arcbin.open ("DatosBin.MMG",ios::in|ios::binary);
	arcbin2.open("DatosBinAux1.MMG",ios::out|ios::binary);
	arcbin3.open("DatosBinAux2.MMG",ios::out|ios::binary);
	if(arcbin.fail()||arcbin2.fail()||arcbin3.fail()||arcbin4.fail())
	{
	cout<<"error al abrir los archivos"	<<endl;
	}
	else
	{
		while (!arcbin.eof())
		{
			arcbin.read((char*)&buffer,numBytes);
			if (band==1)
			{
			arcbin3.write((char*)&buffer,numBytes);	
			band--;
			}
			else
			{
			arcbin2.write((char*)&buffer,numBytes);
			band++;
			}
		}
		band=0;
		
	arcbin.close();
	arcbin2.close();
	arcbin3.close();
    }
  		arcbin2.clear();
		arcbin3.clear();
	arcbin2.open("DatosBinAux1.MMG",ios::in|ios::binary);
	arcbin3.open("DatosBinAux2.MMG",ios::in|ios::binary);
	arcbin4.open("DatosBinAux3.MMG",ios::out|ios::binary);

	if(arcbin2.fail()||arcbin3.fail()||arcbin4.fail())
	{
	cout<<"error al abrir los archivos"	<<endl;
	}
	else
	  {
		while (!arcbin2.eof()||!arcbin3.eof())
		{
		   if(band==0)
		   {
            arcbin2.read((char*)&buffer2,numBytes);	
			arcbin3.read((char*)&buffer3,numBytes);
			band=1;
		   }
		   
           if(buffer3.getCed()>buffer2.getCed())
		   {
		  	arcbin4.write((char*)&buffer3,numBytes);
  		    arcbin3.read((char*)&buffer3,numBytes);
		   }
		   else
		   {
		  	arcbin4.write((char*)&buffer2,numBytes);
          	arcbin2.read((char*)&buffer,numBytes);
		   }
		  
		   if(arcbin2.eof()||arcbin3.eof())
           {
           	break;
           }
           
        }
	arcbin2.close();
	arcbin3.close();
	arcbin4.close();
	}
	
	arcbin4.open("DatosBinAux3.MMG",ios::in|ios::binary);

	if(arcbin4.fail())
	{
	cout<<"error al abrir los archivos"	<<endl;
	}
	else
	  {
		while (!arcbin4.eof())
		 {
		 	arcbin4.read((char*)&buffer,numBytes);
		 	 if(arcbin4.eof())
           {
           	break;
           }
 	        
		   	cout<<buffer.getCed()<<endl;		
         } 
      }
   arcbin4.close();
   }
   

void OrdenamientoEstado()
{
	int band=0;
	Registrado buffer, buffer2, buffer3;
	int numBytes=sizeof(Registrado);
	fstream arcbin,arcbin2,arcbin3,arcbin4;
	arcbin.open ("DatosBin.MMG",ios::in|ios::binary);
	arcbin2.open("DatosBinAux1.MMG",ios::out|ios::binary);
	arcbin3.open("DatosBinAux2.MMG",ios::out|ios::binary);
	if(arcbin.fail()||arcbin2.fail()||arcbin3.fail()||arcbin4.fail())
	{
	cout<<"error al abrir los archivos"	<<endl;
	}
	else
	{
		while (!arcbin.eof())
		{
			arcbin.read((char*)&buffer,numBytes);
			if (band==1)
			{
			arcbin3.write((char*)&buffer,numBytes);	
			band--;
			}
			else
			{
			arcbin2.write((char*)&buffer,numBytes);
			band++;
			}
		}
		band=0;
		
	arcbin.close();
	arcbin2.close();
	arcbin3.close();
    }
  		arcbin2.clear();
		arcbin3.clear();
	arcbin2.open("DatosBinAux1.MMG",ios::in|ios::binary);
	arcbin3.open("DatosBinAux2.MMG",ios::in|ios::binary);
	arcbin4.open("DatosBinAux3.MMG",ios::out|ios::binary);

	if(arcbin2.fail()||arcbin3.fail()||arcbin4.fail())
	{
	cout<<"error al abrir los archivos"	<<endl;
	}
	else
	  {
		while (!arcbin2.eof()||!arcbin3.eof())
		{
		   if(band==0)
		   {
            arcbin2.read((char*)&buffer2,numBytes);	
			arcbin3.read((char*)&buffer3,numBytes);
			band=1;
		   }
		   
           if(buffer3.getEstado()>=buffer2.getEstado())
		   {
		  	arcbin4.write((char*)&buffer3,numBytes);
  		    arcbin3.read((char*)&buffer3,numBytes);
		   }
		   else
		   {
		  	arcbin4.write((char*)&buffer2,numBytes);
          	arcbin2.read((char*)&buffer2,numBytes);
		   }
		  
		   if(arcbin2.eof()||arcbin3.eof())
           {
           	break;
           }
           
        }
	arcbin2.close();
	arcbin3.close();
	arcbin4.close();
	}
	
	arcbin4.open("DatosBinAux3.MMG",ios::in|ios::binary);

	if(arcbin4.fail())
	{
	cout<<"error al abrir los archivos"	<<endl;
	}
	else
	  {
		while (!arcbin4.eof())
		 {
		 	arcbin4.read((char*)&buffer,numBytes);
		 	 if(arcbin4.eof())
           {
           	break;
           }
 	        
		   	cout<<buffer.getEstado()<<endl;		
         } 
      }
   arcbin4.close();
   
}
	/*
	void interCambio(typeid &A,typeid &B)
	{
	typeid Aux=A;
	A=B:
	B=Aux;
	}Template //Cualquiertipo de dato 
	template <class T>
	*/
