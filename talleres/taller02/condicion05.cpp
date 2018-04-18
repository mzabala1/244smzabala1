#include <iostream>

using namespace std;

int main(){

int a;
int b;
int c;

cin>>a>>b>>c;
  
if(a!=b){
    if(b!=c){
      if(a!=c){
	cout << "escaleno" << endl;
      }else{
	cout << "isoceles" << endl;
      }
           
    }else{
      cout << "isoceles" << endl;
    }
  }else{

    if(b==c){
      cout << "equilatero" << endl;
    
    }else{
      cout <<"isoceles"<<endl;
    }
  }
  return 0; 
}
