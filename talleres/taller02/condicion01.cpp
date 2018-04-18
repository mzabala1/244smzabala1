#include <iostream>

using namespace std;

int main() {
  int c;
 
  if(cin >> c == 0){
    cout >> "El usuario digito un valor de cero" << endl;
  }
  else {
    cout << "El usuario digito un valor diferente de cero" << endl;
  }

  return 0;
}
