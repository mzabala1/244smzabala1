#include "intercalate.h"

int*
intercalate(const int arr1[],
	    const int arr2[],
	    const int nbr,
	    const int fact) {


  int* arreglo1 = new int[nbr];

  int iterate = nbr/fact;

  if(iterate == 1){
    for(int i=0; i<nbr; i++){
      arreglo1[i] = arr2[i];
    }
    return arreglo1;
  }
   
    
  for(int i=0; i<iterate; i++){
    if(i%2 == 0){
      for(int j=0; j<fact; j++){
	arreglo1[i*fact+j] = arr2[i*fact+j+fact];
      }
    }
    else{
      for(int k=0; k<fact; k++){
	arreglo1[i*fact+k] = arr1[i*fact+k-fact];
      }
    }
  }
  return arreglo1;
}
