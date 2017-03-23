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


bool Frase :: Invariante () const {

  if ( origen != "" && nTraduc >= 1 )
    for ( Traduc* i = primera ; i->sig != ultima && inv ; i = i->sig )
      for ( Traduc* j = i->sig ; j->sig != ultima && inv ; j = j->sig ) 
        if ( i->traduccion == j->traduccion )
          return false;

    return true;
}


void Frase :: Copiar ( const Frase& F ) {

    origen = F.origen;
    nTraduc = F.nTraduc;

    if ( F.primera == 0 )
      primera = 0;

    else {

      primera = new Traduc;
      primera->traduccion = F.primera->traduccion;

      Traduc* p = primera;
      Traduc* q = F.primera->sig;
   
      while ( q =! 0 ) { 
        p->siguiente = new Traduc;
        p = p->sig;
        p->traduccion = q->traduccion;
        q = q->sig;
        
      }
   
      p->sig = 0;
    }
}


void Frase :: Borrar () {

  while ( primera != 0 ) {
    
    Traduc* aux = primera;
    primera = primera->sig;
    delete [] aux;
  }
}

Frase :: Frase ( const Frase& F ) {

  if ( Invariante() ) {

    Copiar(F);
  }
}


Frase& Frase :: operator= ( const Frase& F ) {

  if ( Invariante() && this != &F ) {

    Borrar();
    Copiar(F); 
  }

  return *this;
}

 
Frase :: ~Frase () {
    
    Borrar();
}


string& Frase :: operator[] ( int i ) {

  assert( i >= 0 && i < nTraduc );
  Traduc* aux = primera;
  int j = 0; // contador

  while ( aux != 0 && j <= i ) {
    aux = aux->sig;
    j++;
  }

  return aux->traduccion;
}


const string& Frase :: operator[] ( int i ) const  {
  assert( i >= 0 && i < nTraduc );
  return cadTraducciones[i];
}


bool Frase :: operator== ( const Frase& F2 ) const {

  // comprobamos si los 2 origenes tienen la misma longitud
  if ( origen.length() == F2.origen.length() ) { 
    // creamos variables locales para no modificar
    string ori = origen;
    string oriF2 = F2.origen; 
    // Recorremos los caracteres del origen de this, y tambien me vale para F2, ya que tienen la misma longitud
    for ( unsigned int i = 0 ; i < origen.length() ; i++ ) {
      ori[i] = toupper ( ori[i] );       // Los pasamos a mayuscula ( tolower para minuscula )
      oriF2[i] = toupper ( oriF2[i] );   // Se pasan los caracteres a mayuscula de F2
    }
    // Comprobamos si son el mismo origen, una vez pasados a mayuscula
    if ( ori == oriF2 )
      // Ahora, comprobamos si tienen el mismo numero de traducciones
      if ( nTraduc == F2.nTraduc ) {
        // Creamos traducciones locales igual que con los origenes
        Traduc* traduc = new Traduc [nTraduc]; 
        Traduc* traducF2 = new Traduc [nTraduc];
        
        // Hacemos una copia para no tocar donde no debemos en las variables originales
        for ( int i = 0 ; i < nTraduc ; i++ ) {
          traduc[i] = cadTraducciones[i];
          traducF2[i] = F2.cadTraducciones[i];
        }
        // Recorremos todas las traducciones de la frase privada y F2
        for ( int i = 0 ; i < nTraduc ; i++ ) 
          if ( traduc[i].length() == traducF2[i].length() )  
            // Recorremos todos los caracteres de las traducciones en la posicon i de ambas frases
            for ( unsigned int j = 0 ; j < traduc[i].length() ; j++ ) {
                // Y los pasamos a mayuscula, almacenandolas en variables locales
              traduc[i][j] = toupper (traduc[i][j]);
              traducF2[i][j] = toupper (traducF2[i][j]);
            }

        // Variable para comparar las coincidencias
        int CoincidenTraduc = 0; 
        
        for ( int i = 0 ; i < nTraduc ; i++ )         
          for ( int j = 0; j < nTraduc ; j++ )
            if ( traduc[i] == traducF2[j] ) // Ahora se comparan una vez pasadas a mayuscula
              CoincidenTraduc ++; 
            
        if ( CoincidenTraduc == nTraduc ) // Permite que haya n-1 traducciones iguales
          return true;

        delete [] traduc;
        delete [] traducF2;
      }
  }
  return false;
}


void Aniade ( string tra ) {

  Traduc* i = cadTraducciones ;

  while ( i->siguiente != 0 ) 
    i = i->siguiente;
  
  i->siguiente

}


istream& operator>> ( istream& flujo, Frase& F ) {

  // Almacenamiento de frase origen: Leo hasta el primer ';' y lo guardo en F.origen 
  getline (flujo, F.origen, ';');

  // Leere hasta el salto de linea. Por eso declaro una bandera.
  bool finLinea = false;
  // int tamanio = 0; // contador para ver cuanto leemos 
  char siguiente = F.cadTraducciones.traduccion[0]; // Para que no tenga un caracter aleatorio

  cout << "\n CHECK 0 :: Entra :: " << endl;

  while (flujo && !finLinea) {

    string tradu;

    getline (flujo, tradu);
    
    int chivato = tradu.find(';'); // Me dira si hay mas de una traduccion

    if ( chivato < 0 ) {
      // Si traduccion solo contiene una oracion, la inserto y termino.
      F.cadTraducciones.Aniade(tradu);
      finLinea = true;
    }  

    else {

      cout << "prueba :: traduccion = ";
      for ( unsigned int i = 0 ; i < traduccion.size() ; i++ )
        cout << traduccion[i];
      cout << endl;
      string trad = traduccion.substr(0,chivato-1);

    }
  }


  return flujo;
}  

 





ostream& operator<< ( ostream& flujo, Frase& F ) {

  flujo << F.origen << ";";

  /* Imprime la frase tal cual viene en el fichero, es decir, 
     Si antes de alguna traduccion hay un caracter "espacio", lo aniade tambien */
  for ( int i = 0 ; i < F.nTraduc ; i++ ) {
    // Hay que distinguir entre las traducciones de enmedio y la ultima
    if ( i < F.nTraduc-1 )
      flujo << F.cadTraducciones[i] << ";";
    // En caso de ser la ultima traduccion, se aniade el salto de linea
    else
      flujo << F.cadTraducciones[i] << endl;
  }

  return flujo;
}


