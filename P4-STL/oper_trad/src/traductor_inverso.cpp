#include "traductor.h"
#include <fstream>
#include <iostream>
using namespace std;


void GetTraductorInverso(const Traductor & t_origen, Traductor & t_destino) {

  Traductor :: const_iterator it;

  for ( it = t_origen.cbegin() ; it != t_origen.cend() ; ++it ) {

    Frase :: const_iterator it_f;

    //Recorremos sus frases
    for ( it_f = (*it).second.cbegin() ; it_f != (*it).second.cend(); ++it_f ) {
      Frase inversa; 
      inversa.SetOrigen((*it_f)); // Ahora cada traduccion, es un nuevo origen
      inversa.Push_Back((*it).first); // A esa nueva, le insertamos su antiguo origen, que ahora es su traduccion
      t_destino.Insert(inversa); // Una vez modificada la nueva frase, se inserta en el traductor
    }  
  }
}


void ImprimeTraductor(const Traductor &T,ostream &os){
   Traductor::const_iterator it;
   for (it=T.cbegin(); it!=T.cend();++it){ 
       os<<(*it).first<<";"; 
       Frase::const_iterator it_d;  
       for (it_d=(*it).second.cbegin(); it_d!=(*it).second.cend();++it_d)  
	       os<<(*it_d)<<";";
       os<<endl;
   }
}   


int main (int argc, char * argv[]) {

  if (argc!=2 && argc!=3){
    cout<<".-Dime el nombre de fichero del traductor origen"<<endl;
    cout<<".-[opcionalmente] El nombre de fichero del traductor destino"<<endl;
    return 0;
  }

  ifstream f (argv[1]);
  if (!f){
    cout<<"No puedo abrir el fichero "<<argv[1]<<endl;
    return 0;
  }
   
  Traductor t_ori;
  f>>t_ori; //Cargamos en memoria, en el traductor.
  Traductor t_des;
   
  GetTraductorInverso(t_ori,t_des);
   
  if (argc==2)
    ImprimeTraductor(t_des,cout);
  else {
    ofstream fout(argv[2]);
    if (!fout){
      cout<<"No puedo crear el fichero "<<argv[2]<<endl;
      return 0;
    }
    
    ImprimeTraductor(t_des,fout);
   }
}