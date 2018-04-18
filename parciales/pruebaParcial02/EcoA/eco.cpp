#include "eco.h"
#include <iostream>

using namespace std;

int*
creacionDeEco(const int arreglo[], const int longitud,
	      const int restraso, float factor) {
  
  int *salida = new int[longitud];

  for (int i = 0; i < restraso; ++i) {
    salida[i] = arreglo[i];
  }
  
  for (int i = restraso, j = 0; i < longitud; ++i, ++j) {
    salida[i] = arreglo[i] + (arreglo[j] * factor);
  }

  return salida;
}

void
imprimirEco(const int eco[], const int longitud) {

  for (int i = 0; i < longitud; ++i) {
    cout << eco[i];
    if ((i + 1) < longitud)
      cout << ", ";
  }
  
  cout << endl;
}
