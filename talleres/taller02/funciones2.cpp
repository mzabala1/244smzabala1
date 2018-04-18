/*
 * fichero: funciones2.cpp
 * compilar: $ g++ -o funciones2 funciones2.cpp
 * ejecutar: $ ./funciones2
 */

#include "funciones2.h"
#include <iostream>

using namespace std;

int mcd(int a, int b){
  if (a == b){
    return a;
  }
  while (a != b){
    if (a > b){
      a = a - b;
    }else {
      b = b - a;
    }
    
  }

  return a;
}

void simpFrac(int n1,int n2){
  int c = mcd(n1,n2);
  n1=n1/c;
  n2=n2/c;
  cout<<"La fracción simplificada es: "<<n1<<"/"<<n2<<endl;
}

int main(){
  int x, y;
  cin >> x;
  cin >> y;

  cout << "mcd " << mcd(x,y) << endl;

  simpFrac(x,y);

  
}
