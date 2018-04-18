#pragma once

class IEnergia{

public:
  void consumir(float nivel);
  void cargar(float nivel);

};

class IPrender{
 public:
  void prender();
};

class IApagar{
  void apagar();
};
