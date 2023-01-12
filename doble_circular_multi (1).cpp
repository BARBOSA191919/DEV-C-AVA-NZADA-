
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct estudiante
{
	int codigo;
	string nombre;
	estudiante *ape;	
} *nuevo_est;
struct lista
{ 
	int codigo;
	string salon;
	lista *ap1;
	lista *ap2;
	estudiante *ape;
} *cola, *cab, *cab2, *cola2, *nuevo;

void menu(void);
void ingresar_salon(void);
void mostrar_salon1(void);   //ascendente
void mostrar_salon2(void);  //descendente
void sacar_salon1(void);    // borrar en forma ascendente
void sacar_salon2(void);    // borrar en forma descendente

void ingresar_estudiante(void);
void mostrar_est_salon(void);
void mostrar_todos_estudiante(void);
void sacar_estudiante(void);

void buscar(void);
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
		cout<<"\n 1 Ingresar Datos Salon";
		cout<<"\n 2 Sacar Datos Salon Ascendente ";
		cout<<"\n 3 Sacar Datos Salon Descendente ";
		cout<<"\n 4 Mostrar Datos Salon Ascendente";
		cout<<"\n 5 Mostrar Datos Salon Descendente";
		cout<<"\n\n 6 Ingresar Datos Estudiante";
		cout<<"\n 7 Sacar Datos Estudiante ";
		cout<<"\n 8 Mostrar Datos Estudiante Salon";
		cout<<"\n 9 Mostrar Todos los Estudiantes";
		cout<<"\n 5 compara CODIGO";
		cout<<"\n 0 Terminar";
		cout<<"\n Ingrese Opcion";
		cin>>opc;
		
		switch(opc)
		{
			case 1:
				ingresar_salon();
				break;
			case 2:
				sacar_salon1();   //ascendente
				break;
			case 3:
				sacar_salon2();   //descendente
				break;
			case 4:
				mostrar_salon1(); //ascendente
				break;
			case 5:
				mostrar_salon2(); //descendente
				break;
			case 6:
				ingresar_estudiante();
				break;
			case 7:	
				sacar_estudiante();
				break;
			case 8:	
				mostrar_est_salon();
				break;
			case 9:	
				mostrar_todos_estudiante();
				break;	
			default:
				cout <<"\n Opcion no Valida !! ";
				break;
		}
		cout <<"\n\n Oprima una tecla para continuar";
		getch();
	}
}

void ingresar_salon(void)
{
	lista *bus1, *bus2;
	int sw;
    // PRIMERA PARTE	
	nuevo = new(lista);
	fflush(stdin);
	
	cout<<"Digite el codigo :  ";
	cin >>nuevo->codigo;
	fflush(stdin);
	
	cout<<"\n"<<"Digite el salon : ";
	getline(cin,nuevo->salon);
	fflush(stdin);
	nuevo->ape = NULL;
	
	//VERIFICAR SI HAY UNA LISTA CREADA    01
	if (!cab)
	{
		cab   = new(lista);	cola  = new(lista);
		cab2  = new(lista);	cola2 = new(lista);
		
		cab   = nuevo;	cola  = nuevo;
		cab2  = nuevo;	cola2 = nuevo;
		
		cab->ap2   = cola;
		cab2->ap1  = cola2;
		cout <<"\n"<<"se creo la lista de Salones";
	}
    else
	{ 
	//  insertamos al inicio de la lista CAB
	    if ( nuevo->codigo <= cab->codigo )	
	    {
	    	if ( nuevo->codigo == cab->codigo )	
	    	{
	    		cout <<"\ncodigo existe en la lista de salones";
			}
			else
			{
	    		nuevo->ap1 = cab;
	    		cab        = nuevo;
	    		cab->ap2   = cab2;
	    		cab2->ap1  = cab;
	    		cola2->ap2 = nuevo;
	    		cola2      = cab;
	    		cout <<"\n"<<"se adiciono un nodo a inicio de la lista";
	    	}
		}
		else
		{
			if ( nuevo->codigo >= cola->codigo )
			{
				if ( nuevo->codigo == cola->codigo )
				{
					cout <<"\ncodigo existe en la lista de salones";
				}
				else
				{
					cola->ap1  = nuevo;
					nuevo->ap2 = cab2;
					cola = nuevo;
					cab2 = nuevo;
					cab2->ap1  = cola2;
					cab->ap2   = cola;
					cout <<"\n"<<"se adiciono un nodo al final de la lista";
				}
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
						sw = 9;
						if ( bus2->codigo == nuevo->codigo )
						{
							cout <<"\ncodigo existe en la lista de salones";
						}
						else
						{
							nuevo->ap1 = bus2;
							bus2->ap2  = nuevo;
							bus1->ap1  = nuevo;
							nuevo->ap2 = bus1;
							cout <<"\n"<<"se adiciono un nodo en intermedio de la lista";
						}
					}
					else
					{
						bus1 = bus2;
						bus2 = bus2->ap1;
					}
				}
			}
		}	
	}
	espera();	
}

