/**
  * @file Cola_maxmin.h
  * @author Jesus Ruiz Castellano
  * @date 14 de Noviembre de 2016, 13:45
  * @brief Fichero implementacion de la ED Lineal Cola con maximo y minimo, representada
  *        mediante una Pila
  *
  * Gestiona una secuencia de elementos con facilidades para la inserción y
  * borrado de elementos en un extremo
  */

#ifndef _COLA_MAX_MIN_H_
#define _COLA_MAX_MIN_H_

#include <cassert>
#include "Pila_maxmin.h"



/**
 *  @brief T.D.A. Cola_maxmin
 *
 *
 * Una instancia @e c del tipo de dato abstracto Cola sobre un dominio @e T es
 * una sucesión finita de elementos del mismo con un funcionamiento @e FIFO
 * (First In, First Out}). En una cola, las operaciones de inserción tienen
 * lugar en uno de los extremos, denominado @e final de la cola, mientras que
 * el borrado y consulta se lleva a cabo en el otro extremo, denominado 
 * @e frente de la cola. Una cola de longitud @e n la denotamos

 * - <a1,a2,a3,..,an<

 * En esta cola, tendremos acceso únicamente al elemento del @e Frente,
 * es decir, a @e a1. El borrado o consulta de un elemento será sobre @e a1,
 * mientras que la inserción de un nuevo elemento se hará después de
 * @e an (final de la cola).
 *
 * Si num_elem = 0 diremos que la cola está vacía.
 *
 * El espacio requerido para el almacenamiento es O(n), donde n es el número 
 * de elementos de la cola.
 *
 */

template <class T>
class Cola_maxmin {	
private:

 /**
  * @brief Pila que almacena los datos de cualquier tipo
  */
	Pila_maxmin<T> datos;
   
public:

 /**
  * @brief Comprueba si la cola está vacía
  */
	bool vacia() const { return datos.Size() == 0; }

 /**
  * @brief Devuelve el elemento del frente de la cola
  */
	elemento<T> frente ();
	
 /**
  * @brief Devuelve el elemento del frente de una cola constante
  */
	const elemento<T> frente () const;

 /**
  * @brief Añade un elemento al final de la cola
  * @param elem Elemento que se va a añadir.
  */
	void poner(const T& elem) { datos.Poner(elem); }

 /**
  * @brief Quita el elemento del frente de la cola
  */
	void quitar();

 /**
  * @brief Devuelve el número de elementos de la cola
  */
	int num_elementos () const { return datos.Size(); }
};
#include <Cola_maxmin.cpp>
#endif // _COLA_MAX_MIN_H_
