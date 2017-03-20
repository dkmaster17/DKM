#include "ArchivoBin.h"



ArchivoBin::ArchivoBin(){
	
}
void ArchivoBin::Bin(){ 

arctxt.open("DatosRegistrados.txt",ios::in);
arcbin.open("DatosBin.MMG",ios::out|ios::binary);
arctxt2.open("DatosRegistradosArreglados.txt",ios::out);
srand(time(NULL));
if(arctxt.fail()||arcbin.fail()||arctxt2.fail()){
   cout<< "Estas Jodido"<<endl;
}
else{
int count=1;
while(true)
{
	
		arctxt>>aux;
		buffer.setPosicion(aux);
		getline(arctxt,arx,'-');
		buffer.setProcedencia(arx);
		
		getline(arctxt,arx,'\t');
		aux=atoi(arx.c_str());
		buffer.setCed(aux);
		
		getline(arctxt,arx,'\n');
		buffer.setNom(arx);
		
		int x= rand()%24;
		buffer.setEstado(ListaEstados[x]);
        if(arctxt.eof())break;
		arctxt2<<buffer.getPosicion()<<"\t"<<buffer.getprocedencia()<<"-"<<buffer.getCed()<<" "<<buffer.getNom()<<" "<<buffer.getEstado()<<endl;
	
		
		arcbin.write((char*)&buffer,numBytes);
	
	arctxt.clear();
	arcbin.clear();
	arctxt2.clear();
}
arctxt.close();
arcbin.close();
arctxt2.close();

}
arcbin.open("DatosBin.MMG",ios::in|ios::binary);
if(arcbin.fail()){
   cout<< "Estas Jodido"<<endl;
}
else{
arcbin.clear();
arcbin.seekg(0,ios::beg);
while(true)
{ 
	    arcbin.clear();
	    arcbin.read((char*)&buffer,numBytes);
        if(arcbin.eof())break;
}
arcbin.close();
}

}
