/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Parciales;
  // Only Style K&R
import java.util.Random;

 

/**
 *
 * @author DK
 */
public class MainP {
    
    void Problema1()// Cercania de pares
{
    int vec[]={1,5,2,4,7,30,9,8},Winners[]={0,0};
    int Resultado, Number1 , Number2,Mayor=999;
        
    for ( int i = 1; i < vec.length; i++ ) {
        
        Number1=vec[i-1];
        Number2=vec[i];
        Resultado=Number1-Number2;
        if ( Resultado<0 ) {
        Resultado=Resultado*-1;   
        }
        if ( Resultado<Mayor ) {
            Mayor=Resultado;
            Winners[0]=Number1;
            Winners[1]=Number2;
        }  
    }
    System.out.println("Parejas con menor distancia:"+Winners[0]+","+Winners[1]);

}
    void Problema2()//El escape de la nave
{
   int T,K=4,W=3,H=3;//T numero de pruebas;K tipos de naves;W ancho de la matriz;H altura de la matriz. 
   int der,iz,top,bot,I=0,J=0,valor=0;
   der=iz=top=bot=0;
   Random M= new Random();
   T=M.nextInt(100)+2;
   //K=M.nextInt(25)+1;Para este caso usareos un valores fijo;
   //W=M.nextInt(1000);
   //H=M.nextInt(1000);
   
    String Lineas_K[]={"A 7",
                       "B 5",
                       "C 4",
                       "D 2",
                       "F 3"};
   
    String MatrizLetras[][]= new String[][]{{"A","B","C"},{"D","E","C"},{"F","C","D"}};
    
    
    for ( int i = 0; i < W; i++ ) {
    for ( int j = 0; j < H; j++ ) {
        
        System.out.print(MatrizLetras[i][j]);
        
        if ( MatrizLetras[i][j]=="E" ) {
            I=i;
            J=j;
            break;
                
            }
 
        }
        System.out.println("");
    }
    for (int i = I; i < W; i++) {
        
            for (int k = 0; k < Lineas_K.length; k++) {
                String C[]=Lineas_K[k].split(" ");
                valor= Integer.parseInt(C[1]);
                
                if ( i+1<W ) {
                   if ( MatrizLetras[i+1][J].equals(C[0])) {
                   bot+=valor;
                   break; 
                   }
                }
                
            }       
    }
    
     for (int i = I; i > 0; i--) {
        
            for (int k = 0; k < Lineas_K.length; k++) {
                String C[]=Lineas_K[k].split(" ");
                valor= Integer.parseInt(C[1]);
                
                if ( i-1>-1 ) {
                   if ( MatrizLetras[i-1][J].equals(C[0])) {
                   top+=valor;
                   break; 
                   }
                }
                
            }    
    }
    for (int j = J; j > 0; j--) {
        
            for (int k = 0; k < Lineas_K.length; k++) {
                String C[]=Lineas_K[k].split(" ");
                valor= Integer.parseInt(C[1]);
                
                if ( j-1>-1 ) {
                    if ( MatrizLetras[I][j-1].equals(C[0])) {
                       iz+=valor;
                       break;  
                    }
                }
                
            }    
    }
    for (int j = J; j < H; j++) {
        
            for (int k = 0; k < Lineas_K.length; k++) {
                String C[]=Lineas_K[k].split(" ");
                valor= Integer.parseInt(C[1]);
                
                if ( j+1<H ) {
                   if ( MatrizLetras[I][j+1].equals(C[0])) {
                   der+=valor;
                   break; 
                }
                }
                
            }    
    }
    
       System.out.println(top+"," + bot+","+ der +","+ iz);
       
       if ( top < bot && top < der && top < iz ) {
           System.out.println(top);
       }
       
       else if ( iz < top && iz < der && iz < bot ) {
           System.out.println(iz);
       }
       
       else if ( bot < top && bot < iz && bot < der ) {
           System.out.println(bot);
       }else    System.out.println(der);

    }
    



    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       MainP n= new MainP();
       n.Problema1();
       n.Problema2();
       
    }
  
}
