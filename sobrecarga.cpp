#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <string>

using namespace std;

void sumar (int a, int b){
	int resultado= a+b;
	cout<< resultado<<endl;
}

void sumar(int a, int b, string c){
	int resultado = a+b;
	cout<< c <<resultado<<endl;
}

int main ()
{
	sumar(10,20);
	sumar(100,200);
	sumar(100,200, "Tercer resultado ");
getch();

}


