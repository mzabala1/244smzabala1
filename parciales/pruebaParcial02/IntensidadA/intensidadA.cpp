#include <iostream>
#include "iluminanciaA.h"

using namespace std;

int
main() {

  float pRojo;
  float pVerde;
  int rojo, verde, azul;

  cin >> pRojo >> pVerde >> rojo >> verde >> azul;

  revisarIluminancia(pRojo, pVerde, rojo, verde, azul);

  return 0;
}