void mostrar_salon1(void) // ascendente
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
   	  while (nuevo->ap1 != cab)
   	  {
   	     cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
		 cout <<"\n"<<"salon  : "<<nuevo->salon;
		 nuevo = nuevo->ap1; 	
	  }
	  cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
	  cout <<"\n"<<"salon  : "<<nuevo->salon;
   }
   espera();   
}

void mostrar_salon2(void) // descendente
{
   if (!cab)
   {
      cout<<"no hay datos o la lista no esta creada";
	  getch();	
   }	
   else
   {
   	  nuevo = new(lista);
   	  nuevo = cab2;    // en forma descendente
   	  while (nuevo->ap2 != cab2)
   	  {
   	     cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
		 cout <<"\n"<<"salon  : "<<nuevo->salon;
		 nuevo = nuevo->ap2; 	
	  }
	  cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
	  cout <<"\n"<<"salon  : "<<nuevo->salon;
   }
   espera();   
}

void sacar_salon1(void)  //ascendente
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
	   cout <<"\n Digite Codigo Salon a Borrar : ";
	   cin >>cod_borra;   // ejemplo 6
	   if ( cab->codigo == cod_borra )
	   {
	   		if (cab->ape == NULL)
	   		{
	   			nuevo = new(lista);     // reservamos un espacio de memoria
	   			nuevo = cab;          // unimos nuevo con "CAB" la cabeza de la lista
	   			//mostramos el registro a borrar
	   			cout <<"\n"<<"El Registro Borrado es:"<<endl;
	   			cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
	   			cout <<"\n"<<"salon  : "<<nuevo->salon;
	   
	   			cab = cab->ap1;  // "CAB" avanza a siguiente nodo
	   			cola2 = cab; 
	   			cab->ap2 = cola; cola->ap1 = cab;
	   			
	   			delete(nuevo);   // retiramos el primer nodo de la lista
   			}
   			else
   			{
				cout<<"\n No se puede Borrar --- Hay Estudiantes";
			}
		}
   		else
   		{
			if ( cola->codigo == cod_borra )
	   		{
	   			if (cola->ape == NULL)
	   			{
	   				nuevo = new(lista);  // reservamos un espacio de memoria
	   				nuevo = cola;        // unimos nuevo con "CAB" la cabeza de la lista
	   				//mostramos el registro a borrar
	   				cout <<"\n"<<"El Registro Borrado es:"<<endl;
	   				cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
	   				cout <<"\n"<<"salon  : "<<nuevo->salon;
	   
	   				cola = cab2->ap2;  // "CAB" avanza a siguiente nodo
	   				cab2 = cola; 
	   				cab->ap2 = cola; cola->ap1 = cab;
	   				delete(nuevo);   // retiramos el primer nodo de la lista
   				}
   				else
   				{
					cout<<"\n No se puede Borrar --- Hay Estudiantes";
				}
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
					{	sw = 1;
						if (bus2->ape == NULL)
						{
							bus1->ap1 = bus2->ap1;
							bus2->ap1->ap2 = bus1;
							
							//mostramos el registro a borrar
	   						cout <<"\n"<<"El Registro Borrado es:"<<endl;
	   						cout <<"\n"<<"Codigo  : "<<bus2->codigo;
	   						cout <<"\n"<<"salon  : "<<bus2->salon;
	   						delete(bus2);
						}
						else
						{
							cout<<"\n No se puede Borrar --- Hay Estudiantes";
						}
					}
					else
					{
						bus1 = bus2;
						bus2 = bus2->ap1;	
					}	
				}
				if ( sw == 0 )
				{
					cout <<endl<<"No se encontro este Codigo en la Lista";	
				}
			}
		}
	}
	espera();
}

