#include <iostream>

#include "Lampara.h"

using namespace std;

Lampara::Lampara():
  prendida(false),
  nivel(0)
{}

float Lampara::obtNivelEnergia(){
  return nivel;
}

bool Lampara::estaPrendida(){
  return prendida;
}

Lampara::~Lampara(){};

void Lampara::consumir(float nivel){

    this->nivel=this->nivel-nivel;
}

void Lampara::cargar(float nivel){
  this->nivel=this->nivel+nivel;
}

void Lampara::prender(){
  prendida = true;
}

void Lampara::apagar(){
  prendida = false;
}

int
main(){
 Lampara* l = new Lampara();
  l->cargar(10);
  cout << "Nivel inicial: " << l->obtNivelEnergia() << endl;
  l->consumir(4);
  cout << "Nivel final: "<< l->obtNivelEnergia()<<endl;
  l->prender();
  if(l->estaPrendida()){
    cout<<"Esta prendida"<<endl;
  }else{
    cout<<"Esta apagada"<<endl;
  }

  Lampara l2 = Lampara();

  l2.cargar(10);
  l2.cargar(10);
  l2.prender();
  l2.consumir(8);

  cout << l2.obtNivelEnergia()<< endl;
  if(l2.estaPrendida())
    cout<<"Estoy prendida"<<endl;

  delete l;
}
