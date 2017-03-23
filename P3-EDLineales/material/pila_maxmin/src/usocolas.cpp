#include <iostream>
#include <Cola_maxmin.h>

using namespace std;

int main() {
	
  Cola_maxmin<int> p;

  for ( int i = 0 ; i < 10 ; i++) 
    p.poner(i);
   
  elemento<int> x = p.frente();
  cout << x << endl;
     
  p.quitar();

  elemento<int> y = p.frente();
  cout << y << endl;
 
  cout << p.num_elementos() << endl;
  
  
  Cola_maxmin<float> q;
  
  
  for ( int j = 0 ; j < 10 ; j++) 
    q.poner(j/10.0);
   
  elemento<float> z = q.frente();
  cout << z << endl;
     
  q.quitar();

  elemento<float> w = q.frente();
  cout << w << endl;
  
  cout << q.num_elementos() << endl;

  return 0;
}
