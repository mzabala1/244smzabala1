#pragma once
#include <string>
#include "INaves.h"

using namespace std;

class Barco{
 public:
  Barco(string id);
  ~Barco();
  virtual string obtId();
 private:
  string id;
};

class Portaviones: public IMar, public Barco{
 public:
  Portaviones(string id);
  ~Portaviones();
};

class Fragata: public IMar,public Barco{
 public:
  Fragata(string id);
  ~Fragata();
};

class Lancha: public IMar, public IRio, public Barco{
 public:
  Lancha(string id);
  ~Lancha();
};
