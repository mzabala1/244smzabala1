#pragma once
#include "Barcos.h"
#include <vector>

using namespace std;

class Armada{
 public:
  vector<Barco> obtenerBarcos();
  virtual void registrarBarco(Barco barco) = 0;
 private:
  vector<Barco> barcos;
};

class ArmadaMarina: public Armada{
 public:
  void registrarBarco(Barco barco);

};

class ArmadaFluvial: public Armada{
 public:
  void registrarBarco(Barco barco);

};
