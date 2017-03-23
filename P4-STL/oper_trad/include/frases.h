 /**
  * @file frases.h
  * @author Jesus Ruiz Castellano
  * @date 07 de Diciembre de 2016, 17:54
  * @brief Fichero cabecera del TDA Frase
  *  
  */

#ifndef _FRASE_H
#define _FRASE_H


#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;


 /**
  * @brief T.D.A. Frase
  *
  */ 

class Frase {
private:

 /**
  * @page TDAFRASE TDA Frase
  *
  * @section esTDAFRASE Especificacion 
  * Una instancia @e c del tipo de dato abstracto @c Frase es un objeto
  * que mantiene la informacion de una frase "hecha" en el idioma origen, 
  * y todas las posibles traducciones en el idioma destino.
  *
  *   Ejemplo:
  *
  *   No worries;Sin problema;No te preocupes
  *
  * @section invTDAFRASE Invariante de la representación
  * - rep.frase.second.size() >= 1, a excepcion del momento de creacion del objeto, 
  *   que estara vacio completamente
  * - rep.frase.second[i] != rep.frase.second[j], i != j, es decir,
  *   No hay traducciones repetidas
  * 
  *
  * @section faTDAFRASE Función de abstracción
  *
  *    Un objeto valido @e rep del TDA Frase representa al valor:
  * 
  *    fa(rep) = rep.frase.first;rep.frase.second[0];...;rep.frase.second[i];...;rep.frase.second[rep.frase.second.size()-1];
  *             
  * 
  */
  	
	pair<string,vector<string> > frase; /**< origen y cada una de las traducciones destino */

public:
 
  /**
  * @brief Metodo auxiliar que modifica el origen
  * @param nuevo : nuevo origen
  * @post ES MODIFICADA
  */
  void SetOrigen ( string nuevo ) { frase.first = nuevo; }

  /**
  * @brief Inserta una nueva traduccion
  * @param traduc : La traduccion a insertar
  * @post ES MODIFICADA
  */
  void Push_Back ( string traduc );
  
  
 /**
  * @brief Sobrecarga del Operador>> 
  * @param flujo: stream de entrada
  * @param F: Frase que recibe los parametros
  * @return la referencia al istream
  */
	friend istream& operator>> ( istream& flujo, Frase& F );  


 /**
  * @brief Numero de traducciones
  * @return El numero de traduciones que contiene la frase origen
  * @post No se modifica
  */
	int NumTraducciones () const { return frase.second.size(); }


 /**
  * @brief Obtencion de la frase origen
  * @return El string origen
  * @post No se modifica
  */
	string GetOrigen () const { return frase.first; }


 /**
  * @brief Obtencion de las traducciones
  * @return El vector con todas las traducciones
  * @post No se modifica
  */
  vector<string> GetDestino() const { return frase.second; }


 /**
  * @brief clase para iterar sobre la frase
  */
  class iterator {
  private:
  
    vector<string> :: iterator it;
  
  public:
  
    iterator & operator++ () { ++it; return *this; }
    iterator & operator-- () { --it; return *this; }
    string & operator* () { return *it; }
    bool operator == ( const iterator &i ) { return i.it == it; }    
    bool operator != ( const iterator &i ) { return i.it != it; }
    friend class Frase;
  };


 /**
  * @brief Inicializa un iterator a la primera traduccion
  */
 iterator begin () {
    iterator i;
    i.it = frase.second.begin();
    return i;
  }

 /**
  * @brief Inicializa un iterator al final de las traducciones
  */
  iterator end () {
    iterator i;
    i.it = frase.second.end();
    return i;
  }


 /**
  * @brief clase constante para iterar sobre la frase
  */
  class const_iterator {
  private:
  
    vector<string> :: const_iterator cit;
  
  public:
  
    const_iterator & operator++ () { ++cit; return *this; }
    const_iterator & operator-- () { --cit; return *this; }
    const string & operator* () { return *cit; }
    bool operator == ( const const_iterator &ci ) { return ci.cit == cit; }    
    bool operator != ( const const_iterator &ci ) { return ci.cit != cit; }
    friend class Frase;
  };


 /**
  * @brief Inicializa un iterator constante a la primera traduccion
  */
  const_iterator cbegin () const {
    const_iterator i;
    i.cit = frase.second.begin();
    return i;
  }
 

 /**
  * @brief Inicializa un iterator constante a la ultima traduccion
  */
  const_iterator cend () const {
    const_iterator i;
    i.cit = frase.second.end();
    return i;
  }  

};
#endif	