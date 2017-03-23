/**
  * @file traductor.h
  * @author Jesus Ruiz Castellano
  * @date 07 de Diciembre de 2016, 17:55
  * @brief Fichero cabecera del TDA Traductor
  *  
  */

#ifndef _TRADUCTOR_H
#define _TRADUCTOR_H


#include <string>
#include <map>
#include <utility>
#include <iostream>
#include <cassert>
#include "frases.h"

using namespace std;


 /** 
  * @brief T.D.A. Traductor
  *
  */

class Traductor {
private:

 /**
  * @page Conjunto TDA Traductor
  *
  * @section esConjunto Especificacion
  * Una instancia @e c del tipo de dato abstracto @c Traductor es un 
  * objeto que contiene una sucesion de frases leidas desde un fichero,
  * o cualquier entrada posible. 
  *
  * Ejemplo : 
  *
  *    <br>Not Bad;No esta mal</br> 
  *    <br>Not for nothing;No es por nada </br>
  *    <br>Not half;Ya lo creo </br>
  *    <br>Not half;Por supuesto </br>
  *    <br>Not my business;No es asunto mio </br>
  *    <br>... </br>
  *
  * @section invConjunto Invariante de la representación
  *  - rep.ConjF[i].GetOrigen() != rep.ConjF[j].GetOrigen(), Para todo i,j => i!=j, 
  *    es decir, no habrá frases repetidas, frases con el mismo campo origen. 
  *  - rep.ConjF.size() >= 1. Excepto en el momento de creación de un objeto de tipo 
  *	   Traductor, este objeto siempre contendrá, al menos, 1 Frase.
  *
  * @section faConjunto Función de Abstracción
  *
  *    Un objeto valido @e rep del TDA Traductor representa al valor:
  * 
  *    <br>fa(rep) =              </br>
  *	   <br> 	       rep.ConjF[0];</br>
  *    <br>          rep.ConjF[1];</br>
  *    <br>               ...	    </br>
  *    <br>          rep.ConjF[i];</br>
  *    <br>               ...	    </br>
  *    <br>          rep.ConjF[rep.ConjF.size()-1];</br>
  *
  */

  map<string,Frase> ConjF; /**< contenedor que almacena una frase en cada posicion */

public:

 /**
  * @brief Numero total de frases
  * @return El numero de frases que contiene el vector ConjF
  */
  int Size() const { return ConjF.size(); }


 /**
  * @brief Inserta una nueva frase por el final del conjunto
  * @param nueva : La frase a insertar
  */
  void Insert ( Frase nueva );


 /**
  * @brief Recorre el fichero buscando en las origen de cada frase para ver si 
  *        la cadena que le hemos pasado corresponde con alguna de ellas
  * @param frase : es la cadena que comprobamos si es alguna de las frases origen
  * @return True si es alguna. Else en caso contrario
  */
  bool Esta ( string frase ) const;


 /**
  * @brief Dado un origen, busca en el conjunto y devuelve la frase completa, con las traducciones
  * @param frase : es la frase origen
  * @return Devuelve las traducciones
  */
  vector<string> GetTraducciones ( string frase ) const;


 /**
  * @brief Dada una subcadena, crea un conjunto de frases, cuyas frases origen contengan
  *        a esa subcadena
  * @param subcadena : es la subcadena a buscar
  * @return Devuelve el conjunto de frases obtenido
  */
  Traductor Contenga ( string subcadena ) const;


 /**
  * @brief Sobrecarga del Operador>> 
  * @param flujo : es el stream de entrada
  * @param CF : es el conjunto de frases que pasa los parametros
  * @return la referencia al istream
  */
	friend istream& operator>> ( istream& flujo, Traductor& CF );  


 /**
  * @brief clase para iterar sobre la frase
  */
  class iterator {
  private:
  
    map<string,Frase> :: iterator it;
  
  public:
  
    iterator & operator++ () { ++it; return *this; }
    iterator & operator-- () { --it; return *this; }
    pair<const string,Frase> & operator* () { return *it; }
    bool operator == ( const iterator &i ) { return i.it == it; }    
    bool operator != ( const iterator &i ) { return i.it != it; }
    friend class Traductor;
  };


 /**
  * @brief Inicializa un iterator a la primera traduccion
  */
 iterator begin () {
    iterator i;
    i.it = ConjF.begin();
    return i;
  }

 /**
  * @brief Inicializa un iterator al final de las traducciones
  */
  iterator end () {
    iterator i;
    i.it = ConjF.end();
    return i;
  }


 /**
  * @brief clase constante para iterar sobre la frase
  */
  class const_iterator {
  private:
  
    map<string,Frase> :: const_iterator cit;
  
  public:
  
    const_iterator & operator++ () { ++cit; return *this; }
    const_iterator & operator-- () { --cit; return *this; }
    const pair<const string,Frase> & operator* () { return *cit; }
    bool operator == ( const const_iterator &ci ) { return ci.cit == cit; }    
    bool operator != ( const const_iterator &ci ) { return ci.cit != cit; }
    friend class Traductor;
  };


 /**
  * @brief Inicializa un iterator constante a la primera traduccion
  */
  const_iterator cbegin () const {
    const_iterator i;
    i.cit = ConjF.begin();
    return i;
  }
 

 /**
  * @brief Inicializa un iterator constante a la ultima traduccion
  */
  const_iterator cend () const {
    const_iterator i;
    i.cit = ConjF.end();
    return i;
  }


};
#endif

