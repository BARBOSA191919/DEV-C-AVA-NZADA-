
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
	lista *ap1;
	lista *ap2;
} *cola, *cab, *cab2, *cola2, *nuevo;

void menu(void);
void ingresar(void);
void mostrar(void);   //ascendente
void mostrar2(void);  //descendente

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
		cout<<"\n 2 Sacar Datos ";
		cout<<"\n 3 Mostrar Datos Ascendente";
		cout<<"\n 4 Mostrar Datos Descendente";
		cout<<"\n 5 compara CODIGO";
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
				mostrar(); //ascendente
				break;
			case 4:
				mostrar2(); //descendente
				break;
			case 5:
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
	lista *bus1, *bus2;
	int sw;
    // PRIMERA PARTE	
	nuevo = new(lista);
	fflush(stdin);
	
	cout<<"Digite el codigo :  ";
	cin >>nuevo->codigo;
	fflush(stdin);
	
	cout<<"\n"<<"Digite el Nombre : ";
	getline(cin,nuevo->nombre);
	nuevo->ap1 = NULL;
	nuevo->ap2 = NULL;
	fflush(stdin);
	
	//VERIFICAR SI HAY UNA LISTA CREADA    01
	if (!cab)
	{
		cab   = new(lista);	cola  = new(lista);
		cab2  = new(lista);	cola2 = new(lista);
		
		cab   = nuevo;	cola  = nuevo;
		cab2  = nuevo;	cola2 = nuevo;
		cout <<"\n"<<"se creo la lista";
	}
    else
	{ 
	//  insertamos al inicio de la lista CAB
	    if ( nuevo->codigo <= cab->codigo )	
	    {
	    	nuevo->ap1 = cab;
	    	cab->ap2   = nuevo;
	    	cab        = nuevo;
	    	cola2      = nuevo;
		}
		else
		{
			if ( nuevo->codigo >= cola->codigo )
			{
				cola->ap1  = nuevo;
				nuevo->ap2 = cab2;
				
				cola = nuevo;
				cab2 = nuevo;
			}
			else
			{
				bus1 = new(lista);
				bus2 = new(lista);
				sw = 0;
				bus1 = cab;
				bus2 = cab->ap1;
				while ( sw == 0 )
				{
					if ( bus2->codigo >= nuevo->codigo )
					{
						nuevo->ap1 = bus2;
						bus2->ap2  = nuevo;
						bus1->ap1  = nuevo;
						nuevo->ap2 = bus1;
						sw = 9;
					}
					else
					{
						bus1 = bus2;
						bus2 = bus2->ap1;
					}
				}
			}
		}
		cout <<"\n"<<"se adiciono un nodo a inicio de la lista";	
	}
	espera();	
}

void mostrar(void) // ascendente
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
		 nuevo = nuevo->ap1; 	
	  }
   }
   espera();   
}

void mostrar2(void) // descendente
{
   if (!cab)
   {
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(lista);
   	  nuevo = cab2;
   	  while (nuevo != NULL)
   	  {
   	     cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
		 cout <<"\n"<<"Nombre  : "<<nuevo->nombre;
		 nuevo = nuevo->ap2; 	
	  }
   }
   espera();   
}

void sacar(void)
{
	int cod_borra, sw;
	lista *bus1, *bus2;
	if (!cab)
   	{
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   	}	
   	else
   	{
	   cout <<"\n Digite Codigo Borrar : ";
	   cin >>cod_borra;
	   if ( cab->codigo == cod_borra )
	   {
	   		nuevo = new(lista);     // reservamos un espacio de memoria
	   		nuevo = cab;          // unimos nuevo con "CAB" la cabeza de la lista
	   		//mostramos el registro a borrar
	   		cout <<"\n"<<"El Registro Borrado es:"<<endl;
	   		cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
	   		cout <<"\n"<<"Nombre  : "<<nuevo->nombre;
	   
	   		cab = cab->ap1; // "CAB" avanza a siguiente nodo
	   		delete(nuevo);        // retiramos el primer nodo de la lista
   		}
   		else
   		{
   			bus1 = new(lista);
		  	bus2 = new(lista);
		  	sw = 0;
		  	bus1 = cab;
		  	bus2 = cab->ap1;
		  	while (sw == 0 && bus2 != NULL )
		  	{
		  		if ( bus2->codigo == cod_borra )
				{
					sw = 1;
					bus1->ap1 = bus2->ap1;
					bus1->ap1=bus2->ap2;
					//mostramos el registro a borrar
	   				cout <<"\n"<<"El Registro Borrado es:"<<endl;
	   				cout <<"\n"<<"Codigo  : "<<bus2->codigo;
	   				cout <<"\n"<<"Nombre  : "<<bus2->nombre;
	   				delete(bus2);
				}
				else
				{
					bus1 = bus2;
					bus2 = bus2->ap1;
					bus2 = bus2->ap2;	
				}	
			}
			if ( sw == 0 )
			{
				cout <<endl<<"No se encontro este Codigo en la Lista";	
			}
		}
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
			nuevo = nuevo->ap1;
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
