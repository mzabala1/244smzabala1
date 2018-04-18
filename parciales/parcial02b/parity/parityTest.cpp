#include "parityTest.h"
#include "string"
#include <iostream>

using namespace std;


Parity parityTest(const char word[], int& nEven, int &nOdd) {

  string ent = word;
  
  for(int i=0; i<ent.size(); i++){
    if(isOddParity(ent.at(i))){
      nOdd++;
    }
    else{
      nEven++;
    }
  }

  Parity paridad;

  if(nOdd > nEven){
    paridad = odd;
  }
  else if(nEven > nOdd){
    paridad = even;
  }
  else if(nOdd == nEven){
    paridad = none;
  }

  return paridad;
}
