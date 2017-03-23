 /**
  * @file Pila_maxmin_VD.h
  * @author Jesus Ruiz Castellano
  * @date 11 de Noviembre de 2016, 13:02
  * @brief Fichero cabecera de la ED Lineal Pila con maximo y minimo, representada 
  * 	   mediante vector dinamico
  *  
  */


#ifndef _PILA_MAX_MIN_VD_H_
#define _PILA_MAX_MIN_VD_H_

#include <iostream>
#include "VD.h"
#include <cassert>
using namespace std;


template <class T>
struct elemento {

 /**
  * @brief Elemento que vamos a almacenar. Puede ser de cualquier tipo de dato
  */
	T elemento;
 /**
  * @brief Indica el valor minimo de los elementos almacenados
  */
	T minimo;

 /**
  * @brief Indica el valor maximo de los elementos almacenados
  */
	T maximo;

};
	

 /**
  * @brief Sobrecarga del Operador<< 
  * @param os : flujo stream de salida
  * @param ele : dato de tipo elemento que pasa los valores
  * @return la referencia al ostream
  */
template <class T>
ostream& operator << ( ostream& os, const elemento<T> ele ) {
	os << "[" << ele.elemento << ", MAX : " << ele.maximo << ", MIN : " << ele.minimo << "]";
	return os;
}
 /**
  * @file Pila_maxmin_VD.h
  * @brief E.D.L Pila con maximo y minimo
  *
  * @page esp Conjunto Especificacion 
  * Una instancia @e c del tipo de datos abstracto @c Pila es un objeto
  * que contiene una secuencia de valores ( a0, a1, ... ,an-1 ) especialmente
  * diseñada para realizar inserciones y borrados por uno de los extremos, el
  * del final, al que se le llama "tope".
  *
  */

template <class T>

class Pila_maxmin {
private:

 /**
  * @brief rep de Pila_maxmin
  *
  * Guardamos los datos en un vector dinamico de tipo elemento
  * En este caso no hay Invariante de la Representación ya que
  * todas las restricciones estan controladas en la clase VD
  *
  */
	VD< elemento<T> > datos;


public:

 /**
  * @brief Consulta el elemento que tenemos en el tope de la Pila
  * @pre El vector de datos no puede estar vacio
  * @return El elemento de tipo T en la posicion tope
  */
	elemento<T> Tope () const;

 /**
  * @brief Comprobacion de si la Pila esta vacia o si tiene algun/os elemento/s
  * @return True, si no hay ningun elemento en la Pila, False si como minimo hay uno
  */
	bool Vacia () { return datos.Size() == 0; }

 /**
  * @brief Elimina el elemento de la posicion tope
  * @pre datos.Size() > 0
  */
	void Quitar ();

 /**
  * @brief Inserta un nuevo elemento en la posicion tope
  */
	void Poner ( const T& v );

 /**
  * @brief Indica el numero de elementos de la Pila
  * @return El tamaño del vector datos
  */
	int Size () const { return datos.Size(); }

};
#include "Pila_maxmin_VD.cpp"
#endif



