#include <iostream>
#include <map>

int main()
{
  std::map<char,int> contador;

  char c;
  while( std::cin >> c && c != '\n' )
    contador[c]++;

  for ( auto& pair : contador )
    std::cout << "La cifra " << pair.first << " aparece " << pair.second << " veces.\n";
}