	
 /**
  * @file Pila_maxmin_VD.cpp
  * @author Jesus Ruiz Castellano
  * @date 11 de Noviembre de 2016, 13:07
  * @brief Fichero .cpp con la implementacion correspondiente al fichero 
  *	   Pila_maxmin_VD.h 
  * 
  */

#include <iostream>
#include "VD.h"
#include <cassert>
using namespace std;

 /**
  * @brief Consulta el elemento que tenemos en el tope de la Pila
  * @pre El vector de datos no puede estar vacio
  */
template <class T>
elemento<T> Pila_maxmin<T> :: Tope () const {

	assert ( datos.Size() > 0 );
	
	return datos[datos.Size()-1];
}


 /**
  * @brief Elimina el elemento de la posicion tope
  * @pre datos.Size() > 0
  */
template <class T>
void Pila_maxmin<T> :: Quitar () {

	assert ( datos.Size() > 0 );
	
	datos.Borrar( datos.Size()-1 );
}

	
 /**
  * @brief Inserta un nuevo elemento en la posicion tope
  */
template <class T>
void Pila_maxmin<T> :: Poner ( const T& v ) {
	
	elemento<T> dato;
	dato.elemento = v;

	// Si la Pila esta vacia, el primer elemento introducido va a ser el minimo
	if ( Vacia() ) {
		dato.minimo = v;
		dato.maximo = v;
	}
	else {
		// Creamos una variable local en la que guardamos lo que hay en tope
		elemento<T> anterior = Tope ();     
		// Ahora comprobamos si el nuevo elemento introducido es menor que el minimo que hay hasta el momento en tope,
		// y si es asi, el nuevo elemento v pasa a ser el nuevo minimo
		dato.minimo = (v < anterior.minimo) ? v : anterior.minimo;
		// y con el maximo hacemos exactamente igual
		dato.maximo = (v > anterior.maximo) ? v : anterior.maximo;	
	}
	// Se inserta el nuevo dato en la siguiente posicion al Tope (n-1), n, que es la que indica Size()
	datos.Insertar ( dato, datos.Size() );
	 
}


	

	
