#include "device.h"
#include <iostream>

using namespace std;

int
main(void) {
  int total;
  cin >> total;
  int nDev;
  cin >> nDev;
  
  Device **arreglo = new Device*[nDev];
  int result = 0;
  
  for (int i = 0; i < nDev; ++i) {
    int kind, fct1;
    
    cin >> kind >> fct1;

    switch (kind) {
    case 5:
      arreglo[i] = new DevByFive(fct1);
      break;
    case 10:
      arreglo[i] = new DevByTen(fct1);
      break;
    }
    
    result += arreglo[i]->compute();
  }

  int nDev2 = total - nDev;
  
  for (int j = nDev, i = 0; i < nDev2; ++i, ++j) {
    int kind, fct1, fct2;
    
    cin >> kind >> fct1 >> fct2;

    switch (kind) {
    case 5:
      arreglo[j] = new Dev2MinusFive(fct1, fct2);
      break;
    case 10:
      arreglo[j] = new Dev2AddTen(fct1, fct2);
      break;
    }
    
    result += arreglo[j]->compute();
  }

  cout << result << endl;
  return 0;
}
