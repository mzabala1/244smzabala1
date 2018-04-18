#include "eco.h"
#include <iostream>

using namespace std;

int
main(void) {
  int n;

  cin >> n;

  for (int i = 0; i < n; ++i) {
    int nVal, retraso;
    float factor;

    cin >> nVal >> retraso >> factor;

#ifdef debug
    cout << "valores: " << nVal
	 << " retraso: " << retraso
	 << " factor: " << factor << endl;
#endif
    
    int *arreglo = new int[nVal];

    for (int j = 0; j < nVal; ++j) {
      cin >> arreglo[j];
    }

    int *eco = creacionDeEco(arreglo, nVal, retraso, factor);
    imprimirEco(arreglo, nVal);
    imprimirEco(eco, nVal);

    delete [] arreglo;
    delete [] eco;
  }

  return 0;
}
