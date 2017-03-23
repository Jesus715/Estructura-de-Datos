 /**
  * @file frases.h
  * @author Jesus Ruiz Castellano
  * @date 17 de Octubre de 2016, 18:29
  * @brief Fichero cabecera del TDA Frase
  *  
  */

#ifndef _FRASE_H
#define _FRASE_H


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
  * - rep.cadTraducciones.size() >= 1, a excepcion del momento de creacion del objeto, 
  *   que estara vacio completamente
  * - rep.cadTraducciones[i] != rep.cadTraducciones[j], i != j, es decir,
  *   No hay traducciones repetidas
  * 
  *
  * @section faTDAFRASE Función de abstracción
  *
  *    Un objeto valido @e rep del TDA Frase representa al valor:
  * 
  *    fa(rep) = rep.origen;rep.cadTraducciones[0];...;rep.cadTraducciones[i];...;rep.cadTraducciones[rep.cadTraducciones.size()-1];
  *             
  * 
  */
  
	string origen; /**< frase en idioma origen */
	
	vector<string> cadTraducciones; /**< cada una de las traducciones destino */

public:
 

  /**
  * @brief Inserta por el final del vector de traducciones una nueva
  * @param traduc : La traduccion a insertar
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
  * @brief Sobrecarga del Operador<< 
  * @param flujo: stream de salida
  * @param F: Frase que pasa los valores
  * @return la referencia al ostream
  */
	friend ostream& operator<< ( ostream& flujo, Frase& F );  


 /**
  * @brief Numero de traducciones
  * @return El numero de traduciones que contiene la frase origen
  * @post No se modifica
  */
	int NumTraducciones () const { return cadTraducciones.size(); }


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
  vector<string> GetDestino() const { return cadTraducciones; }

};
#endif	