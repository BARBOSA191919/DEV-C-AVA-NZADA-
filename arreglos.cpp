#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>

using namespace std;

int codigo[10];
int pos;
void menu(void);
void ingresar(void);
void ingresar(int);
void mostrar(void);
float mostrar(int);
void orden(void);

void menu(void)
{
	int y, opc;
	opc = 99;
	int resultado;
	pos = 0;
	/*
	cout <<" numero y : "<<y<<endl;
	cout <<" numero opc : "<<opc<<endl;
	cout <<" numero resultado : "<<resultado<<endl;
	
	getch();
	*/
	while ( opc != 0)
	{
		system("cls");
		cout<<"\n 1 Ingresar Datos";
		cout<<"\n 2 Ingresar Datos 1 en 1 ";
		cout<<"\n 3 Mostrar con Parametros";
		cout<<"\n 4 Mostrar Sin Parametros";
		cout<<"\n 5 Ordebar - Listar Datos";
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresar();
				break;
			case 2:
				ingresar(pos);
				pos++;
				break;
			
			case 3:
			    //resultado = mostrar(5);
			    cout <<"\n resultado de la suma : "<<mostrar(5);
				break;
			case 4:
				mostrar();
				break;	
			case 5:
				orden();
				break;
			case 0:
				exit;
			default:
				cout <<"\n Opcion no Valida !! ";
				break;
		}
		cout <<"\n\n Oprima una tecla para continuar";
		getch(); //presionar una tecla --- una espera
	}
}

void ingresar(int zz)
{
	cout<<endl<<" Digite codigo posicion ["<<zz<<"] : ";
	cin >>codigo[zz];
}



void ingresar(void)
{
	int k;
	for (k=0; k<10; k++)
	{							
		cout <<endl<<"Digite el codigo del estudiante ["<<k<<"] :";
		cin>>codigo[k];
	}
}


void mostrar(void)
{
	int k;
	k = 0;
	while ( k < pos)
	{
		cout <<" codigo en posicion : ["<<k<<"] "<<codigo[k]<<endl;
		k++;
	}	
	getch();
}

float mostrar(int valor)
{
	int k;
	float suma;
	k = valor;
	suma = 0;	
	while ( k<10 )
	{
		if( k%2 == 0)           
		{
			cout <<"Posicion Par : "<<k<<" "<<codigo[k]<<endl;
		}
		else
		{
			cout <<"Posicion Impar : "<<k<<" "<<codigo[k]<<endl;
		}
		suma = suma + codigo[k] * 0.2;
		k++;	
	}
	return suma;
}	

void orden(void)
{
	int k,j;
	int aux;
	
	for (k=0; k<9; k++)
	{
		for (j=k+1; j<10; j++)
		{
			if (codigo[k] > codigo[j])
			{
				aux       = codigo[k];
				codigo[k] = codigo[j];
				codigo[j] = aux;
			}
		}
	}

	for (k=0; k<10; k++)
	{
		cout <<"Posicion : "<<k<<" "<<codigo[k]<<endl;	
	}
	getch();
}

main()
{
	menu();
}
