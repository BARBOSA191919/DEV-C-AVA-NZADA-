#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>

using namespace std;

string nombre[3];
int pos;

void menu(void);
void ingresar(void);
void ingresar(int);
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
		cout<<"\n 2 Ingresar Datos 1 en 1 ";
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
			case 2:
				ingresar(pos);
				pos++;
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
	cout<<endl<<" Digite nombre posicion ["<<zz<<"] : ";
	cin >>nombre[zz];
}



void ingresar(void)
{
	int k;
	for (k=0; k<3; k++)
	{							
		cout <<endl<<"Digite el nombre del estudiante ["<<k<<"] :";
		getline(cin,nombre[k]);
		fflush(stdin);  // liberar espacio 
	}
}


void mostrar(void)
{
	int k;
	k = 0;
	while ( k < 3)
	{
		cout <<" nombre en posicion : ["<<k<<"] "<<nombre[k]<<endl;
		k++;
	}	
	getch();
}



void orden(void)
{
	int k,j;
	string aux;
	
	for (k=0; k<2; k++)
	{
		for (j=k+1; j<3; j++)
		{
			if (nombre[k] > nombre[j])
			{
				aux       = nombre[k];
				nombre[k] = nombre[j];
				nombre[j] = aux;
			}
		}
	}

	for (k=0; k<3; k++)
	{
		cout <<"Posicion : "<<k<<" "<<nombre[k]<<endl;	
	}
	getch();
}

main()
{
	menu();
}
