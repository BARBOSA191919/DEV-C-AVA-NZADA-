#include<iostream>
#include<conio.h>


// Santiago José Barbosa  2021220802
//Michael Steven Barrios 20201188004
using namespace std;
int main (){
	//agregamos las variables
	int salir=0;
	int n=0;
	int numeros [15] ={1,2,8,8,8,8,5,4,3,4,5,6,4,7,8};
	int repeticiones = 0;
	int i,j,aux;	
	
	//Algoritmo del metodo burbuja
	for(i=0;i<14;i++){
		for(j=0;j<14;j++){
			if(numeros[j]>numeros[j+1]){
				aux = numeros [j];
				numeros [j]=numeros [j+1];
				numeros [j+1] = aux;
								
			}
		}
	}

	cout<<"Nuneros Ordenados: " <<endl;
	for (i=0;i<14;i++){
	cout<<numeros[i]<<" " <<endl;
	}
	 //Pasamos por cada casilla comparando con las demas.
    for ( i = 0; i < sizeof ( numeros ) / sizeof ( numeros[0] ); i++ ) {
        //Pasamos por alto comparaciones de casillas con un valor -1 ya que quiere decir que -1 es repetido y ya ha sido marcado.
        if ( numeros[i] != -1 ) {
            //comparamos cada casilla con todas las demas...
            for ( i = 0; i < sizeof ( numeros ) / sizeof ( numeros[0] ); i++ ) {
                //...pero solo si no se trata de la misma casilla, ya que sabemos que se trata del mismo numero y no se puede comparar un numero con el mismo 
                if ( i != -1 ){
                    //Nos quedamos con el primer numero que no repita, los demas  que se repiten se modifican a -1 y se añaden +1 al contador.   
                    if ( numeros[i] == numeros[i] ){
                        numeros[j] = -1;
                        repeticiones++;
                      
                    }
                }
            }
        }
        
    }	
    cout<<"los numeros que no se repiten son: "<<numeros [-1] <<" "<<endl;
   
    getchar();
    return 0;
}