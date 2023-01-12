
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct lista
{ 
	int codigo;
	string nombre;
	lista *apuntador;
} *cola, *cab, *nuevo;

void menu(void);
void ingresar(void);
void mostrar(void);
void buscar(void);
void sacar(void);

void espera();

main()
{
	menu();
}

void menu(void)
{
	int y, opc;
	opc = 9;
	while ( opc != 0)
	{
		system("cls");
		cout<<"\n 1 Ingresar Datos";
		cout<<"\n 2 Sacar Datos";
		cout<<"\n 3 Mostrar Datos";
		cout<<"\n 4 compara CODIGO";
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresar();
				break;
			case 2:
				sacar();
				break;
			case 3:
				mostrar();
				break;
			case 4:
				buscar();
				break;
			default:
				cout <<"\n Opcion no Valida !! ";
				break;
		}
		cout <<"\n\n Oprima una tecla para continuar";
		getch();
	}
}

void ingresar(void)
{
	

    // PRIMERA PARTE	
	nuevo = new(lista);
	fflush(stdin);
	
	cout<<"Digite el codigo :  ";
	cin >>nuevo->codigo;
	fflush(stdin);
	
	cout<<"\n"<<"Digite el Nombre : ";
	getline(cin,nuevo->nombre);
	nuevo->apuntador = NULL;
	fflush(stdin);
	
	//VERIFICAR SI HAY UNA LISTA CREADA
	if (!cab)
	{
		cab  = new(lista);
		cola = new(lista);
		cab  = nuevo;
		cola = nuevo;
		cout <<"\n"<<"se creo la lista";
	}
    else
	{
	
	    nuevo->apuntador = cab;
		cab = nuevo;
		cout <<"\n"<<"se adiciono un nodo a inicio de la lista";	
	}
	espera();	
}

void mostrar(void)
{
   if (!cab)
   {
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(lista);
   	  nuevo = cab;
   	  while (nuevo != NULL)
   	  {
   	     cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
		 cout <<"\n"<<"Nombre  : "<<nuevo->nombre;
		 nuevo = nuevo->apuntador; 	
	  }
   }
   espera();   
}

void sacar(void)
{
	if (!cab)
   	{
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   	}	
   	else
   	{
	   nuevo = new(lista);     // reservamos un espacio de memoria
	   nuevo = cab;          // unimos nuevo con "CAB" la cabeza de la lista
	   
	   //mostramos el registro a borrar
	   cout <<"\n"<<"El Registro Borrado es:"<<endl;
	   cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
	   cout <<"\n"<<"Nombre  : "<<nuevo->nombre;
	   
	   cab = cab->apuntador; // "CAB" avanza a siguiente nodo
	   delete(nuevo);        // retiramos el primer nodo de la lista
       
	   cout <<endl<<"se retiro un nodo de la lista";
	}
	espera();
}

void buscar(void)
{
	int codigo_busqueda;
	int encontro = 0;
	if (!cab)
   	{
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   	}	
   	else
   	{
	  	cout<<endl<<"Digite el codigo Busqueda : ";
	  	cin >>codigo_busqueda;
	  	nuevo = new(lista);     // reservamos un espacio de memoria
	  	nuevo = cab;          // unimos nuevo con "CAB" la cabeza de la lista
	   	
	   	while (nuevo != NULL && encontro == 0)
	   	{
	   	    if (nuevo->codigo == codigo_busqueda)	
	   	    {
	   	     	cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
	   			cout <<"\n"<<"Nombre  : "<<nuevo->nombre;
				encontro = 1;   	
			}
			nuevo = nuevo->apuntador;
		}
		if (encontro == 0)
		{
			cout <<endl<<"No se encontro el codigo en la lista";
		}
	}
	espera();
}


void espera(void)
{
    cout <<"\n"<<"<Enter";
    getch();	
}
