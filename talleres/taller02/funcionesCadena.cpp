#include <iostream>
#include "funcionesCadena.h"

using namespace std;

char* saltarblancosinicio(char* s){
  int n = sizeof(s)/sizeof(char);

  for (int i=0;i<n;i++){
    if (s[i] == ' '){
      s[i] == '\0';
    }
    else{
      return &s[i];
    }
  }
}

const char* indiceAlaDerecha(const char* s, int c){

  const char* dir;
  int i=0;
  while(s[i]!='\0'){
    if (s[i] == c)
      dir = &s[i];
    i++;
  }
  
  return dir;
}

int
main(void){
  char cadena[256];

  cin >> cadena;

  cout << saltarblancosinicio(cadena) << endl;

  cout << indiceAlaDerecha(cadena,97)<<endl;
  
}
