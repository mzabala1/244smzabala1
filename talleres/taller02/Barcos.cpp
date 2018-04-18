#include <iostream>
#include "Barcos.h"
#include <string>
#include "INaves.h"

using namespace std;

Barco::Barco(string id):
  id(id)
{}

string Barco::obtId(){
  return id;
}

Portaviones::Portaviones(string id):
  Barco(id)
{}

Fragata::Fragata(string id):
  Barco(id)
{}

Lancha::Lancha(string id):
  Barco(id)
{}




