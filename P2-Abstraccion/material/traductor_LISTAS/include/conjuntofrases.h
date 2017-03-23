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
#include <iostream>
#include <cassert>
#include "frases.h"

using namespace std;


 /** 
  *
  * @brief T.D.A. ConjuntoFrases
  *
  * @page esp Conjunto Especificacion
  * Una instancia @e c del tipo de dato abstracto @c ConjuntoFrases es un 
  * objeto que contiene una sucesion de frases leidas desde un fichero,
  * o cualquier entrada posible. 
  *
  * Ejemplo : 
  *
  *    Not Bad;No esta mal 
  *    Not for nothing;No es por nada 
  *    Not half;Ya lo creo 
  *    Not half;Por supuesto 
  *    Not my business;No es asunto mio
  *    ...
  */

class ConjuntoFrases {
private:

 /**
  * @section rep Conjunto Rep del TDA ConjuntoFrases
  *
  * @section inv Conjunto Invariante de la representación
  * - rep.ConjF[i] != rep.ConjF[j], Para todo i,j => i != j
  * - rep.ocupadas >= 2
  * - rep.ocupadas <= rep.TAM-1
  *
  * @section fa Conjunto Función de Abstracción
  *
  *    Un objeto valido @e rep del TDA ConjuntoFrases representa al valor:
  * 
  *    Fa(rep) = rep.ConjF[0];
  *              rep.ConjF[1];
  *                   ...
  *              rep.ConjF[rep.ocupadas-1]
  *                   ...
  *              rep.ConjF[i]
  *                   ...
  *              rep.ConjF[rep.TAM-1]
  *
  */


	int TAM; /**< tamanio inicial del conjunto */

	int ocupadas; /**< contador de frases aniadidas al conjunto */

	Frase* ConjF; /**< contenedor que almacena una frase en cada posicion */

 /**
  * @brief Metodo privado para comprobar que se cumple con el Invariante
  * @return True si cumple las condiciones, False en caso contrario
  * @post No se modifica el conjunto de frases
  */
	bool Invariante () const;

 /**
  * @brief Metodo privado para redimensionar el vector de frases
  * @post El vector de frases queda redimensionado
  */
	void MoreSize ();

public:

 /**
  * @brief Constructor por defecto con tamaño=50 y libre, es decir, con ocupadas = 0 
  * @pre ocupadas = 0
  */
	ConjuntoFrases ();


 /**
  * @brief Constructor de copia
  * @param CF : es el conjunto de frases que tenemos
  * @pre CF cumple el Invariante de esta representacion
  */
	ConjuntoFrases ( const ConjuntoFrases& CF );


 /**
  * @brief Operador de asignacion
  * @param CF : es el conjunto de frases que tenemos
  * @return La referencia al conjunto de frases asignado
  * @pre Debe cumplir con el Invariante de la representacion especificado
  */
	ConjuntoFrases& operator= ( const ConjuntoFrases& CF );


 /**
  * @brief Destructor 
  * @pre ocupadas debe ser distinto de 0
  */
	~ConjuntoFrases ();


 /**
  * @brief Operador de indexacion
  * @param i : Indice de la posicion de indexacion
  * @return La referencia a la Frase en la posicion i
  * @pre i >= 0, el indice debe de ser mayor o igual a 0
  * @pre i < ocupadas, el indice debe ser menor al numero de frases
  */
	Frase& operator[] ( int i );


 /**
  * @brief Operador de indexacion constante
  * @param i : Posicion en ConjF
  * @return La referencia constante a la Frase en la posicion i
  * @pre i >= 0 
  * @pre i < ocupadas
  */
	const Frase& operator[] ( int i ) const;


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


 /**
  * @brief Numero total de frases
  * @return El numero de frases que contiene el vector ConjF
  */
	int Size() const { return ocupadas; }


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
};

#endif

