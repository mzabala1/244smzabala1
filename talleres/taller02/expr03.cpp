#include <iostream>

using namespace std;

int main(void){
  int a;
  int b;
  int c;
  int mayor;
  int minimo;
  int mitad;

  cin >> a >> b >> c;


  mayor = max(max(a,b),c);
  minimo = min(min(a,b),c);
  mitad = max(min(a,b),c);

  if (mitad == mayor)
    mitad = min(max(a,b),c);

  cout << mayor << " " << mitad << " "<< minimo << endl;
  
  return 0;
}
