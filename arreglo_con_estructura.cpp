#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>

using namespace std;

struct Datos   // creamos una nuava variable de tipo structura
{
	int codigo;
	string nombre;
};

Datos Agenda[3]; // creamos una variable de trabajo
				// con la nueva variable de estructura


int pos;

void menu(void);
void ingresar(void);
void mostrar(void);
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
		cout<<"\n 4 Mostrar Sin Parametros";
		cout<<"\n 5 Ordebar - Listar Datos";
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		
		cin>>opc;
		fflush(stdin);  // liberar espacio
		
		switch(opc)
		{
			case 1:
				ingresar();
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

void ingresar(void)
{
	int k;
	for (k=0; k<3; k++)
	{							
		cout <<endl<<"Digite el codigo del estudiante ["<<k<<"] :";
		cin>>Agenda[k].codigo;
		fflush(stdin);  // liberar espacio
		 
		cout <<endl<<"Digite el nombre del estudiante ["<<k<<"] :";
		getline(cin,Agenda[k].nombre);
		fflush(stdin);  // liberar espacio
	}
}


void mostrar(void)
{
	int k;
	k = 0;
	while ( k < 3)
	{
		cout <<" codigo en posicion : ["<<k<<"] "<<Agenda[k].codigo<<endl;
		cout <<" nombre en posicion : ["<<k<<"] "<<Agenda[k].nombre<<endl;
		k++;
	}	
	getch();
}



void orden(void)
{
	int k,j;
	Datos aux;
	
	for (k=0; k<2; k++)
	{
		for (j=k+1; j<3; j++)
		{
			if (Agenda[k].nombre < Agenda[j].nombre)
			{
				aux       = Agenda[k];
				Agenda[k] = Agenda[j];
				Agenda[j] = aux;
			}
		}
	}

	for (k=0; k<3; k++)
	{
		cout <<"Posicion : "<<k<<" Codigo : "<<Agenda[k].codigo<<endl;	
		cout <<"Posicion : "<<k<<" Nombre : "<<Agenda[k].nombre<<endl;	
	}
	getch();
}

main()
{
	menu();
}
