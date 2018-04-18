#include "iluminanciaA.h"
#include <iostream>

void
revisarIluminancia(float pRojo, float pVerde, int rojo, int verde, int azul) {

  if ((pRojo + pVerde) > 1.0f)
    return;

  float pAzul = pRojo + pVerde;

  float prom = pRojo * rojo + pVerde * verde + pAzul * azul;

  if (prom < 10.0f) {
    std::cout << "Oscuro." << std::endl; 
  }
  else if (prom >= 50 and prom <= 200) {
    std::cout << "Bien." << std::endl;
  }
  else if (prom >= 250) {
    std::cout << "Transparente." << std::endl;
  }
}
