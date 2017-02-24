/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Parciales;

/**
 *
 * @author Vit
 */
public class MainP {
    
    
    
    
    void Problema1()
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
        if (Resultado<Mayor) {
            Mayor=Resultado;
            Winners[0]=Number1;
            Winners[1]=Number2;
        }  
    }
    System.out.println("Parejas con menor distancia:"+Winners[0]+","+Winners[1]);

}

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
       MainP n= new MainP();
       n.Problema1();
    }
    // Only Style K&R 

}
