#include<iostream>
#include<conio.h>

impor java.util.Scanner;
public class Ejemplo 3{
public static void main(String arg []){
	Scanner x = new Scanner(System.in);

int N =x.nextInt();
int A[]= new int [N];

for (int i = 0; i<N;i++)
A [i] = x.nexInt();

int con = 0;

for (int  i = 0; i<N;i++)
{
	con = 0;
	for (int j = 0; j <N; j++)
	{
		if (A[i]==A[j])
		con ==con +1;
	}
         if (con==1)
		 cout<< A[i] <<" "<< endl;
}
}
}
   return 0;
}