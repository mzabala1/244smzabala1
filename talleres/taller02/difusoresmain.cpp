



#include <iostream>
#include "Difusores.cpp"

using namespace std;
int main(void){
  DifusorBivalenteCentral* dbc1 = new DifusorBivalenteCentral(2,2,4);

  if(dbc1->potenciaDifusion(2))
    cout << "verdadero" << endl;

 DifusorBivalenteCentral dbc2 =
   DifusorBivalenteCentral(2,2,4);

  if(dbc2.potenciaDifusion(1 ))
    cout << "verdadero" << endl;

  delete dbc1;


}
