/**
  * @file conjuntofrases.h
  * @author Jesus Ruiz Castellano
  * @date 25 de Octubre de 2016, 20:00
  * @brief Fichero cabecera del TDA Conjunto de Frases
  *  
  */

#ifndef _CONJUNTO_FRASES_H
#define _CONJUNTO_FRASES_H


#include <string>
#include <vector>
#include <iostream>
#include <cassert>
#include "frases.h"

using namespace std;


 /** 
  * @brief T.D.A. ConjuntoFrases
  *
  */

class ConjuntoFrases {
private:

 /**
  * @page Conjunto TDA ConjuntoFrases
  *
  * @section esConjunto Especificacion
  * Una instancia @e c del tipo de dato abstracto @c ConjuntoFrases es un 
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
  *	   ConjuntoFrases, este objeto siempre contendrá, al menos, 1 Frase.
  *
  * @section faConjunto Función de Abstracción
  *
  *    Un objeto valido @e rep del TDA ConjuntoFrases representa al valor:
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

	vector<Frase> ConjF; /**< contenedor que almacena una frase en cada posicion */

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
  void Push_Back ( Frase nueva );


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
  * @return Devuelve las traducciones, en formato Frase
  */
  Frase GetTraducciones ( string frase ) const;


 /**
  * @brief Dada una subcadena, crea un conjunto de frases, cuyas frases origen contengan
  *        a esa subcadena
  * @param subcadena : es la subcadena a buscar
  * @return Devuelve el conjunto de frases obtenido
  */
  ConjuntoFrases Contenga ( string subcadena ) const;


 /**
  * @brief Sobrecarga del Operador>> 
  * @param flujo : es el stream de entrada
  * @param CF : es el conjunto de frases que pasa los parametros
  * @return la referencia al istream
  */
	friend istream& operator>> ( istream& flujo, ConjuntoFrases& CF );  


 /**
  * @brief Sobrecarga del Operador<< 
  * @param flujo : es el stream de salida
  * @param CF : es el conjunto de frases que recibe los valores
  * @return la referencia al ostream
  */
	friend ostream& operator<< ( ostream& flujo, ConjuntoFrases& CF ); 

};
#endif

