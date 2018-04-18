/*
 * fichero: arreglo02.cpp
 *
 * compilar: $ g++ -o arreglo02 arreglo02.cpp
 * ejecutar: $ ./arreglo02
 */

#include "arreglo02.h"
#include <iostream>

using namespace std;

void imprimirArreglo(char nombre[], int arreglo[], const int n){
  for(int i = 0; i < n; ++i){
    cout << arreglo[i] << endl;
  }
}

void concatenarArreglos(int dest[], int fuente[], const int n){
  
  for(int i = 5; i < n*2; ++i){
    dest[i] = fuente[i-n];
  }
  char hola[3];
  
  imprimirArreglo(hola,dest,n*2);
}


int main(void) {
  const int N = 5 ;
  int a1[N * 2];
  int a2[N];

  cout << "Escriba arreglo a1" << endl;
  for(int i = 0; i < N; ++i){
    cin >> a1[i];
  }
  cout << "Escriba arreglo a2" << endl;
  for(int i = 0; i < N; ++i){
    cin >> a2[i];
  }
  cout << "Concatenacion de a1 y a2 en a1" << endl;

  concatenarArreglos(a1,a2,N);
    

  return 0;
}
