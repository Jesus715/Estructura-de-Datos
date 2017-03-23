 /**
  * @file Pila_maxmin_List.cpp
  * @author Jesus Ruiz Castellano
  * @date 11 de Noviembre de 2016, 12:50
  * @brief Fichero .cpp con la implementacion correspondiente al fichero 
  *	   Pila_maxmin_List.h 
  * 
  */

#include <iostream>
#include <cassert>
using namespace std;


 /**
  * @brief Consulta el elemento que tenemos en el tope de la Pila
  * @pre El vector de datos no puede estar vacio
  */
template <class T>
elemento<T> Pila_maxmin<T> :: Tope () const {

	assert ( datos.Size() != 0 );

	return datos.Get( datos.Begin() );
}


 /**
  * @brief Elimina el elemento de la posicion tope
  * @pre datos != 0
  */
template <class T>
void Pila_maxmin<T> :: Quitar () {

	assert ( datos.Size() != 0 );
	
	datos.Borrar( datos.Begin() );
}

	
 /**
  * @brief Inserta un nuevo elemento en la posicion tope
  */
template <class T>
void Pila_maxmin<T> :: Poner ( const T& v ) {

	elemento<T> aux;
	aux.d = v;
	
	if ( Vacia() ) {
		aux.minimo = v;
		aux.maximo = v;
	}
	else {
		elemento<T> anterior = Tope();
		aux.minimo = ( v < anterior.minimo ) ? v : anterior.minimo;
		aux.maximo = ( v > anterior.maximo ) ? v : anterior.maximo;
 	}

	datos.Insertar( datos.Begin(), aux );
}