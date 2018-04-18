#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <cstring>
#include "calcex.h"
#include "calculator.h"


using namespace std;

Calculator* calc;

const int MAXBUF = 256;

//al hacerlo con la forma interactiva evita que cuando ya no existan mas lineas por leer en el archivo se pidan mas.

int main(int argc, char* argv[], char* env[]) {
  string line;
  bool prefEnv = false;
  string files[argc];
  string asigVar[argc/2];
  string asigVarEnv[100];
  int contAsignEnv = 0;
  int contFiles = 0;
  int contVariables = 0;
  int cont = 1;
  bool interactive = true;

  calc = new Calculator();

  //Comandos -e (env) y -v (var)
  
  while(cont<argc){

    string comandoEnv = argv[1];

    string comando = argv[cont];

    if(comandoEnv=="-e"){
      prefEnv = true;
    }
    if(comando=="-v"){
      asigVar[contVariables] = argv[cont+1];
      cont = cont + 2;
      contVariables++;
    }else{
      (files[contFiles] = comando);
      contFiles++;
      cont++;
    }

  }
  
  if(contVariables>0){
    for (int i=0; i<contVariables; i++){
      calc->eval(asigVar[i]);

    }
    calc->clearAssigns();
  }

  //Variables de ambiente, antepongo "CALCVAR" y se toma como una condicion para tomarla como variable de am\
  biente si hay un -e (env) se prefieren


    for (int i = 0; env[i] != NULL; i++) {
      string calcvar = "CALCVAR";
      string env1 = env[i];

      if(env1.substr(0,7)==calcvar){
	string expr = env1.substr(7,env1.size()-7);
	//expr.find_first_of, busca a través de una cadena para el primer carácter que coincide con cualquier elemento de una cadena especificada.
	int pos = expr.find_first_of("=");
	string nomVar = expr.substr(0,pos);

	if(prefEnv and calc->isDef(nomVar)){
	  calc->eval(expr);
	}else if(!calc->isDef(nomVar)){
	  calc->eval(expr);
	}
      }

    }

  calc->clearAssigns();

  //lectura de ficheros
  if(contFiles>0){
    interactive = false;
    
    for(int i=0; i<contFiles; i++){
      string buffer;
      char* file1 = new char[files[i].length()+1];

      //c_str(), lo que hace es convertir un string en un puntero a char (el primer elemento del arreglo), para mejor manejo en el string del file
      //Copia a files[i].c_str() en file

      strcpy(file1, files[i].c_str());
      ifstream filein(file1);

      delete [] file1;

      while(getline(filein,buffer)){
	try {
	  string buffer2(buffer);
	  istringstream ins(buffer2);
	  ins >> line;

	  if(buffer!=""){
	    int result = calc->eval(buffer);

	    vector<string> assigns = calc->getAssigns();

	    if(!assigns.empty()){
	      cout << "=> " << result <<" [";
	      for(int i=0; i<assigns.size(); i++){
		if(i+1!=assigns.size()){
		  cout << assigns.at(i) << ", ";
		}else{
		  cout << assigns.at(i);
		}
	      }
	      cout << "]"<< endl;


	    }else{
	      cout << "=> "<< result<<endl;
	    }

	    calc->clearAssigns();

	  }else{

	    cout << "ParseError, needed an expresion" << endl;
	  }

	}
	catch(Exception ex) {
	  cout << "Program Aborted due to exception" << endl;

	}
      }
    }
    calc->clearAssigns();
  }


  //entra en modo interactiva
    
    if(interactive){
      do{
	try {
	  cout << "> ";

	  getline(cin, line);
	  // line + '\n';
	  if(cin.eof()){
	    break;
	  }

	  if(line != ""){

	    int result = calc->eval(line);
	    vector<string> assigns = calc->getAssigns();

	    if(!assigns.empty()){
	      cout << "=> " << result << " [";
	      for(int i=0; i<assigns.size(); i++){
		if(i+1 != assigns.size()){
		  cout << assigns.at(i)<< ", ";
		}else{
		  cout << assigns.at(i);
		}
	      }
	      cout << "]"<<endl;
	    }else{
	      cout << "=> "<< result << endl;
	    }

	    calc->clearAssigns();

	  }else{
	    cout << "ParseError, needed an expresion"<< endl;
	  }
	}catch(Exception ex) {
	  cout << "Program Aborted due to exception" << endl;
	}
    
      }while(true);
    }
    delete calc;
}
