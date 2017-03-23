 /**
  * @file Pila_maxmin_List.h
  * @author Jesus Ruiz Castellano
  * @date 11 de Noviembre de 2016, 13:40
  * @brief Fichero cabecera de la ED Lineal Pila con maximo y minimo, representada
  *        mediante una Lista de celdas enlazadas
  *  
  */


#ifndef _PILA_MAX_MIN_LIST_H_
#define _PILA_MAX_MIN_LIST_H_

#include <iostream>
#include "Lista.h"
#include <cassert>
using namespace std;
  
 /**
  * @file Pila_maxmin_List.h
  * @brief E.D.L Pila con maximo y minimo
  *
  * @page esp Conjunto Especificacion 
  * Una instancia @e c del tipo de datos abstracto @c Pila es un objeto
  * que contiene una secuencia de valores ( a0, a1, ... ,an-1 ) especialmente
  * diseñada para realizar inserciones y borrados por uno de los extremos, el
  * del final, al que se le llama "tope".
  *
  *
  * @section rep Conjunto Rep de la ED Lineal Pila(representacion con Celdas enlazadas)
  * Lista< elemento<T> > datos
  * 
  */
template <class T>
class Pila_maxmin {
private:

 /**
  * @brief Lista que almacena los datos de cualquier tipo
  */
	Lista< elemento<T> > datos;

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
	bool Vacia () const { return datos.Size() == 0; }

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
#include "Pila_maxmin_List.cpp"
#endif
