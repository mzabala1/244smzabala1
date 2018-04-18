#include <iostream>
#include "Difusores.h"

using namespace std;

Difusor::Difusor(float anguloDifusion):
  anguloDifusion(anguloDifusion)
{}

Difusor::~Difusor(){}

float Difusor::obtAnguloDifusion(){
  return anguloDifusion;
}

void Difusor::estAnguloDifusion(float anguloDifusion){
  anguloDifusion = anguloDifusion;
}

DifusorCentral::DifusorCentral(float difusorCentral,
			       float anguloDifusion):
  Difusor(anguloDifusion),
  difusorCentral(difusorCentral)
{}
DifusorCentral::~DifusorCentral(){}

void DifusorCentral::establecerDifusorCentral(float difusorCentral)
{  
  difusorCentral=difusorCentral;
}

bool DifusorCentral::potenciaDifusion(float potencia){
  if((obtAnguloDifusion()+
      difusorCentral)==potencia){
    return true;
  }else{
    return false;
  }
}

DifusorBivalente::DifusorBivalente(float anguloPos,
				   float anguloDifusion):
  anguloPos(anguloPos),
  Difusor(anguloDifusion)
{}
DifusorBivalente::~DifusorBivalente(){}

void DifusorBivalente::estAnguloPos(float anguloPos)  
{
  anguloPos=anguloPos;
}

float DifusorBivalente::obtAnguloPos(){
  return anguloPos;
}

DifusorBivalenteCentral::DifusorBivalenteCentral(float anguloDifusion, float anguloPos,
						 float difusorBiC):
  DifusorBivalente(anguloPos,anguloDifusion),
  difusorBiC(difusorBiC)
{}


DifusorBivalenteCentral::~DifusorBivalenteCentral(){}

void DifusorBivalenteCentral::establecerDifusorBiC(float difusorBiC)
{
  difusorBiC=difusorBiC;
}

bool DifusorBivalenteCentral::potenciaDifusion(float potencia){
  if((obtAnguloDifusion()+obtAnguloPos())== 2*(difusorBiC-potencia)){
    return true;
  }else{
    return false;
  }
}
