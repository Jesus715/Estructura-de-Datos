 /**
  * @file Pila_maxmin_Cola.h
  * @author Jesus Ruiz Castellano
  * @date 11 de Noviembre de 2016, 12:20
  * @brief Fichero cabecera de la ED Lineal Pila con maximo y minimo, representada
  *        mediante una Cola
  *  
  */


#ifndef _PILA_MAX_MIN_COLA_H_
#define _PILA_MAX_MIN_COLA_H_

#include <iostream>
#include "cola.h"
#include <cassert>
using namespace std;
 
 
/**
  * @brief Estructura para los elementos
  *
  */
template <class T>
struct elemento {

	T d;	  ///< elemento a almacenar
	T maximo; ///< el maximo
	T minimo; ///< el minimo
};

 /**
  * @brief Sobrecarga del Operador<< 
  * @param os : flujo stream de salida
  * @param ele : dato de tipo elemento que pasa los valores
  * @return la referencia al ostream
  */
template <class T>
ostream& operator << ( ostream& os, const elemento<T> ele ) {
	os << "[" << ele.d << ", MAX : " << ele.maximo << ", MIN : " << ele.minimo << "]";
	return os;
}


 /**
  * @file Pila_maxmin_Cola.h
  * @brief E.D.L Pila con maximo y minimo
  *
  * @page esp Conjunto Especificacion 
  * Una instancia @e c del tipo de datos abstracto @c Pila es un objeto
  * que contiene una secuencia de valores ( a0, a1, ... ,an-1 ) especialmente
  * diseñada para realizar inserciones y borrados por uno de los extremos, el
  * del final, al que se le llama "tope".
  *
  *
  * @section rep Conjunto Rep de la ED Lineal Pila(representacion con una Cola)
  * Cola< elemento<T> > datos
  * 
  */
template <class T>
class Pila_maxmin {
private:

 /**
  * @brief Cola que almacena los datos de cualquier tipo
  */
	Cola< elemento<T> > datos;

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
	bool Vacia () const { return datos.num_elementos() == 0; }

 /**
  * @brief Elimina el elemento de la posicion tope
  * @pre La Cola no puede estar vacia
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
	int Size () const {return datos.num_elementos();}

};
#include "Pila_maxmin_Cola.cpp"
#endif
