#include <iostream>

using namespace std;

void contadorBaldosasPatronA(const char secuencia[],
                             int& nBaldosas,
                             int& nBaldosasBuenas,
                             int& nBaldosasMalas);

int
main(void) {

  char secuencia[256];

  while (cin >> secuencia) {
    int nBaldosas = 0;
    int nBaldosasBuenas = 0;
    int nBaldosasMalas = 0;

    contadorBaldosasPatronA(secuencia, nBaldosas,
                            nBaldosasBuenas, nBaldosasMalas);

    cout << secuencia
         << " total: " << nBaldosas
         << " buenas: " << nBaldosasBuenas
         << " malas: " << nBaldosasMalas
         << endl;
  }

  return 0;
}

void contadorBaldosasPatronA(const char secuencia[],
                             int& nBaldosas,
                             int& nBaldosasBuenas,
                             int& nBaldosasMalas) {

  for (int i = 0; secuencia[i]; i+=2) {

    nBaldosas++;
    if (islower(secuencia[i]) && isupper(secuencia[i+1]))
      nBaldosasBuenas++;
  }

  nBaldosasMalas = nBaldosas - nBaldosasBuenas;
  return;
}
