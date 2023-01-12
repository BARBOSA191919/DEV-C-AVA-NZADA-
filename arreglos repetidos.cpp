#include<iostream>
#include<conio.h>

using namespace std;
int main (){
	int salir=0;
	int n=0;
	int numeros [15]={1,2,1,2,2,2,3,4,3,4,5,6,6,7,8};
	int repeticiones = 0;
	 string nume = "5,7";
	 string num2 = "1,1,2,2,2,2,3,3,4,4,6,6";
	int i,j,aux,z;	
	
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
            for ( z = 0; z < sizeof ( numeros ) / sizeof ( numeros[0] ); z++ ) {
                //...pero solo si no se trata de la misma casilla, ya que sabemos que se trata del mismo numero y no se puede comparar un numero con el mismo 
                if ( i != z ){
                    //Nos quedamos con el primer numero que no repita, los demas  que se repiten se modifican a -1 y se añaden +1 al contador.   
                    if ( numeros[i] == numeros[z] ){
                        numeros[z] = -1;
                        repeticiones++;
            
            
                    }
                }
            }
        }
        
    }
	
    cout<<" las veces que se repiten son: "<< repeticiones ;
    
    cout<<" Y los numeros son: "<< num2<<endl;
  
    cout<<" los que no se repiten son : el " << nume<<endl;
   
    getchar();
    return 0;
}






