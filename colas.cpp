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
};

lista *cola, *cab, *nuevo;

void menu(void);
void ingresar(void);
void mostrar(void);
void mostrar_cadena(void);
void sacar(void);

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
		cout<<"\n 4 compara nombre";
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresar();	break;
			case 2:
				sacar();	break;
			case 3:
				mostrar();	break;
			case 4:
				mostrar_cadena();	break;
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
	if ( !cab )	
	{
		cab = new(lista);
		cout <<"\n Ingrese un codigo : ";
		cin >>cab->codigo; 
        fflush(stdin);    //esta funcion libera la memoria 
		
		cout<<"Ingresa el nombre : ";
		getline(cin,cab->nombre);        //"juan alberto ramires"
              // cin >> nombre           juan alberto ramirez
              //  realmente almacena es  "juan" 
        
        cout<<"\n\n";
        fflush(stdin);
        
		cab->apuntador = NULL;
		
		cola = new(lista);
		cola = cab;
		return;
	}
	nuevo = new(lista);
	cout <<"\n Ingrese un Codigo: ";
	cin >>nuevo->codigo;
	fflush(stdin);
	
    cout<<"Ingresa el nombre : ";
    getline(cin,nuevo->nombre);
    cout<<"\n\n";
    fflush(stdin);
      
	nuevo->apuntador = NULL;  /// la estructura Nuevo esta apuntando al Final o vacio
	cola->apuntador = nuevo;  /// el ultimo nodo de la lista se une al NUEVO
	
	cola = nuevo;  /// la variable Cola toma la posicion de Nuevo
}


void sacar(void)   // o borrar
{
	if ( !cab )
	{
		cout <<"\n\n No hay Elementos Para Sacar ";
		return;
	}
	nuevo = new(lista);
	
	nuevo = cab;
	
	cout <<"\n\n Elemento Eliminado: "<<nuevo->codigo;
	cout <<"\n Nombre : "<<nuevo->nombre;
	
	cab = nuevo->apuntador;
	//cab = cab->apuntador;   es igual al cab = nuevo->apuntador
	
	delete(nuevo);
}


void mostrar(void)   // o  listar
{
	if ( !cab )
	{
		cout <<"\n\n No hay Elementos Para Mostrar ";
		return;
	}
	nuevo = new(lista);
	nuevo = cab;
	
	while ( nuevo != NULL )
	{
	  cout <<"\n\n Elemento : "<<nuevo->codigo;
      cout <<"\n Nombre : "<<nuevo->nombre;
      
	  nuevo = nuevo->apuntador;  // avanzar en la lista 
    }
}

void mostrar_cadena(void)
{
	if ( !cab )
	{
		cout <<"\n\n No hay Elementos Para Mostrar ";
		return;
	}
	nuevo = new(lista);
	
	string nombre_compara;
    fflush(stdin);
    
	cout <<" \n Digite el Nombre a buscar : ";
    getline(cin,nombre_compara);
    
    cout<<"\n\n";
    fflush(stdin);

	nuevo = cab;
	while ( nuevo != NULL )
	{
	//compara dos cadenas de tipo string si son iguales el resultado es 0
	  if ( nuevo->nombre.compare(nombre_compara) == 0 )
	  {
	      cout <<"\n\n Elemento : "<<nuevo->codigo;
          cout <<"\n Nombre : "<<nuevo->nombre;
      }
	  nuevo = nuevo->apuntador;
    }
}
