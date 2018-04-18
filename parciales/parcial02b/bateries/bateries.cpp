#include "bateries.h"

Batery::Batery(){}

Batery::~Batery(){}

B2Batery::B2Batery(float charge[2]){
  this->charge[0] = charge[0];
  this->charge[1] = charge[1];
}

B2Batery::~B2Batery()
{}

float B2Batery::getCharge(int pos){
  return charge[pos];
}

float B2Batery::getTotalCharge(){
  return charge[0] + charge[1];
}

float B2Batery::setDischarge(float amount){
  prop[0] = charge[0]/(getTotalCharge());
  prop[1] = charge[1]/(getTotalCharge());

  charge[0] = charge[0] - amount * prop[0];
  charge[1] = charge[1] - amount * prop[1];
  return charge[0] + charge[1];
}

float getTotalBateries(Batery **bateries, int nBateries){
  
  float totalCarga=0;
  
  for(int i=0; i<nBateries; i++){
    totalCarga += bateries[i]->getTotalCharge();
  }
  return totalCarga;
}
