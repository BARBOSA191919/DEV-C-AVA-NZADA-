//Metodo Burbuja

#include<iostream>
#include<conio.h>

using namespace std;

int main (){
	int numeros []= {5,5,3,3,2,2,2,2,1,8,9,10,10,10};
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
	
	cout<<"Orden Ascendente: ";
	for (i=0;i<14;i++){
			cout<<numeros[i]<<" ";
	}
	
	cout<<"\n orden descendente:";
	for (i=13;i>=0;i--){
			cout<<numeros[i]<<" ";
		}
	getch ();
	return 0;
	
}
