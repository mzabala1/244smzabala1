/*
 * fichero: condicion06.cpp
 * compilar: $ g++ -o condicion06 condicion06.cpp
 * ejecutar: $ ./condicion06
 */

#include <iostream>

using namespace std;

int main(){
  char c[3];
  cin >> c;

  if(c[0] == 'a' || c[0] == 'c' || c[0] == 'e' || c[0] == 'g'){
    if(c[1] % 2 == 0){
      cout << "Negro" << endl;
    }else{
      cout << "Blanco" << endl;
	}
  }
  
  if(c[0] == 'b' || c[0] == 'd' || c[0] == 'f' || c[0] == 'h'){
    if(c[1] % 2 == 0){
      cout << "Blanco " << endl;
    }else {
      cout << "Negro " << endl;
    }
  }
  
  return 0;
}

