 /**
  * @file frases.h
  * @author Jesus Ruiz Castellano
  * @date 17 de Octubre de 2016, 18:29
  * @brief Fichero cabecera del TDA Frase
  *  
  */

#ifndef _FRASE_H
#define _FRASE_H


#include <string>
#include <iostream>
#include <cassert>
#include <stdlib.h>

using namespace std;


 /**
  * @brief T.D.A. Frase
  *
  * @page esp Conjunto Especificacion 
  * Una instancia @e c del tipo de dato abstracto @c Frase es un objeto
  * que mantiene la informacion de una frase "hecha" en el idioma origen, 
  * y todas las posibles traducciones en el idioma destino.
  *
  *   Ejemplo:
  *
  *   No worries;Sin problema;No te preocupes
  */ 

class Frase {
private:
 /**
  * @page repConjunto Rep del TDA Frase
  *
  * @section invConjunto Invariante de la representación
  * - rep.nTraduc => 1.
  * - rep.cadTraducciones[i] != rep.cadTraducciones[j], i != j
  * - rep.cadTraducciones.size() == nTraduc
  * 
  *
  * @section faConjunto Función de abstracción
  *
  *    Un objeto valido @e rep del TDA Pregunta representa al valor:
  * 
  *    fA(rep) = rep.origen;{ rep.cadTraducciones.traduccion,  { rep.cadTraducciones.traduccion,  ... { rep.cadTraducciones.traduccion,
  *                           rep.cadTraducciones.siguiente  };  rep.cadTraducciones.siguiente  };      rep.cadTraducciones.siguiente  }
  *             
  */
  
  struct Traduc {
    
    string traduccion;
    Traduc* sig;
    int nelementos;

    /*Traduc ( const string& d, Traduc* sig ) {
      traduccion = d;
      siguiente = sig;
    }*/
  };


	string origen; /**< frase en idioma origen */

  int nTraduc; /**< numero de traducciones en el idioma destino */

  Traduc *primera; /**< puntero a la primera traduccion */


 /**
  * @brief Conjunto invariante de la representacion
  * @return True, si cumple las restricciones, False, en caso contrario
  * @post no modifica la frase origen, ni las traducciones
  */
	bool Invariante () const;


 /**
  * @brief Metodo auxiliar para copiar una frase
  * @param F: es la frase que se va a copiar
  * @pre F debe cumplir las restricciones
  */
  void Copiar ( const Frase& F );


 /**
  * @brief Metodo auxiliar para borrar las traducciones 
  */
  void Borrar ();


public:

 /**
  * @brief Constructor por defecto
  */
  Frase () : origen(""), nTraduc(1), primera(0) {};

 
 /**
  * @brief Constructor de copia
  * @param F: Frase que se va a copiar
  * @pre F cumple las restricciones
  */
  Frase ( const Frase& F );


 /**
  * @brief Operador de asignacion
  * @param F: es la frase que se va a asignar en la nueva variable
  * @return La referencia a la Frase que se va a asignar
  * @pre this debe apuntar a zona de memoria diferente a donde apunte F
  * @pre F debe cumplir las restricciones
  */
  Frase& operator= ( const Frase& F );


 /**
  * @brief Destructor 
  */
  ~Frase ();


 /**
  * @brief Operador de acceso y de indexacion en el vector
  * @param i: Posicion que ocupa en el vector de traducciones
  * @return La referencia a la traduccion en la posicion i
  * @pre i >= 0
  * @pre i < n
  */
	string& operator[] ( int i );

  
 /**
  * @brief Sobrecarga del Operador>> 
  * @param flujo: stream de entrada
  * @param F: Frase que recibe los parametros
  * @return la referencia al istream
  */
	friend istream& operator>> ( istream& flujo, Frase& F );  


 /**
  * @brief Sobrecarga del Operador<< 
  * @param flujo: stream de salida
  * @param F: Frase que pasa los valores
  * @return la referencia al ostream
  */
	friend ostream& operator<< ( ostream& flujo, Frase& F );  


 /**
  * @brief Metodo para añadir una traduccion al final de la lista
  * @param tra : Es la frase en idioma destino que se añade
  * @post cadTraducciones ES MODIFICADO
  */ 
  void Aniade ( string tra );


 /**
  * @brief Numero de traducciones
  * @return El numero de traduciones que contiene la frase origen
  * @post No se modifica
  */
	int NumTraducciones () const { return nTraduc; }


 /**
  * @brief Obtencion de la frase origen
  * @return El string origen
  * @post No se modifica
  */
	string GetOrigen () const { return origen; }


 /**
  * @brief Obtencion de las traducciones
  * @return El vector con todas las traducciones
  * @post No se modifica
  */
  Traduc* GetDestino() const { return cadTraducciones; }

};

#endif	