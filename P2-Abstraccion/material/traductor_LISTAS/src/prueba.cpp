#include <iostream>
//#include "frases.h"
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;






class Frase {
private:

  static int TAM = 5;
  int ocupadas;
  string origen;
  string[TAM] cadTraducciones;

  bool Invariante ();
  void MoreSize ();

public:


















int main (int argc, char * argv[]) {
 /* if (argc!=2){
      cout<<"Los parametros son:"<<endl;
      cout<<"1.Dime el nombre del fichero con las frases "<<endl;
      return 0;
  }    
  
  ifstream fin(argv[1]);
  if (!fin){
      cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
      return 0;
  }

  Frase Nueva;

 
  if (&Nueva == 0)
    cout << "ERROR EN CREACION DE FRASE" << endl;
  else
    cout << "ACIERTO : numero de traducciones  = " << Nueva.NumTraducciones() << endl;
*/

  struct Traduc {

    string traduccion;
    Traduc* siguiente;
  };

  string origen;
  Traduc* cadTraducciones;

  origen = "que dise perdise";

  cadTraducciones->traduccion = "que pasa blasa";
  cadTraducciones->siguiente = 0;

  string ya;
  ya = cadTraducciones->traduccion; 

  for ( unsigned int i = 0 ; i < ya.length() ; i++ )
    cout << ya[i];
}