#include <iostream>
#include <string>

using namespace std;

int
main() {
  /*
   * Inserte el codigo en C++ que procese lineas largas y las
   * convierta en una sola linea.
   */
  
  const int MAXBUF = 256;
  string linea="";
  string lineas[MAXBUF];
  
  while(true){
    char linea[MAXBUF];
    string str;
    cin.getline(linea,MAXBUF);
    
    string = linea;
    int tamano = str.size();
    if(tamaño>0){
      if(str.at(tamano-1)=='\\'){
	linea.append(string.substr(0,tamano-1));
      }else if(){
	linea.append(string.substr(0,tamano));
	linea.append("\n");
      }else{
	linea.append(string.substr(0,tamano));
	linea.append("\n");
      }   
    }
    /*
     * Inserte el codigo en C++ que procese lineas largas y las
     * convierta en una sola linea.
     */
  }

  cout<<linea<<endl;
  
  return 0;
}
