	/**
  * @file frases.cpp
  * @author Jesus Ruiz Castellano
  * @date 19 de Octubre de 2016, 12:23
  * @brief Fichero .cpp con la implementacion correspondiente al fichero 
  *        frases.h 
  * 
  */

#include "frases.h"
using namespace std;


istream& operator>> ( istream& flujo, Frase& F ) {


  if ( flujo.peek() != EOF ) { // Para asegurarnos no meter basura en caso de llegar al final del fichero
    // Almacenamiento de frase origen: Leo hasta el primer ';' y lo guardo en F.origen 
    getline (flujo, F.origen, ';');

    // Leere hasta el salto de linea. Por eso declaro una bandera.
    bool finLinea = false;

    string traduccion;

    getline (flujo, traduccion);
    
    int chivato = traduccion.find(';'); // Me dira si hay mas de una traduccion


    if ( chivato < 0 ) {
      // Si traduccion solo contiene una oracion, la inserto y termino.
      F.Push_Back(traduccion);
      finLinea = true;
    }  

    else 
      while ( !finLinea ) {

        string trad = traduccion.substr(0,chivato); // cojo desde la primera posicion, todas las que marca distancia
        F.Push_Back(trad);

        string trad2 = traduccion.substr(chivato+1); // desde el ';' hasta el salto de linea
        int SigChivato = trad2.find(';');

        // vuelvo a comprobar si hay mas traducciones
        if ( SigChivato < 0 ) {
          F.Push_Back(trad2);
          finLinea = true;  
        }
        // Si hay mas, hago avanzar el puntero al Siguiente ;
        else {
          chivato = SigChivato;
          traduccion = trad2;
        }

      }
  }

  return flujo;
}  


ostream& operator<< ( ostream& flujo, Frase& F ) {

  if ( F.origen != "" ) {
    flujo << F.origen << ";";

    /* Imprime la frase tal cual viene en el fichero, es decir, 
       Si antes de alguna traduccion hay un caracter "espacio", lo aniade tambien */
    for ( unsigned int i = 0 ; i < F.cadTraducciones.size() ; i++ ) {
      // Hay que distinguir entre las traducciones de enmedio y la ultima
      if ( i < F.cadTraducciones.size()-1 )
        flujo << F.cadTraducciones[i] << ";";
      // En caso de ser la ultima traduccion, se aniade el salto de linea
      else
        flujo << F.cadTraducciones[i] << endl;
    }
  }
  return flujo;
}


void Frase :: Push_Back ( string traduc ) { 

  bool repetida = false;

  // Para cumplir la restriccion de que no haya traducciones repetidas
  for ( int  i = 0 ; i < NumTraducciones() ; i++ ) 
    for ( int j = i+1 ; j < NumTraducciones() ; j++ ) 
      if ( cadTraducciones[i] == cadTraducciones[j] )
        repetida = true;      
    
  if ( !repetida )
    cadTraducciones.push_back(traduc);       
  
}

