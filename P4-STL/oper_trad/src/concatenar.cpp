 /**
  * @file concatenar.cpp
  * @author Jesus Ruiz Castellano
  * @date 11 de Diciembre de 2016, 22:18
  * @brief Programa Concatenación de Traductores :
  *        
  *        Dados dos traductores, cada uno con su idioma origen e idioma destino, el objetivo de este
  *        programa es obtener el traductor que surge del idioma origen del primer traductor al idioma
  *        destino del segundo traductor. Así por ejemplo si los dos traductores de partida son
  *        frases_ingles_español y frases_español_frances al concatenar obtendremos el traductor
  *        de frases_ingles_frances
  *           
  *        Los parámetros son los siguientes:
  *            1. El nombre del fichero con el primer traductores a concatenar
  *            2. El nombre del fichero con el segundo traductor a concatenar
  *            3. El nombre del fichero del traductor salida.
  * 
  */

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

  for ( it = T.cbegin() ; it != T.cend() ; ++it ) { 
    
    os << (*it).first << ";"; 
    Frase :: const_iterator it_d;  
    
    for ( it_d = (*it).second.cbegin() ; it_d != (*it).second.cend() ; ++it_d )  
      if ( it_d != (*it).second.cend() )
        os << (*it_d) << endl;
      else
        os << (*it_d) << ";";
    
    os << endl;
    }
}   


int main ( int argc, char * argv[] ) {

// ******************************* Lectura de ficheros *******************************
  if ( argc != 4 ) {
      cout << "\n Para ejecutar, la Sintaxis es :" << endl;
      cout << " ./bin/concatenar [Parametro1] [Parametro2]" << endl
           << "\n Parametros : " << endl
           << " 1. ./datos/frases_origen1_destino1" << endl
           << " 2. ./datos/frases_origen2_destino2" << endl
           << " 3. FICHERO RESULTADO => ./datos/frases_origen1_destino2" << endl << endl;
      return 0;
  }    
    
  ifstream fin (argv[1]);
  if ( !fin ) {
      cout << " No puedo abrir el primer fichero " << argv[1] << endl;
      return 0;
  }

  ifstream f2in (argv[2]);
  if ( !f2in ) {
      cout << " No puedo abrir el segundo fichero " << argv[2] << endl;
      return 0;
  }

  Traductor Tuno, Tdos, Tconcatena;

  fin >> Tuno;
  f2in >> Tdos;



  Traductor :: const_iterator it;

  for ( it = Tuno.cbegin() ; it != Tuno.cend() )





  // ******************************* Impresion de la solucion *******************************

  ofstream fout (argv[3]);
  if ( !fout ) {
    cout << " No puedo crear el fichero resultado " << argv[3] << endl;
    return 0;
  }

  ImprimeTraductor (Tconcatena,fout);