void sacar_salon2(void)  //Descendente
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
	   cout <<"\n Digite Codigo Salon a Borrar : ";
	   cin >>cod_borra;   // ejemplo 6
	   if ( cab2->codigo == cod_borra )
	   {
	   		if (cab->ape == NULL)
	   		{
	   			nuevo = new(lista);     // reservamos un espacio de memoria
	   			nuevo = cab2;          // unimos nuevo con "CAB" la cabeza de la lista
	   			//mostramos el registro a borrar
	   			cout <<"\n"<<"El Registro Borrado es:"<<endl;
	   			cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
	   			cout <<"\n"<<"salon  : "<<nuevo->salon;
	   
	   			cab2 = cab->ap2;  // "CAB" avanza a siguiente nodo
	   			cola = cab2; 
	   			cab->ap2 = cola; cola->ap1 = cab;
	   			
	   			delete(nuevo);   // retiramos el primer nodo de la lista
   			}
   			else
   			{
				cout<<"\n No se puede Borrar --- Hay Estudiantes";
			}
		}
   		else
   		{
			if ( cola2->codigo == cod_borra )
	   		{
	   			if (cola2->ape == NULL)
	   			{
	   				nuevo = new(lista);  // reservamos un espacio de memoria
	   				nuevo = cola2;        // unimos nuevo con "CAB" la cabeza de la lista
	   				//mostramos el registro a borrar
	   				cout <<"\n"<<"El Registro Borrado es:"<<endl;
	   				cout <<"\n"<<"Codigo  : "<<nuevo->codigo;
	   				cout <<"\n"<<"salon  : "<<nuevo->salon;
	   
	   				cola2 = cab->ap1;  // "CAB" avanza a siguiente nodo
	   				cab = cola2; 
	   				cab->ap2 = cola; cola->ap1 = cab;
	   				delete(nuevo);   // retiramos el primer nodo de la lista
   				}
   				else
   				{
					cout<<"\n No se puede Borrar --- Hay Estudiantes";
				}
			}
		    else
			{
   				bus1 = new(lista);
		  		bus2 = new(lista);
		  		sw = 0;
		  		bus1 = cab2;
		  		bus2 = cab2->ap1;
		  		while (sw == 0 && bus2 != NULL )
		  		{
		  			if ( bus2->codigo == cod_borra )
					{	sw = 1;
						if (bus2->ape == NULL)
						{
							bus1->ap2 = bus2->ap2;
							bus2->ap2->ap1 = bus1;
							
							//mostramos el registro a borrar
	   						cout <<"\n"<<"El Registro Borrado es:"<<endl;
	   						cout <<"\n"<<"Codigo  : "<<bus2->codigo;
	   						cout <<"\n"<<"salon  : "<<bus2->salon;
	   						delete(bus2);
						}
						else
						{
							cout<<"\n No se puede Borrar --- Hay Estudiantes";
						}
					}
					else
					{
						bus1 = bus2;
						bus2 = bus2->ap2;	
					}	
				}
				if ( sw == 0 )
				{
					cout <<endl<<"No se encontro este Codigo en la Lista";	
				}
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
	   			cout <<"\n"<<"salon  : "<<nuevo->salon;
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


void ingresar_estudiante(void)
{
	lista *bus1, *bus2;
	int sw, busca_salon, sw_est;
	sw = 0;
    if (!cab)
	{
		cout <<"\n no hay salones creados ";	
	}
	else
	{
		cout<<"\nDigite codigo del salon : ";
		cin >>busca_salon;
		nuevo = new(lista);
		fflush(stdin);
		nuevo = cab;
		if ( nuevo->codigo == busca_salon)
		{ 
			sw_est = 0;   sw = 1;
			while ( sw_est == 0 )
			{					
				nuevo_est = new(estudiante);
				cout<<"Digite el codigo Estudiante :  ";
				cin >>nuevo_est->codigo;
				fflush(stdin);
	
				cout<<"\n"<<"Digite el Nombre Estudiante : ";
				getline(cin,nuevo_est->nombre);
				fflush(stdin);
				nuevo_est->ape = NULL;
				
				nuevo_est->ape = nuevo->ape;
				nuevo->ape     = nuevo_est;
				
				cout <<"\n Captura mas estudiantes Digite si(0) no(otro #)";
				cin>>sw_est;	
			}
		}
		else
		{
			nuevo = nuevo->ap1; sw_est = 0; 
			while ( nuevo != cab && nuevo->codigo <= busca_salon && sw_est == 0 )
			{
			   	if ( nuevo->codigo == busca_salon)
				{ 
				    sw = 1;
					while ( sw_est == 0 )
					{					
						nuevo_est = new(estudiante);
						cout<<"Digite el codigo Estudiante :  ";
						cin >>nuevo_est->codigo;
						fflush(stdin);
	
						cout<<"\n"<<"Digite el Nombre Estudiante : ";
						getline(cin,nuevo_est->nombre);
						fflush(stdin);
						nuevo_est->ape = NULL;
				
						nuevo_est->ape = nuevo->ape;
						nuevo->ape     = nuevo_est;
				
						cout <<"\n Captura mas estudiantes Digite si(0) no(otro #)";
						cin>>sw_est;	
					}
				}
				else
				{
					nuevo = nuevo->ap1;	
				}	
			}
		}
	}
	if ( sw == 0)
	{
		cout<<"\n no existe el salon ";
	}
   	espera();
}

void mostrar_est_salon(void)
{
	lista *bus1, *bus2;
	int sw, busca_salon, sw_est;
	sw = 0;
    if (!cab)
	{
		cout <<"\n no hay salones creados ";	
	}
	else
	{
		cout<<"\nDigite codigo del salon : ";
		cin >>busca_salon;
		nuevo = new(lista);
		fflush(stdin);
		nuevo = cab;
		if ( nuevo->codigo == busca_salon)
		{ 
			sw_est = 0;   sw = 1;
			nuevo_est = new(estudiante);
			nuevo_est = nuevo->ape;
			while ( nuevo_est != NULL )
			{	
				cout<<"\nCodigo Estudiante : "<<nuevo_est->codigo;
				cout<<"\nNombre Estudiante : "<<nuevo_est->nombre<<endl;

				nuevo_est = nuevo_est->ape;
			}
		}
		else
		{
			nuevo = nuevo->ap1;
			while ( nuevo != cab && nuevo->codigo <= busca_salon )
			{
			   	if ( nuevo->codigo == busca_salon)
				{ 
					sw_est = 0;   sw = 1;
					nuevo_est = new(estudiante);
					nuevo_est = nuevo->ape;
					while ( nuevo_est != NULL )
					{	
						cout<<"\nCodigo Estudiante : "<<nuevo_est->codigo;
						cout<<"\nNombre Estudiante : "<<nuevo_est->nombre<<endl;

						nuevo_est = nuevo_est->ape;
					}
				}
				else
				{
					nuevo = nuevo->ap1;	
				}	
			}
		}
	}
	if ( sw == 0)
	{
		cout<<"\n no existe el salon ";
	}
   	espera();	
	
}
void mostrar_todos_estudiante(void)
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
   	  while (nuevo_est != NULL) // le agregamos nuevo _est diferente de null para que muestre todos los estudiates
   	  {
   	cout <<"\n"<<"Nombre estudiante : "<<nuevo_est->nombre;  //le agregamos el cin indicado 
   	cout <<"\n"<<"Codigo estudiante  : "<<nuevo_est->codigo;
		 nuevo_est = nuevo_est->ape;	// nuevo_est lo apuntamos ape que es el correspodiente al estudiante
   }
   espera();   
}
}
void sacar_estudiante(void)
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
	   cout <<"\n Digite Codigo Borrar del estudiante: ";
	   cin >>cod_borra;
	   if ( cab->codigo == cod_borra )
	   {
	   		nuevo = new(lista);     // reservamos un espacio de memoria
	   		nuevo = cab;          // unimos nuevo con "CAB" la cabeza de la lista
	   		//mostramos el registro a borrar
	   		cout <<"\n"<<"El Registro Borrado del estudiante es:"<<endl;
	   		cout <<"\n"<<"Nombre estudiante : "<<nuevo_est->nombre; 
         	cout <<"\n"<<"Codigo estudiante  : "<<nuevo_est->codigo;
	   
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
	   				cout <<"\n"<<"El Registro Borrado del estudiante es:"<<endl;
	   			    cout <<"\n"<<"Nombre estudiante : "<<nuevo_est->nombre; 
   	                cout <<"\n"<<"Codigo estudiante  : "<<nuevo_est->codigo;
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
void espera(void)
{
    cout <<"\n"<<"<Enter";
    getch();	
}
