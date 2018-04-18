#include <iostream>
#include "Barcos.h"
#include <vector>
#include "Marina.h"

using namespace std;

vector<Barco> Armada::obtenerBarcos(){
  return barcos;
}

void Armada::registrarBarco(Barco barco){
  barcos.push_back(barco);
}

void ArmadaMarina::registrarBarco(Barco barco){
  Armada::registrarBarco(barco);
}

void ArmadaFluvial::registrarBarco(Barco barco){
  Armada::registrarBarco(barco);
}
