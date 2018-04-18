/*
 * fichero: main.cpp
 * compilar: $ g++ -o programa1 main.cpp
 * ejecutar: $ ./programa1
*/

#include "funciones.h"
#include "funciones.cpp"
#include <iostream>

using namespace std;

int main(){

  int a, b, c;

  cin >> a >> b >> c;
  
  cout << sumaEnt(sumaEnt(a,b),multEnt(c,multEnt(sumaEnt(multEnt(a,b),c),restaEnt(a,b)))) << endl;

  return 0;
}
