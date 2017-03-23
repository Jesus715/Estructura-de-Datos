 /**
  * @file sumar.cpp
  * @author Jesus Ruiz Castellano
  * @date 11 de Diciembre de 2016, 22:18
  * @brief Programa Sumar dos Traductores :
  *        
  *        Dados dos traductores, con la condición que sean o bien se correspondan con el mismo idioma
  *        origen y destino. Obtener el traductor suma, como la unión de los dos traductores.
  *           
  *        Los parámetros son los siguientes:
  *            1. El nombre del fichero con el primer traductores a sumar
  *            2. El nombre del fichero con el segundo traductor a sumar
  *            3. El nombre del fichero del traductor salida.
  * 
  *        Como ejemplo para poder ejecutar este programa el alumno puede crear con los ficheros
  *         frases_español_frances.txt
  *         frases_frances_español.txt, puede en primer lugar crear el
  *         traductor inverso de frases_español_frances y a continuacion hacer la suma con
  *         frases_frances_español.txt.
  *        
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
        os << (*it_d) << ";";
    
    os << endl;
    }
}   


int main ( int argc, char * argv[] ) {

  // ******************************* Lectura de ficheros *******************************
  if ( argc != 4 ) {
      cout << "\n Para ejecutar, la Sintaxis es :" << endl;
      cout << " ./bin/sumar [Parametro1] [Parametro2] [Fichero_Resultado]" << endl
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

  Traductor Tuno, Tdos, Tsuma;
  int c;

  fin >> Tuno;
  f2in >> Tdos;

  // ******************************* Filtro *******************************
  do {
    
    cout << "\n Por favor, indique cuantas coincidencias hay en los ficheros : "
         << "\n > Si coinciden en ambos idiomas, teclee '2'"
         << "\n > Si coinciden solo origen de uno y destino de dos, teclee 1" 
         << "\n Coincidencias : ";
    
    cin >> c;
    cout << endl;

  } while ( c != 1 && c != 2 );

  

  // ******************************* Resolucion del problema *******************************

  /* Si coinciden en origen y destino, lo unico que hay que hacer es insertar Tuno y 
     Tdos a Tsuma, primero uno y luego otro, en orden */
  if ( c == 2 ) {

    Traductor :: const_iterator it;

    for ( it = Tuno.cbegin() ; it != Tuno.cend() ; ++it )
      Tsuma.Insert((*it).second);

    Traductor :: const_iterator otro;
    for ( otro = Tdos.cbegin() ; otro != Tdos.cend() ; ++otro )
      Tsuma.Insert((*otro).second);
  
  } else { // En caso contrario, se le da la vuelta a Tdos y se opera igual que antes

    Traductor Taux;
    GetTraductorInverso (Tdos,Taux);

    Traductor :: const_iterator it;
    for ( it = Tuno.cbegin() ; it != Tuno.cend() ; ++it )
      Tsuma.Insert((*it).second);

    Traductor :: const_iterator otro;
    for ( otro = Taux.cbegin() ; otro != Taux.cend() ; ++otro )
      Tsuma.Insert((*otro).second);

  }

  // ******************************* Impresion de la solucion *******************************

  ofstream fout (argv[3]);
  if ( !fout ) {
    cout << " No puedo crear el fichero resultado " << argv[3] << endl;
    return 0;
  }

  ImprimeTraductor (Tsuma,fout);

}