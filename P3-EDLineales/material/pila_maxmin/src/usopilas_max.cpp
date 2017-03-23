#include <iostream>
#include "Pila_maxmin.h"

using namespace std;

int main(){

  Pila_maxmin<int> p;
  int i;

  for ( i=10; i>=0 ; i--) 
    p.Poner(i);

  while ( !p.Vacia() ){
    elemento<int> x = p.Tope();
    cout << x << endl;
    p.Quitar();
  }     
  
  return 0;
}
