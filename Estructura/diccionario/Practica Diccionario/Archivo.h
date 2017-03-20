#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;
//Alumno Jesus Olmedo C.I 24.781.434
template <class T>
class Archivo
{
      fstream pf;
      char nom[40];
      T buffer;
      int lon, N;
  public:
      Archivo( )                               {                 }   
      Archivo(char *n)                         { strcpy(nom,n);  }
      void Abrir( const std::_Ios_Openmode &t ){ pf.open(nom,t); }
      void Longi( )             { lon= sizeof(T);                }
      void Leer    ( T &b )     { pf.read ((char*)&b,sizeof(T)); }
      void Escribir( T &b )     { pf.write((char*)&b,sizeof(T)); }
      void Cerrar()             { pf.close();                    } 
      bool EsFin()              { return pf.eof();               } 
      bool Falla()              { return pf.fail();              }
      void Limpiar()            { pf.clear();                    }
      void Posicionar( int p )  { pf.seekg(p*lon, ios::beg );    }
      void Tamano();
      void Imprimir(); 
      void Ordenar(); 
      T Buscar_Sec_materias     ( T &bus, int pos=0, int Max=99999999 );
      void Buscar_Sec_docentes( T &bus, int pos=0, int Max=99999999 );
      int Buscar_Sec_maestros( T &bus, int pos=0, int Max=99999999 );
      bool Buscar_Binario ( T &bus );  
};

template <class T>
void Archivo<T>::Tamano() 
{ 
     Longi(); 
     pf.seekg(0,ios::end); 
     pf.clear(); 
     N= pf.tellg()/lon; 
}

template <class T>
void Archivo<T>::Imprimir()
{
    Limpiar();
    Posicionar(0);  
    while ( true )
    { 
      Leer(buffer);  
      if ( EsFin() ) break;    
      buffer.imprime();
    }
    cout<<endl;
}

template <class T>
T Archivo<T>::Buscar_Sec_materias( T &bus, int pos, int Max )
{
     int i;
     int cont=0;
     float promedio=0.0f;
     int condiciones=0;
     Limpiar();
     Posicionar(pos);
     while ( i<=Max)
     { 
       Leer(buffer);  
       if ( EsFin() ) break;    
       if ( bus.get_clave()==buffer.get_clave() )
       {
			promedio=promedio+buffer.get_indice();
			if(buffer.get_condicion()==0)
			{
				condiciones++;
			}
       	    cont++;
            bus= buffer;
       }
	   else i++;
     } // fin while
	 promedio=promedio/cont;
	 condiciones=(condiciones*100)/cont;
	 T devolver(condiciones,cont,' ',promedio);
     return devolver;        
}
template <class T>
int Archivo<T>::Buscar_Sec_maestros( T &bus, int pos, int Max )
{
     int i;
     int cont=0;
     int cedula=0;
     Limpiar();
     Posicionar(pos);
     while ( i<=Max)
     { 
       Leer(buffer);  
       if ( EsFin() ) break;    
       if ( bus.get_clave()==buffer.get_clave() )
       {
       	    cont++;
            bus= buffer;
       }
	   else i++;
     } // fin while
     
     return cont;        
}
template <class T>
void Archivo<T>::Buscar_Sec_docentes( T &bus, int pos, int Max )
{
     int i;
     int cont=0;
     float promedio=0.0f;
     int condiciones=0;
     Limpiar();
     Posicionar(pos);
     while ( i<=Max)
     { 
       Leer(buffer);  
       if ( EsFin() ) break;    
       if ( bus.get_clave()==buffer.get_clave() )
       {
       	    buffer.imprime();
            bus= buffer;
       }
	   else i++;
     } // fin while
     return cont;        
}

template <class T>
bool Archivo<T>::Buscar_Binario( T &bus )
{
     bool enc=false;
     int li=0, ls=N-1, pm;
     Limpiar();
     while ( !enc && li<=ls )
     {
           pm= (li+ls)/2;
           Posicionar(pm);
           Leer(buffer);
           if ( bus.get_clave()==buffer.get_clave() )
           {
                enc=true;
                bus=buffer;
           }
           else if ( bus.get_clave()< buffer.get_clave() )
                ls= pm-1;
           else
                li= pm+1;
     }
     return enc;
}

template <class T>
void Archivo<T>::Ordenar()
{
     T aux, ini;
     int i, j, pmen;  
     Tamano();
     for ( i=0; i<N-1; i++ )
     {
        Posicionar(i);
        Leer (aux); ini= aux;
        pmen=i;
        for (j=i+1; j<N; j++)
        {
            Posicionar(j);
            Leer(buffer);
            if ( buffer.get_clave()< aux.get_clave() )
            {
                 aux= buffer;
                 pmen= j;
            }
        } // fin for j
        if ( i!=pmen )
        {
             Posicionar(i);
             Escribir(aux);
             Posicionar(pmen);
             Escribir(ini);
        } 
     }// fin for i 
}
