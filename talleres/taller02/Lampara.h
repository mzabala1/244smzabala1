#pragma once
#include "Interfaces.h"


class Lampara: public IEnergia, public IPrender, public IApagar {
 private:
  bool prendida;
 public:
  Lampara();
  ~Lampara();
  float nivel;
  float obtNivelEnergia();
  bool estaPrendida();
  void consumir(float nivel);
  void cargar(float nivel);
  void prender();
  void apagar();
};
